#include "bookingwidget.h"
#include "ui_bookingwidget.h"
#include <QDateTime>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include "category.h"

#include <QDebug>

static int numberCategories = 4;



BookingWidget::BookingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookingWidget)
{
    ui->setupUi(this);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    m_amountValidator = new QDoubleValidator();
    m_amountValidator->setBottom(0.0);
    m_amountValidator->setDecimals(2);
    ui->amountEdit->setValidator(m_amountValidator);

    Category *root = Category::getCategories();
    QVector<Category *> categories = root->getChildren();

    m_categoryView = new QTreeView();
    m_categoryModel = new QStandardItemModel();

    QStandardItem *parentItem = m_categoryModel->invisibleRootItem();

    for (int i = 0; i < categories.count(); ++i) {
        parentItem->setSelectable(false);
        Category *category = categories.at(i);
        QStandardItem *item = new QStandardItem(category->title());
        parentItem->appendRow(item);
        traverseCategories(category, item);
    }

    ui->comboBox->setView(m_categoryView);
    ui->comboBox->setModel(m_categoryModel);
    m_categoryView->expandAll();

    ui->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

    // Setup standard imageLabel
    QImage whiteImage(200, 150, QImage::Format_RGB32);
    whiteImage.fill(Qt::white);
    ui->imageLabel->setPixmap(QPixmap::fromImage(whiteImage));
    ui->imageLabel->setAcceptDrops(true);
}

BookingWidget::~BookingWidget()
{
    delete m_amountValidator;
    delete ui;
}

void BookingWidget::traverseCategories(Category *category, QStandardItem *fatherItem) {
    QVector<Category *> children = category->getChildren();
    int numChildren = children.size();

    for (int i = 0; i < numChildren; i++) {
        QStandardItem *categoryItem = new QStandardItem(children.at(i)->title());
        fatherItem->appendRow(categoryItem);
        traverseCategories(children.at(i), categoryItem);
    }
}

void BookingWidget::on_okButton_clicked()
{
    // Timestamp
    QDateTime time = ui->dateTimeEdit->dateTime();
    // Betrag
    QString amount = ui->amountEdit->text();
    // Konto
    QString account = ui->accountEdit->text();
    //Kategorie
    Category category(ui->comboBox->currentData().toString());
    // Notizen
    QString notes = ui->notesEdit->toPlainText();
    // Bild
    QImage image = ui->imageLabel->pixmap()->toImage();

    if (amount.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle(QString("Achtung!"));
        msgBox.setText(QString("Es wurde kein Betrag eingegeben. Trotzdem fortfahren?"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.addButton(QMessageBox::Cancel);
        int result = msgBox.exec();
        if (result == QMessageBox::Cancel) {
            return;
        }
    }

    m_booking.m_account = account;
    m_booking.m_bookingTime = time;
    m_booking.m_amount = amount;
    m_booking.m_category = category.title();
    m_booking.m_note = notes;
    m_booking.m_image = image;

    emit(okPressed(m_booking));

    this->close();
}

void BookingWidget::on_cancelButton_clicked()
{
    this->close();
}

void BookingWidget::on_imgButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Wähle Bild", QDir::homePath(), "Image Files (*.png *.jpg)");

    QImage image(fileName);
    image = image.scaled(250, 100, Qt::KeepAspectRatio);
    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
}

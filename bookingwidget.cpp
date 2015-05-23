#include "bookingwidget.h"
#include "ui_bookingwidget.h"
#include <QDateTime>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include <QDebug>


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

    // Populate the category picker
    CategoryComboBox *categoryComboBox = ui->comboBox;
    QVector<Category *> categories = Category::getCategories();
    QStringList categoryStringList;
    for (int i = 0; i < categories.size(); i++) {
        categoryStringList.append(categories.at(i)->title());
    }
    categoryStringList.append(QString("  Unterkategorie"));
    categoryComboBox->insertItems(0, categoryStringList);
    categoryComboBox->insertSeparator(1);
    connect(categoryComboBox, SIGNAL(categorySelected(Category*)), this, SLOT(on_categorySelected(Category*)));


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

void BookingWidget::on_categorySelected(Category *category)
{
    qDebug() << "bookingwidget category: " << category->title();
    ui->comboBox->setItemIcon(ui->comboBox->currentIndex(), category->icon);
    ui->comboBox->setItemText(ui->comboBox->currentIndex(), category->title());
    m_booking.setCategory(category);
}

void BookingWidget::on_okButton_clicked()
{
    // Timestamp
    QDateTime time = ui->dateTimeEdit->dateTime();
    // Betrag
    QString amount = ui->amountEdit->text();
    // Konto
    QString account = ui->accountEdit->text();
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

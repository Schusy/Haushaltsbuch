#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QDir>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_persons = new QVector<QString>();
    m_persons->append("Jens");

    m_model = new QStandardItemModel(0, 6);

    QStringList headerNames = (QStringList() << "Zeit" << "Betrag" << "Kategorie" << "Konto" << "Notizen" << "Bild");
    m_model->setHorizontalHeaderLabels(headerNames);

    ui->tableView->setModel(m_model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewBookingCreated(const Booking& b)
{
    QList<QStandardItem *> itemList;
    itemList.append(new QStandardItem(b.m_bookingTime.toString()));
    itemList.append(new QStandardItem(b.m_amount));
    itemList.append(new QStandardItem(b.m_category->title()));
    itemList.append(new QStandardItem(b.m_account));
    itemList.append(new QStandardItem(b.m_note));
    QStandardItem *imageItem = new QStandardItem();
    imageItem->setData(QVariant(QPixmap::fromImage(b.m_image)), Qt::DecorationRole);
    itemList.append(imageItem);

    m_model->appendRow(itemList);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_actionNew_Person_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("User name:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty()) {

        qDebug() << text;
    }
    m_persons->append(text);
}

void MainWindow::on_actionNew_Group_triggered()
{

}

void MainWindow::on_actionNew_Category_triggered()
{

}

void MainWindow::on_actionNew_Account_triggered()
{

}

void MainWindow::on_actionNew_Booking_triggered()
{
    bookingWidget = new BookingWidget();
    connect(bookingWidget, SIGNAL(okPressed(Booking)), this, SLOT(onNewBookingCreated(Booking)));
    bookingWidget->show();
}

void MainWindow::on_actionRebooking_triggered()
{

}

void MainWindow::on_actionSettings_triggered()
{

}

void MainWindow::on_actionOverview_triggered()
{

}

void MainWindow::on_actionBookigs_triggered()
{

}

void MainWindow::on_actionPersons_triggered()
{

}

void MainWindow::on_actionGroups_triggered()
{

}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bookingwidget.h"

#include <QVector>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onNewBookingCreated(const Booking& b);

private slots:

    void on_actionNew_Person_triggered();

    void on_actionNew_Group_triggered();

    void on_actionNew_Category_triggered();

    void on_actionNew_Account_triggered();

    void on_actionNew_Booking_triggered();

    void on_actionRebooking_triggered();

    void on_actionSettings_triggered();

    void on_actionOverview_triggered();

    void on_actionBookigs_triggered();

    void on_actionPersons_triggered();

    void on_actionGroups_triggered();

private:
    Ui::MainWindow *ui;
    BookingWidget *bookingWidget;
    QVector<QString> *m_persons;
    QStandardItemModel *m_model;

};

#endif // MAINWINDOW_H

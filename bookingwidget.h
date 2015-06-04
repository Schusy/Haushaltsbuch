#ifndef BOOKINGWIDGET_H
#define BOOKINGWIDGET_H

#include <QWidget>
#include "booking.h"
#include <QDoubleValidator>
#include "category.h"
#include <QTreeView>
#include <QStandardItemModel>

namespace Ui {
class BookingWidget;
}

class BookingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BookingWidget(QWidget *parent = 0);
    ~BookingWidget();
signals:
    void okPressed(const Booking& b);

public slots:

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_imgButton_clicked();

private:
    Ui::BookingWidget *ui;

    Booking m_booking;

    void traverseCategories(Category *category, QStandardItem *fatherItem);

    QTreeView *m_categoryView;
    QStandardItemModel *m_categoryModel;
    QDoubleValidator *m_amountValidator;
};

#endif // BOOKINGWIDGET_H

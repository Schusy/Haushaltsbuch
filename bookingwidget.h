#ifndef BOOKINGWIDGET_H
#define BOOKINGWIDGET_H

#include <QWidget>
#include "booking.h"
#include <QDoubleValidator>
#include "category.h"

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
    void on_categorySelected(Category *category);

    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_imgButton_clicked();

private:
    Ui::BookingWidget *ui;

    Booking m_booking;

    QDoubleValidator *m_amountValidator;
};

#endif // BOOKINGWIDGET_H

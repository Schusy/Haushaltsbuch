#ifndef BOOKING_H
#define BOOKING_H

#include <QObject>
#include <QImage>
#include <QDateTime>
#include "category.h"


class Booking : public QObject
{
    Q_OBJECT
public:
    explicit Booking(QObject *parent = 0);
    ~Booking();

    void setCategory(Category *category);

signals:

public slots:

private:
    enum {
        DAY,
        WEEK,
        MONTH,
        YEAR,

        CUSTOM
    };
public:
    QString m_amount;
    Category *m_category;
    QString m_account;
    QString m_note;
    QImage m_image;
    QDateTime m_inputTime;
    QDateTime m_bookingTime;

    bool m_recurring;
    int m_interval;

};

#endif // BOOKING_H

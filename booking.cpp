#include "booking.h"

Booking::Booking(QObject *parent) : QObject(parent)
{

}

Booking::~Booking()
{

}

void Booking::setCategory(Category *category)
{
    m_category = category;
}


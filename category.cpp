#include "category.h"

Category::Category(QObject *parent) :
    QObject(parent)
{

}

Category::Category(const QString &title) :
    m_title(title)
{

}

Category::~Category()
{

}

QString Category::title() const
{
    return m_title;
}

QVector<Category *> Category::getCategories()
{
    enum Categories {
        Allgemein,
        Kleidung,
        Lebensmittel,
        Miete,
        Haus,
        Versicherung,
        Gesundheit,
        Reisen,
        Freizeit,
        Haustiere,
        Buecher,
        Ausfluege,
        Geschenke,
        Strom,
        Wasser,
        Tanken,
        Auto,
        Schule,
        Sport,
        Musik,
        Freunde,
        Technik,
        Liebe,

        NUM_CATEGORIES
    };
    QVector<Category *> categories;
    categories.push_back(new Category(QString("Hier steht nachher eine Kategorie")));
    return categories;
}

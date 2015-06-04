#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include <QVector>
#include <QIcon>

class Category : public QObject
{
    Q_OBJECT
public:
    explicit Category(QObject *parent = 0);
    Category(const QString& title);

    ~Category();

    QIcon icon;

    QString title() const;
    QVector<Category *> getChildren();

    void addChild(Category *child);
    void setParent(Category *parent);

    static Category *getCategories();

signals:

public slots:

private:
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

    bool m_einnahmen;


    QString m_title;
    //QIcon icon;
    Category *m_parent;
    QVector<Category *> m_children;
};

#endif // CATEGORY_H

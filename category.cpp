#include "category.h"

static Category *rootCategory;


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

QVector<Category *> Category::getChildren()
{
    return m_children;
}

void Category::addChild(Category *child)
{
    m_children.append(child);
    child->setParent(this);
}

void Category::setParent(Category *parent)
{
    m_parent = parent;
}

Category *Category::getCategories()
{
    if (rootCategory == NULL) {
        rootCategory = new Category("ROOT");
    }

    Category *cat1 = new Category("Allgemein");
    Category *cat2 = new Category("Auto");
    Category *cat21 = new Category("Benzin");
    Category *cat22 = new Category("Werkstatt");
    cat2->addChild(cat21);
    cat2->addChild(cat22);
    rootCategory->addChild(cat1);
    rootCategory->addChild(cat2);

    // TODO: load categories from file;

    // TODO: add icon to category

    return rootCategory;
}

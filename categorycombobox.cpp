#include "categorycombobox.h"
#include <QStandardItemModel>


#include <QDebug>

CategoryComboBox::CategoryComboBox(QWidget *parent)
{
    Q_UNUSED(parent);
}

CategoryComboBox::~CategoryComboBox()
{

}

void CategoryComboBox::showPopup()
{
    //QComboBox::hidePopup();
    // Create tree view popup with model data
    m_popupWidget = new QTreeWidget(this);
    m_popupWidget->setWindowFlags(Qt::Popup);
    QPoint parentPos = this->mapToGlobal(QPoint(0, this->geometry().height()));
    QRect newSize(parentPos, QSize(this->geometry().width(), 200));
    m_popupWidget->setGeometry(newSize);

    QTreeWidgetItem *item0 = new QTreeWidgetItem();
    item0->setData(0, Qt::DisplayRole, QVariant("Oberkategorie"));
    QTreeWidgetItem *item00 = new QTreeWidgetItem(item0);
    item00->setData(0, Qt::DisplayRole, "Unterkategorie");
    item00->setData(0, Qt::DecorationRole, QIcon(":res/icons/2442.png"));

    m_popupWidget->addTopLevelItem(item0);

    connect(m_popupWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)), this, SLOT(treeItemSelected(QTreeWidgetItem*,int)));

    m_popupWidget->show();

    // asdf
}

void CategoryComboBox::hidePopup()
{
    qDebug() << "Category hidePopup()";
    if (m_popupWidget == NULL)
        return;
    // Clean up m_popupWidget, but how?
    /*
    if (m_popupWidget->isVisible()) {
        m_popupWidget->hide();
    }*/
    //QComboBox::hidePopup();
}

void CategoryComboBox::setCurrentIndex(int index)
{
    qDebug() << "Category setCurrentIndex(" << index << ")";
}

void CategoryComboBox::treeItemSelected(QTreeWidgetItem *item, int column)
{
    qDebug() << "item selected";
    if (item->childCount() > 0) {
        // We have subcategories -> dont close the popup
    } else {
        // There are no subcategories -> close popup and select category
        QString categoryTitle = item->data(column, Qt::DisplayRole).toString();
        QIcon categoryIcon = item->data(column, Qt::DecorationRole).value<QIcon>();
        qDebug() << categoryTitle << categoryIcon;

        Category *category = new Category(categoryTitle);
        category->icon = categoryIcon;

        emit categorySelected(category);

        hidePopup();

    }
}


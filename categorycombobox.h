#ifndef CATEGORYCOMBOBOX_H
#define CATEGORYCOMBOBOX_H

#include <QComboBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "category.h"

class CategoryComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit CategoryComboBox(QWidget *parent = 0);
    ~CategoryComboBox();

    void showPopup();
    void hidePopup();

public slots:
    void setCurrentIndex(int index);

protected slots:
    void treeItemSelected(QTreeWidgetItem *item, int column);

signals:
    void categorySelected(Category *category);

private:
    QTreeWidget *m_popupWidget;
};

#endif // CATEGORYCOMBOBOX_H

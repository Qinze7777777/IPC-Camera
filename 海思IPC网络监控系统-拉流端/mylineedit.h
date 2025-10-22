#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QDebug>
class MyLineEdit : public QLineEdit
{
public:
    MyLineEdit(QWidget *parent);
private:
    void focusInEvent(QFocusEvent *event) override;
};

#endif // MYLINEEDIT_H

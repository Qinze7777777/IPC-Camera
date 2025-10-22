#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QFocusEvent>

class MyTextEdit : public QTextEdit
{
public:
    MyTextEdit();
protected:
    void focusInEvent(QFocusEvent *event) override;
};

#endif // MYTEXTEDIT_H

#ifndef SIMPLETEXT_H
#define SIMPLETEXT_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleText; }
QT_END_NAMESPACE

class SimpleText : public QWidget
{
    Q_OBJECT

public:
    SimpleText(QWidget *parent = nullptr);
    ~SimpleText();

 public slots:
    void saveText();

private:
    Ui::SimpleText *ui;
    QTextEdit *inputText;
    QPushButton *okButton;
    QPushButton *cancelButton;

};
#endif // SIMPLETEXT_H

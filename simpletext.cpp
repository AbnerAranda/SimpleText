#include "simpletext.h"
#include "./ui_simpletext.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

SimpleText::SimpleText(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SimpleText)
{
    QLabel *inputLabel = new QLabel(tr("Input:"));
    inputText = new QTextEdit;

    okButton = new QPushButton(tr("&Ok"));
    okButton->show();
    cancelButton = new QPushButton(tr("&Cancel"));
    cancelButton->show();

    connect(okButton, &QPushButton::clicked,this, &SimpleText::saveText);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputText);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);
    setWindowTitle("Simple Text");

    ui->setupUi(this);
}

void SimpleText::saveText(){
    QString printText = inputText->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Text"), "",tr("Textk (*.txt);;All Files (*)"));

    if(fileName.isEmpty())
        return;
    else{
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
                return;
            }
            QTextStream out(&file);
            out << printText;
        }
}

SimpleText::~SimpleText()
{
    delete ui;
}


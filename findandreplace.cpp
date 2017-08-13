#include "findandreplace.h"
#include "ui_findandreplace.h"
#include <QString>
#include <QMessageBox>


    int S1=0;
FindAndReplace::FindAndReplace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindAndReplace)
{
    ui->setupUi(this);
    setWindowTitle(tr("Find and Replace"));

}

FindAndReplace::~FindAndReplace()
{
    delete ui;
}





void FindAndReplace::on_pushButton_clicked()
{

    bool found = false;
    QString Sword = ui->lineEdit->text();
    QTextDocument *paragraph = ui->textEdit->document();
    QTextCursor cursor(paragraph);
    QTextCursor Hcursor(paragraph);





    if(Sword.isEmpty()){
        QMessageBox::information(this,tr("Warning!"),tr("Please enter a word to find!!"));
    }
    else{

        cursor.beginEditBlock();
            QTextCharFormat plainFormat(Hcursor.charFormat());
            QTextCharFormat colorFormat = plainFormat;
            colorFormat.setForeground(Qt::red);



            while(!Hcursor.isNull() && !Hcursor.atEnd())
            {
                Hcursor = paragraph->find(Sword,Hcursor,QTextDocument::FindWholeWords);
                if(!Hcursor.isNull()){

                    found = true;
                    Hcursor.movePosition(QTextCursor::WordRight,QTextCursor::KeepAnchor);
                    Hcursor.mergeCharFormat(colorFormat);}
            }

        cursor.endEditBlock();
    }

}

void FindAndReplace::on_pushButton_2_clicked()
{
    QString Sword = ui->lineEdit->text();
    QString Rword = ui->lineEdit_2->text();
    QString wholeText = ui->textEdit->toPlainText();

    wholeText.replace(Sword,Rword,Qt::CaseInsensitive);
    ui->textEdit->setText(wholeText);
}

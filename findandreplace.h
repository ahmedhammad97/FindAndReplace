#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H

#include <QMainWindow>

namespace Ui {
class FindAndReplace;
}

class FindAndReplace : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindAndReplace(QWidget *parent = 0);
    ~FindAndReplace();

private slots:




    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FindAndReplace *ui;
};

#endif // FINDANDREPLACE_H

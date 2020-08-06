#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QLineEdit>
#include"SolvingSudoKu.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
   void checkString(const QString &);
   void solve();
   void clear();
   void example();
private:
    bool wrongNumber;
    QList<QLineEdit *> lists;
    Ui::MainWindow *ui;
    SolvingSudoku sudoku;
};
#endif // MAINWINDOW_H

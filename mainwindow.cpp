#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/images/bkgd.jpg");
    bkgnd = bkgnd.scaled(500 ,535);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    lists={ui->lineEdit_11,ui->lineEdit_12,ui->lineEdit_13,ui->lineEdit_14,ui->lineEdit_15,
                      ui->lineEdit_16,ui->lineEdit_17,ui->lineEdit_18,ui->lineEdit_19,
           ui->lineEdit_21,ui->lineEdit_22,ui->lineEdit_23,ui->lineEdit_24,ui->lineEdit_25,
                      ui->lineEdit_26,ui->lineEdit_27,ui->lineEdit_28,ui->lineEdit_29,
           ui->lineEdit_31,ui->lineEdit_32,ui->lineEdit_33,ui->lineEdit_34,ui->lineEdit_35,
                      ui->lineEdit_36,ui->lineEdit_37,ui->lineEdit_38,ui->lineEdit_39,
           ui->lineEdit_41,ui->lineEdit_42,ui->lineEdit_43,ui->lineEdit_44,ui->lineEdit_45,
                      ui->lineEdit_46,ui->lineEdit_47,ui->lineEdit_48,ui->lineEdit_49,
           ui->lineEdit_51,ui->lineEdit_52,ui->lineEdit_53,ui->lineEdit_54,ui->lineEdit_55,
                      ui->lineEdit_56,ui->lineEdit_57,ui->lineEdit_58,ui->lineEdit_59,
           ui->lineEdit_61,ui->lineEdit_62,ui->lineEdit_63,ui->lineEdit_64,ui->lineEdit_65,
                      ui->lineEdit_66,ui->lineEdit_67,ui->lineEdit_68,ui->lineEdit_69,
           ui->lineEdit_71,ui->lineEdit_72,ui->lineEdit_73,ui->lineEdit_74,ui->lineEdit_75,
                      ui->lineEdit_76,ui->lineEdit_77,ui->lineEdit_78,ui->lineEdit_79,
           ui->lineEdit_81,ui->lineEdit_82,ui->lineEdit_83,ui->lineEdit_84,ui->lineEdit_85,
                      ui->lineEdit_86,ui->lineEdit_87,ui->lineEdit_88,ui->lineEdit_89,
           ui->lineEdit_91,ui->lineEdit_92,ui->lineEdit_93,ui->lineEdit_94,ui->lineEdit_95,
                      ui->lineEdit_96,ui->lineEdit_97,ui->lineEdit_98,ui->lineEdit_99

    };


connect(ui->pushButtonClear,SIGNAL(clicked(bool)),this,SLOT(clear()));
connect(ui->pushButtonSolve,SIGNAL(clicked(bool)),this,SLOT(solve()));
connect(ui->pushButtonExample,SIGNAL(clicked(bool)),this,SLOT(example()));
   for(auto l : lists)
       connect(l, &QLineEdit::textChanged,this,&MainWindow::checkString);
}
void MainWindow::solve(){
    for(auto l : lists)
        l->setStyleSheet("background-color: rgb(211, 215, 207);");


     sudoku.setGrid(lists);
    // sudoku.sudokuGrid();
     sudoku.showGrid(lists);
}void MainWindow::clear(){
    for(auto l : lists){
        l->clear();
        l->setStyleSheet("background-color: rgb(211, 215, 207);");
    }
}
void MainWindow::checkString(const QString & str){
   if (str.size()!=0)
    if(str.size()>1 || str.at(0)<QChar('1') || str.at(0)>QChar('9')){
          QMessageBox::information(this, QString::fromUtf8("Внимание!"), QString::fromUtf8("Цифра от 1 до 9"));

    }


}
void MainWindow::example(){
    sudoku.showExm(lists);
}
MainWindow::~MainWindow()
{
    delete ui;
}


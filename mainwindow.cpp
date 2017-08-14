#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    this->setWindowTitle("数字轮询");
    fileMake();
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
    b = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//文件读取
void MainWindow::fileMake()
{
    QFile file("number.txt");
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd())
    {
        this->fileList.append(file.readAll());
    }
    fileList2 = fileList;

}
//按钮开始
void MainWindow::on_btn_clicked()
{
    QString s;
    s = ui->secondLine->text();
    int ss = s.toInt();
    if(b)
    {
        timer->start(ss*1000);

        ui->btn->setText("停止轮询");
        b = false;
    }
    else
    {
        timer->stop();
        b = true;
        ui->btn->setText("开始轮询");
    }
}
//定时器槽函数
void MainWindow::timerSlot()
{
    int i = fileList.indexOf("*");
    QString str = fileList.mid(0,i);
    fileList.remove(0,i+1);

    ui->lineEdit->setText(str);
    if(fileList.size() == 0)
    {
         fileList = fileList2;
    }
}

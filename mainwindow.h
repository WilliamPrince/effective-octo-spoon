#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QIODevice>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void fileMake();

private slots:
    void on_btn_clicked();
    void timerSlot();
private:
    Ui::MainWindow *ui;
    QString fileList;
    QTimer *timer;
    QString fileList2;
    bool b;
};

#endif // MAINWINDOW_H

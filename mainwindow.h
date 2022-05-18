#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "actionstade.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int CurrentAction;
    bool is_died;
    ActionStade obj1;

private slots:
    void on_pushButton_clicked();
    void Load(int a);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

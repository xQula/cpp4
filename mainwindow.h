#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_psh_setup_clicked();

    void on_pb_bar_valueChanged(int value);

    void on_psh_setup_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    int count;
    bool flag_click;
};
#endif // MAINWINDOW_H

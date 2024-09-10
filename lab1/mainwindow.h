#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_squar_clicked();
    void on_result_square_clicked();

    void on_rect_clicked();
    void on_result_rect_clicked();


    // void on_rect_clicked();

    // void on_circle_clicked();

    // void on_paral_clicked();

    // void on_romb_clicked();

    // void on_sector_clicked();

    // void on_trapc_clicked();

    // void on_treugl_clicked();




    void on_paral_clicked();

    void on_result_paral_clicked();

    void on_romb_clicked();

    void on_result_romb_clicked();

    void on_treugl_clicked();

    void on_result_treg_clicked();

    void on_trapc_clicked();

    void on_result_trap_clicked();

    void on_circle_clicked();

    void on_result_circle_clicked();

    void on_sector_clicked();

    void on_result_sec_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

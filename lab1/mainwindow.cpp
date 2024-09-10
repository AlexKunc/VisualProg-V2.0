#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Квадрат
    QPixmap pix_square(":/resorces/images/square.jpg");
    int w_sq = ui->img_square->width();;
    int h_sq = ui->img_square->height();
    ui->img_square->setPixmap(pix_square.scaled(w_sq, h_sq, Qt::KeepAspectRatio));

    ui->area_square->setVisible(false);
    ui->result_square->setVisible(false);
    ui->label_length_square->setVisible(false);
    ui->label_width_square->setVisible(false);
    ui->inp_length_square->setVisible(false);
    ui->inp_width_square->setVisible(false);
    ui->formula_square->setVisible(false);
    ui->img_square->setVisible(false);
    //Прямоугльник
    QPixmap pix_rect(":/resorces/images/rect.png");
    int w_rect = ui->img_rect->width();;
    int h_rect = ui->img_rect->height();
    ui->img_rect->setPixmap(pix_rect.scaled(w_rect, h_rect, Qt::KeepAspectRatio));

    ui->area_rect->setVisible(false);
    ui->result_rect->setVisible(false);
    ui->label_length_rect->setVisible(false);
    ui->label_width_rect->setVisible(false);
    ui->inp_length_rect->setVisible(false);
    ui->inp_width_rect->setVisible(false);
    ui->formula_rect->setVisible(false);
    ui->img_rect->setVisible(false);
    //Параллелограмм
    QPixmap pix_paral(":/resorces/images/paral.png");
    int w_paral = ui->img_paral->width();;
    int h_paral = ui->img_paral->height();
    ui->img_paral->setPixmap(pix_paral.scaled(w_paral, h_paral, Qt::KeepAspectRatio));

    ui->area_paral->setVisible(false);
    ui->result_paral->setVisible(false);
    ui->label_height_paral->setVisible(false);
    ui->label_width_paral->setVisible(false);
    ui->inp_height_paral->setVisible(false);
    ui->inp_width_paral->setVisible(false);
    ui->formula_paral->setVisible(false);
    ui->img_paral->setVisible(false);
    //Ромб
    QPixmap pix_romb(":/resorces/images/romb.jpg");
    int w_romb = ui->img_romb->width();;
    int h_romb = ui->img_romb->height();
    ui->img_romb->setPixmap(pix_romb.scaled(w_romb, h_romb, Qt::KeepAspectRatio));

    ui->area_romb->setVisible(false);
    ui->result_romb->setVisible(false);
    ui->label_d1_romb->setVisible(false);
    ui->label_d2_romb->setVisible(false);
    ui->inp_d1_romb->setVisible(false);
    ui->inp_d2_romb->setVisible(false);
    ui->formula_romb->setVisible(false);
    ui->img_romb->setVisible(false);
    //Треугольник
    QPixmap pix_treg(":/resorces/images/treg.jpg");
    int w_treg = ui->img_treg->width();;
    int h_treg = ui->img_treg->height();
    ui->img_treg->setPixmap(pix_treg.scaled(w_treg, h_treg, Qt::KeepAspectRatio));

    ui->area_treg->setVisible(false);
    ui->result_treg->setVisible(false);
    ui->label_height_treg->setVisible(false);
    ui->label_width_treg->setVisible(false);
    ui->inp_height_treg->setVisible(false);
    ui->inp_width_treg->setVisible(false);
    ui->formula_treg->setVisible(false);
    ui->img_treg->setVisible(false);
    //Трапеция
    QPixmap pix_trap(":/resorces/images/trap.png");
    int w_trap = ui->img_trap->width();;
    int h_trap = ui->img_trap->height();
    ui->img_trap->setPixmap(pix_trap.scaled(w_trap, h_trap, Qt::KeepAspectRatio));

    ui->area_trap->setVisible(false);
    ui->result_trap->setVisible(false);
    ui->label_height_trap->setVisible(false);
    ui->label_width_trap->setVisible(false);
    ui->inp_height_trap->setVisible(false);
    ui->inp_width_trap->setVisible(false);
    ui->formula_trap->setVisible(false);
    ui->img_trap->setVisible(false);
    //Круг
    QPixmap pix_circle(":/resorces/images/circle.jpg");
    int w_circle = ui->img_circle->width();;
    int h_circle = ui->img_circle->height();
    ui->img_circle->setPixmap(pix_circle.scaled(w_circle, h_circle, Qt::KeepAspectRatio));

    ui->area_circle->setVisible(false);
    ui->result_circle->setVisible(false);
    ui->label_r_circle->setVisible(false);
    ui->inp_r_circle->setVisible(false);
    ui->formula_circle->setVisible(false);
    ui->img_circle->setVisible(false);

    //Сектор
    QPixmap pix_sec(":/resorces/images/sec.jpg");
    int w_sec = ui->img_sec->width();;
    int h_sec = ui->img_sec->height();
    ui->img_sec->setPixmap(pix_sec.scaled(w_sec, h_sec, Qt::KeepAspectRatio));

    ui->area_sec->setVisible(false);
    ui->result_sec->setVisible(false);
    ui->label_d_sec->setVisible(false);
    ui->inp_d_sec->setVisible(false);
    ui->label_r_sec->setVisible(false);
    ui->inp_r_sec->setVisible(false);
    ui->formula_sec->setVisible(false);
    ui->img_sec->setVisible(false);



}

MainWindow::~MainWindow()
{
    delete ui;
}


//Квадрат
void MainWindow::on_squar_clicked()
{
    bool isVisible = ui->label_length_square->isVisible();
    if(isVisible == false) {
        ui->inp_width_square->setText("");
        ui->inp_length_square->setText("");
        ui->area_square->setText("");
    }

    ui->area_square->setVisible(!isVisible);

    ui->result_square->setVisible(!isVisible);
    ui->label_width_square->setVisible(!isVisible);
    ui->label_length_square->setVisible(!isVisible);
    ui->inp_width_square->setVisible(!isVisible);
    ui->inp_length_square->setVisible(!isVisible);
    ui->formula_square->setVisible(!isVisible);
    ui->img_square->setVisible(!isVisible);
}

void MainWindow::on_result_square_clicked()
{
    QString squareLength = ui->inp_length_square->text();
    QString squareWidth = ui->inp_width_square->text();

    int length = squareLength.toInt();
    int width = squareWidth.toInt();

    ui->area_square->setText( QString::number(length * width));
}

// Прямоугольник
void MainWindow::on_rect_clicked()
{
    bool isVisible = ui->label_length_rect->isVisible();
    if(isVisible == false) {
        ui->inp_width_rect->setText("");
        ui->inp_length_rect->setText("");
        ui->area_rect->setText("");
    }

    ui->area_rect->setVisible(!isVisible);

    ui->result_rect->setVisible(!isVisible);
    ui->label_width_rect->setVisible(!isVisible);
    ui->label_length_rect->setVisible(!isVisible);
    ui->inp_width_rect->setVisible(!isVisible);
    ui->inp_length_rect->setVisible(!isVisible);
    ui->formula_rect->setVisible(!isVisible);
    ui->img_rect->setVisible(!isVisible);
}

void MainWindow::on_result_rect_clicked()
{
    QString rectLength = ui->inp_length_rect->text();
    QString rectWidth = ui->inp_width_rect->text();

    int length = rectLength.toInt();
    int width = rectWidth.toInt();

    ui->area_rect->setText( QString::number(length * width));
}

//Параллелограмм
void MainWindow::on_paral_clicked()
{
    bool isVisible = ui->label_height_paral->isVisible();
    if(isVisible == false) {
        ui->inp_width_paral->setText("");
        ui->inp_height_paral->setText("");
        ui->area_paral->setText("");
    }

    ui->area_paral->setVisible(!isVisible);

    ui->result_paral->setVisible(!isVisible);
    ui->label_width_paral->setVisible(!isVisible);
    ui->label_height_paral->setVisible(!isVisible);
    ui->inp_width_paral->setVisible(!isVisible);
    ui->inp_height_paral->setVisible(!isVisible);
    ui->formula_paral->setVisible(!isVisible);
    ui->img_paral->setVisible(!isVisible);
}
void MainWindow::on_result_paral_clicked()
{
    QString paralHeight = ui->inp_height_paral->text();
    QString paralWidth = ui->inp_width_paral->text();

    int height = paralHeight.toInt();
    int width = paralWidth.toInt();

    ui->area_paral->setText( QString::number(height * width));
}

//Ромб
void MainWindow::on_romb_clicked()
{
    bool isVisible = ui->label_d1_romb->isVisible();
    if(isVisible == false) {
        ui->inp_d1_romb->setText("");
        ui->inp_d2_romb->setText("");
        ui->area_romb->setText("");
    }

    ui->area_romb->setVisible(!isVisible);

    ui->result_romb->setVisible(!isVisible);
    ui->label_d1_romb->setVisible(!isVisible);
    ui->label_d2_romb->setVisible(!isVisible);
    ui->inp_d1_romb->setVisible(!isVisible);
    ui->inp_d2_romb->setVisible(!isVisible);
    ui->formula_romb->setVisible(!isVisible);
    ui->img_romb->setVisible(!isVisible);
}


void MainWindow::on_result_romb_clicked()
{
    QString rombD1 = ui->inp_d1_romb->text();
    QString rombD2 = ui->inp_d2_romb->text();

    float d1 = rombD1.toFloat();
    float d2 = rombD2.toFloat();

    ui->area_romb->setText( QString::number((d1 * d2)/2));
}

//Треугольник

void MainWindow::on_treugl_clicked()
{
    bool isVisible = ui->label_height_treg->isVisible();
    if(isVisible == false) {
        ui->inp_width_treg->setText("");
        ui->inp_height_treg->setText("");
        ui->area_treg->setText("");
    }

    ui->area_treg->setVisible(!isVisible);

    ui->result_treg->setVisible(!isVisible);
    ui->label_width_treg->setVisible(!isVisible);
    ui->label_height_treg->setVisible(!isVisible);
    ui->inp_width_treg->setVisible(!isVisible);
    ui->inp_height_treg->setVisible(!isVisible);
    ui->formula_treg->setVisible(!isVisible);
    ui->img_treg->setVisible(!isVisible);
}


void MainWindow::on_result_treg_clicked()
{
    QString tregHeight = ui->inp_height_treg->text();
    QString tregWidth = ui->inp_width_treg->text();

    float height =tregHeight.toFloat();
    float width = tregWidth.toFloat();

    ui->area_treg->setText( QString::number((height * width)/2));
}
//Трапеция
void MainWindow::on_trapc_clicked()
{
    bool isVisible = ui->label_height_trap->isVisible();
    if(isVisible == false) {
        ui->inp_width_trap->setText("");
        ui->inp_height_trap->setText("");
        ui->area_trap->setText("");
    }

    ui->area_trap->setVisible(!isVisible);

    ui->result_trap->setVisible(!isVisible);
    ui->label_width_trap->setVisible(!isVisible);
    ui->label_height_trap->setVisible(!isVisible);
    ui->inp_width_trap->setVisible(!isVisible);
    ui->inp_height_trap->setVisible(!isVisible);
    ui->formula_trap->setVisible(!isVisible);
    ui->img_trap->setVisible(!isVisible);
}


void MainWindow::on_result_trap_clicked()
{
    QString trapHeight = ui->inp_height_trap->text();
    QString trapWidth = ui->inp_width_trap->text();

    float height =trapHeight.toFloat();
    float width = trapWidth.toFloat();

    ui->area_trap->setText( QString::number((height * width)));
}

//Круг

void MainWindow::on_circle_clicked()
{
    bool isVisible = ui->label_r_circle->isVisible();
    if(isVisible == false) {

        ui->inp_r_circle->setText("");
        ui->area_circle->setText("");
    }
    ui->area_circle->setVisible(!isVisible);
    ui->result_circle->setVisible(!isVisible);
    ui->label_r_circle->setVisible(!isVisible);
    ui->inp_r_circle->setVisible(!isVisible);
    ui->formula_circle->setVisible(!isVisible);
    ui->img_circle->setVisible(!isVisible);

}


void MainWindow::on_result_circle_clicked()
{
    QString circleRad = ui->inp_r_circle->text();

    float radius = circleRad.toFloat();
    ui->area_circle->setText( QString::number(3.14*radius*radius));
}

//Сектор
void MainWindow::on_sector_clicked()
{
    bool isVisible = ui->label_r_sec->isVisible();
    if(isVisible == false) {
        ui->inp_d_sec->setText("");
        ui->inp_r_sec->setText("");
        ui->area_sec->setText("");
    }
    ui->area_sec->setVisible(!isVisible);
    ui->result_sec->setVisible(!isVisible);
    ui->label_r_sec->setVisible(!isVisible);
    ui->inp_r_sec->setVisible(!isVisible);
    ui->label_d_sec->setVisible(!isVisible);
    ui->inp_d_sec->setVisible(!isVisible);
    ui->formula_sec->setVisible(!isVisible);
    ui->img_sec->setVisible(!isVisible);
}

void MainWindow::on_result_sec_clicked()
{
    QString secRad = ui->inp_r_sec->text();
    QString secDug = ui->inp_d_sec->text();


    float radius = secRad.toFloat();
    float duga = secDug.toFloat();
    ui->area_sec->setText( QString::number((radius*duga)/2));
}






















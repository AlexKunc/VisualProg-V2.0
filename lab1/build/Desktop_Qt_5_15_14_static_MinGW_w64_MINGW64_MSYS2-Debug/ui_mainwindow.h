/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *rect_form;
    QVBoxLayout *layout_square_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_length_rect;
    QLineEdit *inp_length_rect;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_width_rect;
    QLineEdit *inp_width_rect;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *result_rect;
    QLabel *area_rect;
    QLabel *formula_rect;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *squar;
    QPushButton *rect;
    QPushButton *paral;
    QPushButton *romb;
    QPushButton *treugl;
    QPushButton *trapc;
    QPushButton *circle;
    QPushButton *sector;
    QWidget *widget1;
    QVBoxLayout *suare_form;
    QVBoxLayout *layout_square;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_length_square;
    QLineEdit *inp_length_square;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_width_square;
    QLineEdit *inp_width_square;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *result_square;
    QLabel *area_square;
    QLabel *formula_square;
    QMenuBar *menubar;
    QMenu *authors;
    QMenu *clear;
    QMenu *exit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(490, 140, 255, 120));
        rect_form = new QVBoxLayout(layoutWidget);
        rect_form->setObjectName(QString::fromUtf8("rect_form"));
        rect_form->setContentsMargins(0, 0, 0, 0);
        layout_square_2 = new QVBoxLayout();
        layout_square_2->setObjectName(QString::fromUtf8("layout_square_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_length_rect = new QLabel(layoutWidget);
        label_length_rect->setObjectName(QString::fromUtf8("label_length_rect"));

        horizontalLayout_4->addWidget(label_length_rect);

        inp_length_rect = new QLineEdit(layoutWidget);
        inp_length_rect->setObjectName(QString::fromUtf8("inp_length_rect"));

        horizontalLayout_4->addWidget(inp_length_rect);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_width_rect = new QLabel(layoutWidget);
        label_width_rect->setObjectName(QString::fromUtf8("label_width_rect"));

        horizontalLayout_5->addWidget(label_width_rect);

        inp_width_rect = new QLineEdit(layoutWidget);
        inp_width_rect->setObjectName(QString::fromUtf8("inp_width_rect"));

        horizontalLayout_5->addWidget(inp_width_rect);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_7);


        layout_square_2->addLayout(verticalLayout_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        result_rect = new QPushButton(layoutWidget);
        result_rect->setObjectName(QString::fromUtf8("result_rect"));

        horizontalLayout_6->addWidget(result_rect);

        area_rect = new QLabel(layoutWidget);
        area_rect->setObjectName(QString::fromUtf8("area_rect"));

        horizontalLayout_6->addWidget(area_rect);


        layout_square_2->addLayout(horizontalLayout_6);


        rect_form->addLayout(layout_square_2);

        formula_rect = new QLabel(layoutWidget);
        formula_rect->setObjectName(QString::fromUtf8("formula_rect"));

        rect_form->addWidget(formula_rect);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 150, 108, 236));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        squar = new QPushButton(widget);
        squar->setObjectName(QString::fromUtf8("squar"));

        verticalLayout->addWidget(squar);

        rect = new QPushButton(widget);
        rect->setObjectName(QString::fromUtf8("rect"));

        verticalLayout->addWidget(rect);

        paral = new QPushButton(widget);
        paral->setObjectName(QString::fromUtf8("paral"));

        verticalLayout->addWidget(paral);

        romb = new QPushButton(widget);
        romb->setObjectName(QString::fromUtf8("romb"));

        verticalLayout->addWidget(romb);

        treugl = new QPushButton(widget);
        treugl->setObjectName(QString::fromUtf8("treugl"));

        verticalLayout->addWidget(treugl);

        trapc = new QPushButton(widget);
        trapc->setObjectName(QString::fromUtf8("trapc"));

        verticalLayout->addWidget(trapc);

        circle = new QPushButton(widget);
        circle->setObjectName(QString::fromUtf8("circle"));

        verticalLayout->addWidget(circle);

        sector = new QPushButton(widget);
        sector->setObjectName(QString::fromUtf8("sector"));

        verticalLayout->addWidget(sector);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(190, 60, 210, 120));
        suare_form = new QVBoxLayout(widget1);
        suare_form->setObjectName(QString::fromUtf8("suare_form"));
        suare_form->setContentsMargins(0, 0, 0, 0);
        layout_square = new QVBoxLayout();
        layout_square->setObjectName(QString::fromUtf8("layout_square"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_length_square = new QLabel(widget1);
        label_length_square->setObjectName(QString::fromUtf8("label_length_square"));

        horizontalLayout->addWidget(label_length_square);

        inp_length_square = new QLineEdit(widget1);
        inp_length_square->setObjectName(QString::fromUtf8("inp_length_square"));

        horizontalLayout->addWidget(inp_length_square);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_width_square = new QLabel(widget1);
        label_width_square->setObjectName(QString::fromUtf8("label_width_square"));

        horizontalLayout_2->addWidget(label_width_square);

        inp_width_square = new QLineEdit(widget1);
        inp_width_square->setObjectName(QString::fromUtf8("inp_width_square"));

        horizontalLayout_2->addWidget(inp_width_square);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        layout_square->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        result_square = new QPushButton(widget1);
        result_square->setObjectName(QString::fromUtf8("result_square"));

        horizontalLayout_3->addWidget(result_square);

        area_square = new QLabel(widget1);
        area_square->setObjectName(QString::fromUtf8("area_square"));

        horizontalLayout_3->addWidget(area_square);


        layout_square->addLayout(horizontalLayout_3);


        suare_form->addLayout(layout_square);

        formula_square = new QLabel(widget1);
        formula_square->setObjectName(QString::fromUtf8("formula_square"));

        suare_form->addWidget(formula_square);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        authors = new QMenu(menubar);
        authors->setObjectName(QString::fromUtf8("authors"));
        clear = new QMenu(menubar);
        clear->setObjectName(QString::fromUtf8("clear"));
        exit = new QMenu(menubar);
        exit->setObjectName(QString::fromUtf8("exit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(authors->menuAction());
        menubar->addAction(clear->menuAction());
        menubar->addAction(exit->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lab1", nullptr));
        label_length_rect->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260", nullptr));
        label_width_rect->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        result_rect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        area_rect->setText(QString());
        formula_rect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260 = \320\224\320\273\320\270\320\275\320\260 * \320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        squar->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        rect->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        paral->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\320\276\320\263\321\200\320\260\320\274\320\274", nullptr));
        romb->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\274\320\261", nullptr));
        treugl->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        trapc->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\260\320\277\320\265\321\206\320\270\321\217", nullptr));
        circle->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        sector->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\320\272\321\202\320\276\321\200", nullptr));
        label_length_square->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260", nullptr));
        label_width_square->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        result_square->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        area_square->setText(QString());
        formula_square->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\260 = \320\224\320\273\320\270\320\275\320\260 * \320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        authors->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\321\213", nullptr));
        clear->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        exit->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

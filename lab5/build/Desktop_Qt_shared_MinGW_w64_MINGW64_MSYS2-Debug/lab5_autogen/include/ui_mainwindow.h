/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Open;
    QAction *Save;
    QAction *Add;
    QAction *Search;
    QAction *Replace;
    QAction *Return;
    QAction *Exit;
    QAction *Clear;
    QAction *actionChangeFont;
    QAction *actionChangeColor;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QLabel *backgroundLabel;
    QMenuBar *menubar;
    QMenu *File;
    QMenu *Edit;
    QMenu *FontMenu;
    QMenu *ColorMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 460);
        Open = new QAction(MainWindow);
        Open->setObjectName("Open");
        Save = new QAction(MainWindow);
        Save->setObjectName("Save");
        Add = new QAction(MainWindow);
        Add->setObjectName("Add");
        Search = new QAction(MainWindow);
        Search->setObjectName("Search");
        Replace = new QAction(MainWindow);
        Replace->setObjectName("Replace");
        Return = new QAction(MainWindow);
        Return->setObjectName("Return");
        Exit = new QAction(MainWindow);
        Exit->setObjectName("Exit");
        Clear = new QAction(MainWindow);
        Clear->setObjectName("Clear");
        actionChangeFont = new QAction(MainWindow);
        actionChangeFont->setObjectName("actionChangeFont");
        actionChangeColor = new QAction(MainWindow);
        actionChangeColor->setObjectName("actionChangeColor");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(110, 10, 581, 321));
        backgroundLabel = new QLabel(centralwidget);
        backgroundLabel->setObjectName("backgroundLabel");
        backgroundLabel->setGeometry(QRect(40, 230, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        File = new QMenu(menubar);
        File->setObjectName("File");
        Edit = new QMenu(menubar);
        Edit->setObjectName("Edit");
        FontMenu = new QMenu(menubar);
        FontMenu->setObjectName("FontMenu");
        ColorMenu = new QMenu(menubar);
        ColorMenu->setObjectName("ColorMenu");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(File->menuAction());
        menubar->addAction(Edit->menuAction());
        menubar->addAction(FontMenu->menuAction());
        menubar->addAction(ColorMenu->menuAction());
        File->addAction(Open);
        File->addAction(Save);
        Edit->addAction(Search);
        Edit->addAction(Replace);
        Edit->addAction(Return);
        Edit->addAction(Clear);
        FontMenu->addAction(actionChangeFont);
        ColorMenu->addAction(actionChangeColor);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        Replace->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
        Return->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionChangeFont->setText(QCoreApplication::translate("MainWindow", "Change font", nullptr));
        actionChangeColor->setText(QCoreApplication::translate("MainWindow", "Change Texr Color", nullptr));
        backgroundLabel->setText(QString());
        File->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        Edit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        FontMenu->setTitle(QCoreApplication::translate("MainWindow", "Font", nullptr));
        ColorMenu->setTitle(QCoreApplication::translate("MainWindow", "Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

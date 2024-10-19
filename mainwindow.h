#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QCloseEvent>
#include <QMessageBox>

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
    void on_openFile_triggered();
    void on_saveFile_triggered();
    void clearAndSave();
    void restoreFromTemp();
    void on_fontChange_triggered();
    void on_colorChange_triggered();
    void on_search_triggered();
    void on_replace_triggered();
    void on_createTable_triggered();
    void textChanged();

private:
    void saveToTempFile();
    void loadSettings();
    void saveSettings();
    void closeEvent(QCloseEvent *event) override;

    Ui::MainWindow *ui;
    QString lastFilePath;
    QFile tempFile;
    bool isTempFileEmpty;
    bool isContentModified;
};

#endif // MAINWINDOW_H

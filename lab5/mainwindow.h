#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QCloseEvent>
#include <QSettings>  // Для хранения настроек

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


protected:
    void closeEvent(QCloseEvent *event) override; // Переопределение closeEvent

private:
    Ui::MainWindow *ui;
    QFile tempFile;
    QString lastFilePath;

    void saveToTempFile();
    void loadFromTempFile();

    //Load and save
    void saveSettings();
    void loadSettings();


private slots:
    void on_openFile_triggered();
    void on_saveFile_triggered();
    void clearAndSave();
    void restoreFromTemp();
    void on_fontChange_triggered();
    void on_colorChange_triggered();
    void on_search_triggered();
    void on_replace_triggered();

};



#endif // MAINWINDOW_H

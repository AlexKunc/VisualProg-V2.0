#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QInputDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QTextDocument>
#include <QSettings>
#include <QTextEdit>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isTempFileEmpty(true)
    , isContentModified(false)
{
    ui->setupUi(this);
    loadSettings();
    connect(ui->Open, &QAction::triggered, this, &MainWindow::on_openFile_triggered);
    connect(ui->Save, &QAction::triggered, this, &MainWindow::on_saveFile_triggered);

    tempFile.setFileName(QDir::temp().filePath("temp.html"));

    connect(ui->Clear, &QAction::triggered, this, &MainWindow::clearAndSave);
    connect(ui->Return, &QAction::triggered, this, &MainWindow::restoreFromTemp);
    connect(ui->actionChangeFont, &QAction::triggered, this, &MainWindow::on_fontChange_triggered);
    connect(ui->actionChangeColor, &QAction::triggered, this, &MainWindow::on_colorChange_triggered);
    connect(ui->Search, &QAction::triggered, this, &MainWindow::on_search_triggered);
    connect(ui->Replace, &QAction::triggered, this, &MainWindow::on_replace_triggered);
    connect(ui->Create, &QAction::triggered, this, &MainWindow::on_createTable_triggered);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::textChanged);

    ui->actionChangeFont->setShortcut(QKeySequence("Ctrl+I"));
    ui->actionChangeColor->setShortcut(QKeySequence("Ctrl+O"));
    ui->Open->setShortcut(QKeySequence("Ctrl+R"));
    ui->Save->setShortcut(QKeySequence("Ctrl+T"));
    ui->Clear->setShortcut(QKeySequence("Ctrl+U"));
    ui->Return->setShortcut(QKeySequence("Ctrl+P"));
    ui->Search->setShortcut(QKeySequence("Ctrl+E"));
    ui->Replace->setShortcut(QKeySequence("Ctrl+W"));

    QPixmap background(":/images/images/background.jpg");
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setGeometry(this->rect());
    backgroundLabel->lower();

    ui->Return->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("HTML Files (*.html);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Error"), tr("Cannot open file: %1").arg(file.errorString()));
            return;
        }
        QTextStream in(&file);
        QString htmlContent = in.readAll();
        ui->textEdit->setHtml(htmlContent);
        file.close();
        ui->Return->setEnabled(false);
        isContentModified = false;
    }
}

void MainWindow::on_saveFile_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("HTML Files (*.html);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Error"), tr("Cannot save file: %1").arg(file.errorString()));
            return;
        }
        QTextStream out(&file);
        out << ui->textEdit->toHtml();
        file.close();
        lastFilePath = fileName;
        isContentModified = false;
    }
}

void MainWindow::saveToTempFile() {
    if (!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot write to temp file: %1").arg(tempFile.errorString()));
        return;
    }
    QTextStream out(&tempFile);
    out << ui->textEdit->toHtml();
    tempFile.close();
    isTempFileEmpty = false;
}

void MainWindow::restoreFromTemp() {
    if (isTempFileEmpty) {
        QMessageBox::warning(this, tr("Warning"), tr("No text to restore."));
        return;
    }

    QFile file(tempFile.fileName());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open temp file: %1").arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    QString htmlContent = in.readAll();
    ui->textEdit->setHtml(htmlContent);
    file.close();
}

void MainWindow::clearAndSave() {
    saveToTempFile();
    ui->textEdit->clear();
    ui->Return->setEnabled(true);
    isContentModified = false;
}

void MainWindow::on_fontChange_triggered() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        QTextCursor cursor = ui->textEdit->textCursor();
        if (!cursor.hasSelection()) {
            ui->textEdit->setFont(font);
        } else {
            QTextCharFormat format;
            format.setFont(font);
            cursor.mergeCharFormat(format);
            ui->textEdit->setTextCursor(cursor);
        }
        isContentModified = true;
    }
}

void MainWindow::on_colorChange_triggered() {
    QColor color = QColorDialog::getColor(Qt::white, this);
    if (color.isValid()) {
        ui->textEdit->setTextColor(color);
        isContentModified = true;
    }
}

void MainWindow::on_search_triggered() {
    // Реализация поиска
}

void MainWindow::on_replace_triggered() {
    // Реализация замены
}

void MainWindow::on_createTable_triggered()
{
    bool ok;
    int rows = QInputDialog::getInt(this, tr("Input Rows"), tr("Number of rows:"), 1, 1, 100, 1, &ok);
    if (!ok) return;

    int columns = QInputDialog::getInt(this, tr("Input Columns"), tr("Number of columns:"), 1, 1, 100, 1, &ok);
    if (!ok) return;

    QString html = "<table border=\"1\">";
    for (int i = 0; i < rows; ++i) {
        html += "<tr>";
        for (int j = 0; j < columns; ++j) {
            html += "<td><div contenteditable=\"false\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div></td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    ui->textEdit->append(html);
    isContentModified = true;
}

void MainWindow::textChanged() {
    isContentModified = true;
}

void MainWindow::loadSettings() {
    QSettings settings("MyCompany", "MyApp");
    lastFilePath = settings.value("lastFilePath", "").toString();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (isContentModified) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Save Changes", "Do you want to save your changes?",
                                      QMessageBox::Save | QMessageBox::No  | QMessageBox::Cancel);
        if (reply == QMessageBox::Save) {
            on_saveFile_triggered();
        } else if (reply == QMessageBox::Cancel) {
            event->ignore();
            return;
        }
    }
    saveSettings();
    event->accept();
}

void MainWindow::saveSettings() {
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("lastFilePath", lastFilePath);
}

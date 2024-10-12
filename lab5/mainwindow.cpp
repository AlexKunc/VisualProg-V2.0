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

#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
    connect(ui->Open, &QAction::triggered, this, &MainWindow::on_openFile_triggered);
    connect(ui->Save, &QAction::triggered, this, &MainWindow::on_saveFile_triggered);
    // Файл для хранения времменной инфы
    tempFile.setFileName(QDir::temp().filePath("temp.txt"));
    //Коннеткы для очистки и сохранения в temp.txt и возвращение из него
    connect(ui->Clear, &QAction::triggered, this, &MainWindow::clearAndSave);
    connect(ui->Return, &QAction::triggered, this, &MainWindow::restoreFromTemp);

    // Коннекты для изменения шрифта и цвета текста
    connect(ui->actionChangeFont, &QAction::triggered, this, &MainWindow::on_fontChange_triggered);
    connect(ui->actionChangeColor, &QAction::triggered, this, &MainWindow::on_colorChange_triggered);

    //Коннект search
    connect(ui->Search, &QAction::triggered, this, &MainWindow::on_search_triggered);

    //Коннект replace
    connect(ui->Replace, &QAction::triggered, this, &MainWindow::on_replace_triggered);


    //Хот кеи
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Открытие
void MainWindow::on_openFile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Error"), tr("Cannot open file: %1").arg(file.errorString()));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setPlainText(in.readAll());
        file.close();
    }
}

//Сохранение
void MainWindow::on_saveFile_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Error"), tr("Cannot save file: %1").arg(file.errorString()));
            return;
        }
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();
        lastFilePath = fileName;  // Сохраняем последний путь файла
    }
}

//Сохранение временного текста
void MainWindow::saveToTempFile() {
    if (!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot write to temp file: %1").arg(tempFile.errorString()));
        return;
    }
    QTextStream out(&tempFile);
    out << ui->textEdit->toPlainText();
    tempFile.close();
}

//Загрузка временного текста
void MainWindow::loadFromTempFile() {
    if (!tempFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot read temp file: %1").arg(tempFile.errorString()));
        return;
    }
    QTextStream in(&tempFile);
    ui->textEdit->setPlainText(in.readAll());
    tempFile.close();
}

//Очистка и сохранение в temp.txt
void MainWindow::clearAndSave() {
    saveToTempFile();
    ui->textEdit->clear();
}

//Вернуть из temp.txt
void MainWindow::restoreFromTemp() {
    loadFromTempFile();
}

//Обработка закрытия
void MainWindow::closeEvent(QCloseEvent *event)
{
    // Проверяем, есть ли изменения в тексте
    if (ui->textEdit->document()->isModified()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Save Changes"),
                                      tr("Do you want to save your changes?"),
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if (reply == QMessageBox::Yes) {
            // Предлагаем сохранить в последний использованный путь
            if (!lastFilePath.isEmpty()) {
                // Вызываем диалог для сохранения в предыдущий путь
                QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), lastFilePath, tr("Text Files (*.txt);;All Files (*)"));
                if (!fileName.isEmpty()) {
                    QFile file(fileName);
                    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                        QMessageBox::warning(this, tr("Error"), tr("Cannot save file: %1").arg(file.errorString()));
                        event->ignore();
                        return;
                    }
                    QTextStream out(&file);
                    out << ui->textEdit->toPlainText();
                    file.close();
                    lastFilePath = fileName; // Обновляем путь файла на новый
                } else {
                    event->ignore();
                    return;
                }
            } else {
                // Если файл ранее не сохранялся, вызываем диалог сохранения
                on_saveFile_triggered();
            }
        } else if (reply == QMessageBox::Cancel) {
            event->ignore();
            return;
        }
    }
    saveSettings();
    event->accept();
}

// Изменение шрифта
void MainWindow::on_fontChange_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        ui->textEdit->setFont(font);
    }
}

// Изменение цвета текста
void MainWindow::on_colorChange_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    if (color.isValid()) {
        ui->textEdit->setTextColor(color);
    }
}
//Сохры настроек
void MainWindow::saveSettings() {
    QSettings settings("lab3", "lab3App");

    QFont font = ui->textEdit->font();
    settings.setValue("font", font.toString());

    QColor color = ui->textEdit->textColor();
    settings.setValue("color", color.name());
}
//Загрузка настроек
void MainWindow::loadSettings() {
    QSettings settings("lab3", "lab3App");

    QString fontStr = settings.value("font").toString();
    if (!fontStr.isEmpty()) {
        QFont font;
        font.fromString(fontStr);
        ui->textEdit->setFont(font);
    }

    QString colorName = settings.value("color").toString();
    if (!colorName.isEmpty()) {
        QColor color(colorName);
        ui->textEdit->setTextColor(color);
    }
}


//Поиск
void MainWindow::on_search_triggered() {
    bool ok;
    QString searchText = QInputDialog::getText(this, tr("Search"), tr("Enter text to search:"), QLineEdit::Normal, "", &ok);

    if (ok && !searchText.isEmpty()) {
        // Сброс выделения
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.setPosition(0);
        ui->textEdit->setTextCursor(cursor);

        // Сброс старых выделений
        QTextCursor allCursor = ui->textEdit->textCursor();
        allCursor.select(QTextCursor::Document);
        QTextCharFormat clearFormat;
        clearFormat.setBackground(Qt::transparent);
        allCursor.setCharFormat(clearFormat);

        ui->textEdit->moveCursor(QTextCursor::Start);

        QTextDocument::FindFlags options;
        while (ui->textEdit->find(searchText, options)) {
            QTextCursor highlightCursor = ui->textEdit->textCursor();
            QTextCharFormat highlightFormat;
            highlightFormat.setBackground(Qt::yellow);
            highlightCursor.mergeCharFormat(highlightFormat);
        }
    }
}

void MainWindow::on_replace_triggered() {
    bool ok;

    // Ввод искомого слова
    QString searchText = QInputDialog::getText(this, tr("Replace"), tr("Enter text to search:"), QLineEdit::Normal, "", &ok);
    if (!ok || searchText.isEmpty()) {
        return;
    }

    // Ввод слова для замены
    QString replaceText = QInputDialog::getText(this, tr("Replace"), tr("Enter text to replace with:"), QLineEdit::Normal, "", &ok);
    if (!ok) {
        return;
    }

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.setPosition(0);
    ui->textEdit->setTextCursor(cursor);

    QTextCursor allCursor = ui->textEdit->textCursor();
    allCursor.select(QTextCursor::Document);
    QTextCharFormat clearFormat;
    clearFormat.setBackground(Qt::transparent);
    allCursor.setCharFormat(clearFormat);

    ui->textEdit->moveCursor(QTextCursor::Start);

    while (ui->textEdit->find(searchText)) {
        QTextCursor highlightCursor = ui->textEdit->textCursor();
        highlightCursor.beginEditBlock();
        highlightCursor.removeSelectedText();
        highlightCursor.insertText(replaceText);
        highlightCursor.endEditBlock();
    }
}



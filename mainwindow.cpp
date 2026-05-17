#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QString>
#include <QFileDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Add a text display area below the button
    displayArea = new QTextEdit(this);
    displayArea->setGeometry(10, 50, 780, 520);
    displayArea->setReadOnly(true);
    displayArea->setText("Open a JSON file to display its contents here.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*
     * Open file then load path
    */
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JSON Files (*.json)"));
    if (fileName.isEmpty())
        return;
    
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        displayArea->setText("Error: Could not open file!");
        return;
    }
    
    QString fileContent = QString::fromUtf8(file.readAll());
    file.close();
    
    // Parse the JSON
    ParsedData data = parser.parse(fileContent.toStdString());
    
    // Display the parsed data
    displayParsedData(data);
}

void MainWindow::displayParsedData(const ParsedData& data)
{
    std::ostringstream oss;
    
    oss << "=== PARSED JSON DATA ===\n\n";
    
    oss << "USERS (" << data.users.size() << "):\n";
    oss << "------------------------\n";
    for (const auto& user : data.users) {
        oss << "  Name: " << user->getName() << "\n";
        oss << "  ID: " << user->getID() << "\n\n";
    }
    
    oss << "\nPOSTS (" << data.posts.size() << "):\n";
    oss << "------------------------\n";
    for (const auto& p : data.posts) {
        oss << "  Post ID: " << p->getID() << "\n";
        oss << "  User ID: " << p->getUserID() << "\n";
        oss << "  Content: " << p->getContent() << "\n\n";
    }
    
    displayArea->setText(QString::fromStdString(oss.str()));
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbrir_triggered()
{
    QFile arch;
    QTextStream io;
    QString nombreArch;
    nombreArch = QFileDialog::getOpenFileName(this, "Abrir");
    if(nombreArch.isEmpty())
        return;
    arch.setFileName(nombreArch);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    ui->plainTextEdit->setPlainText(io.readAll());
    arch.flush();
    arch.close();

}

void MainWindow::on_actionGuardar_como_triggered()
{
    QFile arch;
    QTextStream io;
    QString nombreArch;
    nombreArch = QFileDialog::getSaveFileName(this, "Guardar");
    if(nombreArch.isEmpty())
        return;
    arch.setFileName(nombreArch);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error",arch.errorString());
        return;
    }
    io.setDevice(&arch);
    io << ui->plainTextEdit->toPlainText();
    arch.flush();
    arch.close();
}

void MainWindow::on_actionCerrar_triggered()
{
    close();
}

void MainWindow::on_actionCopiar_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionCortar_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionPegar_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QString txt;
    txt = "Dolph Hincapie\nEl mejor del mundo";
    QMessageBox::about(this, "Autor", txt);

}

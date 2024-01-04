#include "mainwindow.h"
// #include "readywindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set background color
    this->setStyleSheet("background-color: #009150 ;");
    ui-> stackedWidget_main->setCurrentIndex(4);
    connect(ui->homeBtn, &QPushButton::clicked, this, &MainWindow::on_homeBtn_clicked);
    connect(ui->roomBtn, &QPushButton::clicked, this, &MainWindow::on_roomBtn_clicked);
    connect(ui->inviteBtn, &QPushButton::clicked, this, &MainWindow::on_inviteBtn_clicked);
    connect(ui->playGame, &QPushButton::clicked, this, &MainWindow::on_playGame_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

// set action for sidebar button
void MainWindow::on_homeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    setTappedButton(ui->homeBtn, ui->roomBtn, ui->inviteBtn);
}


void MainWindow::on_roomBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setTappedButton(ui->roomBtn, ui->homeBtn, ui->inviteBtn);
}


void MainWindow::on_inviteBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    setTappedButton(ui->inviteBtn, ui->roomBtn, ui->homeBtn);
}



void MainWindow::setTappedButton(QPushButton *button, QPushButton *otherButton1, QPushButton *otherButton2){
    button->setStyleSheet("QPushButton {"
                               "    background-color:rgba(217, 217, 217, 128); /* Set your desired background color */"
                               "    backdrop-filter: blur(5px); /* Set the blur radius as needed */"
                               "}");
    otherButton1->setStyleSheet("QPushButton {"
                                    "background-color: transparent;"
                               "}");
    otherButton2->setStyleSheet("QPushButton {"
                                     "background-color: transparent;"
                                "}");

}

void MainWindow::setTappedMode(QPushButton *mode1, QPushButton *mode2){
    mode1->setStyleSheet("QPushButton {"
                          "    background-color: rgba(58, 32, 32, 0.9); /* Set your desired background color */"
                          "    backdrop-filter: blur(5px); /* Set the blur radius as needed */"
                          "    border-radius: 10px;"
                          "}");
    mode2->setStyleSheet("QPushButton {"
                                "background-color: #3A2020;"
                                "border-radius: 10px;"
                                "}");
}


void MainWindow::on_playAloneBtn_clicked()
{
    setTappedMode(ui->playAloneBtn, ui->playGroupBtn);
}


void MainWindow::on_playGroupBtn_clicked()
{
    setTappedMode(ui->playGroupBtn, ui->playAloneBtn);
}




void MainWindow::on_playGame_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);

}


void MainWindow::on_cancelBtn_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}


void MainWindow::on_login_btn_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}


void MainWindow::on_to_login_page_btn_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(4);
}


void MainWindow::on_to_signup_page_btn_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(3);
}


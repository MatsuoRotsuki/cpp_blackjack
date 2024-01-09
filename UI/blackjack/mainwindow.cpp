#include "mainwindow.h"
// #include "readywindow.h"
#include "ui_mainwindow.h"
#include "playwindow.h"
#include "screencontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socketManager(SocketManager::GetInstance())
{
    ui->setupUi(this);

    //set background color
    this->setStyleSheet("background-color: #009150 ;");
    ui-> stackedWidget_main->setCurrentIndex(4);
    connect(ui->homeBtn, &QPushButton::clicked, this, &MainWindow::on_homeBtn_clicked);
    connect(ui->roomBtn, &QPushButton::clicked, this, &MainWindow::on_roomBtn_clicked);
    connect(ui->inviteBtn, &QPushButton::clicked, this, &MainWindow::on_inviteBtn_clicked);
    connect(socketManager->socket(), &QTcpSocket::readyRead, this, &MainWindow::on_readyRead);

    socketManager->socket()->connectToHost("127.0.0.1", 5500);
    // Hiển thị màn hình đầu tiên
    ScreenController::instance().setStackedWidget(ui->stackedWidget_main);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete socketManager;
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

void MainWindow::on_to_login_page_btn_clicked()
{
    ScreenController::instance().switchToScreen(4);
}


void MainWindow::on_to_signup_page_btn_clicked()
{
    ScreenController::instance().switchToScreen(3);
}


// void MainWindow::on_readyRead()
// {
//     QByteArray data = socketManager->socket()->read(sizeof(Message));
//     const Message* msgPtr = reinterpret_cast<const Message*>(data.constData());
//     Message msg;
//     memcpy(&msg, msgPtr, sizeof(Message));

//     qDebug() << QString::fromStdString(MessageTypeToString(msg.type));
// }

void MainWindow::on_login_btn_clicked()
{
    // Get input data
    QString q_Username = ui->usernameLineEdit->text();
    QString q_Password = ui->passwordLineEdit->text();
    
    char username[64];
    strcpy(username,q_Username.toLocal8Bit().data());
    char password[64];
    strcpy(password, q_Password.toLocal8Bit().data());

    // Create request message
    Message msg;
    msg.type = MessageType::CLT_LOGIN_REQ;
    strcpy(msg.payload.loginRequestData.username, username);
    strcpy(msg.payload.loginRequestData.password, password);

    // Send request message
    QByteArray byteArray;
    byteArray.append(reinterpret_cast<const char*>(&msg), sizeof(Message));
    socketManager->socket()->write(byteArray);

    //switch to home screen
    ScreenController::instance().switchToScreen(0);
}


void MainWindow::on_readyRead()
{
    QByteArray data = socketManager->socket()->read(sizeof(Message));
    const Message* msgPtr = reinterpret_cast<const Message*>(data.constData());
    Message msg;
    memcpy(&msg, msgPtr, sizeof(Message));

    qDebug() << QString::fromStdString(MessageTypeToString(msg.type));
    switch(msg.type)
    {
    case MessageType::SRV_INVALID_REQUEST:
        break;
    case MessageType::SRV_LOGIN_RES:
        break;
    case MessageType::SRV_SIGNUP_RES:
        break;
    case MessageType::SRV_VIEWONLINE_RES:
        break;
    case MessageType::SRV_DISCONNECT:
        break;
    case MessageType::SRV_ROOMLIST_RES:
        break;
    case MessageType::SRV_ADDTOROOM:
        break;
    case MessageType::SRV_START_ROUND:
        break;
    case MessageType::SRV_BET_REQUEST:
        break;
    case MessageType::SRV_PLAYER_BET:
        break;
    case MessageType::SRV_GAME_STATE:
        break;
    case MessageType::SRV_ACTION_REQUEST:
        break;
    case MessageType::SRV_OUTCOME:
        break;
    case MessageType::SRV_READY_REQUEST:
        break;
    case MessageType::SRV_INVITE:
        break;
    case MessageType::SRV_INVITE_OUTCOME:
        break;
    default:
        qDebug() << "INVALID";
    }
}

void MainWindow::on_signup_btn_clicked()
{
    // Get input data
    QString q_name = ui->fullnameLineEdit->text();
    QString q_Username = ui->usernameLineEdit_2->text();
    QString q_Password = ui->passwordLineEdit_2->text();
    QString q_ConfirmPassword = ui->confirmpasswordLineEdit->text();
    char name[64];
    strcpy(name,q_name.toLocal8Bit().data());
    char username[64];
    strcpy(username,q_Username.toLocal8Bit().data());
    char password[64];
    strcpy(password, q_Password.toLocal8Bit().data());
    char confirm_password[64];
    strcpy(confirm_password, q_ConfirmPassword.toLocal8Bit().data());
    // Create request message
    Message msg;
    msg.type = MessageType::CLT_SIGNUP_REQ;
    strcpy(msg.payload.signupRequestData.name, name);
    strcpy(msg.payload.signupRequestData.username, username);
    strcpy(msg.payload.signupRequestData.password, password);
    strcpy(msg.payload.signupRequestData.confirm_password, confirm_password);
    // Send request message
    QByteArray byteArray;
    byteArray.append(reinterpret_cast<const char*>(&msg), sizeof(Message));
    socketManager->socket()->write(byteArray);
}




void MainWindow::on_joinRandomBtn_clicked()
{
    qDebug() << "play game";
}


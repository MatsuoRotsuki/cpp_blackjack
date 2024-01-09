#include "playwindow.h"
#include "ui_playwindow.h"
#include "player.h"
#include <QVBoxLayout>
#include "quitdialog.h"
#include "inviteplayerdialog.h"
#include "screencontroller.h"
#include "message.h"
#include "socketmanager.h"
#include <QTcpSocket>
#include <QListWidgetItem>

PlayWindow::PlayWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayWindow)
    , socketManager(SocketManager::GetInstance())
{
    ui->setupUi(this);
    // this->mainWindow = mainWindow;
    connect(socketManager->socket(), &QTcpSocket::readyRead, this, &PlayWindow::on_readFlag);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}


void PlayWindow::on_hit_btn_clicked()
{
    player *newPlayer = new player();
    ui->listPlayer->addWidget(newPlayer);
}


void PlayWindow::on_stand_btn_clicked()
{

    // Get the number of items in the layout
    int itemCount = ui->listPlayer->count();

    // Check if there is at least one item in the layout
    if (itemCount > 0) {
        // Get the last item (widget) in the layout
        QWidget *lastItem = ui->listPlayer->itemAt(itemCount - 1)->widget();

        // Remove the last item from the layout
        ui->listPlayer->removeWidget(lastItem);

        // Delete the last item to free memory
        delete lastItem;
    }
}


void PlayWindow::on_cashout_btn_clicked()
{
    QLayoutItem* item;
    while ((item = ui->listPlayer->takeAt(0)) != nullptr) {
        // Remove the item from the layout and delete it
        delete item->widget();
        delete item;
    }
}

void PlayWindow::on_inviteBtn_clicked()
{
    if(!isInvitePopupShown){
        InvitePlayerDialog *invitePlayerDialog = new InvitePlayerDialog();
        // invitePopup->show();

        QPoint buttonPos = ui->inviteBtn->mapToGlobal(QPoint(0, 0));

        // Set the position of the popup
        invitePlayerDialog->move(buttonPos.x(), buttonPos.y() + ui->inviteBtn->height());
        invitePlayerDialog->setWindowTitle("Online players");
        invitePlayerDialog->show();
        isInvitePopupShown = true;

        Message msg;
        msg.type = MessageType::CLT_READYLIST_REQ;
        QByteArray byteArray;
        byteArray.append(reinterpret_cast<const char*>(&msg), sizeof(Message));
        SocketManager::instance().socket()->write(byteArray);

        // Connect the dialog's destroyed signal to a slot that will reset the flag when the dialog is closed
        // connect(invitePlayerDialog, &InvitePlayerDialog::destroyed, this, [&]() {
        //     isInvitePopupShown = false;
        //     qDebug() << "check" << isInvitePopupShown;

        //     // Disconnect the signal-slot connection
        //     disconnect(invitePlayerDialog, &InvitePlayerDialog::destroyed, this, nullptr);
        // });
        connect(invitePlayerDialog, &InvitePlayerDialog::rejected, this, [&]() {
            isInvitePopupShown = false;
            // Handle the case when the user clicks Cancel or closes the window
        });
    }
}
void PlayWindow::on_quitBtn_clicked()
{
    if(!isQuitPopupShown){
        QuitDialog *quitDialog = new QuitDialog();
        // invitePopup->show();

        QPoint buttonPos = ui->quitBtn->mapToGlobal(QPoint(0, 0));

        // Set the position of the popup
        quitDialog->move(buttonPos.x(), buttonPos.y() + ui->quitBtn->height());
        quitDialog->setWindowTitle("Confirm quit");
        quitDialog->show();
        isQuitPopupShown = true;

        // Connect accepted and rejected signals
        connect(quitDialog, &QuitDialog::accepted, this, [&]() {
            isQuitPopupShown = false;
            // Handle the case when the user clicks OK
            // Kiểm tra xem có cửa sổ chính (main window) hay không
            // Gọi hàm doSomething từ MainWindow sau khi nó đã được tạo và hiển thị
            // if (auto mainWindow = qobject_cast<MainWindow*>(parentWidget())) {
            //     QMetaObject::invokeMethod(mainWindow, "on_back_to_main_window", Qt::QueuedConnection);
            // }

            // if (mainWindow) {
            //     // Gọi hàm trong MainWindow
            //     mainWindow->on_back_to_main_window();
            // }
            qDebug() << "Yes to exit" ;
            back_to_home_screen();

        });
        connect(quitDialog, &QuitDialog::rejected, this, [&]() {
            isQuitPopupShown = false;
            // Handle the case when the user clicks Cancel or closes the window
        });
    }
}

void PlayWindow::back_to_home_screen()
{
    ScreenController::instance().switchToScreen(0);
}

void PlayWindow::on_readFlag(){
    // player *currentPlayer = ui->listPlayer->itemAt(2);

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
       // QListWidgetItem *item = ui->listPlayer->item(2);


       //  ui->listPlayer->addWidget(newPlayer);
        ui->bet_btn->setDisabled(true);
        break;
    case MessageType::SRV_GAME_STATE:
        for(int i = 0; i<=3;i++){
            player *player = ui->listPlayer->itemAt(i)->widget();
        }
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



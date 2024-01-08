#include "playwindow.h"
#include "ui_playwindow.h"
#include "player.h"
#include <QVBoxLayout>
#include "quitdialog.h"
#include "inviteplayerdialog.h"
#include "screencontroller.h"

PlayWindow::PlayWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    // this->mainWindow = mainWindow;

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




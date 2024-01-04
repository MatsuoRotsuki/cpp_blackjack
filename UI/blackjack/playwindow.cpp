#include "playwindow.h"
#include "ui_playwindow.h"
#include "player.h"
#include <QVBoxLayout>
#include "inviteplayerpopup.h"

PlayWindow::PlayWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
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


void PlayWindow::on_quit_game_btn_clicked()
{


}


void PlayWindow::on_invite_player_btn_clicked()
{
    if(!isInvitePopupShown){
        InvitePlayerPopup *invitePopup = new InvitePlayerPopup();
        // invitePopup->show();

        QPoint buttonPos = ui->invite_player_btn->mapToGlobal(QPoint(0, 0));

        // Set the position of the popup
        invitePopup->move(buttonPos.x(), buttonPos.y() + ui->invite_player_btn->height());

        invitePopup->show();
        isInvitePopupShown = true;

        // Connect the popup's destroyed signal to a slot that will reset the flag when the popup is closed
        connect(invitePopup, &InvitePlayerPopup::destroyed, this, [&]() {
            isInvitePopupShown = false;
        });
    }

}


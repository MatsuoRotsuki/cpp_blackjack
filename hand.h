#pragma once
#include "card.h"
#include "deck.h"

/**
 * Lớp hand thể hiện Tay bài, là tập hợp các lá bài trên tay
 * của người chơi hoặc nhà cái
 * Chủ yếu dùng để tính điểm
*/
class Hand
{
public:
    /**
     * Hàm khởi tạo
    */
    Hand();
    Hand(std::vector<Card> cards);

    /**
     * Thêm một lá bài vào tay người chơi
     * @param Card card
     * @return void
    */
    void addCard(Card card);

    /**
     * Rút thêm một lá bài từ bộ bài cho lên tay
     * @param Deck deck
     * @return void
    */
    void takeCardFromDeck(Deck deck);

    /**
     * Bỏ hết bài trên tay về bộ bài bỏ
     * @param Deck discardedDeck
     * @return void
    */
    void discardHandToDeck(Deck discardedDeck);

    /**
     * Tính điểm của bài
     * @param void
     * @return int
    */
    int calculateValue() const;

    /**
     * Lấy lá bài thứ idx
     * @param int idx
     * @return Card
    */
    Card getCard(int idx) const;

    /**
     * Trả về xâu thể hiển thông tin tay bài
     * gồm các lá bài bên trong
     * @param void
     * @return std::string
    */
    std::string toString() const;

    private:
    std::vector<Card> hand;
};
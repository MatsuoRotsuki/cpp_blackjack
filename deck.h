#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <random>
#include "card.h"

/**
 * Lớp Deck thể hiện bộ bài được trộn từ các bộ bài 52 lá (1 - 8 bộ này)
 * Số bộ bài thường là 1, 2, 4, 6, 8
*/
class Deck
{
private:
    std::vector<Card> deck;

public:
    /**
     * Hàm khởi tạo
    */
    Deck();
    Deck(int numberOfDecks);
    Deck(std::vector<Card> cards);

    /**
     * Hàm trả về danh sách các lá bài trong bộ bài
     * @param void
     * @return std::vector<Card>
    */
    std::vector<Card> getDeck();

    /**
     * Hàm trả về xâu thể hiện thông tin bộ bài
     * gồm danh sách các lá bài bên trong
     * @param void
     * @return std::string
    */
    std::string toString();

    /**
     * Thực hiện xáo bài
     * @param void
     * @return void
    */
    void shuffle();

    /**
     * Rút lá bài đầu tiên của bộ bài và trả về lá bài
     * @param void
     * @return Card
    */
    Card dealCard();

    /**
     * Trả về true nếu bộ bài không rỗng
     * @param void
     * @return bool
    */
    bool isNotEmpty() const;

    /**
     * Thực hiện làm rỗng bộ bài
     * @param void
     * @return void
    */
    void emptyDeck();

    /**
     * Thêm các lá bài vào bộ bài
     * @param std::vector<Card> cards
     * @return void
    */
    void addCards(std::vector<Card> cards);

    /**
     * Thêm lá bài vào bộ bài
     * @param Card
     * @return void
    */
    void addCard(Card card);

    /**
     * Nạp lại bộ bày từ đống bài đã bỏ
     * @param Deck discard
     * @return void
    */
    void reloadDeckFromDiscard(Deck discard);

    /**
     * Trả về số lá còn lại trong bộ bài
     * @param void
     * @return int
    */
    int cardsLeft() const;
};
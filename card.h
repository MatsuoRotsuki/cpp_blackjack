#pragma once
#include <iostream>

enum class Suit
{
    CLUB = 0,
    DIAMOND,
    HEART,
    SPADE,
};

enum class Rank
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

/**
 * Lớp Card thể hiện một lá bài
*/
class Card
{
public:
    /**
     * Hàm khởi tạo
    */
    Card(Rank _rank, Suit _suit);

    /**
     * Trả về xâu thể hiện thông tin lá bài
     * gồm số và chất lá bài
     * @param void
     * @return std::string
    */
    std::string toString() const;

    /**
     * Trả về giá trị của lá bài
     * theo luật của Blackjack
     * @param void
     * @return int
    */
    int getValue() const;

    /**
     * Trả về chất của lá bài
     * @param void
     * @return Suit
    */
    Suit getSuit() const;

    /**
     * Trả về số trên lá bài
     * @param void
     * @return Rank
    */
    Rank getRank() const;

private:
    Suit suit;
    Rank rank;

    /**
     * Trả về xâu thể hiện chất của lá bài
     * @param void
     * @return std::string
    */
    std::string rankToString() const;

    /**
     * Trả về xâu thể hiện số trên lá bài
     * @param void
     * @return std::string
    */
    std::string suitToString() const;
};
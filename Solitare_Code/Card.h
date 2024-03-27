#pragma once
#include <iostream>
/*
 * Final Project:
 * - Solitare
 * Description:
 * This program plays a functioning game of solitare and
 * allows the user to restart the game or exit whenever
 * Developers:
 * - Terrance Miller - mille5th@mail.uc.edu
 * - Kyle liberatore - liberaks@mail.uc.edu
 *
 * Help Received:
 *
 * Special Instructions: // optional
 *
 * Developer comments: // Not optional
 * Terrance Miller:
 * Worked on this header code
 * Kyle Liberatore:
 * Didn't work on this code
 *
 */
#ifdef _WIN32
#include<windows.h>
const static int BLACK = 0;
const static int BLUE = 9;
const static int RED = 12;
const static int WHITE = 15;
#endif

class Card
{
public:
    Card(void);
    Card(char rank,char suit);
    ~Card(void);

    void Flip();
    bool GetIsFaceUp();

    int GetSolitaireValue();
    char GetCardSuit();
    char GetCardRank();

    friend std::ostream & operator<< (std::ostream & os, Card& c);

    /*
       Used to navigate up and
       down the cards in a row
     */
    Card* parent;
    Card* child;

private:
    char rank;
    char suit;
    bool isFaceUp;

};

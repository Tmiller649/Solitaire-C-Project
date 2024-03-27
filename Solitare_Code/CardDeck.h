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
 */
#pragma once
#include "Card.h"
#include <ctime>
#include <iostream>
#include "Table.h"

const static int RANK_SIZE = 13;
const static int SUIT_SIZE = 4;
const static char RANKS[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
const static char SUITS[] = {'h','d','s','c'};


class Deck
{
public:
    Deck(void);
    ~Deck(void);

    void Populate(void);
    void Shuffle(void);
    void PrintDeck(void);

    void PopulateVector(TableCard& aDeck);

private:
    Card _deck[52];
    int currentIndex;
};

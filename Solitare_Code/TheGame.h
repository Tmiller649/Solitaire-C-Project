#pragma once

#include <iostream>
#include <vector>

#include "CardDeck.h"
#include "Card.h"
#include "Table.h"

const static int TABLE_SIZE = 7;

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
 * zybooks
 * Special Instructions: // optional
 *
 * Developer comments: // Not optional
 * Terrance Miller:
 * didn't work on this header code
 * Kyle Liberatore:
 * Worked on this header code
 *
 */
class Solitaire
{
public:
    Solitaire(void);
    ~Solitaire(void);

    void PopulateTable(void);
    void Deal(int numToDeal=1);



    /* Functions for validating and moving cards  */
    void MakeSuitMove(int from);
    void MakeMoveBetweenRows(int from, int to);
    void MakeMoveDeckToRow(int to);
    void MakeMoveRowToRow(int from, int to);
    bool ValidMove(int from, int to);
    bool ValidRowToRowMove(Card* fromCard, int to);
    bool ValidSuitMove(int from);

    /* Checks to see if all answer sections full */
    bool GameCompleted();
    bool Impossible();

    /* Functions for printing card details */
    void PrintAllDetails(void);
    void PrintSuitDetails(void);
    void PrintDeckDetails(void);

private:

    TableCard _deck;
    TableCard _discardedCards;
    std::vector<TableCard> _tableCards;

    //Destination of cards. When all filled player wins
    std::vector<TableCard> _suitCards;


};

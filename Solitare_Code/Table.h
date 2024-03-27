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
 * Didn't work on this code
 * Kyle Liberatore:
 * Worked on header code
 *
 */
#pragma once
#include "Card.h"
#include <vector>

class TableCard
{
public:
    TableCard(int maxSize);
    ~TableCard(void);

    Card& operator[](int index);
    bool Push(Card& card);
    bool PushValueCopy(Card card);
    int Size();
    bool empty();
    Card& top(void);

    bool RemoveAt(int index);
    bool Pop();
    void Clear();


    static void MoveBetween(TableCard& from, TableCard& to);


private:
    int _maxSize;
    int _size;
    std::vector<Card*> _cards;

};

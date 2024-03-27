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
 * Made this source code
 *
 */
#include "CardDeck.h"


Deck::Deck(void):currentIndex(0)
{
    srand((unsigned)time(0));
    Populate();
}


Deck::~Deck(void)
{}

// function for shuffling the deck and randomizing it
void Deck::Shuffle()
{
    int max = SUIT_SIZE * RANK_SIZE;
    for(int i=0; i<max-1; i++)
    {
        int randNum = rand() % 52;
        std::swap(_deck[i],_deck[randNum]);
    }

}

// function for making sure the correct cards are in the deck.
void Deck::Populate()
{
    int index = 0;
    for(int i=0; i<SUIT_SIZE; i++)
    {
        for(int j=0; j<RANK_SIZE;j++)
        {
            _deck[index] = Card(RANKS[j],SUITS[i]);
            index++;
        }
    }
}
// function for dealing the cards out
void Deck::PopulateVector(TableCard& aDeck)
{
    int max = SUIT_SIZE * RANK_SIZE;
    aDeck.Clear();
    for(int i=0; i<max; i++)
        aDeck.PushValueCopy(_deck[i]);
}

// function for displaying cards
void Deck::PrintDeck(void)
{
    int max = SUIT_SIZE * RANK_SIZE;
    for(int i=0; i<max; i++)
    {
        if(i %13 == 0)
            std::cout<< '\n' <<'\n';

    }
}



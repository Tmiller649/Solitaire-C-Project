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
#include "Card.h"

// Assigns letters for the cards that are not single digit numbers
int Card::GetSolitaireValue()
{
    if(rank == 'A')
        return 1;
    else if(rank == 'T')
        return 10;
    else if(rank == 'J')
        return 11;
    else if(rank == 'Q')
        return 12;
    else if(rank == 'K')
        return 13;
    else
    {
        char c[] = {rank, '\0'};
        return atoi(c);
    }
}

Card::Card(void)
{}

Card::Card(char ranking, char suitType ):rank(ranking),suit(suitType),isFaceUp(false),child(NULL),parent(NULL)
{}

Card::~Card(void)
{}

// for flipping over the card behind a card you moved
void Card::Flip()
{
    isFaceUp = !isFaceUp;
}
// to check if the card is accessible or not
bool Card::GetIsFaceUp()
{
    return isFaceUp;
}
// getting rank to make sure the card move is legal
char Card::GetCardRank()
{
    return rank;
}
// getting suit to make sure the card move is legal
char Card::GetCardSuit()
{
    return suit;
}

// for color coding the cards to make it easier to use
std::ostream & operator<< (std::ostream & os, Card& c)
{

#ifdef _WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if(c.suit == 'c' || c.suit == 's')
        SetConsoleTextAttribute(handle, BLUE);
    else
        SetConsoleTextAttribute(handle,RED);

    os<< c.suit << c.rank;
    SetConsoleTextAttribute(handle,WHITE);
#endif

    return os;
}

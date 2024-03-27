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
 * Made this source code
 * Kyle Liberatore:
 * Didn't work on this code
 */
#include "TheGame.h"
using namespace std;

// function for creating a new solitare game, populating the deck and board.
Solitaire::Solitaire(void):_deck(52),_discardedCards(52)
{
    //Uses the deck class to create the solitaire deck
    //Shuffles the deck to create a random result each game
    Deck deck = Deck();
    deck.Shuffle();
    deck.PopulateVector(_deck);

    for(int i=0; i<TABLE_SIZE; i++)
    {
        TableCard tableCard = TableCard(20);
        _tableCards.push_back(tableCard);
    }

    //_suitCards.resize(4);
    for(int i=0; i<4; i++)
    {
        TableCard suitCard = TableCard(13);
        _suitCards.push_back(suitCard);
    }
    PopulateTable();
}

Solitaire::~Solitaire(void)
{}

// puts the cards on the table and flips over the ones you cant see yet.
void Solitaire::PopulateTable(void)
{
    for(int i=0; i<TABLE_SIZE; i++)
    {
        for(int j=0; j<TABLE_SIZE -i; j++)
        {
            if(j == (TABLE_SIZE - i) - 1)
                _deck.top().Flip();

            _tableCards[j].Push(_deck.top());
            _deck.Pop();
        }
    }
}

// deals out cards from the deck
void Solitaire::Deal(int numToDeal)
{
    int size = _deck.Size();
    for(int i=0; i<size; i++)
    {
        if(_deck.top().GetIsFaceUp())
        {
            _deck.top().Flip();
            _discardedCards.Push(_deck.top());
            _deck.Pop();
        }
    }

    if(_deck.empty())
    {
        for(int i=_discardedCards.Size()-1; i>=0; i--)
            _deck.Push(_discardedCards[i]);

        _discardedCards.Clear();
    }

    int index = 0;
    for(int i=0; i<numToDeal; i++)
    {
        index = _deck.Size() -i -1;
        if(index >= 0)
        {
            _deck[index].Flip();
        }
        else
            break;
    }
}

// function for displaying each of the suit's sections
void Solitaire::PrintSuitDetails()
{
    cout<<"=============================================\n";
    for(int j=0; j<_suitCards.size(); j++)
    {
        switch(j)
        {
        case 0:
            cout<< "H :";
            break;
        case 1:
            cout<< "D :";
            break;
        case 2:
            cout<< "S :";
            break;
        case 3:
            cout<< "C :";
            break;
        }

        for(int i=0; i<_suitCards[j].Size(); i++)
        {
            if(&_suitCards[j][i] != NULL)
                cout<<_suitCards[j][i] << " ";
            else
                break;
        }
        cout<< endl;
    }
    cout<<"=============================================\n";
    cout<<endl;
}

void Solitaire::PrintDeckDetails()
{
    cout<<"--------------------------------------------\n";
    cout<<"|Deck: ";
    for(unsigned int i=0; i<_deck.Size(); i++)
    {
        if(_deck[i].GetIsFaceUp())
            cout<<_deck[i] << " ";

    }
    cout<<"\n--------------------------------------------\n";
}

// displays the headers and other things for user interaction
void Solitaire::PrintAllDetails()
{

    PrintDeckDetails();
    PrintSuitDetails();


    cout<< "| 6 | \t | 5 | \t | 4 | \t | 3 | \t | 2 | \t | 1 | \t | 0 |\n";
    cout<< "----- \t ----- \t ----- \t ----- \t ----- \t ----- \t -----\n";

    //Cannot be unsigned as number is always greater than or equal to 0 --
    int colMax = _tableCards.size();
    int rowMax = 0;
    for(int i=0; i<colMax; i++)
    {
        if(_tableCards[i].Size() > rowMax)
        {
            rowMax = _tableCards[i].Size();
        }
    }

    for(int i=0; i<rowMax; i++)
    {
        for(int j=colMax-1; j>=0; j--)
        {
            if(i >= _tableCards[j].Size())
            {
                cout<< " \t " ;
                continue;
            }

            if(_tableCards[j][i].GetIsFaceUp())
                cout << "  "  << _tableCards[j][i] << " \t ";
            else
                cout << "  " <<(char)254 << " \t ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

}

// function  for making sure the moves are valid if not it doesn't go with the move.
bool Solitaire::ValidMove(int from, int to)
{
    if(from == to && from != 7)
        return false;

    Card* toCard;
    Card* fromCard;

    if(from == 7)
    {
        if(!_deck.empty())
        {
            if(!_deck.top().GetIsFaceUp())
            {
                return false;
            }
            else
            {
                fromCard = &_deck.top();
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        // checks to make sure there is a card in the column
        if(!_tableCards[from].empty())
            fromCard = &_tableCards[from].top();
        else
            return false;
    }

    if(!_tableCards[to].empty())
        toCard = &_tableCards[to].top();


    if(_tableCards[to].empty())
    {
        if(fromCard->GetCardRank() == 'K')
            return true;
        else
            return false;
    }

    else if(fromCard->GetSolitaireValue() == toCard->GetSolitaireValue()-1 )
    {
        int toColor = 0, fromColor = 0;
        if(toCard->GetCardSuit() == 'h' || toCard->GetCardSuit() == 'd')
            toColor = 0;
        else
            toColor = 1;
        if(fromCard->GetCardSuit() =='h' || fromCard->GetCardSuit() == 'd')
            fromColor = 0;
        else
            fromColor = 1;

        if(fromColor == toColor)
            return false;
        else
            return true;
    }
    return false;
}

// A function for checking the validity of completing a suit.
bool Solitaire::ValidSuitMove(int from)
{
    Card* fromCard;
    if(from == 7)
    {
        if(!_deck.empty())
        {
            if(!_deck.top().GetIsFaceUp())
            {
                return false;
            }
            else
            {
                fromCard = &_deck.top();
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(!_tableCards[from].empty())
            fromCard = &_tableCards[from].top();
        else
            return false;
    }


    char suit = fromCard->GetCardSuit();
    int moveIndex = 0;
    switch(suit)
    {
    case 'h':
        moveIndex = 0;
        break;
    case 'd':
        moveIndex =	1;
        break;
    case 's':
        moveIndex = 2;
        break;
    case 'c':
        moveIndex = 3;
        break;
    }

    if(fromCard->GetSolitaireValue() ==
            _suitCards[moveIndex].Size() + 1 )
    {
        if(!_suitCards[moveIndex].Size() == 0)
        {
            if(fromCard->parent != NULL)
                fromCard->parent->child = NULL;
            fromCard->parent = &_suitCards[moveIndex].top();
            _suitCards[moveIndex].top().child = fromCard;
            fromCard->child = NULL;

        }
        if(from != 7){
            TableCard::MoveBetween(_tableCards[from],_suitCards[moveIndex]);
            if(!_tableCards[from].empty())
            {
                if(!_tableCards[from].top().GetIsFaceUp())
                    _tableCards[from].top().Flip();
            }
        }
        else
        {
            _suitCards[moveIndex].Push(_deck.top());
            _deck.Pop();
        }
    }


    return false;
}

void Solitaire::MakeSuitMove(int from)
{
    ValidSuitMove(from)	;
}


// function for moving full rows of cards
void Solitaire::MakeMoveBetweenRows(int from, int to)
{
    if(ValidMove(from,to))
    {
        if(!_tableCards[to].empty())
            _tableCards[to].top().child = &_tableCards[from].top();

        if(_tableCards[from].top().GetCardRank() != 'K')
            _tableCards[from].top().parent = &_tableCards[to].top();

        TableCard::MoveBetween(_tableCards[from], _tableCards[to]);

        if(!_tableCards[from].empty())
            if(!_tableCards[from].top().GetIsFaceUp())
                _tableCards[from].top().Flip();
    }
}

// function for moving the card from the deck to a row
void Solitaire::MakeMoveDeckToRow(int to)
{
    if(ValidMove(7 ,to))
    {
        if(!_tableCards[to].empty())
            _tableCards[to].top().child = &_deck.top();
        if(_deck.top().GetCardRank() != 'K')
            _deck.top().parent = & _tableCards[to].top();

        _tableCards[to].Push(_deck.top());
        _deck.Pop();


    }
}

// function for moving the cards during turns
void Solitaire::MakeMoveRowToRow(int from, int to)
{
    if(from == 7)
    {
        MakeMoveDeckToRow(to);
        return;
    }
    else if(_tableCards[from].Size() == 0)
        return;

    Card* fromCard;
    fromCard = &_tableCards[from].top();

    if(fromCard->parent == NULL)
        MakeMoveBetweenRows(from,to);
    else
    {
        int pos = _tableCards[from].Size()-1;
        bool checkParent = true;
        bool found = false;
        while(checkParent && !found)
        {
            if(ValidRowToRowMove(fromCard,to))
                found = true;
            else if(fromCard->parent == NULL)
                checkParent = false;
            else
            {
                fromCard = fromCard->parent;
                pos--;
            }

        }

        if(found)
        {
            bool hasChildren = true;
            if(fromCard->parent != NULL)
                    fromCard->parent->child = NULL;

            while(hasChildren)
            {

                if(!_tableCards[to].empty())
                {
                    fromCard->parent = &_tableCards[to].top();
                    _tableCards[to].top().child = fromCard;
                }
                _tableCards[to].Push(*fromCard);

                _tableCards[from].RemoveAt(pos);
                fromCard = fromCard->child;


                pos++;
                if(fromCard == NULL)
                    hasChildren = false;
            }

        }

        if(!_tableCards[from].empty())
            if(!_tableCards[from].top().GetIsFaceUp())
                _tableCards[from].top().Flip();
    }
}
// function for making sure that moves between rows are legal
bool Solitaire::ValidRowToRowMove(Card* fromCard, int to)
{
    Card* toCard;

    if(!_tableCards[to].empty())
        toCard = &_tableCards[to].top();

    //move king to empty space
    if(_tableCards[to].empty())
    {
        if(fromCard->GetCardRank() == 'K')
            return true;
        else
            return false;
    }

    else if(fromCard->GetSolitaireValue() == toCard->GetSolitaireValue()-1 )
    {
        int toColor = 0, fromColor = 0;
        if(toCard->GetCardSuit() == 'h' || toCard->GetCardSuit() == 'd')
            toColor = 0;
        else
            toColor = 1;
        if(fromCard->GetCardSuit() =='h' || fromCard->GetCardSuit() == 'd')
            fromColor = 0;
        else
            fromColor = 1;

        if(fromColor == toColor)
            return false;
        else
            return true;
    }
    return false;

}

// determines if user can still win game
bool Solitaire::Impossible()
{
    int q;
    if(_deck.empty())
    {
        q++;
    }
    if (q > 30)
    {
        return true;
    }
}

// checks to see if game is won
bool Solitaire::GameCompleted()
{
    for(int i=0; i<_suitCards.size(); i++)
        if(_suitCards[i].Size() < 13)
            return false;
    return true;
}
/*==============================================*/

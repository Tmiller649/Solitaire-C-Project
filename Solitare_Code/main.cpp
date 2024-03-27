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
 * Worked on the menu
 * Kyle Liberatore:
 * Worked on the move functions
 *
 */
#include <iostream>
#include "TheGame.h"


using namespace std;

void HandleMove(Solitaire& game);
void HandleMoveToAnswer(Solitaire& game);
void ClearScreen();
void RestartGame(Solitaire& game);
int main(int argc, char** argv)
{
    Solitaire game = Solitaire();
    game.PrintAllDetails();
    bool running = true;
    do{
        char option = ' ';
        cout<<endl<<endl;
        cout<<"1. move card between rows";
        cout<<"\n2. move to answers";
        cout<<"\n3. deal";
        cout<<"\n4. restart";
        cout<<"\n0. quit";
        cout<<"\nEnter option:";
        cin >> option;

        // determines if user can still win game
        if (bool Impossible = false)
        {
            cout << "It is no longer possible to win this game of Solitaire." << endl;
            break;
        }
        if(game.GameCompleted())
        {
            ClearScreen();
            cout<<"\n\n\n\t\t\t CONGRATULATIONS YOU WON!!!\n\n";
            cin.get();
            running = false;
        }
        /* 48 - 55 ascii code is 0 - 7 */
        else
        {
            switch((int)option)
            {
            case 48:
                running = false;
                break;
            case 49:
                HandleMove(game);
                break;
            case 50:
                HandleMoveToAnswer(game);
                break;
            case 51:
                game.Deal(1);
                break;
            case 52:
              RestartGame(game);
            default:
                cout<<"\ninvalid option";
                cin.ignore(80,'\n');
                break;
            }
            ClearScreen();
            game.PrintAllDetails();
        }

    }while(running);
    return 0;
}

void RestartGame(Solitaire& game){
    game = Solitaire();
    game.PrintAllDetails();
}
void HandleMove(Solitaire& game)
{
    char from = '0' ,to = '0';
    cout<<endl <<endl;
    cout<<"From (7 for deck):";
    cin >> from;
    cout<< "To: ";
    cin>> to;

    if( ((int)from >= 48 && (int)from <= 55) &&
        ((int)from >= 48 && (int)to <= 54) )

    {
        game.MakeMoveRowToRow((int)from - 48,(int)to - 48);
    }

    else
    {
        cout<<"invalid input";
        cin.get();
        cin.get();
    }

}

void HandleMoveToAnswer(Solitaire& game)
{
    char from = 0;
    cout<<endl <<endl;
    cout<< "From (7 for deck): ";
    cin>> from;

    if((int)from >= 48 && (int)from <= 55)
        game.MakeSuitMove((int)from - 48);

    else
    {
        cout<<"invalid input";
        cin.get();
        cin.get();
    }

}

void ClearScreen()
{
#if _WIN32
    system("cls");
#endif
}








void Lose()
{
    if (bool Possible = true)
    {
        cout << "It is no longer possible to win this game of Solitaire." << endl;
    }
}

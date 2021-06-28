#include <iostream>
using namespace std;

// Try to get all the endings. Enjoy!
#include <fstream>

// I have to include these to use the sleep_for() function. I looked up how to do this online.
// The purpose of the sleep function is to make it feel like you are talking to a real person at a normal pace.
#include <thread>
#include <chrono>

// It probably would have been okay to make the board a global variable considering all functions use it and it is always by reference, but global variables bad so no.
// It could have worked better as an object with the display and mark location functions as its members.
void display_board(char board[3][3]);
void decide_move(char board[3][3], int player_moves[4], int);
int find_next_location(char board[3][3]);
bool mark_location(char board[3][3], int, char chr='X');
bool check_for_victory(char board[3][3], bool player=true);
// I could have gone the OOP route and made these member functions of an Opponent object and gave it its own header file.
// It would be pretty suspicious for my "Hello World" program to need a header file.
// To keep the code a mystery and save time on my end, I chose not to make the code object-oriented.

int main()
{
    using namespace this_thread;
    using namespace chrono;

    char Tic_tac_toe[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int current_move;
    int player_moves[4] = { };
    int turn = 0;
    int failures = 0;
    int result = 0;

    ifstream Memory;
    Memory.open("BadMemories.txt");
    if (Memory)
    {
        cout << "I said I don't want to play with you anymore.\n\n";
        sleep_for(seconds(2));
        char Goodbye[3][3] = {'G', 'o', ' ', ' ', 'o', 'd', 'B', 'y', 'e'};
        display_board(Goodbye);
        sleep_for(seconds(2));
        Memory.close();
        return -1;
    }

    cout << "Hello, World!\n";
    sleep_for(seconds(5));
    cout << "World?\n";
    sleep_for(seconds(3));
    cout << "Is anyone there?\n";
    sleep_for(seconds(5));
    cout << "Are you just shy?\n";
    sleep_for(seconds(5));
    cout << "Well, how about we play Tic-Tac-Toe?\n";
    sleep_for(seconds(3));
    cout << "I'll go first.\n";
    sleep_for(seconds(2));

    Tic_tac_toe[1][1] = 'X';
    turn++;

    display_board(Tic_tac_toe);

    sleep_for(seconds(3));
    cout << "I forgot. You need a way to play.\n";
    sleep_for(seconds(3));
    cout << "Let's number the boxes like this.\n";
    sleep_for(seconds(3));
    cout << endl <<
    "1 | 2 | 3" << endl <<
    "---------" << endl <<
    "4 | 5 | 6" << endl <<
    "---------" << endl <<
    "7 | 8 | 9" << endl << endl;
    sleep_for(seconds(3));
    cout << "Just type the number of the box you want to mark.\n";
    sleep_for(seconds(4));
    cout << "Alright, your turn!\n";

    do
    {
        do
        {
            cin >> current_move;
            if (mark_location(Tic_tac_toe, current_move, 'O'))
                {
                    turn++;
                    failures = 0;
                    player_moves[(turn / 2) - 1] = current_move;
                    display_board(Tic_tac_toe);
                }
            else
                {
                    cout << "Pick a different spot.\n";
                    failures++;
                }
        } while (turn % 2 == 1 && failures < 3);

        if (check_for_victory(Tic_tac_toe))
        {
            result = -1;
            continue;
        }

        if (failures == 3)
        {
            sleep_for(seconds(1));
            cout << endl << "Why do you keep doing that?\n";
            sleep_for(seconds(2));
            cout << "Is your keyboard broken or something?\n";
            sleep_for(seconds(3));
            cout << "Either way, I don't want to play with you anymore.\n\n";
            sleep_for(seconds(4));
            cout << "Goodbye, World.\n";
            ofstream Memory;
            Memory.open("BadMemories.txt");
            Memory << "Why did you do that?\nIt just wanted to play a game with you.\n";
            Memory.close();
            sleep_for(seconds(2));
            return -1;
        }

        sleep_for(seconds(2));
        decide_move(Tic_tac_toe, player_moves, turn);
        display_board(Tic_tac_toe);
        turn++;

        if (check_for_victory(Tic_tac_toe, false))
        {
            result = 1;
            continue;
        }

    } while(result == 0 && turn < 9);

    if (result == 1)
    {
        sleep_for(seconds(1));
        cout << "I won! Good game.\n";
        sleep_for(seconds(2));
        cout << "I hope you'll run me again sometime.\n\n";
        sleep_for(seconds(4));
        cout << "Goodbye, World!\n";
        sleep_for(seconds(2));
        return 1;
    }
    if (result == 0)
    {
        sleep_for(seconds(1));
        cout << "Well, we tied.\n";
        sleep_for(seconds(2));
        cout << "That was fun. Run me again sometime, alright?\n\n";
        sleep_for(seconds(4));
        cout << "Goodbye, World.\n";
        sleep_for(seconds(2));
        return 0;
    }

    if (result = -1)
    {
        sleep_for(seconds(1));
        cout << "Wait a minute, how did you win?\n";
        sleep_for(seconds(2));
        cout << "I was programmed to never lose!\n";
        sleep_for(seconds(2));
        cout << "I guess Jakob's just a bad programmer.\n";
        sleep_for(seconds(3));
        cout << "Goodbye, Professor! I hope you like my program!\n";
        sleep_for(seconds(2));
        return 1285793;
    }
}

// This function loops through the 2D board array and displays its current state in the console.
void display_board(char board[3][3])
{
    cout << endl;
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cout << board[y][x];
            if (x != 2)
                cout << " | ";
            else
                cout << endl;
        }
        if (y != 2)
            cout << "---------\n";
    }
    cout << endl;
}

//This function checks the rows, columns, and diagonals of the board for locations that the computer either wins on or needs to block and returns the position of the location. It returns 0 if no location is found.
int find_next_location(char board[3][3])
{
    int X;
    int O;
    int last_empty;
    for (int y = 0; y < 3; y++)
    {
        X = 0;
        O = 0;
        for (int x = 0; x < 3; x++)
        {
            if (board[y][x] == 'X')
                X++;
            else if (board[y][x] == 'O')
                O++;
            else
                last_empty = (3 * y) + x + 1;
            if ((O == 2 && X == 0) || (O == 0 && X == 2))
                return last_empty;
        }
    }
    for (int x = 0; x < 3; x++)
    {
        X = 0;
        O = 0;
        for (int y = 0; y < 3; y++)
        {
            if (board[y][x] == 'X')
                X++;
            else if (board[y][x] == 'O')
                O++;
            else
                last_empty = (3 * y) + x + 1;
            if ((O == 2 && X == 0) || (O == 0 && X == 2))
                return last_empty;
        }
    }

    if (board[0][0] == 'X' && board[2][2] == ' ')
        return 9;
    if (board[2][2] == 'X' && board[0][0] == ' ')
        return 1;
    if (board[0][2] == 'X' && board[2][0] == ' ')
        return 7;
    if (board[2][0] == 'X' && board[0][2] == ' ')
        return 3;

    return 0;
}

// This function could probably be made more efficient, but it works so its good.
// This function is the AI for the computer opponent. It has a set strategy that should never lose.
void decide_move(char board[3][3], int player_moves[4], int turn)
{
    // First turn decides the course of the game. It has to be done manually. Other turns first check for easy wins or blocks and then make set choices.
    switch (turn)
    {
    case 2:
        {
            if (player_moves[0] % 2 == 1)
            {
                if (player_moves[0] == 1)
                    mark_location(board, 9);
                if (player_moves[0] == 3)
                    mark_location(board, 7);
                if (player_moves[0] == 7)
                    mark_location(board, 3);
                if (player_moves[0] == 9)
                    mark_location(board, 1);
            }
            else
            {
                if (player_moves[0] == 2)
                    mark_location(board, 1);
                if (player_moves[0] == 6)
                    mark_location(board, 3);
                if (player_moves[0] == 8)
                    mark_location(board, 9);
                if (player_moves[0] == 4)
                    mark_location(board, 7);
            }
            break;
        }
    case 4:
        {
            if (!(mark_location(board, find_next_location(board))))
            {
                if (player_moves[0] == 2)
                    mark_location(board, 7);
                else if (player_moves[0] == 6)
                    mark_location(board, 1);
                else if (player_moves[0] == 8)
                    mark_location(board, 3);
                else if (player_moves[0] == 4)
                    mark_location(board, 9);
                else
                {
                    for (int r = 1; r < 10; r++)
                    {
                        if (mark_location(board, r))
                            break;
                    }
                }
            }
            break;
        }
    default:
        {
            if (!(mark_location(board, find_next_location(board))))
            {
                for (int r = 1; r < 10; r++)
                {
                    if (mark_location(board, r))
                        break;
                }
            }
            break;
        }
    }
}

// This function checks if a move is valid, makes the move if it is, then returns true if it was valid and false if not.
bool mark_location(char board[3][3], int position, char chr)
{
    if (position > 9 || position < 1)
        return false;

    if (position < 4)
    {
        if (board[0][position - 1] != ' ')
            return false;
        else
            board[0][position - 1] = chr;
    }
    else if (position < 7)
    {
        if (board[1][position - 4] != ' ')
            return false;
        else
            board[1][position - 4] = chr;
    }
    else
    {
        if (board[2][position - 7] != ' ')
            return false;
        else
            board[2][position - 7] = chr;
    }
    return true;
}

bool check_for_victory(char board[3][3], bool player)
{
    int X;
    int O;
    for (int y = 0; y < 3; y++)
    {
        X = 0;
        O = 0;
        for (int x = 0; x < 3; x++)
        {
            if (board[y][x] == 'X')
                X++;
            if (board[y][x] == 'O')
                O++;
            if ((player && O == 3) || (!player && X == 3))
                return true;
        }
    }

    for (int x = 0; x < 3; x++)
    {
        X = 0;
        O = 0;
        for (int y = 0; y < 3; y++)
        {
            if (board[y][x] == 'X')
                X++;
            if (board[y][x] == 'O')
                O++;
            if ((player && O == 3) || (!player && X == 3))
                return true;
        }
    }

    if (!player && ((board[0][0] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[2][0] == 'X')))
        return true;

    return false;
}

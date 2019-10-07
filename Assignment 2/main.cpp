#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;



const int NUM_ROWS = 8;
const int NUM_COLS = 8;
const int NUM_ATTEMPTS = 5;
const int GOLD = 5;
const int BOMB = 1;



void boardMake(char board[NUM_ROWS][NUM_COLS]);
void hiddenCharsMake(char board[NUM_ROWS][NUM_COLS]);
void hideChars(char board[NUM_ROWS][NUM_COLS]);
void rulesUser();
void userGuesses(char board[NUM_ROWS][NUM_COLS]);
int main()
{
    char entireBoard[NUM_ROWS][NUM_COLS];
    char reply;
    do
    {
        boardMake(entireBoard);
        hiddenCharsMake(entireBoard);
        hideChars(entireBoard);
        rulesUser();
        userGuesses(entireBoard);
        
        cin >> reply;
    } while (reply == 'Y' || reply == 'y');
    if (reply != 'Y' && reply != 'y')
        
        return 0;
}

void boardMake(char board[NUM_ROWS][NUM_COLS]) // Makes the board with only "?" symbols.
{
    int x;
    int y;
    
    for (x = 0; x < NUM_ROWS; x++)
    {
        for (y = 0; y < NUM_COLS; y++)
        {
            board[x][y] = '?';
        }
    }
}

void hiddenCharsMake(char entireBoard[NUM_ROWS][NUM_COLS])
{
    int x;
    int y;
    
    cout << endl;
    cout << " ";
    
    for (x = 0; x < NUM_COLS; x++)
        
        cout << setw(4) << x + 1;
    
    cout << endl;
    cout << " " << "-------------------------------------" << endl;
    
    for (y = 0; y < NUM_ROWS; y++)
    {
        cout << " " << y + 1 << " |";
        for (x = 0; x < NUM_COLS; x++)
        {
            cout << setw(4) << entireBoard[y][x];
        }
        cout << endl;
    }
    cout << " " << "-------------------------------------" << endl;
}

void hideChars(char entireBoard[NUM_ROWS][NUM_COLS])
{
    int goldAmount = 0;
    int a;
    int b;
    int bombAmount = 0;
    srand(time(NULL));
    
    for (goldAmount = 0; goldAmount < GOLD; goldAmount++)
    {
        a = rand() % NUM_ROWS;
        b = rand() % NUM_COLS;
        entireBoard[a][b] = 'G';
    }
    
    for (bombAmount = 0; bombAmount < BOMB; bombAmount++)
    {
        a = rand() % NUM_ROWS;
        b = rand() % NUM_COLS;
        entireBoard[a][b] = 'B';
    }
}

void rulesUser()
{
    cout << endl;
    cout << "Welcome to Treasure Hunt!" << endl;
    cout << "The Rules:" << endl;
    cout << "Input your coordinate guesses into the console." << endl;
    cout << "You have " << NUM_ATTEMPTS << " tries." << endl;
    cout << "If you guess the coordinates of GOLD, you get a point!"<< endl;
    cout << "If you get GOLD, you also get an extra attempt!" << endl;
    cout << "If you guess the coordinates of a BOMB, you lose! GAME OVER!" << endl;
    cout << "Press Y after completing a game to play again." << endl;
    cout << "Press any other key to exit after playing." << endl;
    cout << endl;
}

void userGuesses(char entireBoard[NUM_ROWS][NUM_COLS])
{
    
    int rowAttempt;
    int colAttempt;
    int attemptsRemain = NUM_ATTEMPTS;
    int score = 0;
    
    
    while (attemptsRemain > 0)
    {
        cout << endl;
        cout << "Please enter your Row Coordinate: ";
        cin >> rowAttempt;
        cout << endl;
        cout << "Please enter your Column Coordinate: ";
        cin >> colAttempt;
        
        if (entireBoard[rowAttempt][colAttempt] == 'G')
        {
            cout << endl;
            cout << "You found GOLD!";
            entireBoard[rowAttempt][colAttempt] = 'F';
            score++;
            attemptsRemain++;
            cout << "You have " << attemptsRemain << " attempts remaining." << endl;
            cout << endl;
            continue;
        }
        else if (entireBoard[rowAttempt][colAttempt] == 'B')
        {
            cout << endl;
            cout << "Oh No! You hit a bomb! GAME OVER." << endl;
            attemptsRemain = 0;
            break;
        }
        else
            cout << endl;
        cout << "You missed! ";
        attemptsRemain--;
        cout << "You have " << attemptsRemain << " tries left!" << endl;
        cout << endl;
    }
    

    
    cout << "You found " << score << " pieces of gold!" << endl;
    cout << "Here are your results:" << endl;
    cout << endl;
    cout << endl;
    
    cout << " ";
    for (colAttempt = 0; colAttempt < NUM_COLS; colAttempt++)
        cout << setw(4) << colAttempt + 1;
    cout << endl;
    cout << " " << "------------------------------------" << endl;
    
    for (rowAttempt = 0; rowAttempt < NUM_ROWS; rowAttempt++)
    {
        cout << " " << rowAttempt + 1 << " |";
        for (colAttempt = 0; colAttempt < NUM_COLS; colAttempt++)
        {
            cout << setw(4) << entireBoard[rowAttempt][colAttempt];
        }
        cout << endl;
    }
    cout << " " << "------------------------------------" << endl;
    cout << "Press Y to play again!" << endl;
    cout << endl;
    cout << "Press any other key to exit the game." << endl;
}

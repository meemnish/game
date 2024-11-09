#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <iomanip>
using namespace std;

// Tic-Tac-Toe Game Code
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //initialize the array with 1 to 9
int choice, row, column;
char turn = 'X';
bool draw = false;

void display_board()    //2 dimensional array of 3*3 matrix of char type
{
    cout<<"\t\t     |      |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|______|_____\n";
    cout<<"\t\t     |      |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|______|_____\n";
    cout<<"\t\t     |      |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |      |     \n";
}
//the elements of the array are added to a structure by writing array name, row index, column index

void player_turn()      //Function to get the player input and update the board
{
    if(turn == 'X')
    {
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O')
    {
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }
    cin>> choice;
    cout<<endl;

    switch(choice)      //switch case to get which row and column will be updated
    {
    case 1:
        row=0;
        column=0;
        break;
    case 2:             //the input digit needs to be replaced by X or 0
        row=0;
        column=1;
        break;
    case 3:
        row=0;
        column=2;       //each time a particular block will execute whichever matches with the input
        break;
    case 4:
        row=1;
        column=0;
        break;
    case 5:
        row=1;
        column=1;
        break;
    case 6:
        row=1;
        column=2;
        break;
    case 7:
        row=2;
        column=0;
        break;
    case 8:
        row=2;
        column=1;
        break;
    case 9:
        row=2;
        column=2;
        break;
    default:
        cout<<"Invalid Move! Enter another!!";
        player_turn();
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';   //updating the position with 'X' symbol if it is not already occupied
        turn = 'O';                 //update the turn for the next player
    }
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';   //updating the position for 'O' symbol if it is not already occupied
        turn = 'X';                 //update the turn for the next player
    }
    else
    {
        cout<<"Box already filled!\n Please choose another!!\n\n";    //if input position already filled
        player_turn();
    }
}

//Function to get GAME WON, GAME DRAW , GAME IN CONTINUE MODE
bool gameover()
{
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
    }

    //checking the win for both diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking if the game is in continue mode or not
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O') //returns true if any position in the board is empty. Then the game will continue.
                return true;

    //if the game is already draw
    draw = true;
    return false;
}

void play_tic_tac_toe()
{
    cout<<"\n\t\tT I C     T A C    T O E    G A M E\n\t\t\t";
    cout<<"FOR 2 PLAYERS\n\t\t";
    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";

    while(gameover())
    {
        display_board();
        player_turn();
        gameover();
    }

    //after the game is over
    if(turn == 'X' && draw == false)        //the game is over and it is not a draw game. And now the next turn is for [X].
    {                                       //That means the last turn was for [0] and then the game was over. So the player with turn [0] won.
        display_board();
        cout<<"\n\n\t** Congratulations!  Player with 'O' has won the game!!\n\n";
    }
    else if(turn == 'O' && draw == false)   //the game is over and it is not a draw game. And now the next turn is for [0].
    {                                       //That means the last turn was for [X] and then the game was over. So the player with turn [X] won.
        display_board();
        cout<<"\n\n\t** Congratulations!  Player with 'X' has won the game!!\n\n";
    }
    else
    {
        display_board();
        cout<<"\n\n\t** GAME DRAW!!!\n";     //this block executes when draw == true.
    }                                        //draw condition example: 1 2 3 4 5 7 9 8 6


    cout << "Wanna play another game?? Select from the menu again >.<"<<endl<<endl<<endl;
}


// 8-Queens Game Code
#define N 8                                     // solution will be for 8 queen

void configRandomly(int board[][N],int* state)   // configures the arrays named board and state randomly
{                                                // in order to provide a starting point
    srand(time(0));                              // random function
    for (int i = 0; i < N; i++)                  // iterating through the column indices
    {
        state[i] = rand() % N;                   // getting a random row index
        board[state[i]][i] = 1;                  // placing a queen on the obtained place in chessboard
    }
}

void printBoard(int board[][N])                  // displays the 2D array named board
{
    for (int i = 0; i < N; i++)
    {
        cout << " ";
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

void printState(int* state)                      // displays the array named state
{
    for (int i = 0; i < N; i++)
        cout << " " << state[i] << " ";
    cout << endl;
}

bool compareStates(int* state1, int* state2)     // compares two arrays, state1 and state2
{

    for (int i = 0; i < N; i++)
    {
        if (state1[i] != state2[i])
            return false;
    }
    return true;                                 // returns true if equal and false otherwise
}

void fill(int board[][N], int value)             // fills the 2D array "board" with values "value"
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            board[i][j] = value;
    }
}

int calculate(int board[][N], int* state)         // calculates state or queens attacking each other using the board
{
    int attacking = 0;                                // Number of queens attacking each other is initially zero.
    int row, col;                                     // Variables to index a particular row and column on board.
    for (int i = 0; i < N; i++)                       // For each queen in a column, check for other queens falling in the line of current queen
    {                                                 // if found any, then increment the variable attacking count.
        row = state[i], col = i - 1;                  // At each column 'i', the queen is placed at row 'state[i]'
        while (col >= 0 && board[row][col] != 1)      // To the left of same row
        {
            col--;                                    //row remains constant and col decreases
        }
        if (col >= 0 && board[row][col] == 1)
        {
            attacking++;
        }
        row = state[i], col = i + 1;                         // To the right of same row
        while (col < N && board[row][col] != 1)
        {
            col++;                                           //row remains constant and col increases
        }
        if (col < N && board[row][col] == 1)
        {
            attacking++;
        }
        row = state[i] - 1, col = i - 1;                     // Diagonally to the left up
        while (col >= 0 && row >= 0 && board[row][col] != 1)
        {
            col--;                                           //row and col simultaneously decrease
            row--;
        }
        if (col >= 0 && row >= 0 && board[row][col] == 1)
        {
            attacking++;
        }
        row = state[i] + 1, col = i + 1;                     // Diagonally to the right down
        while (col < N && row < N && board[row][col] != 1)
        {
            col++;                                           // row and col simultaneously increase
            row++;
        }
        if (col < N && row < N && board[row][col] == 1)
        {
            attacking++;
        }
        row = state[i] + 1, col = i - 1;                     // Diagonally to the left down
        while (col >= 0 && row < N && board[row][col] != 1)
        {
            col--;                                           // col decreases and row increases
            row++;
        }
        if (col >= 0 && row < N && board[row][col] == 1)
        {
            attacking++;
        }
        row = state[i] - 1, col = i + 1;                     // Diagonally to the right up
        while (col < N && row >= 0 && board[row][col] != 1)
        {
            col++;                                           // col increases and row decreases
            row--;
        }
        if (col < N && row >= 0 && board[row][col] == 1)
        {
            attacking++;
        }
    }
    return (int)(attacking / 2);                             // return pairs
}

void generateBoard(int board[][N], int* state)               //generates a board configuration given the state
{
    fill(board, 0);
    for (int i = 0; i < N; i++)
    {
        board[state[i]][i] = 1;
    }
}

void copyState(int* state1, int* state2)                    //copies contents of state2 to state1.
{
    for (int i = 0; i < N; i++)
    {
        state1[i] = state2[i];
    }
}

void getNeighbour(int board[][N],int* state)         // gets the neighbour of the current state having the least objective value
{                                                    // amongst all neighbours as well as the current state.
    int opBoard[N][N];                               // Declaring and initializing the optimal board and state
    int opState[N];                                  // with the current board and the state as the starting point.
    copyState(opState, state);
    generateBoard(opBoard, opState);
    int opObjective = calculate(opBoard,opState);           // Initializing the optimal value
    int NeighbourBoard[N][N];                               // Declaring and initializing the temporary board and state for computation.
    int NeighbourState[N];
    copyState(NeighbourState,state);
    generateBoard(NeighbourBoard, NeighbourState);
    for (int i = 0; i < N; i++)                             // Iterating through all possible neighbours of the board.
    {
        for (int j = 0; j < N; j++)
        {
            if (j != state[i])                              // Condition for skipping the current state
            {
                NeighbourState[i] = j;                      // Initializing temporary neighbour with the current neighbour
                NeighbourBoard[NeighbourState[i]][i]= 1;
                NeighbourBoard[state[i]][i]= 0;
                int temp = calculate(NeighbourBoard,NeighbourState);
                if (temp <= opObjective)                    // Comparing temporary and optimal neighbour objectives
                {                                           // if temporary is less than optimal then updating accordingly.
                    opObjective = temp;
                    copyState(opState, NeighbourState);
                    generateBoard(opBoard,opState);
                }
                NeighbourBoard[NeighbourState[i]][i] = 0;   // back to the original configuration for the next iteration.
                NeighbourState[i] = state[i];
                NeighbourBoard[state[i]][i] = 1;
            }
        }
    }
    copyState(state, opState);                            // Copying the optimal board and state thus found to the current board and state
    fill(board, 0);
    generateBoard(board, state);
}

void hillClimbing(int board[][N], int* state)
{
    int neighbourBoard[N][N] = {};                       // Declaring  and initializing the neighbour board and state
    int neighbourState[N];                               // with the current board and the state as the starting point.
    copyState(neighbourState, state);
    generateBoard(neighbourBoard, neighbourState);
    do
    {
        copyState(state, neighbourState);                // Copying the neighbour board and state to the current board and state
        generateBoard(board, state);                     // since a neighbour becomes current after the jump.
        getNeighbour(neighbourBoard, neighbourState);    // Getting the optimal neighbour
        if (compareStates(state, neighbourState))
        {
            printBoard(board);                           // If neighbour and current are equal then no optimal neighbour exists
            break;                                       // output the result and break the loop
        }
        else if (calculate(board,state) == calculate(neighbourBoard,neighbourState))
        {
            neighbourState[rand() % N]= rand() % N;         // Random neighbour
            generateBoard(neighbourBoard, neighbourState);  // If neighbour and current are not equal but their objectives are equal
        }                                                   // jump to a random neighbour to escape it
    }
    while (true);
}

void play_8_queens()
{
    cout<<"\n\nIn a faraway kingdom, Meemnish needed to place 8 queens on a grand chessboard ^.^"<<endl<<endl;
    cout<<"Wanna know the catch? No queen could be in a position where she could attack another :)"<<endl<<endl;
    cout<<"Each queen had the power to strike down any other queen in the same row, column, or diagonal :( "<<endl<<endl;
    cout<<"Meemnish needed to place all 8 of her queens on the board very carefully, ensuring none of them could threaten each other :)"<<endl<<endl;
    cout<<"Will you help Meemnish find a safe arrangement for all 8 queens? Pretty please with sugar on top ^.^"<<endl<<endl;
    cout<<"..........Please agree............"<<endl;
    cout<<"What? You agreed? Yaaay!!!!"<<endl<<endl;
    cout<<"Great news!!! Meemnish solved it on her own!!!"<<endl<<endl;
    cout<<"Hm.....I am just curious to know whether your answer and Meemnish's answer are similar...."<<endl<<endl;
    cout<<"Match your answer with Meemnish's answer ^.^"<<endl<<endl;
    int state[N] = {};
    int board[N][N] = {};
    configRandomly(board, state);                           // Getting a starting point by randomly configuring the board
    hillClimbing(board, state);                             // Doing hill climbing on the board obtained
    cout<<"\nIf it matched, Bingo!! And if it didn't match, don't worry, answers can vary :)"<<endl<<endl;
    cout<<"Wanna play another game?? Select from the menu again >.<"<<endl<<endl<<endl;
}


// Missionaries and Cannibals Game Code
int im = 3, ic = 3, fm = 0, fc = 0, i, j, flag = 0, select = 0;

//im means total missionary at initial state (right side) and fm means total missionary at final state (left side)
//ic means total cannibal   at initial state (right side) and fc means total cannibal   at final state (left side)

void display(char boatpasser1, char boatpasser2)
{
    cout << "\n\n";
    for (int i = 0; i < fm; i++)       //prints number of missionaries (M) at final state (left side)
        cout << " M ";

    for (int i = 0; i < fc; i++)       //prints number of   cannibals  (C) at final state (left side)
        cout << " C ";

    if (flag == 0)
        cout << "     _____________________(" << boatpasser1 << "," << boatpasser2 << ")  ";
    else
        cout << "     (" << boatpasser1 << "," << boatpasser2 << ")_____________________  ";

    for (int i = 0; i < im; i++)         //prints number of missionaries (M) at initial state (right side)
        cout << " M ";

    for (int i = 0; i < ic; i++)         //prints number of   cannibals  (C) at initial state (right side)
        cout << " C ";
}



int notFinished()
{
    if (fc == 3 && fm == 3)           // if all of the 3 Missionaries (M) and 3 Cannibals (C) are in the final state, then the game is finished
        return 0;

    else
        return 1;
}


void solution()
{
    while (notFinished())
    {
        if (flag == 0)         // flag==0 deals with the number of M and C at initial state
        {
            switch (select)
            {
            case 1:
                display('C', ' ');
                ic++;                // 1 cannibal crossed the river by boat. So cannibals at the initial state will be increased by 1.
                break;
            case 2:
                display('C', 'M');   // 1 missionary and 1 cannibal crossed the river by boat. so M and C both will be increased by 1.
                ic++;
                im++;
                break;
            }

                                                                        //  after sending 2 M, check if
            if (((im - 2) >= ic && (fm + 2) >= fc) || (im - 2) == 0)    //  initial: M >= C and also final:  M >= C
            {
                im = im - 2;                                            //then 2 M will go to the boat
                select = 1;                                             //so the initial missionary will decrease by 2
                display('M', 'M');
                flag = 1;
            }
            else if ((ic - 2) < im &&  (fm == 0 || (fc + 2) <= fm)   || im == 0)   //  initial:  M > C or no M left
            {                                                                      //  final:    M >= C or no C
                ic = ic - 2;                                                       //  then 2 C will go to the boat
                select = 2;                                                        //so the initial cannibal will decrease by 2
                display('C', 'C');
                flag = 1;
            }
            else if ((ic--) <= (im--) && (fm++) >= (fc++))           // initial:  M>=C
            {                                                        // final:    M>=C
                ic = ic - 1;                                         // 1 M and 1 C will cross the river by boat.
                im = im - 1;                                         //so the initial missionary will decrease by 1
                select = 3;                                          //and the initial cannibal will decrease by 1
                display('M', 'C');
                flag = 1;
            }
        }
        else               //when flag==1. It deals with the number of M and C at final state
        {
            switch (select)                                         //2nd time display will occur for every step
            {
            case 1:
                display('M', 'M');
                fm = fm + 2;
                break;
            case 2:
                display('C', 'C');
                fc = fc + 2;
                break;
            case 3:
                display('M', 'C');
                fc = fc + 1;
                fm = fm + 1;
                break;
            }


            if (notFinished())
            {

                if (((fc > 1 && fm == 0) || im == 0))     //if final C > 1 and finally there is no M
                {                                         // then no M can cross the river because cannibal number will be greater than missionary number
                    fc--;
                    select = 1;                           //if initially there is no M,
                    display('C', ' ');                    //then no M will cross the river
                    flag = 0;
                }                                         //1 cannibal will cross the river

                else if ((ic + 2) > im)
                {
                    fc--;
                    fm--;
                    select = 2;
                    display('C', 'M');
                    flag = 0;
                }//else if

            }//if (notFinished())
        }//else
    }//while (notFinished())
}//void solution()


void play_missionaries_and_cannibals()
{
    // Reset the game state before starting
    im = 3;     // Initial number of missionaries
    ic = 3;     // Initial number of cannibals
    fm = 0;     // Final number of missionaries
    fc = 0;     // Final number of cannibals
    flag = 0;   // Reset flag to 0 (starting side)
    select = 0; // Reset select to 0 (no move selected yet)
    cout << "\n                  MISSIONARIES AND CANNIBALS"<<endl<<endl;
    cout << "Three missionaries and three cannibals need to cross a river."<<endl;
    cout << "They have a small boat that can carry at most 2 people at a time."<<endl;
    cout << "     But there are some rules!!!"<<endl;
    cout << "i)   The boat can carry either one or two people :("<<endl;
    cout << "ii)  Missionaries cannot be outnumbered by cannibals on either side of the river, or the cannibals will eat them :("<<endl;
    cout << "iii) All must safely reach the other side :("<<endl;
    cout << "     Try to solve now xD "<<endl;
    cout << "..... "<<endl;
    cout << "..... "<<endl;
    cout << "\t\tWant to check whether your answer is correct or not?"<<endl;
    cout << "\t\t\t\tHere you go ^_^"<<endl;

    display(' ', ' ');         //displays the initial condition, nobody is in the boat (because all of them are in initial state / right side of the river)
    solution();

    display(' ', ' ');         //displays the final condition, nobody is in the boat (because all of them are in final state / left side of the river)
    cout << "\n\n";
    cout << "Wanna play another game?? Select from the menu again >.<"<<endl<<endl<<endl;
}


int main()
{
    int choice;
    cout << "\t\t\tWelcome to Meemnish's Game Zone :) There are 3 games here <3\n";
    cout << "\t\t\t\t\tWanna start playing? Let's go!!\n";
    do
    {
        cout << "\nChoose a game to play:\n\n";
        cout << "1. Tic-Tac-Toe\n";
        cout << "2. 8 Queens\n";
        cout << "3. Missionaries and Cannibals\n";
        cout << "4. I don't have time to play \n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            play_tic_tac_toe();
            break;
        case 2:
            play_8_queens();
            break;
        case 3:
            play_missionaries_and_cannibals();
            break;
        case 4:
            cout << "Sad to see you go. Have a good day <3 <3 <3\n\n";
            break;
        default:
            cout << "\nThis is not a correct choice :^) Try again and this time, choose 1/2/3 xD \n\n";
            break;
        }
    }
    while(choice != 4);

    return 0;
}

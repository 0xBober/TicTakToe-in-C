#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void initializeTable(char table[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            {
                table[i][j] = ' '; //empty cells in table
            }
    }
}

void displayTable(char table[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf(" %c | %c | %c\n", table[i][0], table[i][1], table[i][2]);
        if(i < SIZE -1){
            printf("---+---+---\n");
        }
    }
}

void applyInsertionOfCharIntoTable(char table[SIZE][SIZE], int x, int y, char MainPlayer)
{
    if(table[x][y] != ' ')
    {    
        int a;
        int b;
        printf("Invalid Move, space [%d,%d] is occupied.\n", x ,y);
        printf("Please select a new location for ex. 0 0\n");
        scanf("%d %d", &a, &b);
        applyInsertionOfCharIntoTable(table, a, b, MainPlayer);
    }
    else
        table[x][y] = MainPlayer;
}

char ValidateWhoWon(char table[SIZE][SIZE])
{    
    //checking rows
    for(int i = 0; i < 3; i++)
    {
        if(table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != ' ')
        {    
            return table[i][0];    
        }   
    }
    //checking colms
    for(int i = 0; i < 3; i++)
    {
        if(table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[i][0] != ' ')
        {    
            return table[i][0];    
        }   
    }
    //checking diagnols
    if(table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[1][1] != ' ')
    {
        return table[1][1];
    }
    if(table[2][0] == table[1][1] && table[1][1] == table[0][2] && table[1][1] != ' ')
        return table[1][1];
    
    //checking if bored is full, if is full and no one wins declares a Draw
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            if(table[i][j] == ' ')
            {
                return 'F'; //returning that bored failed if filled test
            }
            else if(table[i][j] != ' ')
            {
                continue;
            }
            else
            {
                return 'D'; //returns that its a draw;
            }
    }    
}



int main(){
    int MaxRounds;
    printf("How many rounds you wanna play?\n");
    scanf("%d", &MaxRounds);
    for(int rounds = 1; rounds <= MaxRounds; rounds++)
    {
        char table[SIZE][SIZE]; //3x3 table for Tic-Tak-Toe input
        initializeTable(table);
        int PlayerMoves = 1;
        const char PlayerX = 'X';
        const char PlayerO = 'O';
        char MainPlayer;
        int x;
        int y;
        char winner;
        
        while(PlayerMoves <= 10)
        {
            system("cls");
            if(PlayerMoves % 2 == 1)MainPlayer = PlayerX;
            if(PlayerMoves % 2 == 0)MainPlayer = PlayerO;
            printf("Where would Player %c like to place their letter?\n", MainPlayer);
            displayTable(table);
            scanf("%d %d", &x, &y);
            applyInsertionOfCharIntoTable(table, x, y, MainPlayer);
            ++PlayerMoves;
        
            if(PlayerMoves >= 5)
            {    //define who wins
                winner = ValidateWhoWon(table);
                
                //output the winner
                if(winner == 'X' || winner == 'O')
                {
                    printf("\n%c is the winner\n", winner);
                    printf("Press any key to play again or exit\n");
                    scanf(" %*c");  // Discard all input until a newline (Enter) is encountered
                    break;
                }
                else if (winner == 'D')
                {
                    printf("\nIt's a Draw\n");
                    printf("Press any key to play again or exit\n");
                    scanf(" %*c");  // Discard all input until a newline (Enter) is encountered
                    break;
                }
            }
            
        }
        displayTable(table);
    }
    return 0;
}

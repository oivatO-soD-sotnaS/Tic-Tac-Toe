#include <stdio.h>
#include <stdbool.h>

bool checkForWin();
void markBoard(int choice, char mark);
void drawBoard();

int board[3][3] = {
                        {'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'}
};
int player = 0;
int main(int argc, char **argv)
{
    int choice = 0;
    
    while(checkForWin()){
        system("clear");
        printf("\t\t\t    Tic Tac Toe\n");
    
        printf("\t\tPlayer 1 ( X ) - Player 2 ( O )\n\n");
        drawBoard();
        if(player % 2 == 0){
            printf("Player 1, enter a number: ");
            scanf("%d", &choice);
            markBoard(choice + '0', 'X');
        }else{
            printf("Player 2, enter a number: ");
            scanf("%d", &choice);
            markBoard(choice + '0', 'O');
        }
    }
        
	
    return 0;
}


bool checkForWin(){
    for(int linha = 0; linha < 2; linha++){
        if(board[linha][0] == 'X' && board[linha][1] == 'X' && board[linha][2] == 'X'){
            printf("\t\t\t****Jogador 1 venceu!*****");
            return false;
        }
        if(board[linha][0] == 'O' && board[linha][1] == 'O' && board[linha][2] == 'O'){
            printf("\t\t\t****Jogador 2 venceu!*****");
            return false;
        }
    }
    for(int coluna = 0; coluna < 3; coluna++){
        if(board[0][coluna] == 'X' && board[1][coluna] == 'X' && board[2][coluna] == 'X'){
            printf("\t\t\t****Jogador 1 venceu!*****");
            return false;
        }
        if(board[0][coluna] == 'O' && board[1][coluna] == 'O' && board[2][coluna] == 'O'){
            printf("\t\t\t****Jogador 2 venceu!*****");
            return false;
        }
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        printf("\t\t\t****Jogador 1 venceu!*****");
        return false;
    }
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
        printf("\t\t\t****Jogador 1 venceu!*****");
        return false;
    }
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        printf("\t\t\t****Jogador 2 venceu!*****");
        return false;
    }
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
        printf("\t\t\t****Jogador 2 venceu!*****");
        return false;
    }
    
    return true;
}


void markBoard(int choice, char mark){  
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){
            if(board[linha][coluna] == choice){
                board[linha][coluna] = mark;
                player++;
            }
        }
    }
}

void drawBoard(){
    for(int linha = 0; linha < 3; linha++){
        printf("\n___________________\n|     |     |     |\n|  %c  |  %c  |  %c  |\n|_____|_____|_____|\n",board[linha][0],board[linha][1],board[linha][2]);
    }
}

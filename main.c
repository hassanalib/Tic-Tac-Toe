/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: hassanali
 *
 * Created on May 23, 2019, 4:04 PM
 */

#include <stdio.h>
#include <stdlib.h>

const int true = 1;
const int false = 0;

int humanWin = 0;
int computerWin = 0;
int tieGame = 0;

int wins = 0;
int losses = 0;
int ties = 0;

void initializeBoard(char space[9]) {
    
    char index = '1';
    int iterator = 0;
    
        for (iterator = 0; iterator < 9; iterator++) {
            space[iterator] = index;
            index++;
        }
    
}

void printBoard(char space[9]) {
    
    printf("\n %c  |  %c  |  %c \n", space[0], space[1], space[2]);
    printf("---------------\n");
    printf(" %c  |  %c  |  %c \n", space[3], space[4], space[5]);
    printf("---------------\n");
    printf(" %c  |  %c  |  %c \n", space[6], space[7], space[8]);
    
}

void printChoices() {
    
    printf("\nPress '1' if you want the computer to go first\n");
    printf("Press '2' if you want to go first\n");     
    printf("Press '3' if you want to flip a coin (pick who goes first randomly)\n\n");
    printf("Press '0' to exit.\n\n");
    
}

int getChoice() {
    
    int choice;
    
    scanf("%d", &choice);
    fgetc(stdin);
    
        while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 0)) {
            
            printf("Sorry, your input is invalid. Please enter again:\n");
            
            printf("\nPress '1' if you want to go first\n");
            printf("Press '2' if you want the computer to go first\n");     
            printf("Press '3' if you want to flip a coin (pick who goes first randomly)\n\n");
            
            scanf("%d", &choice);
            fgetc(stdin);
            
        }
    
    return choice;
    
}

char getLocation() {
    
    int location;
    
    scanf("%d", &location);
    fgetc(stdin);
    
        while ((location > 9) && (location < 1)) {

                printf("Sorry, your input is invalid. Please enter again:\n");
                printf("Which space (1 - 9) would you like to go in?");
                
                scanf("%d", &location);
                fgetc(stdin);

            }

        return location;
    
}



char placeMark(char markType, char space[9], int numberChoice) {
  
    // Check if space is occupied
    
    
        if (numberChoice == 1) {
            space[0] = markType;
        } 
        
        if (numberChoice == 2) {
            space[1] = markType;
        }
        
        if (numberChoice == 3) {
            space[2] = markType;
        } 
        
        if (numberChoice == 4) {
            space[3] = markType;
        } 
        
        if (numberChoice == 5) {
            space[4] = markType;
        }
        
        if (numberChoice == 6) {
            space[5] = markType;
        }
        
        if (numberChoice == 7) {
            space[6] = markType;
        }
        
        if (numberChoice == 8) {
            space[7] = markType;
        } 
        
        if (numberChoice == 9) {
            space[8] = markType;
        }
        
        return markType;
    
}// FUNCTION TO PLACE MARK (VARIABLE IN MAIN) IN BOARD SPOT (USING PARAMETER)
// MAKE MORE EFFICIENT BY MAKING FUNCTION LIKE THIS:

/*
 
 double getValueofCoins(int totalCalc, int coinValue, char* coinName) {

    double coinType;
    
    coinType = totalCalc / coinValue;
    totalCalc = totalCalc % coinValue; 
    printf("\n%s: %.0lf", coinName, coinType);
    
    return totalCalc;
    
}
 
 */


void checkWin(char space[9]) {
    
    // Horizontal
    
    if ((space[0] == space[1] && space[1] == space[2]) && (space[0] && space[1] && space[2] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
         
    } else if ((space[0] == space[1] && space[1] == space[2]) && (space[0] && space[1] && space[2] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
    
    } else if ((space[3] == space[4] && space[4] == space[5]) && (space[3] && space[4] && space[5] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        
    } else if ((space[3] == space[4] && space[4] == space[5]) && (space[3] && space[4] && space[5] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        
    } else if ((space[6] == space[7] && space[7] == space[8]) && (space[6] && space[7] && space[8] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        
    } else if ((space[6] == space[7] && space[7] == space[8]) && (space[6] && space[7] && space[8] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        
        // Vertical
        
    } else if ((space[0] == space[3] && space[3] == space[6]) && (space[0] && space[3] && space[6] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        
    
    } else if ((space[0] == space[3] && space[3] == space[6]) && (space[0] && space[3] && space[6] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        
    } else if ((space[1] == space[4] && space[4] == space[7]) && (space[1] && space[4] && space[7] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        
    } else if ((space[1] == space[4] && space[4] == space[7]) && (space[1] && space[4] && space[7] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        
    } else if ((space[2] == space[5] && space[5] == space[8]) && (space[2] && space[5] && space[8] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        
    } else if ((space[2] == space[5] && space[5] == space[8]) && (space[2] && space[5] && space[8] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        
        // Diagonal
        
    }  else if ((space[0] == space[4] && space[4] == space[8]) && (space[0] && space[4] && space[8] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true; 
    
    } else if ((space[0] == space[4] && space[4] == space[8]) && (space[0] && space[4] && space[8] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true; 
        
        // Tie Game
        
    } else if (space[0] != '1' && space[1] != '2' && space[2] != '3' && space[3] != '4' && space[4] != '5' && space[5] != '6' && space[6] != '7' && space[7] != '8' && space[8] != '9') {

        printf("\nTie Game");
        tieGame = true;
        
    }
    
}


int main(int argc, char** argv) {

    srand( time( NULL ));
    
    char boardSpace[9];
    int choice;
    int gamesPlayed;
    int counter;
    int markLocation;
    int wins = 0;
    int losses = 0;
    int ties = 0;

    initializeBoard(boardSpace);
    
    // while choice != 0 loop around entire program
    
    printf("Welcome to Tic Tac Toe!\n");
    printf("\nPress the number of the space you would like to place your 'x' in.");
    printf("\nTo win, get three x's in a row.\n");
    
    printChoices();
    choice = getChoice();

            if (choice == 1) {
                
                printBoard(boardSpace);
                printf("\nWhich space (1 - 9) would you like to go in?: ");
                markLocation = getLocation();
                
                while (((computerWin == false) && (humanWin == false) && (tieGame == false))) {
                    
                    placeMark('X', boardSpace, markLocation);
                    printBoard(boardSpace);
                    checkWin(boardSpace);
                    
                    placeMark('O', boardSpace, 1 + rand() % 9);
                    printf("\nComputer has placed their mark\n");
                    printBoard(boardSpace);
                    checkWin(boardSpace);
                    
                    printf("\nWhich space (1 - 9) would you like to go in?: ");
                    markLocation = getLocation();
                    placeMark('X', boardSpace, markLocation);
                    printBoard(boardSpace);
                    checkWin(boardSpace);
                    
                }
                
                gamesPlayed++;
                
            } else if (choice == 2) {
                
                
                
            } else if (choice == 3) {
                
                
                
            } else {
                
                printf("THIS SHOULDN'T HAPPEN");
                
            }

        
   
    printf("\n\nThanks for playing. Goodbye!\n");
    
    if (gamesPlayed > 0) {
        
        printf("\nHere are your statistics for the games you played!\n");
        
        printf("\nWins: %d\n", wins);
        printf("Losses: %d\n", losses);
        printf("Ties: %d\n", ties);

    }
    
    
    return (EXIT_SUCCESS);
}


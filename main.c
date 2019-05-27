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
    
    int index = 0;
    
        for (index = 0; index < 9; index++) {
            space[index] = 0;
            
        }
    
}

// new function print with array and hard code numbers

void displayBoard() {
    
    printf("\n 1  |  2  |  3 \n");
    printf("---------------\n");
    printf(" 4  |  5  |  6 \n");
    printf("---------------\n");
    printf(" 7  |  8  |  9 \n");
    
    
}

void printBoard(char space[9]) {
    
    int indexCheck = 0;
    
    printf("\n %c  | %c  |  %c \n", space[0], space[1], space[2]);
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

char getLocation(char space[9]) {
        
    int location;
    int validMove;
    
    scanf("%d", &location);
    fgetc(stdin);
    
        while ((location > 9) || (location < 1) || (space[location - 1] == 'X') || (space[location - 1] == 'O')) {

        printf("\nSorry, your input is invalid. Please enter again\n");
        printf("Which space (1 - 9) would you like to go in?: ");

        scanf("%d", &location);
        fgetc(stdin);

        }

        return location;
    
}



char placeMark(char markType, char space[9], int numberChoice) {
    
        space[numberChoice - 1] = markType;
        printBoard(space);
            
        return markType;
    
}

void checkWin(char space[9]) {
    
    // Horizontal
    
    if ((space[0] == space[1] && space[1] == space[2]) && (space[0] && space[1] && space[2] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
         
    } else if ((space[0] == space[1] && space[1] == space[2]) && (space[0] && space[1] && space[2] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        losses++;
    
    } else if ((space[3] == space[4] && space[4] == space[5]) && (space[3] && space[4] && space[5] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        wins++;
        
    } else if ((space[3] == space[4] && space[4] == space[5]) && (space[3] && space[4] && space[5] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        losses++;
        
    } else if ((space[6] == space[7] && space[7] == space[8]) && (space[6] && space[7] && space[8] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        wins++;
        
    } else if ((space[6] == space[7] && space[7] == space[8]) && (space[6] && space[7] && space[8] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        losses++;
        
        // Vertical
        
    } else if ((space[0] == space[3] && space[3] == space[6]) && (space[0] && space[3] && space[6] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        wins++;
        
    
    } else if ((space[0] == space[3] && space[3] == space[6]) && (space[0] && space[3] && space[6] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        losses++;
        
    } else if ((space[1] == space[4] && space[4] == space[7]) && (space[1] && space[4] && space[7] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        wins++;
        
    } else if ((space[1] == space[4] && space[4] == space[7]) && (space[1] && space[4] && space[7] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        losses++;
        
    } else if ((space[2] == space[5] && space[5] == space[8]) && (space[2] && space[5] && space[8] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true;
        wins++;
        
    } else if ((space[2] == space[5] && space[5] == space[8]) && (space[2] && space[5] && space[8] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true;
        losses++;
        
        // Diagonal
        
    }  else if ((space[0] == space[4] && space[4] == space[8]) && (space[0] && space[4] && space[8] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true; 
        wins++;
    
    } else if ((space[0] == space[4] && space[4] == space[8]) && (space[0] && space[4] && space[8] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true; 
        losses++;
        
    } else if ((space[2] == space[4] && space[4] == space[6]) && (space[2]) && (space[4] && space[8] == 'X')) {
        printf("\nHUMAN Win!");
        humanWin = true; 
        wins++;
       
    } else if ((space[2] == space[4] && space[4] == space[6]) && (space[2]) && (space[4] && space[8] == 'O')) {
        printf("\nCOMPUTER Win!");
        computerWin = true; 
        losses++;
        
        // Tie Game
        
    } else if ((space[0] != '\0') && (space[1] != '\0') && (space[2] != '\0') && (space[3] != '\0') && (space[4] != '\0') && (space[5] != '\0') && (space[6] != '\0') && (space[7] != '\0') && (space[8] != '\0')) {

        printf("\nTie Game");
        tieGame = true;
        ties++;
        
    }
    
}


int main(int argc, char** argv) {

    srand( time( NULL ));
    
    char boardSpace[9];
    int choice = 5; // so program doesn't automatically end
    int gamesPlayed;
    int counter;
    int markLocation;
    int random;
    
    initializeBoard(boardSpace);
    
    while (choice != 0) {
    
    printf("\nWelcome to Tic Tac Toe!\n");
    printf("\nPress the number of the space you would like to place your 'x' in.\n");
    printf("\nTo win, get three x's in a row.\n");
    
    printChoices();
    choice = getChoice();

            if (choice == 1) {
                
                
            } else if (choice == 2) {
                
                displayBoard();
                printf("\nWhich space (1 - 9) would you like to go in?: ");
                markLocation = getLocation(boardSpace);
                
                while (((computerWin == false) && (humanWin == false) && (tieGame == false))) {
                    
                    placeMark('X', boardSpace, markLocation);
                    checkWin(boardSpace);
                    
                    placeMark('O', boardSpace, random = 1 + rand() % 9);
                    
                    if ((boardSpace[random - 1] == 'X') || (boardSpace[random - 1] == 'O')) {
                        
                       placeMark('O', boardSpace, 1 + rand() % 9);
                        
                    }
                    
                    printf("\nComputer has placed their mark on spot %d\n", random);
                    
                    // create rand variable
                    // in function call, assign it to rand % 9 
                    // create function with random number as parameter and boardSpace
                    // copy space occupied code from placemark
                    
                    checkWin(boardSpace);
                    
                    if (computerWin == false) {
                    
                        printf("\nWhich space (1 - 9) would you like to go in?: ");
                        markLocation = getLocation(boardSpace);
                        placeMark('X', boardSpace, markLocation);
                        checkWin(boardSpace);
                    
                    }
                    
                }
                
                gamesPlayed++;
                
            } else if (choice == 3) {
                
                
                
            }
    
    }
    
    if (gamesPlayed > 0) {
        
        printf("\nHere are your statistics for the games you played!\n");

        printf("\nWins: %d\n", wins);
        printf("Losses: %d\n", losses);
        printf("Ties: %d\n", ties);
        
        printf("\nThanks for playing. Goodbye!\n");

    }
    
    return (EXIT_SUCCESS);
}


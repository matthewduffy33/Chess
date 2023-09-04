#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "linkedList.h"
#include "fileHandling.h"



void saveHistory(char *historyFileName, List historyList){    
	printf("Saving History...\n");

	FILE *fp = fopen(historyFileName, "w");
	if (!fp) {
		printf("Error opening file. Unable to save!\n");
		return;
	}

	if(*historyList != NULL){

        Node *node = *historyList;
        while (node != NULL){       //loops through history list and puts it in file
            fprintf(fp, "%s\n", node->val);
            node = node->next; 
        }

    }


	fclose(fp);
}



int loadHistory(char *historyFileName, List historyList){

    
    FILE *fp = fopen(historyFileName, "r");
    if (!fp) {
        return 0;
    }

    int historyAmount=0;

    char *line= malloc(sizeof(char) * 50);

    int turn;
    int initialX;
    int initialY;

    char type[6];

    int destinationX;
    int destinationY;

    char piece;
    char takenPiece;

    bool valid=true;

	while(fgets(line, 51, fp) != NULL){  //loops through all lines of file

        if(strstr(line, "takes")){  //scan the files 
            if(sscanf(line, "%d %d %d %c %s %d %d %c", &turn, &initialX, &initialY, &piece, type, &destinationX, &destinationY, &takenPiece)==2){
                valid=false;
            }


        }else{
           if(sscanf(line, "%d %d %d %c %s %d %d", &turn, &initialX, &initialY, &piece, type, &destinationX, &destinationY)==2){
                valid=false;
            }
            takenPiece = ' ';

        }

        

        if(valid && strcmp(type, "takes") != 0 && strcmp(type, "moves") != 0 && strcmp(type, "castle") != 0){  //checks type is valid
            valid=false;

        }


        //checks the numbers are valid
        if(valid &&( turn<0 || turn>1 || initialX<0 || initialX>7 ||initialY<0 || initialY>7 || destinationX<0 || destinationX>7 || destinationY<0 || destinationY>7)){
            valid=false;
            
        }

        char upperPiece = toupper(piece);  //checks the piece is valid

        if(valid && piece != ' ' && upperPiece != 'K' && upperPiece != 'Q'  && upperPiece != 'B' && upperPiece != 'N' && upperPiece != 'R' && upperPiece != 'P'){
            valid=false;
        }

        upperPiece = toupper(takenPiece);   //checks the taken piece is valid

        if(valid && takenPiece != ' ' && upperPiece != 'K' && upperPiece != 'Q'  && upperPiece != 'B' && upperPiece != 'N' && upperPiece != 'R' && upperPiece != 'P'){
            valid=false;
        }

        //checks the taken piece is not of the same side as the piece it is taken by
        if(valid && (turn != isupper(piece) || (takenPiece !=' ' && turn == isupper(takenPiece)))){
            valid = false;
        }

        if(!valid){
            clearList(historyList);
            free(line);
            fclose(fp);
            fp = fopen(historyFileName, "w"); //resets file
            return 0;
        }
            
        line[strlen(line)-1] = '\0';
        add(historyList, line);

        historyAmount++;
    }

    free(line);

    
    fclose(fp);

    fp = fopen(historyFileName, "w"); //resets file
    return historyAmount;
}





void saveBoard(char *boardFileName, char *board, int turnNum, bool whiteTurn, bool check, bool*castlingptr){
	printf("Saving Board...\n");

	FILE *fp = fopen(boardFileName, "w");
	if (!fp) {
		printf("Error opening file. Unable to save!\n");
		return;
	}

	for (int y = 0 ; y < 8 ; y++) {  //loop through and put the board in the file
        fprintf(fp, "%c%c%c%c%c%c%c%c\n", 
        *(board + (8*y)), *(board + (8*y) +1), *(board + (8*y) +2), *(board + (8*y) +3), 
        *(board + (8*y) +4), *(board + (8*y) +5), *(board + (8*y) +6), *(board + (8*y) +7));
          
	}

    fprintf(fp, "%d %d %d %d %d %d %d\n", turnNum, whiteTurn, check, *(castlingptr),  *(castlingptr+1),  *(castlingptr+2),  *(castlingptr+3));

	fclose(fp);
}



bool loadBoard(char *boardFileName, char *board, int* turnNumPtr, bool* turnPtr, bool* checkPtr, bool*castlingPtr) {
    printf("Looking for saved game...\n");

    FILE *fp = fopen(boardFileName, "r");
    if (!fp) {
		printf("No Save Data to load\n");
        return false;
    }

    char line[513];
    char pieces[8];
    char upperPiece;

  
	// read in board
    for(int i=0; i<8; i++){  
        if(fgets(line, 512, fp) == NULL){
            printf("No game saved\n");
            return false;

        }else{
            for(int x=0; x<8; x++){
                upperPiece = toupper(line[x]);

                if(line[x] != ' ' && upperPiece != 'K' && upperPiece != 'Q'  && upperPiece != 'B' && upperPiece != 'N' && upperPiece != 'R' && upperPiece != 'P'){
                    printf("Error opening file. Unable to load previous save data\n");
                    return false;
                }

                *(board+(8*i)+x) = line[x];
            }
        }

		
	}
    

    if(fgets(line, 512, fp) == NULL){
        printf("Error opening file. Unable to load previous save data\n");
        return false;

    }else{
        int turnNum;

        int turn;
        int check;

        int castle1;
        int castle2;
        int castle3;
        int castle4;

        if(sscanf(line, "%d %d %d %d %d %d %d", &turnNum, &turn, &check, &castle1, &castle2, &castle3, &castle4)==2){  //scans in line of other data
           printf("Error opening file. Unable to load previous save data\n");
           return false;
        }

        *turnNumPtr = turnNum;

        //check the data is all valid
        if(!(booleanReader(turnPtr, turn)) || !(booleanReader(checkPtr, check))  ||!(booleanReader(castlingPtr, castle1))  || !(booleanReader(castlingPtr+1, castle2))  ||  !(booleanReader(castlingPtr+2, castle3))  || !(booleanReader(castlingPtr+3, castle4))  ){
            printf("Error opening file. Unable to load previous save data\n");
            return false;

        }

        if(*turnPtr){
           *turnNumPtr = (*turnNumPtr) -1;  //stops turn number being added again later
        }

        *turnPtr = !(*turnPtr);    //flips the turn so it flips back later

        
    }
    fclose(fp);



    fp = fopen(boardFileName, "w"); //resets file
    return true;
}


bool booleanReader(bool* ptr, int val){
    if(val == 1){      //turns a value into a boolean
        *ptr = true;
        return true;

    }else if(val == 0){
        *ptr = false;
        return true;

    }else{
        return false;

    }

}
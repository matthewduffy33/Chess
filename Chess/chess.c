#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "linkedList.h"
#include "fileHandling.h"

#include "chess.h"


#include "makeMoves.h"
#include "checkChecker.h"
#include "viewMoves.h"


int main (void) {
	
	char chess[8][8];	            //variables for the state of the game
	char *board= &chess[0][0];

    char *boardFileName ="Files/boardFile.txt";	
    char *historyFileName ="Files/historyFile.txt";	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    int amountOfHistory=0;

    bool whiteTurn;
    bool* turnPtr = &whiteTurn;

    int turnNum;
    int* numPtr = &turnNum;

    bool castlingAllowed[4]={true, true, true, true}; //array showing whether castling is allowed with rooks at a1, h1, a8, h8 (in that order)
    bool *castlingPointer= &castlingAllowed[0];

    bool check=false;
    bool *checkptr = &check;

    if(loadBoard(boardFileName, board, numPtr, turnPtr, checkptr, castlingPointer)){   //attemps to load a previous game if it exists
        printf("Loading previous game\n");

        amountOfHistory= loadHistory(historyFileName, historyList);  //gets history

    }else{
        printf("Starting new game\n");
        
    
        char newChess[8][8]= {                    //sets values to defaults for a new game
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
		    {' ',' ',' ',' ',' ',' ',' ',' '},
		    {' ',' ',' ',' ',' ',' ',' ',' '},
		    {' ',' ',' ',' ',' ',' ',' ',' '},
		    {'P','P','P','P','P','P','P','P'},
		    {'R','N','B','Q','K','B','N','R'}};

        board= &newChess[0][0];
        

        whiteTurn=0;
        turnNum=0;

        amountOfHistory=0;

        *checkptr=false;
        
        *(castlingAllowed)=true;
        *(castlingAllowed+1)=true;
        *(castlingAllowed+2)=true;
        *(castlingAllowed+3)=true;

    }

    char input[12];      // variables for the game loop

	bool stop=0;

    bool turnComplete;

    bool quitting = false;
    bool quitConfirm;
    char quittingInput[4];

    while (stop==0){   //loop for the whole game
		whiteTurn = !whiteTurn;   //flips the turn

        if(whiteTurn){           // adds an extra turn number when the turn is set to white
            turnNum++;
        }

        if(quitting){          //if the other player asks to quit the game the current player chooses if they also want to quit
            quitConfirm=0;

            if(whiteTurn){
                printf("\n\n\n\n\n  -----------White Turn-----------\n\n");   // header for top of turn
            }else{
                printf("\n\n\n\n\n  -----------Black Turn-----------\n\n");
            }

            while(!quitConfirm){
                printf("\nOther Player Wants To Quit! Do You Want To Quit? (YES/NO)\n");
	        
                if(fgets(quittingInput, 9, stdin) != NULL &&!strchr(quittingInput, '\n') ){
                    while (getchar()!='\n');
                }
                quittingInput[strlen(quittingInput)-1] = '\0';

                for(int i=0; i<strlen(quittingInput); i++){
                    quittingInput[i] = toupper(quittingInput[i]);
                }

                if(strcmp(quittingInput, "YES")==0){
                    printf("\nQutting - Stopping The Game\n");
                    stop=1;
                    turnComplete = 1;
                    quitConfirm=1;

                }else if(strcmp(quittingInput, "NO")==0){
                    printf("\nNot Qutting - Continuing Game\n");
                    quitConfirm=1;
                    quitting=0;

                    whiteTurn = !whiteTurn;
                    if(!whiteTurn){
                        turnNum--;
                    }

                }else{
                    printf("\nNot an option!\n");
                
                }
            }
        }

        if(stop==0){
            if(mateChecker(board, whiteTurn, *checkptr)){   //sees if player is in checkmate or stalemate and ends the game if so

                if(*checkptr == 1){
                    printf("\nCheckmate!\n");
                    if(whiteTurn){
                        printf("White Wins!");
                    }else{
                        printf("Black Wins!");
                    }
                }else{
                    printf("\nStalemate!\n");
                    printf("\nNo One Loses\n");
                }
                
            
                stop=1;
            }else{

                if(whiteTurn){
                    printf("\n\n\n\n\n  -----------White Turn-----------\n\n");   // header for top of turn
                }else{
                    printf("\n\n\n\n\n  -----------Black Turn-----------\n\n");
                }
                printf("Turn: %d\n",turnNum);

                if(*checkptr == 1){
                    printf("Check! You are in check!");
                }
                turnComplete = 0;
            }
        }


        while(!turnComplete){  //loop that loops until a turn is complete

            printf("\n");    //top text and board that appears every turn
            printGrid(board, whiteTurn);

            if(whiteTurn){
                printf("\nTurn: White");
            }else{
                printf("\nTurn: Black");
            }




            printf("\nMOVE: Move a piece \nVIEW: Check possible moves a piece can make \nCASTLE: Castle your rook and king \nHISTORY: See the previous moves made (up to 50 moves)\nHIST LIST: See a list of previously made move \nRESIGN: Resign the match \nSAVE: Save and quit the game and return later \nQUIT: Quit the game (Both players need to accept quitting)\n");
	    
            if(fgets(input, 11, stdin) != NULL &&!strchr(input, '\n') ){   //gets input from user
                while (getchar()!='\n');
            }
            input[strlen(input)-1] = '\0';

            for(int i=0; i<strlen(input); i++){
                input[i] = toupper(input[i]);
            }



            if(strcmp(input, "MOVE")==0){         //checks if user inputted a sepcific function and if so runs it
                if(movePiece(board, whiteTurn, castlingPointer, checkptr, historyList)){
                    turnComplete = 1;
                }

            }else if(strcmp(input, "CASTLE")==0){
                if(check){
                    printf("\nCan't castle while in check!\n");
                }else{
                    if(castle(board, whiteTurn, castlingPointer, historyList)){
                        turnComplete = 1;
                    }
                }

            }else if(strcmp(input, "VIEW")==0){
                viewPiece(board, whiteTurn, castlingPointer, checkptr);

            }else if(strcmp(input, "RESIGN")==0){
                turnComplete = 1;
                if(whiteTurn){                    //quits the function
                    printf("\nWhite Resigned!\n");
                    printf("\nBlack Wins! \n");
                }else{
                    printf("\nBlack Resigned!\n");
                    printf("\nWhite Wins! \n");
                }
                stop=1;

            }else if(strcmp(input, "HISTORY")==0){
                selectHistory(board, historyList, amountOfHistory, turnNum, whiteTurn);

            }else if(strcmp(input, "HIST LIST")==0){
                histList(board, historyList, turnNum, whiteTurn);

            }else if(strcmp(input, "SAVE")==0){
                saveBoard(boardFileName, board, turnNum, whiteTurn, check, castlingPointer);  //save boards and history
                saveHistory(historyFileName, historyList);
                turnComplete = 1;
                stop=1;
                
            }else if(strcmp(input, "QUIT")==0){
                turnComplete = 1;
                quitting=1;

            }else{                              //if the user has not entered a valid function the turn would loop again
                printf("\nNot an option!\n");
                
            }
        }
        amountOfHistory++;
		
	}
    printf("\nExiting"); //exits the game if game is done
	
    clearList(historyList);
    free(historyList);

    return 0;
}   


void printGrid(char *board, bool turn){                //prints the grid and flips it based on turns
    printf("  ---------------------------------\n");
    if(turn){
        for (int y = 0 ; y < 8 ; y++) {
		    printf("%d ",(8-y));
		    for (int x = 0 ; x < 8 ; x++) {
			    printf("| %c ", *(board+(8*y)+x)  );
		    }
            printf("|\n  |---|---|---|---|---|---|---|---|\n");
          
	    }
        printf("    A   B   C   D   E   F   G   H");
    }else{
        for (int y = 7 ; y >=0 ; y--) {
		    printf("%d ",(8-y));
            for (int x = 7 ; x >=0 ; x--) {
                printf("| %c ", *(board+(8*y)+x)  );
            }
            printf("|\n  |---|---|---|---|---|---|---|---|\n");
	    }
        printf("    H   G   F   E   D   C   B   A");
    }
    printf("\n\n\n");
    
}



bool movePiece(char *board, bool turn, bool *castlingPointer, bool *checkptr, List historyList){
    char pos[7];
    char piece;

    int pieceX;
	int pieceY;

	int destinationX;
	int destinationY;

    bool valid;

    bool back;

    do{    //in a loop to allow the user to go back a step if they wish
        back=0;

        do{
            printf("\nSelect Piece (or back): ");
            if(fgets(pos, 6, stdin) != NULL && !strchr(pos, '\n') ){     //gets input for selected piece
                while (getchar()!='\n');
            }

            pos[strlen(pos)-1] = '\0';

            if(strcmp(pos, "Back")==0 || strcmp(pos, "BACK")==0 || strcmp(pos, "back")==0){
                return false;

            }
            
            pieceX=toupper(pos[0])-'A';  //converts the input to 2d array positions
            pieceY=7-(pos[1]-'1');
            
            piece= *(board+(8*pieceY)+pieceX);

            if(pieceX<0 || pieceX>7 || pieceY<0 || pieceY>7){   //checks input is allowed
                printf("\nNot Valid Position\n");

            }else if(piece==' '){
                printf("\nNo Piece At That Position\n");

            }else if(turn != isupper(piece)){
                printf("\nNot Your Piece\n");

            }

        }while(pieceX<0 || pieceX>7 || pieceY<0 || pieceY>7 || piece==' ' || turn != isupper(piece));
    

        do{
            printf("\nSelect Position to move to (or back): ");
            if(fgets(pos, 6, stdin) != NULL &&!strchr(pos, '\n') ){      //gets input for selected piece
                while (getchar()!='\n');
            }
            pos[strlen(pos)-1] = '\0';

            if(strcmp(pos, "Back")==0 || strcmp(pos, "BACK")==0 || strcmp(pos, "back")==0){
                back=1;

            }else{
                destinationX =toupper(pos[0])-'A';         //converts the input to 2d array positions
                destinationY=7-(pos[1]-'1');
                
                if(destinationX<0 || destinationX>7 || destinationY<0 || destinationY>7){       //checks input is allowed
                    printf("\nNot Valid Position");

                }else if(pieceX == destinationX && pieceY == destinationY){
                    printf("\nSame Position As Before");

                }else{
                    valid = checkMove(board, turn, piece, pieceX, pieceY, destinationX, destinationY, checkptr, historyList);

                }

            }

            

        }while(!back && (destinationX<0 || destinationX>7 || destinationY<0 || destinationY>7 || !valid));

    }while(back);
    


    if(toupper(piece) == 'P' && (destinationY == 7 || destinationY == 0)){  // if pawn reaches end then promote the pawn
        promoter(board, turn, destinationX, destinationY);
    }

    if(opponentCheckChecker(board, !turn, piece, pieceX, pieceY, destinationX, destinationY)){    //sees if move puts thopponent in check
        *checkptr=1;
    }

    if( toupper(piece) == 'K' || toupper(piece) == 'R'){             //if a king or rook moves stop castling being allowed with those pieces
        castleSet(turn, piece, castlingPointer, pieceX, pieceY);
    }

    return true;   
}



void promoter(char *board, bool turn, int x, int y){
    bool repeat= true;

    while (repeat==true){          //picks a piece to promote to

        printf("\nWhat do you want to promote your pawn too?");
        printf("\nQUEEN, ROOK, KNIGHT, BISHOP\n");
        char promotion[7];
	        
        if(fgets(promotion, 7, stdin) != NULL &&!strchr(promotion, '\n') ){ //takes input
            while (getchar()!='\n');
        }
        promotion[strlen(promotion)-1] = '\0';

        for(int i=0; i<strlen(promotion); i++){
            promotion[i] = toupper(promotion[i]);
        }

        if(strcmp(promotion, "QUEEN")==0){
            if(turn){
                *(board+(8*y)+x) = 'Q';
            }else{
                *(board+(8*y)+x) = 'q';
            }
            repeat=false;

        }else if(strcmp(promotion, "ROOK")==0){
            if(turn){
                *(board+(8*y)+x) = 'R';
            }else{
                *(board+(8*y)+x) = 'r';
            }
            repeat=false;
                    
        }else if(strcmp(promotion, "KNIGHT")==0){
            if(turn){
                *(board+(8*y)+x) = 'N';
            }else{
                *(board+(8*y)+x) = 'n';
            }
            repeat=false;
                    
        }else if(strcmp(promotion, "BISHOP")==0){
            if(turn){
                *(board+(8*y)+x) = 'B';
            }else{
                *(board+(8*y)+x) = 'b';
            }
            repeat=false;
                    
        }else{
            printf("\nNot valid option");
        }
    }
    
}



void viewPiece(char *board, bool turn, bool *castlingPointer, bool *checkptr){  //views pieces to see potential moves
    char pos[7];
    int posX;
    int posY;
    int piece;

    do{
        printf("\nSelect Piece (or back): ");
	    if(fgets(pos, 6, stdin) != NULL &&!strchr(pos, '\n') ){   //takes input
            while (getchar()!='\n');
        }

        pos[strlen(pos)-1] = '\0';

        if(strcmp(pos, "Back")==0 || strcmp(pos, "BACK")==0 || strcmp(pos, "back")==0){
            return;
        }
        


		posX=toupper(pos[0])-'A';  //converts the input to 2d array positions
        
        posY=7-(pos[1]-'1');
        
        piece= *(board+(8*posY)+posX);  //gets piece based on position



        if(posX<0 || posX>7 || posY<0 || posY>7){   //checks piece is valid
            printf("\nNot Valid Position\n");

        }else if(piece==' '){
            printf("\nNo Piece At That Position\n");

        }else if(turn != isupper(piece)){
            printf("\nNot Your Piece\n");

        }

    }while(posX<0 || posX>7 || posY<0 || posY>7 || piece==' ' || turn != isupper(piece));


    List possibleList = malloc(sizeof(List));   //list of potential moves
  	*possibleList = NULL;

    getMoves(board, turn, piece, posX, posY, possibleList, checkptr);  //gets moves that can be made
    getCastling(board, turn, piece, posX, posY, possibleList, checkptr, castlingPointer);  //gets moves that can be made through castling

    printList(possibleList);   //print the list of potential moves

    if(!isEmpty(possibleList)){
        char tempchess[8][8];
					
	    char *tempBoard= &tempchess[0][0];	

        for (int y = 0 ; y < 8 ; y++) {
		    for (int x = 0 ; x < 8 ; x++) {
			    *(tempBoard+(8*y)+x) = *(board+(8*y)+x) ;
		    }
           
          
	    }

        listToGrid(possibleList, tempBoard);  //converts the possible list to a grid

        printGrid(tempBoard, turn);
    }

    clearList(possibleList);   //clear the list
    free(possibleList);
}


bool castle(char *board, bool turn, bool* castlePointer, List historyList){
    bool aCastle=false;
    bool hCastle=false;

    if(turn){      //checks which castles are allowed based on turn and if castle can occur
        if(*castlePointer && castleCheck(board, turn, 0, 4, 7)){
            aCastle=true;
        }
        
        if(*(castlePointer+1) && castleCheck(board, turn, 7, 4, 7)){
            hCastle=true;
        }
    }else{
        if(*(castlePointer+2) && castleCheck(board, turn, 0, 4, 0)){
            aCastle=true;
        }
        
        if(*(castlePointer+3) && castleCheck(board, turn, 7, 4, 0)){
            hCastle=true;
        }
    }

    char input[9];
    bool repeat = false;

    if(aCastle && hCastle){
        do{
            printf("\nWould you like to castle with the rook in column A or H?");   //if both sides are possible then give the option for the user to pick
            printf("\nAnswer with: A, H or NEITHER\n");
            if(fgets(input, 9, stdin) != NULL &&!strchr(input, '\n') ){
                while (getchar()!='\n');
            }
            input[strlen(input)-1] = '\0';

            for(int i=0; i<strlen(input); i++){
                input[i] = toupper(input[i]);
            }

            if(strcmp(input, "A")==0){     //do the castle selected
                doCastle(board, turn, 'A', castlePointer, historyList);
                return true;

            }else if(strcmp(input, "H")==0){
                doCastle(board, turn, 'H', castlePointer, historyList);

            }else if(strcmp(input, "NEITHER")==0){  //if neither is selected then quit
                return false;

            }else{
                repeat=true;
            }
        }while(repeat);

    }else if(aCastle || hCastle){
        do{

            if(aCastle){
                printf("\nOnly the rook in column A can castle? Would you like to castle with it? (Yes or No)\n");
            }else{
                printf("\nOnly the rook in column H can castle? Would you like to castle with it? (Yes or No)\n");
            }
            
            if(fgets(input, 5, stdin) != NULL &&!strchr(input, '\n') ){  //gets user input
                while (getchar()!='\n');
            }
            input[strlen(input)-1] = '\0';

            for(int i=0; i<strlen(input); i++){
                input[i] = toupper(input[i]);
            }



            if(strcmp(input, "YES")==0){
                if(aCastle){   //do the castle
                    doCastle(board, turn, 'A', castlePointer, historyList);
                }else{
                    doCastle(board, turn, 'H', castlePointer, historyList);
                }

            }else if(strcmp(input, "NO")==0){   //quit if neither is picked
                return false;

            }else{
                repeat=true;

            }

        }while(repeat);

    }else{
        printf("\nYou can't castle now!");    //if no castling is allowed then go back to turn
        return false;
    }
    return true;
}




void selectHistory(char *board, List historyList, int amountOfTurns, int turnNum, bool turn){
    char input[3];
    int num;
    bool stop = false;

    if(amountOfTurns==0){     //if no history then
        printf("There is no history to show\n");
        return;
    }

    do{
        printf("\nThere are %d previous moves you can look at\n", amountOfTurns);
        printf("Which move would you like to see (1 is the most recent %d is the oldest one):", amountOfTurns);
    

	    if(fgets(input, 4, stdin) != NULL &&!strchr(input, '\n') ){   //get user input
            while (getchar()!='\n');
        }

        input[strlen(input)-1] = '\0';

        if(strcmp(input, "Back")==0 || strcmp(input, "BACK")==0 || strcmp(input, "back")==0){  //go back if that is selected
            return;
        }
        
		num = atoi(input); //converts char to int


        if(num>=1 && num<=amountOfTurns){
            getHistory(board, historyList, num, turnNum, turn);   //get the history selected
            stop=1;

        }else{
            printf("\nNot Valid History Number");

        }

    }while(!stop);

}




void getHistory(char *board, List historyList, int num, int turnNum, bool currTurn){

    char tempchess[8][8];       //makes a tempboard to get the history
	char *tempBoard= &tempchess[0][0];	

    for (int y = 0 ; y < 8 ; y++) {
		for (int x = 0 ; x < 8 ; x++) {
			*(tempBoard+(8*y)+x) = *(board+(8*y)+x);

		}
          
	}

    char* history = malloc(20*sizeof(char));
    char piece;
    char takenPiece;

    char* type = malloc(10*sizeof(char));

    int turn;

    int destinationX;
    int destinationY;

    int originalX;
    int originalY;


    int i = 0;

    if(*historyList != NULL){

        Node *node = *historyList;

        while (node != NULL && i<num){    //loops through the history list till the selected number is reached
            strcpy(history, node->val);
            

            if (strstr(history, "takes") != NULL) {  //reads list value
                sscanf(history, "%d %d %d %c %s %d %d %c", &turn, &originalX, &originalY, &piece, type, &destinationX, &destinationY, &takenPiece);

            }else{
                takenPiece =' ';
                sscanf(history, "%d %d %d %c %s %d %d", &turn, &originalX, &originalY, &piece, type, &destinationX, &destinationY);

            }


            *(tempBoard+(8*destinationY)+destinationX) = takenPiece;   //reverses the move from history
            *(tempBoard+(8*originalY)+originalX) = piece;

            if(strcmp(type,"castle")==0){   //moves the rook for castling
                if(destinationX==2){
                    if(turn==1){
                        *(tempBoard+(8*originalY)+0) = 'R';
                    }else{
                        *(tempBoard+(8*originalY)+0) = 'r';
                    }
                    
                    *(tempBoard+(8*originalY)+3) = ' ';
                }else{
                    if(turn==1){
                        *(tempBoard+(8*originalY)+7) = 'R';
                    }else{
                        *(tempBoard+(8*originalY)+7) = 'r';
                    }
                    
                    *(tempBoard+(8*originalY)+5) = ' ';
                }
            }

            node = node->next; 

            i++;

        }

        if(i != num){
            printf("\nError with history\n");
            return;
        }

        printf("\n\n\n");

        int previousTurnNum;
        if(currTurn == turn || turn){   //calculates the turn num of the selected turn
            previousTurnNum = turnNum - (num/2);

        }else{
            previousTurnNum = (turnNum - (num/2)) -1;

        }
        
        printf("Turn: %d", previousTurnNum);

        if(turn == 1){
            printf("\nWhite\n");

        }else{
            printf("\nBlack\n");

        }

        printf("%c%d %c ", (originalX +'A'), ((7-originalY) + 1 ), piece);   //displays the history value

        if(strstr(history, "takes") != NULL) {
            printf("takes %c at", takenPiece);

        }else if(strstr(history, "castle") != NULL){
            printf("castled to");

        }else{
            printf("moves to");

        }
        printf(" %c%d\n", (destinationX +'A'), ((7-destinationY) +1), piece);

        printGrid(tempBoard, turn);   //prints the grid of the stage before the selected move

        

        printf("                  |\n");
        printf("                  |\n");
        printf("                  |\n");
        printf("                  |\n");
        printf("                  V\n\n");


        *(tempBoard+(8*destinationY)+destinationX) = piece;   //redoes the selected move
        *(tempBoard+(8*originalY)+originalX) = ' ';

        if(strcmp(type,"castle")==0){
            if(destinationX==2){
                if(turn==1){
                    *(tempBoard+(8*originalY)+3) = 'R';
                }else{
                    *(tempBoard+(8*originalY)+3) = 'r';
                }
                    
                *(tempBoard+(8*originalY)+0) = ' ';
            }else{
                if(turn==1){
                    *(tempBoard+(8*originalY)+5) = 'R';
                }else{
                    *(tempBoard+(8*originalY)+5) = 'r';
                }
                    
                *(tempBoard+(8*originalY)+7) = ' ';
            }
        }



        printGrid(tempBoard, turn);   //prints the grid after the selected grid

        printf("\n");

        free(history);
        free(type);

    }else{
        printf("\nNo history! \n");
    }

}




void histList(char *board, List historyList, int turnNum, bool currTurn){  // gets the list of past history

    char* history = malloc(20*sizeof(char));
    char piece;
    char takenPiece;

    char* type = malloc(10*sizeof(char));

    int turn;

    int destinationX;
    int destinationY;

    int originalX;
    int originalY;


    int i = 0;

    if(*historyList != NULL){

        Node *node = *historyList;
        while (node != NULL){  //loops through list
            strcpy(history, node->val);
            

            if (strstr(history, "takes") != NULL) {  //reads value from list
                sscanf(history, "%d %d %d %c %s %d %d %c", &turn, &originalX, &originalY, &piece, type, &destinationX, &destinationY, &takenPiece);

            }else{
                sscanf(history, "%d %d %d %c %s %d %d", &turn, &originalX, &originalY, &piece, type, &destinationX, &destinationY);

            }

            int previousTurnNum;

            if(currTurn == turn || turn){    // get the turn number
                previousTurnNum = turnNum - ((i+1)/2);

            }else{
                previousTurnNum = (turnNum - ((i+1)/2)) -1;

            }

            
            printf("\n\n%d.   Turn %d", (i+1), previousTurnNum);   //prints a string from the read in value from list

            if(turn == 1){
                printf(" White:\t");
            }else{
                printf(" Black:\t");
            }

            printf("%c%d %c ", (originalX +'A'), ((7-originalY) + 1 ), piece);

            if(strstr(history, "takes") != NULL) {
                printf("takes %c at", takenPiece);

            }else if(strstr(history, "castle") != NULL){
                printf("castled to");

            }else{
                printf("moves to");

            }
            printf(" %c%d", (destinationX +'A'), ((7-destinationY) +1), piece);



            node = node->next; 

            i++;

        }


        free(history);
        free(type);
        printf("\n\n\n");

    }else{
        printf("\nNo history! \n");
    }

}





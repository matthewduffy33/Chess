#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "linkedList.h"
#include "makeMoves.h"
#include "checkChecker.h"


bool checkMove(char *board, bool turn, char piece, int startX, int startY, int destinationX, int destinationY, bool *checkptr, List historyList){

    bool valid;
    char destinationPiece = *(board+(8*destinationY)+destinationX);

    if(turn == isupper(destinationPiece) && destinationPiece != ' '){  //checks if the piece being taken is their own piece
        printf("\nCan't Take Your Own Piece!");
        return false;
    }

    char upperPiece = toupper(piece);

    if(upperPiece == 'P'){   //splits off into different function based on the piece being moved
        valid = pawnCheck(board, turn, startX, startY, destinationX, destinationY);

    }else if(upperPiece == 'R'){
        valid = rookCheck(board, startX, startY, destinationX, destinationY);
        
    }else if(upperPiece == 'N'){
        valid = knightCheck(board, startX, startY, destinationX, destinationY);

    }else if(upperPiece == 'B'){
        valid = bishopCheck(board, startX, startY, destinationX, destinationY);

    }else if(upperPiece == 'Q'){
        valid = queenCheck(board, startX, startY, destinationX, destinationY);

    }else{
        valid = kingCheck(board, startX, startY, destinationX, destinationY);

    }

    if(!valid){
        printf("\nCan't Move Piece Here");
        return valid;
    }

    char ogPiece = *(board+(8*destinationY)+destinationX);  //keeps a track of the original piece incase the move needs to be retracted

    //makes move
    *(board+(8*destinationY)+destinationX)=piece;
	*(board+(8*startY)+startX)=' ';


    valid=true;

    if(*checkptr == 1 || piece=='k' || piece=='K'){   //if in check or are moving a king then do a full check check
        if(fullCheckChecker(board, turn, destinationX, destinationY)){
            valid = false;
        }
        *checkptr = 0;

    }else{      //sees if move puts player in check
        if(selfCheckChecker(board, turn, startX, startY)){
            valid = false;
        }

    }


    if(!valid){  //if in check then retract move
        printf("\nCan't Move Here! Will Cause Check");

        *(board+(8*destinationY)+destinationX)=ogPiece;
        *(board+(8*startY)+startX)=piece;

        return false;
    }



    char* history = malloc(25*sizeof(char));

    if(ogPiece == ' '){   //creates history value
        sprintf(history, "%d %d %d %c moves %d %d", turn, startX, startY, piece, destinationX, destinationY);
    }else{
        sprintf(history, "%d %d %d %c takes %d %d %c",turn, startX, startY, piece, destinationX, destinationY, ogPiece);
    }


    addToFront(historyList, history);  //add to history list

    removeAfter(historyList, 49);   //remove from end if too long

    free(history);
    
    return true;
    
}



bool pawnCheck(char *board, bool turn, int startX, int startY, int destinationX, int destinationY){

    if(*(board+(8*destinationY)+destinationX)==' '){
        if(!turn){
            if(startY == 1 && destinationX == startX && destinationY==3 && *(board+(8*2)+destinationX)==' '){  //checks if attempting to move 2 spaces
                return true;
            }
        }else{
            if(startY == 6 && destinationX == startX && destinationY==4 && *(board+(8*3)+destinationX)==' '){
                return true;
            }
        }
        
        if(destinationX == startX  && ((!turn & ((destinationY - startY) ==1)) || (turn & ((destinationY - startY) == -1)))){  //checks if moving forward 1 is valid
            return true;
        }else{
            return false;
        }

    }else{
        if(((destinationY-startY)==-1 || (destinationY-startY)==1) && (destinationX-startX==1 || destinationX-startX==-1)){  //checks if diagonal movement is valid
            return true;
        }else{
            return false;
        }
    }

}



bool knightCheck(char *board, int startX, int startY, int destinationX, int destinationY){
    if((abs(startX-destinationX)==2 && abs(startY-destinationY)==1)||((abs(startX-destinationX)==1 && abs(startY-destinationY)==2))){  //checks mathematically if the knight move is right
        return true;
    }else{
        return false;
    }
    

}



bool bishopCheck(char *board, int startX, int startY, int destinationX, int destinationY){
    //checks diagonal 
    if(abs((startX-destinationX)/(startY-destinationY)) != 1){
        
        return false;
    }
    
    int xFactor;
    int yFactor;

    if(destinationX>startX){
        xFactor=1;
    }else{
        xFactor=-1;
    }

    if(destinationY>startY){
        yFactor=1;
    }else{
        yFactor=-1;
    }

    int y= startY + yFactor;
    for(int x=startX+xFactor; x != destinationX; x= x + xFactor){  //checks nothing is in the diagonal between the start and destination
       
        if(*(board+(8*y)+x) != ' '){
            
            return false;
        }
        y= y + yFactor;
        
    }


    return true;
}


bool rookCheck(char *board, int startX, int startY, int destinationX, int destinationY){

     //check on same line
    if(startX != destinationX && startY != destinationY){
        return false;
    }
    
    if(startX == destinationX){
        int yFactor;

        if(destinationY>startY){
            yFactor=1;
        }else{
            yFactor=-1;
        }

        for(int y=startY+yFactor; y != destinationY; y= y + yFactor){  //checks nothing is in the line between the start and destination
            if(*(board+(8*y)+startX) != ' '){
                return false;
            }
        
        
        }
    
    }else{
        int xFactor;

        if(destinationX>startX){
            xFactor=1;
        }else{
            xFactor=-1;
        }

        for(int x=startX+xFactor; x != destinationX; x= x + xFactor){  //checks nothing is in the line between the start and destination
        
            if(*(board+(8*startY)+x) != ' '){
                return false;
            }
        
        
        }
    }


    return true;
}



bool queenCheck(char *board, int startX, int startY, int destinationX, int destinationY){

    if(startX == destinationX || startY == destinationY){  //uses bishops and rook checks =
        return rookCheck(board, startX, startY, destinationX, destinationY);
    }else{
        return bishopCheck(board, startX, startY, destinationX, destinationY);
    }
}



bool kingCheck(char *board, int startX, int startY, int destinationX, int destinationY){
    if(abs(destinationX-startX)<=1 && abs(destinationY-startY)<=1){  //ensures each movement is 1 space away
        return true;
    }else{
        return false;
    }

}

bool castleCheck(char *board, bool turn, int rookX, int kingX, int y){
    int xFactor;

    if(rookX<kingX){
        xFactor=-1;
    }else{
        xFactor=1;
    }

    for(int x=kingX + xFactor; x!= rookX; x=x + xFactor){   //checks nothing between king and rook
        if(*(board+(8*y)+x) != ' '){
            return false;
        }
    }

    int x = kingX;
    *(board+(8*y)+kingX) = ' ';

    for(int i=0; i<2; i++){  //loops through the spaces between castle and king
        x = x + xFactor;

        if(turn){
            *(board+(8*y)+x) = 'K';
        }else{
            *(board+(8*y)+x) = 'k';
        }


        if(fullCheckChecker(board, turn, x, y)){   //checks the king is not put through check
            *(board+(8*y)+x) = ' ';
            if(turn){
                *(board+(8*y)+kingX) = 'K';    //puts kings back
            }else{
                *(board+(8*y)+kingX) = 'k';
            }
            return false;
        }

        *(board+(8*y)+x) = ' ';

    }

    if(turn){
        *(board+(8*y)+kingX) = 'K'; //puts king back and returns true
    }else{
        *(board+(8*y)+kingX) = 'k';
    }

    return true;
}


void castleSet(bool turn, char piece, bool* castlingPointer, int x, int y){

    if(piece == 'K'){                  //set both castling to false if king is moved
        *(castlingPointer+0) = false;
        *(castlingPointer+1) = false;

    }else if(piece == 'k'){
        *(castlingPointer+2) = false;
        *(castlingPointer+3) = false;

    }else if(turn && y == 7){          //sets appropriate castling pointer based on rook movement
        if(x==0){
            *(castlingPointer+0) = false;

        }else if(x==7){
            *(castlingPointer+1) = false;

        }

    }else if(!turn && y == 0){
        if(x==0){
            *(castlingPointer+2) = false;

        }else if(x==7){
            *(castlingPointer+3) = false;

        }
    }

}



void doCastle(char* board, bool turn, char column, bool* castlePointer, List historyList){
    char piece;
    int startX;
    int y;
    int destinationX;
    int destinationY;

    if(turn){
        if(column=='A'){               //does the castle
            *(board+(8*7)+2) = 'K';
            *(board+(8*7)+3) = 'R';
            *(board+(8*7)) = ' ';
            *(board+(8*7)+4) = ' ';

            startX = 4;
            destinationX = 2;
        }else{
            *(board+(8*7)+6) = 'K';
            *(board+(8*7)+5) = 'R';
            *(board+(8*7)+7) = ' ';
            *(board+(8*7)+4) = ' ';

            startX = 4;
            destinationX = 6;
        }

        *(castlePointer+0) = false; //setting castling pointer to stop future castling
        *(castlePointer+1) = false;

        piece = 'K';
        y=7;

    }else{
        if(column=='A'){
            *(board+2) = 'k';
            *(board+3) = 'r';
            *(board) = ' ';
            *(board+4) = ' ';

            startX = 4;
            destinationX = 2;
            
        }else{

            *(board+6) = 'k';
            *(board+5) = 'r';
            *(board+7) = ' ';
            *(board+4) = ' ';

            startX = 4;
            destinationX = 6;
            
        }

        piece = 'k';

        *(castlePointer+2) = false; //setting castling pointer to stop future castling
        *(castlePointer+3) = false;

        y=0;

    }

    char* history = malloc(25*sizeof(char));

    sprintf(history, "%d %d %d %c castle %d %d", turn, startX, y, piece, destinationX, y);

    addToFront(historyList, history); //adds castling to history

    removeAfter(historyList, 49);

    free(history);

   
}

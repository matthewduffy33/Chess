#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "viewMoves.h"
#include "linkedList.h"
#include "checkChecker.h"
#include "makeMoves.h"




void getMoves(char *board, bool turn, char piece, int posX, int posY, List possibleList, bool checkptr){
    char upperPiece=toupper(piece);

    if(upperPiece == 'P'){          //splits into sub functions
        pawnMoves(board, turn, posX, posY, possibleList);

    }else if(upperPiece == 'N'){
        knightMoves(board, turn, posX, posY, possibleList);

    }else if(upperPiece == 'B'){
        bishopMoves(board, turn, posX, posY, possibleList);

    }else if(upperPiece == 'R'){
        rookMoves(board, turn, posX, posY, possibleList);

    }else if(upperPiece == 'Q'){
        bishopMoves(board, turn, posX, posY, possibleList);
        rookMoves(board, turn, posX, posY, possibleList);

    }else{
       kingMoves(board, turn, posX, posY, possibleList);
    }

    if(checkptr == 1 && upperPiece != 'K'){ //if in check remove values that keep it still in check
        movesInCheck(board, turn, piece, posX, posY, possibleList);
    }

}


void getCastling(char *board, bool turn, char piece, int posX, int posY, List possibleList, bool check, bool* castlePointer){
    char upperPiece=toupper(piece);

    if(!check){
        if(upperPiece == 'R'){
            rookCastleMoves(board, turn, posX, posY, possibleList, castlePointer);

        }else if(upperPiece == 'K'){
            kingCastleMoves(board, turn, possibleList, castlePointer);

        }
    }
    
}

void pawnMoves(char *board, bool turn, int posX, int posY, List possibleList){
    char piece;
    char *pos = malloc(sizeof(char)*3);
    memset(pos, '\0', 3);
    
    if(selfCheckChecker(board, turn, posX, posY)){  //checks if moving the piece puts the king in check
        return;
    }

    if(turn && posY>0){
        piece=*(board+(8*(posY-1))+posX-1);
        if(posX>0 && !isupper(piece) && piece != ' '){  //adds left diagonal moves
            
            pos[0] = (posX-1) +'0';
            pos[1] = (posY-1) +'0';

            add(possibleList, pos);
            
            
        }

        piece=*(board+(8*(posY-1))+posX+1);
        if(posX<7 && !isupper(piece)  && piece != ' '){   //adds right diagonal moves

            pos[0] = (posX+1) +'0';
            pos[1] = (posY-1) +'0';

            add(possibleList, pos);
            
        }

        piece=*(board+(8*(posY-1))+posX);
        
        
        if(piece==' '){
            
            pos[0] = (posX) +'0';   //adds moving 1 square forward
            pos[1] = (posY-1) +'0';
                
            add(possibleList, pos);
            
            if(posY==6){

                piece=*(board+(8*(posY-2))+posX);
        
                if(piece==' '){         //adds moving 2 squares forward

                    pos[0] = (posX) +'0';
                    pos[1] = (posY-2) +'0';
                        
                    add(possibleList, pos);
            
                }

            }
            
        }

    }else if(!turn && posY<7){
        piece=*(board+(8*(posY+1))+posX-1);
        if(posX>0 && isupper(piece) && piece != ' '){ //adds left diagonal moves
            
            pos[0]= (posX-1)+'0';
            pos[1]= (posY+1)+'0';
            add(possibleList, pos);
           
            
        }

        piece=*(board+(8*(posY+1))+posX+1);
        if(posX<7 && isupper(piece) && piece != ' '){ //adds right diagonal moves
            
            pos[0]= (posX+1)+'0';
            pos[1]= (posY+1)+'0';
            add(possibleList, pos);
           
        }

        piece=*(board+(8*(posY+1))+posX);
        if(piece==' '){
           
            pos[0]= posX+'0';          //adds moving 1 square forward
            pos[1]= (posY+1)+'0';
            add(possibleList, pos);

            if(posY==1){

                piece=*(board+(8*(posY+2))+posX);
        
                if(piece==' '){

                    pos[0] = (posX) +'0';     //adds moving 2 squares forward
                    pos[1] = (posY+2) +'0';
                        
                    add(possibleList, pos);
                    
                }

            }
        }
    }

    free(pos);
    
}


void knightMoves(char *board, bool turn, int posX, int posY, List possibleList){
    char *pos = malloc(sizeof(char)*3);
    memset(pos, '\0', 3);

    if(selfCheckChecker(board, turn, posX, posY)){   //checks if moving the piece puts the king in check
        return;
    }

    for(int i=-2; i<=2; i=i+4){
        for(int j=-1; j<=1; j=j+2){                                //mathematically loops through the possible moves knights make
            if(posX+i>=0 && posX+i<=7 && posY+j>=0 && posY+j<=7){
                char piece = *(board+(8*(posY+j))+(posX+i));
                if(turn != isupper(piece) || piece==' '){

                    pos[0] = (posX +i) +'0';
                    pos[1] = (posY +j) +'0';

                    add(possibleList, pos);
                 
                }
                
            }

            if(posX+j>=0 && posX+j<=7 && posY+i>=0 && posY+i<=7){   //flips the x and y being shifted
                char piece = *(board+(8*(posY+i))+(posX+j));
                if(turn != isupper(piece) || piece==' '){

                    pos[0] = (posX +j) +'0';
                    pos[1] = (posY +i) +'0';

                    add(possibleList, pos);
                    
                }
                
            }
        }
    }

    free(pos);
    
}

void bishopMoves(char *board, bool turn, int posX, int posY, List possibleList){
    char *pos = malloc(sizeof(char)*3);
    memset(pos, '\0', 3);
    int j=posY+1;

    if(selfCheckChecker(board, turn, posX, posY)){   //checks if moving the piece puts the king in check
        return;
    }

    for(int i=posX+1; i <8; i++){        //loops through the bottom right line until another piece is encountered
        char piece = *(board+(8*j)+i);
        if((j<8 && j>=0) && (turn != isupper(piece) || piece ==' ')){
            
                pos[0] = i +'0';
                pos[1] = j +'0';

                add(possibleList, pos);
            
            if(piece !=' '){
                break;
            }
        }else{
            break;
        }
        j++;
        
        
    }

    j=posY+1;

    for(int i=posX-1; i >=0; i--){               //loops through the bottom left line until another piece is encountered
        char piece = *(board+(8*j)+i);
        if((j<8 && j>=0) && (turn != isupper(piece) || piece ==' ')){
            
            pos[0] = i +'0';
            pos[1] = j +'0';

            add(possibleList, pos);
            
            if(piece !=' '){
                break;
            }
            
        }else{
            break;
        }
        j++;
        
    }

    j=posY-1;

    for(int i=posX+1; i <8; i++){        //loops through the top right line until another piece is encountered
        char piece = *(board+(8*j)+i);
        if((j<8 && j>=0) && (turn != isupper(piece) || piece ==' ')){
            
            pos[0] = i +'0';
            pos[1] = j +'0';

            add(possibleList, pos);
            
            if(piece !=' '){
                break;
            }
        }else{
            break;
        }
        j--;
        
    }


    j=posY-1;

    for(int i=posX-1; i >=0; i--){       //loops through the top left line until another piece is encountered
        
        char piece = *(board+(8*j)+i);
        if((j<8 && j>=0) && (turn != isupper(piece) || piece ==' ')){
            
            pos[0] = i +'0';
            pos[1] = j +'0';

            add(possibleList, pos);
            

            if(piece !=' '){
                break;
            }
        }else{
            break;
        }

        j--;
        
    }

    free(pos);
    
}



void rookMoves(char *board, bool turn, int posX, int posY, List possibleList){
    char *pos = malloc(sizeof(char)*3);
    memset(pos, '\0', 3);

    if(selfCheckChecker(board, turn, posX, posY)){   //checks if moving the piece puts the king in check
        return;
    }

    for(int i=posX+1; i <8; i++){            //loops through the right line until another piece is encountered
        char piece = *(board+(8*posY)+i);
        if((turn != isupper(piece)) || piece ==' '){
           
            pos[0] = i +'0';
            pos[1] = posY +'0';

            add(possibleList, pos);
            
            if(piece !=' '){
                break;
            }
        }else{
            break;
        }
        
        
    }

    for(int i=posX-1; i >=0; i--){         //loops through the left line until another piece is encountered
        char piece = *(board+(8*posY)+i); 
        if((turn != isupper(piece)) || piece ==' '){
            
            pos[0] = i +'0';
            pos[1] = posY +'0';

            add(possibleList, pos);
            
            if(piece !=' '){
                break;
            }
        }else{
            break;
        }
        
        
    }


    for(int i=posY+1; i <8; i++){                //loops through the bottom line until another piece is encountered
        char piece = *(board+(8*i)+posX);
        if((turn != isupper(piece)) || piece ==' '){
            
            pos[0] = posX +'0';
            pos[1] = i +'0';

            add(possibleList, pos);
            
            if(piece !=' '){
                break;
            }
        }else{
            break;
        }
        
        
    }


    for(int i=posY-1; i >=0; i--){                       //loops through the top right line until another piece is encountered
        char piece = *(board+(8*i)+posX);
        if((turn != isupper(piece)) || piece ==' '){
            
            pos[0] = posX +'0';
            pos[1] = i +'0';

            add(possibleList, pos);
            
            if(piece !=' '){
                break;
            }
        }else{
            break;
        }
        
        
    }


    free(pos);


}


void kingMoves(char *board, bool turn, int posX, int posY, List possibleList){
    char *pos = malloc(sizeof(char)*3);
    memset(pos, '\0', 3);

    char piece;
    char king = *(board+(8*posY)+posX);
    

    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){          //loops through all moves 1 square away
            if(posY+i>=0 && posY+i<=7 && posX+j>=0 && posX+j<=7){
                piece =*(board+(8*(posY+i))+posX+j);
                if(turn != isupper(piece) || piece==' '){
                    
                    *(board+(8*(posY+i))+posX+j)=king;  //makes the move
                    *(board+(8*posY)+posX)=' ';

                    if(!fullCheckChecker(board, turn, posX+j, posY+i)){  //if not put in check then add
                        pos[0] = (posX +j) +'0';
                        pos[1] = (posY +i) +'0';

                        add(possibleList, pos);
                    }
                    

                    *(board+(8*(posY+i))+posX+j)=piece;   //redoes the move
                    *(board+(8*posY)+posX)=king;
                    
                }
            }
                
        }
    }

    free(pos);
}


void rookCastleMoves(char *board, bool turn, int posX, int posY, List possibleList, bool* castlePointer){
    //checking if castling is possible
    if(turn){

        if(posX == 0 && posY == 7){
            if(*castlePointer && castleCheck(board, turn, 0, 4, 7)){
                printf("\nCastling is possible!");
            }
        }else if(posX == 7 && posY == 7){
            if(*castlePointer+1 && castleCheck(board, turn, 7, 4, 7)){
                printf("\nCastling is possible!");
            }
        }     
        
    }else{
        if(posX == 0 && posY == 0){
            if(*castlePointer+2 && castleCheck(board, turn, 0, 4, 0)){
                printf("\nCastling is possible!");
            }

        } else if(posX == 7 && posY == 0){
            if(*castlePointer+3 && castleCheck(board, turn, 7, 4, 0)){
                printf("\nCastling is possible!");
            }
        }
        
        
    }

}


void kingCastleMoves(char *board, bool turn, List possibleList, bool* castlePointer){
    //checking if castling is possible
    if(turn){      
        if(*castlePointer && castleCheck(board, turn, 0, 4, 7)){
            add(possibleList, "27");
            printf("\nCastling in Column A is possible!");
        }
        
        if(*(castlePointer+1) && castleCheck(board, turn, 7, 4, 7)){
            add(possibleList, "67");
            printf("\nCastling in Column H is possible!");
        }
    }else{
        if(*(castlePointer+2) && castleCheck(board, turn, 0, 4, 0)){
            add(possibleList, "20");
            printf("\nCastling in Column A is possible!");
        }
        
        if(*(castlePointer+3) && castleCheck(board, turn, 7, 4, 0)){
            add(possibleList, "60");
            printf("\nCastling in Column H is possible!");
        }
    }


}





void movesInCheck(char *board, bool turn, char piece, int posX, int posY, List possibleList){
  char ogPiece;
  int destinationX;
  int destinationY;

  char *pos = malloc(sizeof(char)*3);

  memset(pos, '\0', 3);
  findKing(board, turn, pos);

  int kingX = pos[0] -'0';
  int kingY = pos[1] -'0';


  if(*possibleList != NULL){
    int count=0;
    Node *node = *possibleList;
    Node *prev = *possibleList;


    while (node != NULL){  //loop through list
        
        destinationX = (node->val[0] - '0');    
        destinationY = (node->val[1] - '0') ;

        ogPiece = *(board+(8*destinationY)+destinationX);

        *(board+(8*destinationY)+destinationX)=piece; //temporary makes the move
        *(board+(8*posY)+posX)=' ';

        if(fullCheckChecker(board, turn, kingX, kingY)){

            if(count>0){  //remove value from list if still in check
                prev->next = node->next;
                node= node->next;
                
    
            }else{

                *possibleList = (*possibleList)->next;
                node = *possibleList;
                prev = *possibleList;
            }
            
        }else{
            prev = node;
            node = node->next;
            count++;
        }

        *(board+(8*destinationY)+destinationX)=ogPiece;  //puts the pieces back
        *(board+(8*posY)+posX)=piece;

        
    }
  }

    
}
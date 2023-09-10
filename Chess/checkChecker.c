#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "checkChecker.h"
#include "linkedList.h"
#include "viewMoves.h"


bool mateChecker(char *board, bool turn, bool checkptr){  //checks to see if board is in checkmate or stalemate
    char piece;

    List possibleList = malloc(sizeof(List));
  	*possibleList = NULL;

    for(int x=0; x < 8; x++) {  //loops through the board
		for(int y=0; y< 8; y++) {

            piece=*(board+(8*y)+x);
            
            if((turn == isupper(piece)) && piece != ' '){ //checks if piece is one of the same turn being changed
                
                getMoves(board, turn, piece, x, y, possibleList, checkptr);   //uses get moves to see all possible moves for the piece

                if(!isEmpty(possibleList)){   //if the possible moves is not empty then not in checkmate or stalemate
                    clearList(possibleList);
                    free(possibleList);
                    return false;
                }
            }
			
		}
	}

    free(possibleList);

    return true;
}


bool fullCheckChecker(char *board, bool turn, int x, int y){  //hard checks all possible ways the king could be in check
    
    if(knightCheckChecker(board, turn, x, y)){
        return true;
    }
    
    if(pawnCheckChecker(board, turn, x, y)){
        return true;
    }
    
    if(diagonalCheckChecker(board, turn, x, y, x, y)){
        return true;
    }
    
    if(lineCheckChecker(board, turn, x, y, x, y)){
        return true;
    }
    
    return false;
}


bool selfCheckChecker(char *board, bool turn, int x, int y){  //checks if moves themselves into check

    char *pos = malloc(sizeof(char)*3);

    memset(pos, '\0', 3);

    findKing(board, turn, pos);

    int kingX = pos[0] -'0';
    int kingY = pos[1] -'0';
    
    if(x==kingX || y==kingY){   //if piece is in line with the king then check the lines
        free(pos);
        return lineCheckChecker(board, turn, x, y, kingX, kingY);
    }

    if(abs((x-kingX)/(y-kingY))){  //if piece is diagonal with the king then check the lines
        free(pos);
        return diagonalCheckChecker(board, turn, x, y, kingX, kingY);
    }

    free(pos);
    return false;

}


bool opponentCheckChecker(char *board, bool turn, char piece, int originalX, int originalY, int newX, int newY){
    
    char *pos = malloc(sizeof(char)*3);

    memset(pos, '\0', 3);

    findKing(board, turn, pos);

    int kingX = pos[0] -'0';
    int kingY = pos[1] -'0';


    
    if(piece=='n' || piece == 'N'){   //special checks for knights and pawns
        if(knightCheckChecker(board, turn, kingX, kingY)){
            free(pos);
            return true;
        }
    }else if(piece=='p' || piece == 'P'){
        if(pawnCheckChecker(board, turn, kingX, kingY)){
            free(pos);
            return true;
        }
    }

    if(newX==kingX || newY==kingY){   //if piece is in line with the king then check the lines
        if(lineCheckChecker(board, turn, newX, newY, kingX, kingY)){
            free(pos);
            return true;
        }

    }else if(abs((newX-kingX)/(newY-kingY))){   //if piece was diagonal with the king then check the lines
        if(diagonalCheckChecker(board, turn, newX, newY, kingX, kingY)){
            free(pos);
            return true;
        }

    }

    if(originalX==kingX || originalY==kingY){ //if piece was in line with the king then check the lines
        if(lineCheckChecker(board, turn, originalX, originalY, kingX, kingY)){
            free(pos);
            return true;
        }

    }else if(abs((originalX-kingX)/(originalY-kingY))){   //if piece was diagonal with the king then check the lines
        if(diagonalCheckChecker(board, turn, originalX, originalY, kingX, kingY)){
            free(pos);
            return true;
        }

    }

    free(pos);
    return false;

}


bool lineCheckChecker(char *board, bool turn, int x, int y, int kingX, int kingY){
    char piece;
    if(x==kingX){
        for(int i=kingY+1; i<8; i++){  //loops through bottom line of the king and checks if a queen or a rook is there and if it is then return true
            piece = *(board+(8*i)+kingX);

            if((turn && (piece == 'q' || piece == 'r')) || ((!turn && (piece == 'Q' || piece == 'R')))){
                return true;
            }else if(piece != ' '){
                break;
            }
        }

        for(int i=kingY-1; i>=0; i--){    //loops through top line of the king and checks if a queen or a rook is there and if it is then return true
            piece = *(board+(8*i)+ kingX);

            if((turn && (piece == 'q' || piece == 'r')) || (!turn && (piece == 'Q' || piece == 'R'))){
                return true;
            }else if(piece != ' '){
                break;
            }
        }

    }
    
    if(y==kingY){
        for(int i=kingX+1; i<8; i++){   //loops through right line of the king and checks if a queen or a rook is there and if it is then return true
            piece = *(board+(8*kingY)+i);
            if((turn && (piece == 'q' || piece == 'r')) || (!turn && (piece == 'Q' || piece == 'R'))){
                    return true;
            }else if(piece != ' '){
                    break;
            }
         }

        for(int i=kingX-1; i>=0; i--){    //loops through left line of the king and checks if a queen or a rook is there and if it is then return true
            piece = *(board+(8*kingY)+i);
            if((turn && (piece == 'q' || piece == 'r')) || (!turn && (piece == 'Q' || piece == 'R'))){
                    return true;
            }else if(piece != ' '){
                    break;
            }
        }
    }
    
    return false;
 
}


bool diagonalCheckChecker(char *board, bool turn, int x, int y, int kingX, int kingY){
    char piece;
    int j;

    if(x>=kingX && y>=kingY){   
        j=kingY+1;

        for(int i=kingX+1; i <8; i++){ //loops through diagonal bottom-right of the king and checks if a queen or a bishop is there and if it is then return true
            piece = *(board+(8*j)+i);

            if(j<=7 && ((turn && (piece == 'q' || piece == 'b')) || (!turn && (piece == 'Q' || piece == 'B')))){
                return true;
            }else if(piece != ' ' || j>7){
                break;
            }

            j++;
        
        }

    }
    
    if(x<=kingX && y>=kingY){   

        j=kingY+1;

        for(int i=kingX-1; i >=0; i--){  //loops through diagonal bottom-left of the king and checks if a queen or a bishop is there and if it is then return true
            piece = *(board+(8*j)+i);

            if(j<=7 && ((turn && (piece == 'q' || piece == 'b')) || (!turn && (piece == 'Q' || piece == 'B')))){
                return true;
            }else if(piece != ' ' || j>7){
                break;
            }

            j++;
        
        }

    }
    
    
    if(x>=kingX && y<=kingY){
        j=kingY-1;

        for(int i=kingX+1; i <8; i++){  //loops through diagonal top-right of the king and checks if a queen or a bishop is there and if it is then return true
            piece = *(board+(8*j)+i);

            if(j>=0 && ((turn && (piece == 'q' || piece == 'b')) || (!turn && (piece == 'Q' || piece == 'B')))){
                return true;
            }else if(piece != ' ' || j<0){
                break;
            }

            j--;
        
        }
    }
    

    if(x<=kingX && y<=kingY){
        j=kingY-1;

        for(int i=kingX-1; i >=0; i--){  //loops through diagonal top-right of the king and checks if a queen or a bishop is there and if it is then return true
            piece = *(board+(8*j)+i);

            if(j>=0 && ( (turn && (piece == 'q' || piece == 'b')) || (!turn && (piece == 'Q' || piece == 'B')) ) ){
                return true;
            }else if(piece != ' ' || j<0){
                break;
            }

            j--;
        
        }
    }

    return false;
}



bool knightCheckChecker(char *board, bool turn, int x, int y){

    for(int i=-2; i<=2; i=i+4){   //loops through possible knights moves and returns true if in check
        for(int j=-1; j<=1; j=j+2){
            if(x+i>=0 && x+i<=7 && y+j>=0 && y+j<=7){
                
                if((*(board+(8*(y+j))+(x+i))=='n' && turn) || (*(board+(8*(y+j))+(x+i))=='N' && !turn)){
                    return true;
                }
                
            }

            if(x+j>=0 && x+j<=7 && y+i>=0 && y+i<=7){
                if((*(board+(8*(y+i))+(x+j))=='n' && turn) || (*(board+(8*(y+i))+(x+j))=='N' && !turn)){
                    return true;
                }
                
            }
        }
    }

    return false;
}


bool pawnCheckChecker(char *board, bool turn, int x, int y){ //checks if pawn puts king in check
    if(turn && y>0){  
        if(x>0 && *(board+(8*(y-1))+x-1) == 'p'){
            return true;
        }else if(x<7 && *(board+(8*(y-1))+x+1) == 'p'){
            return true;
        }
    }else if(!turn && y<7){
        if(x>0 && *(board+(8*(y+1))+x-1) == 'P'){
            return true;
        }else if(x<7 && *(board+(8*(y+1))+x+1) == 'P'){
            return true;
        }
    }

    return false;
}








void findKing(char* board, bool turn, char* pos){

    bool found=false;
    int kingY;
    int kingX;

    for (kingY=0; kingY < 8  && found == false; kingY++) { //loops through board until correct kings is found
		for (kingX=0; kingX < 8 && found == false; kingX++) {
            if((*(board+(8*kingY)+kingX) == 'K' && turn) || (*(board+(8*kingY)+kingX) == 'k' && !turn)){
                found=true;
            }
			
		}
	}
    kingX--;  //loop goes one too many
    kingY--;

    pos[0] = kingX +'0';
    pos[1] = kingY +'0';

}
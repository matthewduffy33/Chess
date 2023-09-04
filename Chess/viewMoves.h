#ifndef VIEWMOVES_H_INCLUDED
#define VIEWMOVES_H_INCLUDED

    #include "linkedList.h"

    void getMoves(char *board, bool turn, char piece, int posX, int posY, List possibleList, bool checkptr);

    void pawnMoves(char *board, bool turn, int posX, int posY, List possibleList);

    void knightMoves(char *board, bool turn, int posX, int posY, List possibleList);

    void bishopMoves(char *board, bool turn, int posX, int posY, List possibleList);

    void rookMoves(char *board, bool turn, int posX, int posY, List possibleList);
    
    void kingMoves(char *board, bool turn, int posX, int posY, List possibleList);

    void movesInCheck(char *board, bool turn, char piece, int posX, int posY, List possibleList);

#endif
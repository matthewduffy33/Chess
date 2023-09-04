#ifndef MAKE_MOVES_H_INCLUDED
#define MAKE_MOVES_H_INCLUDED

    bool checkMove(char *board, bool turn, char piece, int startX, int startY, int destinationX, int destinationY, bool *checkptr, List historyList);

    bool pawnCheck(char *board, bool turn, int startX, int startY, int destinationX, int destinationY);

    bool knightCheck(char *board, int startX, int startY, int destinationX, int destinationY);

    bool bishopCheck(char *board, int startX, int startY, int destinationX, int destinationY);

    bool rookCheck(char *board, int startX, int startY, int destinationX, int destinationY);

    bool queenCheck(char *board, int startX, int startY, int destinationX, int destinationY);

    bool kingCheck(char *board, int startX, int startY, int destinationX, int destinationY);

    bool castleCheck(char *board, bool turn, int rookX, int kingX, int y);

    void castleSet(bool turn, char piece, bool* castlingPointer, int x, int y);

    void doCastle(char* board, bool turn, char column, bool* castlePointer, List historyList);


#endif
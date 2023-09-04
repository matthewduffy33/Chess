#ifndef CHECK_CHECKER_H_INCLUDED
#define CHECK_CHECKER_H_INCLUDED

    bool mateChecker(char *board, bool turn, bool checkPtr);

    bool fullCheckChecker(char *board, bool turn, int x, int y);

    bool selfCheckChecker(char *board, bool turn, int x, int y);

    bool opponentCheckChecker(char *board, bool turn, char piece, int originalX, int originalY, int newX, int newY);



    bool lineCheckChecker(char *board, bool turn, int x, int y, int kingX, int kingY);

    bool diagonalCheckChecker(char *board, bool turn, int x, int y, int kingX, int kingY);

    bool knightCheckChecker(char *board, bool turn, int x, int y);

    bool pawnCheckChecker(char *board, bool turn, int x, int y);

    void findKing(char* board, bool turn, char* pos);

#endif
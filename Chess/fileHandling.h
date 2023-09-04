#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

    void saveHistory(char *historyFileName, List historyList);

    int loadHistory(char *historyFileName, List historyList);

    void saveBoard(char *boardFileName, char *board, int turnNum, bool whiteTurn, bool check, bool*castlingptr);

    bool loadBoard(char *boardFileName, char *board, int* turnNumPtr, bool* turnPtr, bool* checkPtr, bool*castlingptr);

    bool booleanReader(bool* ptr, int val);

#endif 
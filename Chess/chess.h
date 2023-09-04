#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

  void printGrid(char *board, bool turn);

  bool movePiece(char *board, bool turn, bool *castlingPointer, bool* checkptr, List historyList);
  
  void promoter(char *board, bool turn, int x, int y);

  void viewPiece(char *board, bool turn, bool *castlingPointer, bool *checkptr);

  bool castle(char *board, bool turn, bool* castlePointer, List historyList);

  void selectHistory(char *board, List historyList, int amountOfTurns, int turnNum, bool turn);

  void getHistory(char *board, List historyList, int num, int turnNum, bool currTurn);

  void histList(char *board, List historyList, int turnNum, bool currTurn);

#endif 
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../linkedList.h"
#include "../makeMoves.h"




//function for testing

bool listCompare(List list1, List list2){   
  if(*list1 != NULL){
      Node *node = *list1;
      Node *correctNode = *list2;

      while (node != NULL){
          ck_assert_str_eq(node->val, correctNode->val);
            
          

          if((node->next != NULL && correctNode->next == NULL) || (node->next == NULL && correctNode->next != NULL)){
            ck_assert(0);
            return false;
          }
          node = node->next;
          correctNode = correctNode->next;
          
      }
  }else{
    ck_assert(0);
    return false;
  }

  return true;
}


START_TEST (movePawnWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'P', 0, 6, 0, 5, checkptr, historyList));

    ck_assert(*(board + (8*6)) == ' ');
    ck_assert(*(board + (8*5)) == 'P');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 0 6 P moves 0 5");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);



}
END_TEST




START_TEST (takePawnWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {'P',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'P', 0, 2, 1, 1, checkptr, historyList));

    ck_assert(*(board + (8*2)) == ' ');
    ck_assert(*(board + (8*1)+1) == 'P');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 0 2 P takes 1 1 p");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST



START_TEST (movePawnBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'p', 0, 1, 0, 2, checkptr, historyList));

    ck_assert(*(board + (8*1)) == ' ');
    ck_assert(*(board + (8*2)) == 'p');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 0 1 p moves 0 2");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);
}
END_TEST




START_TEST (takePawnBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {' ','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'p',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'p', 0, 5, 1, 6, checkptr, historyList));

    ck_assert(*(board + (8*5)) == ' ');
    ck_assert(*(board + (8*6)+1) == 'p');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 0 5 p takes 1 6 P");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (moveKnightWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'N', 1, 7, 0, 5, checkptr, historyList));

    ck_assert(*(board + (8*7)+1) == ' ');
    ck_assert(*(board + (8*5)) == 'N');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 1 7 N moves 0 5");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (takeKnightWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','N',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R',' ','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'N', 1, 3, 0, 1, checkptr, historyList));

    ck_assert(*(board + (8*3)+1) == ' ');
    ck_assert(*(board + (8*1)) == 'N');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 1 3 N takes 0 1 p");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);
}
END_TEST



START_TEST (moveKnightBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'n', 1, 0, 0, 2, checkptr, historyList));

    ck_assert(*(board + 1) == ' ');
    ck_assert(*(board + (8*2)) == 'n');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 1 0 n moves 0 2");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);
}
END_TEST





START_TEST (takeKnightBlack)
{
  char chess[8][8] = {
            {'r',' ','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','n',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'n', 1, 4, 0, 6, checkptr, historyList));

    ck_assert(*(board + (8*4)+1) == ' ');
    ck_assert(*(board + (8*6)) == 'n');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 1 4 n takes 0 6 P");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);
}
END_TEST





START_TEST (moveBishopWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'B',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N',' ','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'B', 0, 4, 2, 2, checkptr, historyList));

    ck_assert(*(board + (8*4)) == ' ');
    ck_assert(*(board + (8*2)+2) == 'B');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 0 4 B moves 2 2");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST






START_TEST (takeBishopWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'B',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N',' ','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'B', 0, 4, 3, 1, checkptr, historyList));

    ck_assert(*(board + (8*4)) == ' ');
    ck_assert(*(board + (8*1)+3) == 'B');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 0 4 B takes 3 1 p");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST





START_TEST (moveBishopBlack)
{
  char chess[8][8] = {
            {'r','n',' ','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {'b',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'b', 0, 2, 3, 5, checkptr, historyList));

    ck_assert(*(board + (8*2)) == ' ');
    ck_assert(*(board + (8*5)+3) == 'b');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 0 2 b moves 3 5");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST






START_TEST (takeBishopBlack)
{
  char chess[8][8] = {
            {'r','n',' ','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {'b',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'b', 0, 2, 4, 6, checkptr, historyList));

    ck_assert(*(board + (8*2)) == ' ');
    ck_assert(*(board + (8*6)+4) == 'b');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 0 2 b takes 4 6 P");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST





START_TEST (moveRookWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P','P','P','P','P','P','P'},
            {' ','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'R', 0, 4, 7, 4, checkptr, historyList));

    ck_assert(*(board + (8*4)) == ' ');
    ck_assert(*(board + (8*4)+7) == 'R');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 0 4 R moves 7 4");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST





START_TEST (takeRookWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P','P','P','P','P','P','P'},
            {' ','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'R', 0, 4, 0, 1, checkptr, historyList));

    ck_assert(*(board + (8*4)) == ' ');
    ck_assert(*(board + (8*1)) == 'R');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 0 4 R takes 0 1 p");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST





START_TEST (moveRookBlack)
{
  char chess[8][8] = {
            {' ','n','b','q','k','b','n','r'},
            {' ','p','p','p','p','p','p','p'},
            {'r',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'r', 0, 2, 0, 5, checkptr, historyList));

    ck_assert(*(board + (8*2)) == ' ');
    ck_assert(*(board + (8*5)) == 'r');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 0 2 r moves 0 5");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST






START_TEST (takeRookBlack)
{
  char chess[8][8] = {
            {' ','n','b','q','k','b','n','r'},
            {' ','p','p','p','p','p','p','p'},
            {'r',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'r', 0, 2, 0, 6, checkptr, historyList));

    ck_assert(*(board + (8*2)) == ' ');
    ck_assert(*(board + (8*6)) == 'r');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 0 2 r takes 0 6 P");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (moveQueenWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P',' ','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'Q', 3, 7, 3, 3, checkptr, historyList));

    ck_assert(*(board + (8*7)+3) == ' ');
    ck_assert(*(board + (8*3)+3) == 'Q');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 3 7 Q moves 3 3");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST





START_TEST (takeQueenWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P',' ','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'Q', 3, 7, 3, 1, checkptr, historyList));

    ck_assert(*(board + (8*7)+3) == ' ');
    ck_assert(*(board + (8*1)+3) == 'Q');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 3 7 Q takes 3 1 p");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST





START_TEST (moveQueenBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'q', 3, 0, 3, 3, checkptr, historyList));

    ck_assert(*(board + 3) == ' ');
    ck_assert(*(board + (8*3)+3) == 'q');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 3 0 q moves 3 3");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST





START_TEST (takeQueenBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'q', 3, 0, 3, 6, checkptr, historyList));

    ck_assert(*(board + 3) == ' ');
    ck_assert(*(board + (8*6)+3) == 'q');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 3 0 q takes 3 6 P");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST



START_TEST (moveKingWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','K',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B','Q',' ','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'K', 4, 5, 4, 4, checkptr, historyList));

    ck_assert(*(board + (8*5)+4) == ' ');
    ck_assert(*(board + (8*4)+4) == 'K');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 4 5 K moves 4 4");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (takeKingWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','p',' ',' ',' '},
            {' ',' ',' ',' ','K',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B','Q',' ','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'K', 4, 5, 4, 4, checkptr, historyList));

    ck_assert(*(board + (8*5)+4) == ' ');
    ck_assert(*(board + (8*4)+4) == 'K');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 4 5 K takes 4 4 p");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (moveKingBlack)
{
  char chess[8][8] = {
            {'r','n','b','q',' ','b','n','r'},
            {'p','p','p','p',' ','p','p','p'},
            {' ',' ',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'k', 4, 2, 4, 3, checkptr, historyList));

    ck_assert(*(board + (8*2)+4) == ' ');
    ck_assert(*(board + (8*3)+4) == 'k');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 4 2 k moves 4 3");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (takeKingBlack)
{
  char chess[8][8] = {
            {'r','n','b','q',' ','b','n','r'},
            {'p','p','p','p',' ','p','p','p'},
            {' ',' ',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'k', 4, 2, 4, 3, checkptr, historyList));

    ck_assert(*(board + (8*2)+4) == ' ');
    ck_assert(*(board + (8*3)+4) == 'k');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 4 2 k takes 4 3 P");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (notTakeOwnPieceWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 1, 'K', 4, 7, 4, 6, checkptr, historyList));

    ck_assert(*(board + (8*6)+4) == 'P');
    ck_assert(*(board + (8*7)+4) == 'K');

    if(*historyList != NULL){
      ck_assert(0);
    }

    clearList(historyList);
    free(historyList);


}
END_TEST




START_TEST (notTakeOwnPieceBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 0, 'k', 4, 0, 4, 1, checkptr, historyList));

    ck_assert(*(board + (8*1)+4) == 'p');
    ck_assert(*(board + (8*0)+4) == 'k');

    if(*historyList != NULL){
      ck_assert(0);
    }

    clearList(historyList);
    free(historyList);


}
END_TEST




START_TEST (inCheckMoveOutCheckWhite)
{
  char chess[8][8] = {
            {'r','n','b',' ','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'Q', 3, 7, 4, 6, checkptr, historyList));

    ck_assert(*(board + (8*7)+3) == ' ');
    ck_assert(*(board + (8*6)+4) == 'Q');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 3 7 Q moves 4 6");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (inCheckMoveOutCheckBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p',' ','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','Q',' ',' ',' '},
            {'P','P','P',' ','P','P','P','P'},
            {'R','N','B',' ','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'q', 3, 0, 4, 1, checkptr, historyList));

    ck_assert(*(board + (8*0)+3) == ' ');
    ck_assert(*(board + (8*1)+4) == 'q');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 3 0 q moves 4 1");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (inCheckStillInCheckWhite)
{
  char chess[8][8] = {
            {'r','n','b',' ','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 1, 'K', 4, 7, 4, 6, checkptr, historyList));

    ck_assert(*(board + (8*7)+4) == 'K');
    ck_assert(*(board + (8*6)+4) == ' ');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);

}
END_TEST




START_TEST (inCheckStillInCheckBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p',' ','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','Q',' ',' ',' '},
            {'P','P','P',' ','P','P','P','P'},
            {'R','N','B',' ','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 0, 'k', 4, 0, 4, 1, checkptr, historyList));

    ck_assert(*(board + (8*0)+4) == 'k');
    ck_assert(*(board + (8*1)+4) == ' ');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);

}
END_TEST




START_TEST (notInCheckMoveInCheckWhite)
{
  char chess[8][8] = {
            {'r','n','b',' ','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','Q','P','P','P'},
            {'R','N','B',' ','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 1, 'Q', 4, 6, 3, 7, checkptr, historyList));

    ck_assert(*(board + (8*7)+3) == ' ');
    ck_assert(*(board + (8*6)+4) == 'Q');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);

}
END_TEST




START_TEST (notInCheckMoveInCheckBlack)
{
  char chess[8][8] = {
            {'r','n','b',' ','k','b','n','r'},
            {'p','p','p','p','q','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','Q',' ',' ',' '},
            {'P','P','P',' ','P','P','P','P'},
            {'R','N','B',' ','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 0, 'q', 4, 1, 3, 0, checkptr, historyList));

    ck_assert(*(board +3) == ' ');
    ck_assert(*(board + (8*1)+4) == 'q');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);

}
END_TEST



START_TEST (kingInCheckMoveOutCheckWhite)
{
  char chess[8][8] = {
            {'r','n','b',' ','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','K',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B','Q',' ','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 1, 'K', 4, 5, 3, 5, checkptr, historyList));

    ck_assert(*(board + (8*5)+4) == ' ');
    ck_assert(*(board + (8*5)+3) == 'K');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "1 4 5 K moves 3 5");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST



START_TEST (kingInCheckMoveOutCheckBlack)
{
  char chess[8][8] = {
            {'r','n','b','q',' ','b','n','r'},
            {'p','p','p','p',' ','p','p','p'},
            {' ',' ',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B',' ','Q','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(checkMove(board, 0, 'k', 4, 2, 3, 2, checkptr, historyList));

    ck_assert(*(board + (8*2)+4) == ' ');
    ck_assert(*(board + (8*2)+3) == 'k');

    ck_assert(!check);

    List correctList = malloc(sizeof(List));
    *correctList = NULL;

    add(correctList, "0 4 2 k moves 3 2");

    ck_assert(listCompare(historyList, correctList));

    clearList(historyList);
    free(historyList);

    clearList(correctList);
    free(correctList);

}
END_TEST



START_TEST (kingInCheckStillInCheckWhite)
{
  char chess[8][8] = {
            {'r','n','b',' ','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','K',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B','Q',' ','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 1, 'K', 4, 5, 4, 6, checkptr, historyList));

    ck_assert(*(board + (8*6)+4) == ' ');
    ck_assert(*(board + (8*5)+4) == 'K');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);


}
END_TEST





START_TEST (kingInCheckStillInCheckBlack)
{
  char chess[8][8] = {
            {'r','n','b','q',' ','b','n','r'},
            {'p','p','p','p',' ','p','p','p'},
            {' ',' ',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B',' ','Q','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 0, 'k', 4, 2, 4, 1, checkptr, historyList));

    ck_assert(*(board + (8*1)+4) == ' ');
    ck_assert(*(board + (8*2)+4) == 'k');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);


}
END_TEST





START_TEST (kingNotInCheckMoveInCheckWhite)
{
  char chess[8][8] = {
            {'r','n','b',' ','k','b','n','r'},
            {'p','p','p',' ','p','p','p','p'},
            {' ',' ',' ',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {'P','P','P','P',' ','P','P','P'},
            {'R','N','B','Q',' ','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 1, 'K', 3, 5, 4, 5, checkptr, historyList));

    ck_assert(*(board + (8*5)+4) == ' ');
    ck_assert(*(board + (8*5)+3) == 'K');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);

}
END_TEST




START_TEST (kingNotInCheckMoveInCheckBlack)
{
  char chess[8][8] = {
            {'r','n','b','q',' ','b','n','r'},
            {'p','p','p','p',' ','p','p','p'},
            {' ',' ',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P','P','P',' ','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];	

    List historyList = malloc(sizeof(List));
    *historyList = NULL;

    bool check=false;
    bool *checkptr = &check;

    ck_assert(!checkMove(board, 0, 'k', 4, 2, 3, 2, checkptr, historyList));

    ck_assert(*(board + (8*2)+3) == ' ');
    ck_assert(*(board + (8*2)+4) == 'k');

    if(*historyList != NULL){
      ck_assert(0);
    }

    ck_assert(!check);

    clearList(historyList);
    free(historyList);


}
END_TEST





Suite * check_move_suite(void){
  Suite *s;
  TCase *tc_core;
  s = suite_create("Chess");

  /* Core test case */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, movePawnWhite);
  tcase_add_test(tc_core, takePawnWhite);

  tcase_add_test(tc_core, movePawnBlack);
  tcase_add_test(tc_core, takePawnBlack);

  tcase_add_test(tc_core, moveKnightWhite);
  tcase_add_test(tc_core, takeKnightWhite);

  tcase_add_test(tc_core, moveKnightBlack);
  tcase_add_test(tc_core, takeKnightBlack);

  tcase_add_test(tc_core, moveBishopWhite);
  tcase_add_test(tc_core, takeBishopWhite);

  tcase_add_test(tc_core, moveBishopBlack);
  tcase_add_test(tc_core, takeBishopBlack);

  tcase_add_test(tc_core, moveRookWhite);
  tcase_add_test(tc_core, takeRookWhite);

  tcase_add_test(tc_core, moveRookBlack);
  tcase_add_test(tc_core, takeRookBlack);

  tcase_add_test(tc_core, moveQueenWhite);
  tcase_add_test(tc_core, takeQueenWhite);

  tcase_add_test(tc_core, moveQueenBlack);
  tcase_add_test(tc_core, takeQueenBlack);

  tcase_add_test(tc_core, moveKingWhite);
  tcase_add_test(tc_core, takeKingWhite);

  tcase_add_test(tc_core, moveKingBlack);
  tcase_add_test(tc_core, takeKingBlack);

  tcase_add_test(tc_core, notTakeOwnPieceWhite);
  tcase_add_test(tc_core, notTakeOwnPieceBlack);

  tcase_add_test(tc_core, inCheckMoveOutCheckWhite);
  tcase_add_test(tc_core, inCheckMoveOutCheckBlack);

  tcase_add_test(tc_core, inCheckStillInCheckWhite);
  tcase_add_test(tc_core, inCheckStillInCheckBlack);

  tcase_add_test(tc_core, notInCheckMoveInCheckWhite);
  tcase_add_test(tc_core, notInCheckMoveInCheckBlack);

  tcase_add_test(tc_core, kingInCheckMoveOutCheckWhite);
  tcase_add_test(tc_core, kingInCheckMoveOutCheckBlack);

  tcase_add_test(tc_core, kingInCheckStillInCheckWhite);
  tcase_add_test(tc_core, kingInCheckStillInCheckBlack);

  tcase_add_test(tc_core, kingNotInCheckMoveInCheckWhite);
  tcase_add_test(tc_core, kingNotInCheckMoveInCheckBlack);

  suite_add_tcase(s, tc_core);
  return s;
}


int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = check_move_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
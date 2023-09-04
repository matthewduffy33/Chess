#include <check.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../linkedList.h"
#include "../fileHandling.h"


bool listCompare(List list1, List list2){   //function for testing
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



START_TEST (boolReadInBounds)
{
  bool valid;
  bool *ptr =&valid;

  ck_assert(booleanReader(ptr, 1));
  ck_assert(valid == 1);

  ck_assert(booleanReader(ptr, 0));
  ck_assert(valid == 0);

}
END_TEST


START_TEST(boolReadOutOfBounds)
{
  bool valid;
  bool *ptr =&valid;

  ck_assert(!booleanReader(ptr, 2));

}
END_TEST

START_TEST (saveBoardTestNormal)
{
  char chess[8][8] = {
            {' ',' ',' ',' ','k',' ',' ','r'},
            {' ','p','p','p',' ',' ','p',' '},
            {' ','q',' ','N',' ',' ','b',' '},
            {'B',' ',' ','B',' ',' ',' ',' '},
            {' ',' ','P',' ',' ','P',' ',' '},
            {' ','P',' ',' ','n',' ',' ',' '},
            {' ',' ','R',' ',' ',' ','Q',' '},
            {' ','K',' ',' ',' ','R',' ',' '}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={true, true, true, true}; 
  bool *castlingPointer= &castlingAllowed[0];

  saveBoard("Files/testFile.txt", board, 10, 1, 0, castlingPointer);

  FILE *fp = fopen("Files/testFile.txt", "r");

  if (!fp) {
	  ck_assert(0);
  }

  char *line= malloc(sizeof(char) * 50);

  fgets(line, 51, fp);
  if((strcmp(line, "    k  r\n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, " ppp  p \n") != 0)){
    ck_assert(0);
  }


  fgets(line, 51, fp);
  if((strcmp(line, " q N  b \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "B  B    \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "  P  P  \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, " P  n   \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "  R   Q \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, " K   R  \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "10 1 0 1 1 1 1\n") != 0)){
    ck_assert(0);
  }

  if(fgets(line, 51, fp)!=NULL){
    ck_assert(0);
  }


}
END_TEST

START_TEST (saveBoardTestExtreme)
{
  char chess[8][8] = {
            {'r','B','p','k','k','p','Q','r'},
            {'P','p','p','p','R','B','p','Q'},
            {'P','q','n','N','q','q','b','r'},
            {'B','n','B','B','k','K','k','R'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={false}; 
  bool *castlingPointer= &castlingAllowed[0];

  saveBoard("Files/testFile.txt", board, 1000, 0, 1, castlingPointer);

  FILE *fp = fopen("Files/testFile.txt", "r");

  if (!fp) {
	  ck_assert(0);
  }

  char *line= malloc(sizeof(char) * 50);

  fgets(line, 51, fp);
  if((strcmp(line, "rBpkkpQr\n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "PpppRBpQ\n") != 0)){
    ck_assert(0);
  }


  fgets(line, 51, fp);
  if((strcmp(line, "PqnNqqbr\n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "BnBBkKkR\n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "        \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "        \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "        \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "        \n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "1000 0 1 0 0 0 0\n") != 0)){
    ck_assert(0);
  }

  if(fgets(line, 51, fp)!=NULL){
    ck_assert(0);
  }

}
END_TEST



START_TEST (loadBoardTestNormal)
{
  char chess[8][8] = {
            {' ',' ',' ',' ','k',' ',' ','r'},
            {' ','p','p','p',' ',' ','p',' '},
            {' ','q',' ','N',' ',' ','b',' '},
            {'B',' ',' ','B',' ',' ',' ',' '},
            {' ',' ','P',' ',' ','P',' ',' '},
            {' ','P',' ',' ','n',' ',' ',' '},
            {' ',' ','R',' ',' ',' ','Q',' '},
            {' ','K',' ',' ',' ','R',' ',' '}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={true, true, true, true}; 
  bool *castlingPointer= &castlingAllowed[0];

  saveBoard("Files/testFile.txt", board, 10, 1, 0, castlingPointer);


  char loadChess[8][8];
					
	char *loadedBoard= &loadChess[0][0];

  bool loadCastlingAllowed[4]={true, true, true, true}; 
  bool *loadCastlingPointer= &loadCastlingAllowed[0];

  bool whiteTurn;
  bool* turnPtr = &whiteTurn;

  int turnNum;
  int* numPtr = &turnNum;

  bool check=false;
  bool *checkptr = &check;

  ck_assert(loadBoard("Files/testFile.txt", loadedBoard, numPtr, turnPtr, checkptr, loadCastlingPointer));

  for(int x=0; x<8; x++){
    for(int y=0; y<8; y++){
      ck_assert(*(board+(8*y)+x) ==  *(loadedBoard+(8*y)+x));
    }
  }

  ck_assert_int_eq(turnNum, 9);//1 less to acount for a turn being added in loop
  ck_assert(!whiteTurn);
  ck_assert(!check);

  ck_assert(*(loadCastlingAllowed));
  ck_assert(*(loadCastlingAllowed+1));
  ck_assert(*(loadCastlingAllowed+2));
  ck_assert(*(loadCastlingAllowed+3));



}
END_TEST

START_TEST (loadBoardTestExtreme)
{
  char chess[8][8] = {
            {'r','B','p','k','k','p','Q','r'},
            {'P','p','p','p','R','B','p','Q'},
            {'P','q','n','N','q','q','b','r'},
            {'B','n','B','B','k','K','k','R'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={false}; 
  bool *castlingPointer= &castlingAllowed[0];

  saveBoard("Files/testFile.txt", board, 1000, 0, 1, castlingPointer);


  char loadChess[8][8];
					
	char *loadedBoard= &loadChess[0][0];

  bool loadCastlingAllowed[4]={true, true, true, true}; 
  bool *loadCastlingPointer= &loadCastlingAllowed[0];

  bool whiteTurn;
  bool* turnPtr = &whiteTurn;

  int turnNum;
  int* numPtr = &turnNum;

  bool check=false;
  bool *checkptr = &check;

  ck_assert(loadBoard("Files/testFile.txt", loadedBoard, numPtr, turnPtr, checkptr, loadCastlingPointer));

  for(int x=0; x<8; x++){
    for(int y=0; y<8; y++){
      ck_assert(*(board+(8*y)+x) ==  *(loadedBoard+(8*y)+x));
    }
  }

  ck_assert_int_eq(turnNum, 1000);
  ck_assert(whiteTurn);
  ck_assert(check);

  ck_assert(!*(loadCastlingAllowed));
  ck_assert(!*(loadCastlingAllowed+1));
  ck_assert(!*(loadCastlingAllowed+2));
  ck_assert(!*(loadCastlingAllowed+3));



}
END_TEST

START_TEST (loadBoardTestNothing)
{
  fopen("Files/testFile.txt", "w"); //resets file


  char loadChess[8][8];
					
	char *loadedBoard= &loadChess[0][0];

  bool loadCastlingAllowed[4]={true, true, true, true}; 
  bool *loadCastlingPointer= &loadCastlingAllowed[0];

  bool whiteTurn;
  bool* turnPtr = &whiteTurn;

  int turnNum;
  int* numPtr = &turnNum;

  bool check=false;
  bool *checkptr = &check;

  ck_assert(!loadBoard("Files/testFile.txt", loadedBoard, numPtr, turnPtr, checkptr, loadCastlingPointer));


}
END_TEST

START_TEST (loadBoardTestNotValid)
{
 
  fprintf(fopen("Files/testFile.txt", "w"), "%s\n", "not valid");

  char loadChess[8][8];
					
	char *loadedBoard= &loadChess[0][0];

  bool loadCastlingAllowed[4]={true, true, true, true}; 
  bool *loadCastlingPointer= &loadCastlingAllowed[0];

  bool whiteTurn;
  bool* turnPtr = &whiteTurn;

  int turnNum;
  int* numPtr = &turnNum;

  bool check=false;
  bool *checkptr = &check;

  ck_assert(!loadBoard("Files/testFile.txt", loadedBoard, numPtr, turnPtr, checkptr, loadCastlingPointer));


}
END_TEST


START_TEST (saveHistoryNone)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;


  saveHistory("Files/testFile.txt", historyList);

  FILE *fp = fopen("Files/testFile.txt", "r");

  if (!fp) {
	  ck_assert(0);
  }

  char *line= malloc(sizeof(char) * 50);

  if(fgets(line, 51, fp)!=NULL){
    ck_assert(0);
  }



}
END_TEST



START_TEST (saveHistoryOne)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "abcdefghijkl");

  saveHistory("Files/testFile.txt", historyList);

  FILE *fp = fopen("Files/testFile.txt", "r");

  if (!fp) {
	  ck_assert(0);
  }

  char *line= malloc(sizeof(char) * 50);

  fgets(line, 51, fp);
  if((strcmp(line, "abcdefghijkl\n") != 0)){
    ck_assert(0);
  }


  if(fgets(line, 51, fp)!=NULL){
    ck_assert(0);
  }



}
END_TEST

START_TEST (saveHistoryNormal)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "ab");
  add(historyList, "cd");
  add(historyList, "ef");
  add(historyList, "gh");

  saveHistory("Files/testFile.txt", historyList);

  FILE *fp = fopen("Files/testFile.txt", "r");

  if (!fp) {
	  ck_assert(0);
  }

  char *line= malloc(sizeof(char) * 50);

  fgets(line, 51, fp);
  if((strcmp(line, "ab\n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "cd\n") != 0)){
    ck_assert(0);
  }


  fgets(line, 51, fp);
  if((strcmp(line, "ef\n") != 0)){
    ck_assert(0);
  }

  fgets(line, 51, fp);
  if((strcmp(line, "gh\n") != 0)){
    ck_assert(0);
  }

  if(fgets(line, 51, fp)!=NULL){
    ck_assert(0);
  }



}
END_TEST

START_TEST (loadHistoryTestNone)
{
  fopen("Files/testFile.txt", "w");


  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 0);

  if(*loadedList != NULL){
    ck_assert(0);
  }



}
END_TEST


START_TEST (loadHistoryTestOne)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "0 0 1 p moves 0 2");

  saveHistory("Files/testFile.txt", historyList);

  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 1);

  ck_assert(listCompare(loadedList, historyList));


}
END_TEST




START_TEST (loadHistoryTestNormal)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "0 0 1 p moves 0 2");
  add(historyList, "1 2 4 R moves 2 7");
  add(historyList, "0 0 3 q takes 0 6 P");
  add(historyList, "1 3 4 R takes 6 4 p");
  add(historyList, "1 4 7 K castle 2 7");
  add(historyList, "0 4 0 k castle 2 0");

  saveHistory("Files/testFile.txt", historyList);

  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 6);

  ck_assert(listCompare(historyList, loadedList));



}
END_TEST


START_TEST (loadHistoryTestExceptionNotTurn)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "3 0 1 p moves 0 2");

  saveHistory("Files/testFile.txt", historyList);

  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 0);

  if(*loadedList != NULL){
    ck_assert(0);
  }



}
END_TEST

START_TEST (loadHistoryTestExceptionNotInRange)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "0 9 1 p moves 0 2");

  saveHistory("Files/testFile.txt", historyList);

  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 0);

  if(*loadedList != NULL){
    ck_assert(0);
  }



}
END_TEST

START_TEST (loadHistoryTestExceptionNotPiece)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "1 0 1 S moves 0 2");

  saveHistory("Files/testFile.txt", historyList);

  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 0);

  if(*loadedList != NULL){
    ck_assert(0);
  }



}
END_TEST

START_TEST (loadHistoryTestExceptionNotType)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "1 0 1 p type 0 2");

  saveHistory("Files/testFile.txt", historyList);

  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 0);

  if(*loadedList != NULL){
    ck_assert(0);
  }



}
END_TEST

START_TEST (loadHistoryTestExceptionNoTakenPiece)
{
  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  add(historyList, "1 0 1 p takes 0 2");

  saveHistory("Files/testFile.txt", historyList);

  List loadedList = malloc(sizeof(List));
  *loadedList=NULL;

  ck_assert_int_eq(loadHistory("Files/testFile.txt", loadedList), 0);

  if(*loadedList != NULL){
    ck_assert(0);
  }



}
END_TEST


Suite * file_suite(void){
  Suite *s;
  TCase *tc_core;
  s = suite_create("Chess");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, boolReadInBounds);
  tcase_add_test(tc_core, boolReadOutOfBounds);

  tcase_add_test(tc_core, saveBoardTestNormal);
  tcase_add_test(tc_core, saveBoardTestExtreme);

  tcase_add_test(tc_core, loadBoardTestNormal);
  tcase_add_test(tc_core, loadBoardTestExtreme);

  tcase_add_test(tc_core, loadBoardTestNothing);
  tcase_add_test(tc_core, loadBoardTestNotValid);

  tcase_add_test(tc_core, saveHistoryNone);
  tcase_add_test(tc_core, saveHistoryOne);
  tcase_add_test(tc_core, saveHistoryNormal);

  tcase_add_test(tc_core, loadHistoryTestNone);
  tcase_add_test(tc_core, loadHistoryTestOne);
  tcase_add_test(tc_core, loadHistoryTestNormal);

  tcase_add_test(tc_core, loadHistoryTestExceptionNotTurn);
  tcase_add_test(tc_core, loadHistoryTestExceptionNotInRange);
  tcase_add_test(tc_core, loadHistoryTestExceptionNotType);
  tcase_add_test(tc_core, loadHistoryTestExceptionNotPiece);
  tcase_add_test(tc_core, loadHistoryTestExceptionNoTakenPiece);

  suite_add_tcase(s, tc_core);
  return s;
}


int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = file_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
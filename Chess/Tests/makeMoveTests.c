#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../linkedList.h"
#include "../makeMoves.h"




START_TEST (pawnMoveWhite)
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

  ck_assert(pawnCheck(board, 1, 1, 6, 1, 4)); //going forward 2 spaces

  ck_assert(!pawnCheck(board, 1, 1, 4, 1, 5)); //not going back 1 space

  ck_assert(!pawnCheck(board, 1, 1, 4, 1, 2)); //not going forward 2 spaces later

  ck_assert(!pawnCheck(board, 1, 1, 4, 0, 3)); //not going diagonal when nothing is there

  ck_assert(!pawnCheck(board, 1, 1, 4, 2, 3));

  ck_assert(!pawnCheck(board, 1, 1, 4, 1, 5)); //going 1 space forward


}
END_TEST

START_TEST (pawnTakeWhite)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ','P',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'P',' ','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];

  ck_assert(pawnCheck(board, 1, 1, 2, 0, 1));  // going diagonal

  ck_assert(!pawnCheck(board, 1, 0, 1, 0, 0)); // not going straight to take

  ck_assert(pawnCheck(board, 1, 0, 1, 1, 0)); // going diagonal
  
}
END_TEST


START_TEST (pawnMoveBlack)
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

  ck_assert(pawnCheck(board, 0, 1, 1, 1, 3));

  ck_assert(!pawnCheck(board, 0, 1, 3, 1, 2));

  ck_assert(!pawnCheck(board, 0, 1, 4, 0, 5));

  ck_assert(!pawnCheck(board, 0, 1, 4, 2, 5));

  ck_assert(!pawnCheck(board, 1, 1, 4, 0, 5));

  ck_assert(!pawnCheck(board, 1, 1, 4, 1, 5));
}
END_TEST


START_TEST (pawnTakeBlack)
{
  char chess[8][8] = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ',' ',' ',' '},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}};
					
	char *board= &chess[0][0];

  ck_assert(pawnCheck(board, 0, 1, 5, 0, 6));

  ck_assert(!pawnCheck(board, 0, 0, 6, 0, 7));

  ck_assert(pawnCheck(board, 0, 0, 6, 1, 7));
  
}
END_TEST

START_TEST (kingValidMoveWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ','p',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(kingCheck(board, 3, 4, 3, 3)); 

  ck_assert(kingCheck(board, 3, 3, 3, 4)); 

  ck_assert(kingCheck(board, 3, 4, 2, 4)); 

  ck_assert(kingCheck(board, 3, 4, 3, 4)); 

  ck_assert(kingCheck(board, 3, 4, 2, 5)); 

  ck_assert(kingCheck(board, 2, 5, 3, 4)); 

  ck_assert(kingCheck(board, 3, 4, 4, 5)); 

  ck_assert(kingCheck(board, 3, 4, 4, 5)); 

}
END_TEST

START_TEST (kingNotValidMoveWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ','p',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!kingCheck(board, 3, 4, 3, 2)); 

  ck_assert(!kingCheck(board, 3, 4, 3, 0)); 

  ck_assert(!kingCheck(board, 3, 4, 1, 4)); 

  ck_assert(!kingCheck(board, 3, 4, 5, 4)); 

  ck_assert(!kingCheck(board, 3, 4, 1, 2)); 

  ck_assert(!kingCheck(board, 3, 4, 5, 6)); 

  ck_assert(!kingCheck(board, 3, 4, 1, 6)); 

  ck_assert(!kingCheck(board, 3, 4, 5, 2)); 

}
END_TEST


START_TEST (kingValidMoveBlack)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(kingCheck(board, 3, 4, 3, 3)); 

  ck_assert(kingCheck(board, 3, 3, 3, 4)); 

  ck_assert(kingCheck(board, 3, 4, 2, 4)); 

  ck_assert(kingCheck(board, 3, 4, 3, 4)); 

  ck_assert(kingCheck(board, 3, 4, 2, 5)); 

  ck_assert(kingCheck(board, 2, 5, 3, 4)); 

  ck_assert(kingCheck(board, 3, 4, 4, 5)); 

  ck_assert(kingCheck(board, 3, 4, 4, 5)); 

}
END_TEST

START_TEST (kingNotValidMoveBlack)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!kingCheck(board, 3, 4, 3, 2)); 

  ck_assert(!kingCheck(board, 3, 4, 3, 0)); 

  ck_assert(!kingCheck(board, 3, 4, 1, 4)); 

  ck_assert(!kingCheck(board, 3, 4, 5, 4)); 

  ck_assert(!kingCheck(board, 3, 4, 1, 2)); 

  ck_assert(!kingCheck(board, 3, 4, 5, 6)); 

  ck_assert(!kingCheck(board, 3, 4, 1, 6)); 

  ck_assert(!kingCheck(board, 3, 4, 5, 2)); 

}
END_TEST


START_TEST (knightMoveWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p','p','p',' ',' ',' '},
            {' ',' ','p','N','p',' ',' ',' '},
            {' ',' ','p','p','p',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(knightCheck(board, 3, 4, 2, 2));
  ck_assert(knightCheck(board, 2, 2, 3, 4)); 

  ck_assert(knightCheck(board, 3, 4, 4, 2));
  ck_assert(knightCheck(board, 4, 2, 3, 4)); 

  ck_assert(knightCheck(board, 3, 4, 1, 3));
  ck_assert(knightCheck(board, 1, 3, 3, 4)); 

  ck_assert(knightCheck(board, 3, 4, 1, 5));
  ck_assert(knightCheck(board, 1, 5, 3, 4)); 

}
END_TEST

START_TEST (knightMoveBlack)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','P','P','P',' ',' ',' '},
            {' ',' ','P','n','P',' ',' ',' '},
            {' ',' ','P','P','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(knightCheck(board, 3, 4, 2, 2));
  ck_assert(knightCheck(board, 2, 2, 3, 4)); 

  ck_assert(knightCheck(board, 3, 4, 4, 2));
  ck_assert(knightCheck(board, 4, 2, 3, 4)); 

  ck_assert(knightCheck(board, 3, 4, 1, 3));
  ck_assert(knightCheck(board, 1, 3, 3, 4)); 

  ck_assert(knightCheck(board, 3, 4, 1, 5));
  ck_assert(knightCheck(board, 1, 5, 3, 4)); 

}
END_TEST



START_TEST (rookMoveWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ','R',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!rookCheck(board, 3, 4, 0, 4));
  ck_assert(rookCheck(board, 3, 4, 2, 4));
  ck_assert(rookCheck(board, 3, 4, 1, 4));

  ck_assert(!rookCheck(board, 3, 4, 3, 7));
  ck_assert(rookCheck(board, 3, 4, 3, 6));
  ck_assert(rookCheck(board, 3, 4, 3, 5));

  ck_assert(!rookCheck(board, 3, 4, 7, 4));
  ck_assert(rookCheck(board, 3, 4, 5, 4));
  ck_assert(rookCheck(board, 3, 4, 6, 4));

  ck_assert(!rookCheck(board, 3, 4, 3, 0));
  ck_assert(rookCheck(board, 3, 4, 3, 2));
  ck_assert(rookCheck(board, 3, 4, 3, 1));
}
END_TEST



START_TEST (rookMoveBlack)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','r',' ',' ','P',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!rookCheck(board, 3, 4, 0, 4));
  ck_assert(rookCheck(board, 3, 4, 2, 4));
  ck_assert(rookCheck(board, 3, 4, 1, 4));

  ck_assert(!rookCheck(board, 3, 4, 3, 7));
  ck_assert(rookCheck(board, 3, 4, 3, 6));
  ck_assert(rookCheck(board, 3, 4, 3, 5));

  ck_assert(!rookCheck(board, 3, 4, 7, 4));
  ck_assert(rookCheck(board, 3, 4, 5, 4));
  ck_assert(rookCheck(board, 3, 4, 6, 4));

  ck_assert(!rookCheck(board, 3, 4, 3, 0));
  ck_assert(rookCheck(board, 3, 4, 3, 2));
  ck_assert(rookCheck(board, 3, 4, 3, 1));
}
END_TEST


START_TEST (bishopMoveWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','B',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!bishopCheck(board, 3, 4, 0, 7));
  ck_assert(bishopCheck(board, 3, 4, 1, 6));
  ck_assert(bishopCheck(board, 3, 4, 2, 5));

  ck_assert(!bishopCheck(board, 3, 4, 7, 0));
  ck_assert(bishopCheck(board, 3, 4, 5, 2));
  ck_assert(bishopCheck(board, 3, 4, 4, 3));

  ck_assert(!bishopCheck(board, 3, 4, 0, 1));
  ck_assert(bishopCheck(board, 3, 4, 1, 2));
  ck_assert(bishopCheck(board, 3, 4, 2, 3));

  ck_assert(!bishopCheck(board, 3, 4, 6, 7));
  ck_assert(bishopCheck(board, 3, 4, 5, 6));
  ck_assert(bishopCheck(board, 3, 4, 4, 5));
}
END_TEST



START_TEST (bishopMoveBlack)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','b',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!bishopCheck(board, 3, 4, 0, 7));
  ck_assert(bishopCheck(board, 3, 4, 1, 6));
  ck_assert(bishopCheck(board, 3, 4, 2, 5));

  ck_assert(!bishopCheck(board, 3, 4, 7, 0));
  ck_assert(bishopCheck(board, 3, 4, 5, 2));
  ck_assert(bishopCheck(board, 3, 4, 4, 3));

  ck_assert(!bishopCheck(board, 3, 4, 0, 1));
  ck_assert(bishopCheck(board, 3, 4, 1, 2));
  ck_assert(bishopCheck(board, 3, 4, 2, 3));

  ck_assert(!bishopCheck(board, 3, 4, 6, 7));
  ck_assert(bishopCheck(board, 3, 4, 5, 6));
  ck_assert(bishopCheck(board, 3, 4, 4, 5));
}
END_TEST

START_TEST (queenMoveWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ','B',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ','p',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!queenCheck(board, 3, 4, 0, 7));
  ck_assert(queenCheck(board, 3, 4, 1, 6));
  ck_assert(queenCheck(board, 3, 4, 2, 5));

  ck_assert(!queenCheck(board, 3, 4, 7, 0));
  ck_assert(queenCheck(board, 3, 4, 5, 2));
  ck_assert(queenCheck(board, 3, 4, 4, 3));

  ck_assert(!queenCheck(board, 3, 4, 0, 1));
  ck_assert(queenCheck(board, 3, 4, 1, 2));
  ck_assert(queenCheck(board, 3, 4, 2, 3));

  ck_assert(!queenCheck(board, 3, 4, 6, 7));
  ck_assert(queenCheck(board, 3, 4, 5, 6));
  ck_assert(queenCheck(board, 3, 4, 4, 5));

  ck_assert(!queenCheck(board, 3, 4, 0, 4));
  ck_assert(queenCheck(board, 3, 4, 2, 4));
  ck_assert(queenCheck(board, 3, 4, 1, 4));

  ck_assert(!queenCheck(board, 3, 4, 3, 7));
  ck_assert(queenCheck(board, 3, 4, 3, 6));
  ck_assert(queenCheck(board, 3, 4, 3, 5));

  ck_assert(!queenCheck(board, 3, 4, 7, 4));
  ck_assert(queenCheck(board, 3, 4, 5, 4));
  ck_assert(queenCheck(board, 3, 4, 6, 4));

  ck_assert(!queenCheck(board, 3, 4, 3, 0));
  ck_assert(queenCheck(board, 3, 4, 3, 2));
  ck_assert(queenCheck(board, 3, 4, 3, 1));
}
END_TEST


START_TEST (queenMoveBlack)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','b',' ',' ','P',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','P',' ','P',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!queenCheck(board, 3, 4, 0, 7));
  ck_assert(queenCheck(board, 3, 4, 1, 6));
  ck_assert(queenCheck(board, 3, 4, 2, 5));

  ck_assert(!queenCheck(board, 3, 4, 7, 0));
  ck_assert(queenCheck(board, 3, 4, 5, 2));
  ck_assert(queenCheck(board, 3, 4, 4, 3));

  ck_assert(!queenCheck(board, 3, 4, 0, 1));
  ck_assert(queenCheck(board, 3, 4, 1, 2));
  ck_assert(queenCheck(board, 3, 4, 2, 3));

  ck_assert(!queenCheck(board, 3, 4, 6, 7));
  ck_assert(queenCheck(board, 3, 4, 5, 6));
  ck_assert(queenCheck(board, 3, 4, 4, 5));

  ck_assert(!queenCheck(board, 3, 4, 0, 4));
  ck_assert(queenCheck(board, 3, 4, 2, 4));
  ck_assert(queenCheck(board, 3, 4, 1, 4));

  ck_assert(!queenCheck(board, 3, 4, 3, 7));
  ck_assert(queenCheck(board, 3, 4, 3, 6));
  ck_assert(queenCheck(board, 3, 4, 3, 5));

  ck_assert(!queenCheck(board, 3, 4, 7, 4));
  ck_assert(queenCheck(board, 3, 4, 5, 4));
  ck_assert(queenCheck(board, 3, 4, 6, 4));

  ck_assert(!queenCheck(board, 3, 4, 3, 0));
  ck_assert(queenCheck(board, 3, 4, 3, 2));
  ck_assert(queenCheck(board, 3, 4, 3, 1));
}
END_TEST


//castling tests
START_TEST (castleSetWhiteLeft)
{
  
  bool castlingAllowed[4]={true, true, true, true}; 

  bool *castlingPointer= &castlingAllowed[0];

  castleSet(1, 'R', castlingPointer, 0, 7);


  ck_assert(!*(castlingPointer+0));
  ck_assert(*(castlingPointer+1));
  ck_assert(*(castlingPointer+2));
  ck_assert(*(castlingPointer+3));

  *castlingPointer=NULL;

}  
END_TEST

START_TEST (castleSetBlackLeft)
{

  bool castlingAllowed[4]={true, true, true, true}; 

  bool *castlingPointer= &castlingAllowed[0];

  castleSet(0, 'r', castlingPointer, 0, 0);

  ck_assert(*(castlingPointer+0));
  ck_assert(*(castlingPointer+1));
  ck_assert(!*(castlingPointer+2));
  ck_assert(*(castlingPointer+3));
  

}  
END_TEST



START_TEST (castleSetWhiteRight)
{
  
  bool castlingAllowed[4]={true, true, true, true}; 

  bool *castlingPointer= &castlingAllowed[0];

  castleSet(1, 'R', castlingPointer, 7, 7);


  ck_assert(*(castlingPointer+0));
  ck_assert(!*(castlingPointer+1));
  ck_assert(*(castlingPointer+2));
  ck_assert(*(castlingPointer+3));

  *castlingPointer=NULL;

}  
END_TEST

START_TEST (castleSetBlackRight)
{

  bool castlingAllowed[4]={true, true, true, true}; 

  bool *castlingPointer= &castlingAllowed[0];

  castleSet(0, 'r', castlingPointer, 7, 0);

  ck_assert(*(castlingPointer+0));
  ck_assert(*(castlingPointer+1));
  ck_assert(*(castlingPointer+2));
  ck_assert(!*(castlingPointer+3));
  

}  
END_TEST

START_TEST (castleSetWhiteKing)
{

  bool castlingAllowed[4]={true, true, true, true}; 

  bool *castlingPointer= &castlingAllowed[0];

  castleSet(1, 'K', castlingPointer, 7, 0);

  ck_assert(!*(castlingPointer+0));
  ck_assert(!*(castlingPointer+1));
  ck_assert(*(castlingPointer+2));
  ck_assert(*(castlingPointer+3));
  

}  
END_TEST


START_TEST (castleSetBlackKing)
{

  bool castlingAllowed[4]={true, true, true, true}; 

  bool *castlingPointer= &castlingAllowed[0];

  castleSet(0, 'k', castlingPointer, 7, 0);

  ck_assert(*(castlingPointer+0));
  ck_assert(*(castlingPointer+1));
  ck_assert(!*(castlingPointer+2));
  ck_assert(!*(castlingPointer+3));
  

}  
END_TEST


START_TEST (castleLeftWhiteBlocked)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R','N',' ',' ','K',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 1, 0, 4, 7));
}
END_TEST


START_TEST (castleLeftBlackBlocked)
{
  char chess[8][8] = {
            {'r','n',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 0, 0, 4, 0));
}
END_TEST


START_TEST (castleRightWhiteBlocked)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','K',' ','N','R'}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 1, 7, 4, 7));
}
END_TEST

START_TEST (castleRightBlackBlocked)
{
  char chess[8][8] = {
            {' ',' ',' ',' ','k',' ','n','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 0, 7, 4, 0));
}
END_TEST


START_TEST (castleLeftWhiteCheck)
{
  char chess[8][8] = {
            {' ',' ',' ','r',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ','K',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 1, 0, 4, 7));

  *(board+3) = ' ';
  *(board+2) = 'r';

  ck_assert(!castleCheck(board, 1, 0, 4, 7));

  *(board+2) = ' ';
  *(board+1) = 'r';

  ck_assert(castleCheck(board, 1, 0, 4, 7));

}
END_TEST


START_TEST (castleLeftBlackCheck)
{
  char chess[8][8] = {
            {'r',' ',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','R',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 0, 0, 4, 0));

  *(board+(8*7)+3) = ' ';
  *(board+(8*7)+2) = 'R';

  ck_assert(!castleCheck(board, 0, 0, 4, 0));

  *(board+(8*7)+2) = ' ';
  *(board+(8*7)+1) = 'R';

  ck_assert(castleCheck(board, 0, 0, 4, 0));


}
END_TEST



START_TEST (castleRightWhiteCheck)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ','r',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','K',' ',' ','R'}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 1, 7, 4, 7));

  *(board+5) = ' ';
  *(board+6) = 'r';

  ck_assert(!castleCheck(board, 1, 7, 4, 7));

  *(board+6) = ' ';
  *(board+7) = 'r';

  ck_assert(castleCheck(board, 1, 7, 4, 7));

}
END_TEST


START_TEST (castleRightBlackCheck)
{
  char chess[8][8] = {
            {' ',' ',' ',' ','k',' ',' ','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ','R',' ',' '}};
					
	char *board= &chess[0][0];

  ck_assert(!castleCheck(board, 0, 7, 4, 0));

  *(board+(8*7)+5) = ' ';
  *(board+(8*7)+6) = 'R';

  ck_assert(!castleCheck(board, 0, 7, 4, 0));

  *(board+(8*7)+6) = ' ';
  *(board+(8*7)+7) = 'R';

  ck_assert(castleCheck(board, 0, 7, 4, 0));


}
END_TEST



START_TEST (doCastleLeftWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ','K',' ',' ',' '}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={true, true, true, true}; 
  bool *castlingPointer= &castlingAllowed[0];

  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  doCastle(board, 1, 'A', castlingPointer, historyList);

  ck_assert(*(board + (8*7)) == ' ');
  ck_assert(*(board + (8*7)+1) == ' ');
  ck_assert(*(board + (8*7)+2) == 'K');
  ck_assert(*(board + (8*7)+3) == 'R');
  ck_assert(*(board + (8*7)+4) == ' ');

  ck_assert(!*(castlingPointer));
  ck_assert(!*(castlingPointer + 1));

  clearList(historyList);
  free(historyList);

}
END_TEST


START_TEST (doCastleLeftBlack)
{
  char chess[8][8] = {
            {'r',' ',' ',' ','k',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={true, true, true, true}; 
  bool *castlingPointer= &castlingAllowed[0];

  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  doCastle(board, 0, 'A', castlingPointer, historyList);

  ck_assert(*(board) == ' ');
  ck_assert(*(board+1) == ' ');
  ck_assert(*(board + 2) == 'k');
  ck_assert(*(board + 3) == 'r');
  ck_assert(*(board + 4) == ' ');

  ck_assert(!*(castlingPointer + 2));
  ck_assert(!*(castlingPointer + 3));

  clearList(historyList);
  free(historyList);

}
END_TEST



START_TEST (doCastleRightWhite)
{
  char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','K',' ',' ','R'}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={true, true, true, true}; 
  bool *castlingPointer= &castlingAllowed[0];

  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  doCastle(board, 1, 'F', castlingPointer, historyList);

  ck_assert(*(board + (8*7)+7) == ' ');
  ck_assert(*(board + (8*7)+6) == 'K');
  ck_assert(*(board + (8*7)+5) == 'R');
  ck_assert(*(board + (8*7)+4) == ' ');

  ck_assert(!*(castlingPointer));
  ck_assert(!*(castlingPointer + 1));

  clearList(historyList);
  free(historyList);
}
END_TEST


START_TEST (doCastleRightBlack)
{
  char chess[8][8] = {
            {' ',' ',' ',' ','k',' ',' ','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];

  bool castlingAllowed[4]={true, true, true, true}; 
  bool *castlingPointer= &castlingAllowed[0];

  List historyList = malloc(sizeof(List));
  *historyList=NULL;

  doCastle(board, 0, 'F', castlingPointer, historyList);

  ck_assert(*(board + 7) == ' ');
  ck_assert(*(board + 6) == 'k');
  ck_assert(*(board + 5) == 'r');
  ck_assert(*(board + 4) == ' ');

  ck_assert(!*(castlingPointer + 2));
  ck_assert(!*(castlingPointer + 3));

  clearList(historyList);
  free(historyList);
}
END_TEST


Suite * move_suite(void){
  Suite *s;
  TCase *tc_core;
  s = suite_create("Chess");

  /* Core test case */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, pawnMoveWhite);
  tcase_add_test(tc_core, pawnTakeWhite);

  tcase_add_test(tc_core, pawnMoveBlack);
  tcase_add_test(tc_core, pawnTakeBlack);

  tcase_add_test(tc_core, kingValidMoveWhite);
  tcase_add_test(tc_core, kingNotValidMoveWhite);

  tcase_add_test(tc_core, kingValidMoveBlack);
  tcase_add_test(tc_core, kingNotValidMoveBlack);

  tcase_add_test(tc_core, knightMoveBlack);
  tcase_add_test(tc_core, knightMoveWhite);
  
  tcase_add_test(tc_core, rookMoveBlack);
  tcase_add_test(tc_core, rookMoveWhite);

  tcase_add_test(tc_core, bishopMoveBlack);
  tcase_add_test(tc_core, bishopMoveWhite);

  tcase_add_test(tc_core, queenMoveWhite);
  tcase_add_test(tc_core, queenMoveBlack);

  tcase_add_test(tc_core, castleSetWhiteLeft);
  tcase_add_test(tc_core, castleSetBlackLeft);

  tcase_add_test(tc_core, castleSetWhiteRight);
  tcase_add_test(tc_core, castleSetBlackRight);

  tcase_add_test(tc_core, castleSetWhiteKing);
  tcase_add_test(tc_core, castleSetBlackKing);

  tcase_add_test(tc_core, castleLeftWhiteBlocked);
  tcase_add_test(tc_core, castleLeftBlackBlocked);

  tcase_add_test(tc_core, castleRightWhiteBlocked);
  tcase_add_test(tc_core, castleRightBlackBlocked);

  tcase_add_test(tc_core, castleLeftWhiteCheck);
  tcase_add_test(tc_core, castleLeftBlackCheck);

  tcase_add_test(tc_core, castleRightWhiteCheck);
  tcase_add_test(tc_core, castleRightBlackCheck);

  tcase_add_test(tc_core, doCastleLeftWhite);
  tcase_add_test(tc_core, doCastleLeftBlack);

  tcase_add_test(tc_core, doCastleRightWhite);
  tcase_add_test(tc_core, doCastleRightBlack);

  suite_add_tcase(s, tc_core);
  return s;
}


int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = move_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
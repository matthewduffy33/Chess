#include <check.h>
#include <stdbool.h>
#include "../linkedList.h"
#include "../viewMoves.h"



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


START_TEST (singleMovePawnWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 1, 3, 4, moveList);

    if(*moveList != NULL){
      Node *node = *moveList;
  
      ck_assert_str_eq(node->val, "33"); 

      if(node->next != NULL){
        ck_assert(0);
      }
    }else{
      ck_assert(0);
    }


}
END_TEST


START_TEST (singleMovePawnBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 0, 3, 4, moveList);

    if(*moveList != NULL){
      Node *node = *moveList;
  
      ck_assert_str_eq(node->val, "35"); 

      if(node->next != NULL){
        ck_assert(0);
      }
    }else{
      ck_assert(0);
    }


}
END_TEST



START_TEST (doubleMovePawnWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 1, 3, 6, moveList);

    if(*moveList != NULL){
      Node *node = *moveList;
  
      ck_assert_str_eq(node->val, "35"); //checks can move 1 square

      if(node->next != NULL){
        node = node->next;
  
        ck_assert_str_eq(node->val, "34"); //checks can move second square

        if(node->next != NULL){
          ck_assert(0);
        }
      }else{
        ck_assert(0);
      }
    }else{
      ck_assert(0);
    }


}
END_TEST


START_TEST (doubleMovePawnBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 0, 3, 1, moveList);

    if(*moveList != NULL){
      Node *node = *moveList;
  
      ck_assert_str_eq(node->val, "32"); //checks can move 1 square

      if(node->next != NULL){
        node = node->next;
  
        ck_assert_str_eq(node->val, "33"); //checks can move second square

        if(node->next != NULL){
          ck_assert(0);
        }
      }else{
        ck_assert(0);
      }
    }else{
      ck_assert(0);
    }


}
END_TEST




START_TEST (blockMovePawnWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 1, 3, 6, moveList);

    if(*moveList != NULL){
      ck_assert(0);
    }else{
      ck_assert(1);
    }


}
END_TEST


START_TEST (blockMovePawnBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 0, 3, 1, moveList);

    if(*moveList != NULL){
      ck_assert(0);
    }else{
      ck_assert(1);
    }


}
END_TEST




START_TEST (diagonalMovePawnWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p','p','p',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 1, 3, 6, moveList);

    if(*moveList != NULL){
      Node *node = *moveList;
  
      ck_assert_str_eq(node->val, "25"); //checks can move left diagonal

      if(node->next != NULL){
        node = node->next;
  
        ck_assert_str_eq(node->val, "45"); //checks can move right diagonal

        if(node->next != NULL){
          ck_assert(0);
        }
      }else{
        ck_assert(0);
      }
    }else{
      ck_assert(0);
    }

}
END_TEST


START_TEST (diagonalMovePawnBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ','P','P','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    pawnMoves(board, 0, 3, 1, moveList);

    if(*moveList != NULL){
      Node *node = *moveList;
  
      ck_assert_str_eq(node->val, "22"); //checks can move left diagonal

      if(node->next != NULL){
        node = node->next;
  
        ck_assert_str_eq(node->val, "42"); //checks can move right diagonal

        if(node->next != NULL){
          ck_assert(0);
        }
      }else{
        ck_assert(0);
      }
    }else{
      ck_assert(0);
    }

}
END_TEST




START_TEST (moveKingWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    kingMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "22");
    add(correctList, "32");
    add(correctList, "42");
    add(correctList, "23");
    add(correctList, "43");
    add(correctList, "24");
    add(correctList, "34");
    add(correctList, "44");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST


START_TEST (moveKingBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    kingMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "22");
    add(correctList, "32");
    add(correctList, "42");
    add(correctList, "23");
    add(correctList, "43");
    add(correctList, "24");
    add(correctList, "34");
    add(correctList, "44");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST




START_TEST (takeKingWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p','K','p',' ',' ',' '},
            {' ',' ','p','p','p',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    kingMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "22");
    add(correctList, "32");
    add(correctList, "42");
    add(correctList, "23");
    add(correctList, "43");
    add(correctList, "24");
    add(correctList, "44");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST


START_TEST (takeKingBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','P','P','P',' ',' ',' '},
            {' ',' ','P','k','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    kingMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "22");
    
    add(correctList, "42");
    add(correctList, "23");
    add(correctList, "43");
    add(correctList, "24");
    add(correctList, "34");
    add(correctList, "44");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST




START_TEST (moveKingCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','q',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    kingMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "22");
    add(correctList, "42");
    add(correctList, "23");
    add(correctList, "43");
    add(correctList, "24");
    add(correctList, "44");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST


START_TEST (moveKingCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','Q',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    kingMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "22");
    add(correctList, "42");
    add(correctList, "23");
    add(correctList, "43");
    add(correctList, "24");
    add(correctList, "44");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST


START_TEST (moveKingCastleBothWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ','K',' ',' ','R'}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;
    bool castlingAllowed[4]={true, true, true, true}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 1, 'K', 4, 7, moveList, 0, castlingPointer);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "27");
    add(correctList, "67");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST



START_TEST (moveKingCastleBothBlack)
{
    char chess[8][8] = {
            {'r',' ',' ',' ','k',' ',' ','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;
    bool castlingAllowed[4]={true, true, true, true}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 0, 'k', 4, 0, moveList, 0, castlingPointer);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "20");
    add(correctList, "60");

    ck_assert(listCompare(moveList, correctList));


}
END_TEST


START_TEST (moveKingCastleAWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ','K',' ',' ','R'}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bool castlingAllowed[4]={true, false, true, true}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 1, 'K', 4, 7, moveList, 0, castlingPointer);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "27");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);
}
END_TEST



START_TEST (moveKingCastleABlack)
{
    char chess[8][8] = {
            {'r',' ',' ',' ','k',' ',' ','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bool castlingAllowed[4]={true, true, true, false}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 0, 'k', 4, 0, moveList, 0, castlingPointer);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "20");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (moveKingCastleHWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ','K',' ',' ','R'}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;
    bool castlingAllowed[4]={false, true, true, true}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 1, 'K', 4, 7, moveList, 0, castlingPointer);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "67");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST



START_TEST (moveKingCastleHBlack)
{
    char chess[8][8] = {
            {'r',' ',' ',' ','k',' ',' ','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;
    bool castlingAllowed[4]={true, true, false, true}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 0, 'k', 4, 0, moveList, 0, castlingPointer);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "60");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (moveKingCastleNoneWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ',' ','K',' ',' ','R'}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bool castlingAllowed[4]={false, false, true, true}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 1, 'K', 4, 7, moveList, 0, castlingPointer);

    ck_assert(isEmpty(moveList));

    clearList(moveList);
    free(moveList);

}
END_TEST



START_TEST (moveKingCastleNoneBlack)
{
    char chess[8][8] = {
            {'r',' ',' ',' ','k',' ',' ','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bool castlingAllowed[4]={true, true, false, false}; 
    bool *castlingPointer= &castlingAllowed[0];

    getCastling(board, 0, 'k', 4, 0, moveList, 0, castlingPointer);

    ck_assert(isEmpty(moveList));

    clearList(moveList);
    free(moveList);

}
END_TEST


START_TEST (moveKnightWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p','p','p',' ',' ',' '},
            {' ',' ','p','N','p',' ',' ',' '},
            {' ',' ','p','p','p',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    knightMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "12");
    add(correctList, "21");

    add(correctList, "14");
    add(correctList, "41");

    add(correctList, "52");
    add(correctList, "25");

    add(correctList, "54");
    add(correctList, "45");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (moveKnightBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','P','P','P',' ',' ',' '},
            {' ',' ','P','n','P',' ',' ',' '},
            {' ',' ','P','P','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    knightMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "12");
    add(correctList, "21");

    add(correctList, "14");
    add(correctList, "41");

    add(correctList, "52");
    add(correctList, "25");

    add(correctList, "54");
    add(correctList, "45");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (takeKnightWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p',' ','p',' ',' ',' '},
            {' ','p','p','p','p','p',' ',' '},
            {' ',' ','p','N','p',' ',' ',' '},
            {' ','p','p','p','p','p',' ',' '},
            {' ',' ','p',' ','p',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    knightMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "12");
    add(correctList, "21");

    add(correctList, "14");
    add(correctList, "41");

    add(correctList, "52");
    add(correctList, "25");

    add(correctList, "54");
    add(correctList, "45");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (takeKnightBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','P',' ','P',' ',' ',' '},
            {' ','P','P','P','P','P',' ',' '},
            {' ',' ','P','n','P',' ',' ',' '},
            {' ','P','P','P','P','P',' ',' '},
            {' ',' ','P',' ','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    knightMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "12");
    add(correctList, "21");

    add(correctList, "14");
    add(correctList, "41");

    add(correctList, "52");
    add(correctList, "25");

    add(correctList, "54");
    add(correctList, "45");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (moveBishopWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','B',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','P',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bishopMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "44");
    add(correctList, "55");

    add(correctList, "24");
    add(correctList, "42");
    add(correctList, "22");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (moveBishopBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','b',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bishopMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "44");
    add(correctList, "55");

    add(correctList, "24");
    add(correctList, "42");
    add(correctList, "22");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (takeBishopWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','B',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bishopMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "44");
    add(correctList, "55");
    add(correctList, "66");

    add(correctList, "24");
    add(correctList, "15");

    add(correctList, "42");
    add(correctList, "51");

    add(correctList, "22");
    add(correctList, "11");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (takeBishopBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','B',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    bishopMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "44");
    add(correctList, "55");
    add(correctList, "66");

    add(correctList, "24");
    add(correctList, "15");

    add(correctList, "42");
    add(correctList, "51");

    add(correctList, "22");
    add(correctList, "11");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (moveRookWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','R',' ',' ','P',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    rookMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "43");//up
    add(correctList, "53");

    add(correctList, "23");//down

    add(correctList, "34");//left
    add(correctList, "35");

    add(correctList, "32");//right

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (moveRookBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ','r',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    rookMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "43");//up
    add(correctList, "53");

    add(correctList, "23");//down

    add(correctList, "34");//left
    add(correctList, "35");

    add(correctList, "32");//right

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (takeRookWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ','R',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    rookMoves(board, 1, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "43");//up
    add(correctList, "53");
    add(correctList, "63");

    add(correctList, "23");//down
    add(correctList, "13");

    add(correctList, "34");//left
    add(correctList, "35");
    add(correctList, "36");

    add(correctList, "32");//right
    add(correctList, "31");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (takeRookBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','r',' ',' ','P',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    rookMoves(board, 0, 3, 3, moveList);

    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "43");//up
    add(correctList, "53");
    add(correctList, "63");

    add(correctList, "23");//down
    add(correctList, "13");

    add(correctList, "34");//left
    add(correctList, "35");
    add(correctList, "36");

    add(correctList, "32");//right
    add(correctList, "31");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST




START_TEST (movesInCheckNoMovesWhite)
{
    char chess[8][8] = {
            {' ',' ','q','q','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','P',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    add(moveList, "64");
    add(moveList, "65");

    movesInCheck(board, 1, 'P', 6, 6, moveList);

    isEmpty(moveList);

    clearList(moveList);
    free(moveList);

}
END_TEST

START_TEST (movesInCheckNoMovesBlack)
{
    char chess[8][8] = {
            {' ',' ','Q','Q','Q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','p',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    add(moveList, "62");
    add(moveList, "63");

    movesInCheck(board, 0, 'P', 6, 1, moveList);

    isEmpty(moveList);

    clearList(moveList);
    free(moveList);


}
END_TEST





START_TEST (movesInCheckOneMovesWhite)
{
    char chess[8][8] = {
            {' ',' ','q','q','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','R',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    add(moveList, "60");
    add(moveList, "61");
    add(moveList, "63");
    add(moveList, "64");
    add(moveList, "65");
    add(moveList, "66");
    add(moveList, "67");

    add(moveList, "02");
    add(moveList, "12");
    add(moveList, "22");
    add(moveList, "32");
    add(moveList, "42");
    add(moveList, "52");
    add(moveList, "72");


    movesInCheck(board, 1, 'R', 6, 2, moveList);
   if(*moveList != NULL){
      Node *node = *moveList;

      ck_assert_str_eq(node->val, "32");

          
      if((node->next)!=NULL){
        ck_assert(0);
      }
          

    }else{
      ck_assert(0);
    }

    clearList(moveList);
    free(moveList);


}
END_TEST

START_TEST (movesInCheckOneMovesBlack)
{
    char chess[8][8] = {
            {' ',' ','Q','Q','Q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ','r',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    add(moveList, "60");
    add(moveList, "61");
    add(moveList, "63");
    add(moveList, "64");
    add(moveList, "65");
    add(moveList, "66");
    add(moveList, "67");

    add(moveList, "02");
    add(moveList, "12");
    add(moveList, "22");
    add(moveList, "32");
    add(moveList, "42");
    add(moveList, "52");
    add(moveList, "72");


    movesInCheck(board, 0, 'r', 6, 2, moveList);
   if(*moveList != NULL){
      Node *node = *moveList;

      ck_assert_str_eq(node->val, "32");

          
      if((node->next)!=NULL){
        ck_assert(0);
      }
          

    }else{
      ck_assert(0);
    }

    clearList(moveList);
    free(moveList);


}
END_TEST




START_TEST (movesInCheckMultiMovesWhite)
{
    char chess[8][8] = {
            {' ',' ','q','q','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','Q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    add(moveList, "40");
    add(moveList, "41");
    add(moveList, "42");
    add(moveList, "43");
    
    add(moveList, "45");
    add(moveList, "46");
    add(moveList, "47");

    add(moveList, "04");
    add(moveList, "14");
    add(moveList, "24");
    add(moveList, "34");

    add(moveList, "54");
    add(moveList, "64");
    add(moveList, "74");

    add(moveList, "11");
    add(moveList, "22");
    add(moveList, "33");

    add(moveList, "55");
    add(moveList, "66");
    add(moveList, "77");

    add(moveList, "17");
    add(moveList, "26");
    add(moveList, "35");

    add(moveList, "53");
    add(moveList, "62");
    add(moveList, "71");


    movesInCheck(board, 1, 'Q', 4, 4, moveList);


    List correctList = malloc(sizeof(List));
    *correctList=NULL;
    add(correctList, "34");
    add(correctList, "33");
    add(correctList, "35");

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);

}
END_TEST


START_TEST (movesInCheckMultiMovesBlack)
{
    char chess[8][8] = {
            {' ',' ','Q','Q','Q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    List moveList = malloc(sizeof(List));
    *moveList=NULL;

    add(moveList, "40");
    add(moveList, "41");
    add(moveList, "42");
    add(moveList, "43");
    
    add(moveList, "45");
    add(moveList, "46");
    add(moveList, "47");

    add(moveList, "04");
    add(moveList, "14");
    add(moveList, "24");
    add(moveList, "34");

    add(moveList, "54");
    add(moveList, "64");
    add(moveList, "74");

    add(moveList, "11");
    add(moveList, "22");
    add(moveList, "33");

    add(moveList, "55");
    add(moveList, "66");
    add(moveList, "77");

    add(moveList, "17");
    add(moveList, "26");
    add(moveList, "35");

    add(moveList, "53");
    add(moveList, "62");
    add(moveList, "71");


    movesInCheck(board, 0, 'q', 4, 4, moveList);


    List correctList = malloc(sizeof(List));
    *correctList=NULL;
    add(correctList, "34");
    add(correctList, "33");
    add(correctList, "35");
    

    ck_assert(listCompare(moveList, correctList));

    clearList(moveList);
    free(moveList);

    clearList(correctList);
    free(correctList);


}
END_TEST



Suite * view_suite(void){
  Suite *s;
  TCase *tc_core;
  s = suite_create("Chess");

  /* Core test case */
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, singleMovePawnWhite);
  tcase_add_test(tc_core, singleMovePawnBlack);

  tcase_add_test(tc_core, doubleMovePawnWhite);
  tcase_add_test(tc_core, doubleMovePawnBlack);

  tcase_add_test(tc_core, blockMovePawnWhite);
  tcase_add_test(tc_core, blockMovePawnBlack);

  tcase_add_test(tc_core, diagonalMovePawnWhite);
  tcase_add_test(tc_core, diagonalMovePawnBlack);

  tcase_add_test(tc_core, moveKingWhite);
  tcase_add_test(tc_core, moveKingBlack);

  tcase_add_test(tc_core, takeKingWhite);
  tcase_add_test(tc_core, takeKingBlack);

  tcase_add_test(tc_core, moveKingCheckWhite);
  tcase_add_test(tc_core, moveKingCheckBlack);

  tcase_add_test(tc_core, moveKingCastleBothWhite);
  tcase_add_test(tc_core, moveKingCastleBothBlack);

  tcase_add_test(tc_core, moveKingCastleAWhite);
  tcase_add_test(tc_core, moveKingCastleABlack);

  tcase_add_test(tc_core, moveKingCastleHWhite);
  tcase_add_test(tc_core, moveKingCastleHBlack);

  tcase_add_test(tc_core, moveKingCastleNoneWhite);
  tcase_add_test(tc_core, moveKingCastleNoneBlack);

  tcase_add_test(tc_core, moveKnightWhite);
  tcase_add_test(tc_core, moveKnightBlack);

  tcase_add_test(tc_core, takeKnightWhite);
  tcase_add_test(tc_core, takeKnightBlack);

  tcase_add_test(tc_core, moveBishopWhite);
  tcase_add_test(tc_core, moveBishopBlack);

  tcase_add_test(tc_core, takeBishopWhite);
  tcase_add_test(tc_core, takeBishopBlack);

  tcase_add_test(tc_core, moveRookWhite);
  tcase_add_test(tc_core, moveRookBlack);

  tcase_add_test(tc_core, takeRookWhite);
  tcase_add_test(tc_core, takeRookBlack);

  tcase_add_test(tc_core, movesInCheckNoMovesWhite);
  tcase_add_test(tc_core, movesInCheckNoMovesBlack);

  tcase_add_test(tc_core, movesInCheckOneMovesWhite);
  tcase_add_test(tc_core, movesInCheckOneMovesBlack);

  tcase_add_test(tc_core, movesInCheckMultiMovesWhite);
  tcase_add_test(tc_core, movesInCheckMultiMovesBlack);


  suite_add_tcase(s, tc_core);
  return s;
}


int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = view_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
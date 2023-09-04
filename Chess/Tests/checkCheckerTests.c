#include <check.h>
#include <stdbool.h>
#include "../checkChecker.h"


START_TEST (knightInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','n',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(knightCheckChecker(board, 1, 3, 4));

    *(board+(8*2)+2)=' ';
    *(board+(8*2)+4)='n';

    ck_assert(knightCheckChecker(board, 1, 3, 4));

    *(board+(8*2)+4)=' ';
    *(board+(8*3)+5)='n';
    ck_assert(knightCheckChecker(board, 1, 3, 4));

    *(board+(8*3)+5)=' ';
    *(board+(8*5)+5)='n';
    ck_assert(knightCheckChecker(board, 1, 3, 4));

    *(board+(8*5)+5)=' ';
    *(board+(8*6)+4)='n';
    ck_assert(knightCheckChecker(board, 1, 3, 4));

    *(board+(8*6)+4)=' ';
    *(board+(8*6)+2)='n';
    ck_assert(knightCheckChecker(board, 1, 3, 4));

    *(board+(8*6)+2)=' ';
    *(board+(8*5)+1)='n';
    ck_assert(knightCheckChecker(board, 1, 3, 4));

    *(board+(8*5)+1)=' ';
    *(board+(8*3)+1)='n';
    ck_assert(knightCheckChecker(board, 1, 3, 4));
}
END_TEST


START_TEST (knightInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','N',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(knightCheckChecker(board, 0, 3, 4));

    *(board+(8*2)+2)=' ';
    *(board+(8*2)+4)='N';

    ck_assert(knightCheckChecker(board, 0, 3, 4));

    *(board+(8*2)+4)=' ';
    *(board+(8*3)+5)='N';
    ck_assert(knightCheckChecker(board, 0, 3, 4));

    *(board+(8*3)+5)=' ';
    *(board+(8*5)+5)='N';
    ck_assert(knightCheckChecker(board, 0, 3, 4));

    *(board+(8*5)+5)=' ';
    *(board+(8*6)+4)='N';
    ck_assert(knightCheckChecker(board, 0, 3, 4));

    *(board+(8*6)+4)=' ';
    *(board+(8*6)+2)='N';
    ck_assert(knightCheckChecker(board, 0, 3, 4));

    *(board+(8*6)+2)=' ';
    *(board+(8*5)+1)='N';
    ck_assert(knightCheckChecker(board, 0, 3, 4));

    *(board+(8*5)+1)=' ';
    *(board+(8*3)+1)='N';
    ck_assert(knightCheckChecker(board, 0, 3, 4));
}
END_TEST


START_TEST (knightNotInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','q',' ','q',' ',' ',' '},
            {' ','q',' ',' ',' ','q',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ','q',' ',' ',' ','q',' ',' '},
            {' ',' ','q',' ','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(!knightCheckChecker(board, 1, 3, 4));

}
END_TEST


START_TEST (knightNotInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','Q',' ','Q',' ',' ',' '},
            {' ','Q',' ',' ',' ','Q',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ','Q',' ',' ',' ','Q',' ',' '},
            {' ',' ','Q',' ','Q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(!knightCheckChecker(board, 1, 3, 4));

}
END_TEST


START_TEST (pawnInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(pawnCheckChecker(board, 1, 3, 4));

    *(board+(8*3)+3)=' ';
    *(board+(8*3)+5)='p';

    ck_assert(pawnCheckChecker(board, 1, 3, 4));

    *(board+(8*4)+3)=' ';                 //checks it works on borders
    *(board+(8*7)+7)='K';
    
    *(board+(8*3)+5)=' ';
    *(board+(8*6)+6)='p';

    ck_assert(pawnCheckChecker(board, 1, 3, 4));

    *(board+(8*7)+7)=' ';
    *(board+(8*7)+0)='K';
    
    *(board+(8*6)+6)=' ';
    *(board+(8*6)+1)='p';

    ck_assert(pawnCheckChecker(board, 1, 3, 4));

    *(board+(8*7)+0)=' ';
    *(board+(8*2)+0)='K';
    
    *(board+(8*6)+1)=' ';
    *(board+(8*1)+1)='p';

    ck_assert(pawnCheckChecker(board, 1, 3, 4));


    *(board+(8*2)+0)=' ';
    *(board+(8*2)+7)='K';
    
    *(board+(8*1)+1)=' ';
    *(board+(8*1)+6)='p';

    ck_assert(pawnCheckChecker(board, 1, 3, 4));


}
END_TEST


START_TEST (pawnInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ','P',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(pawnCheckChecker(board, 0, 3, 4));

    *(board+(8*5)+3)=' ';
    *(board+(8*5)+5)='P';

    ck_assert(pawnCheckChecker(board, 0, 3, 4));

    *(board+(8*4)+3)=' ';                 //checks it works on borders
    *(board+(8*6)+6)='k';
    
    *(board+(8*3)+5)=' ';
    *(board+(8*7)+7)='P';

    ck_assert(pawnCheckChecker(board, 0, 3, 4));

    *(board+(8*6)+6)=' ';
    *(board+(8*6)+0)='k';
    
    *(board+(8*7)+7)=' ';
    *(board+(8*7)+1)='P';

    ck_assert(pawnCheckChecker(board, 0, 3, 4));

    *(board+(8*6)+0)=' ';
    *(board+(8*0)+0)='k';
    
    *(board+(8*7)+1)=' ';
    *(board+(8*1)+1)='P';

    ck_assert(pawnCheckChecker(board, 0, 3, 4));


    *(board+(8*0)+0)=' ';
    *(board+(8*0)+7)='k';
    
    *(board+(8*1)+1)=' ';
    *(board+(8*1)+6)='P';

    ck_assert(pawnCheckChecker(board, 0, 3, 4));


}
END_TEST


START_TEST (pawnNotInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ','p','K','p',' ',' ',' '},
            {' ',' ','p','p','p',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(!pawnCheckChecker(board, 1, 3, 4));


}
END_TEST


START_TEST (pawnNotInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','P','P','P',' ',' ',' '},
            {' ',' ','P','k','P',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	  char *board= &chess[0][0];	

    ck_assert(!pawnCheckChecker(board, 1, 3, 4));


}
END_TEST


START_TEST (diagonalBishopInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','b'},
            {'b',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'b',' ',' ',' ',' ',' ','b',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(diagonalCheckChecker(board, 1, 0, 1, 3, 4));

    ck_assert(diagonalCheckChecker(board, 1, 7, 0, 3, 4));

    ck_assert(diagonalCheckChecker(board, 1, 6, 7, 3, 4));

    ck_assert(diagonalCheckChecker(board, 1, 0, 7, 3, 4));


}
END_TEST


START_TEST (diagonalBishopInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','B'},
            {'B',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'B',' ',' ',' ',' ',' ','B',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(diagonalCheckChecker(board, 0, 0, 1, 3, 4));

    ck_assert(diagonalCheckChecker(board, 0, 7, 0, 3, 4));

    ck_assert(diagonalCheckChecker(board, 0, 6, 7, 3, 4));

    ck_assert(diagonalCheckChecker(board, 0, 0, 7, 3, 4));


}
END_TEST


START_TEST (diagonalBishopNotInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','b'},
            {'b',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {'b',' ',' ',' ',' ',' ','b',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!diagonalCheckChecker(board, 1, 0, 1, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 1, 7, 0, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 1, 0, 7, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 1, 6, 7, 3, 4));


}
END_TEST


START_TEST (diagonalBishopNotInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','B'},
            {'B',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {'B',' ',' ',' ',' ',' ','B',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!diagonalCheckChecker(board, 0, 0, 1, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 0, 7, 0, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 0, 0, 7, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 0, 6, 7, 3, 4));



}
END_TEST


START_TEST (diagonalQueenInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','q'},
            {'q',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q',' ',' ',' ',' ',' ','q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(diagonalCheckChecker(board, 1, 0, 1, 3, 4));

    ck_assert(diagonalCheckChecker(board, 1, 7, 0, 3, 4));

    ck_assert(diagonalCheckChecker(board, 1, 6, 7, 3, 4));

    ck_assert(diagonalCheckChecker(board, 1, 0, 7, 3, 4));


}
END_TEST


START_TEST (diagonalQueenInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','Q'},
            {'Q',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q',' ',' ',' ',' ',' ','Q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(diagonalCheckChecker(board, 0, 0, 1, 3, 4));

    ck_assert(diagonalCheckChecker(board, 0, 7, 0, 3, 4));

    ck_assert(diagonalCheckChecker(board, 0, 6, 7, 3, 4));

    ck_assert(diagonalCheckChecker(board, 0, 0, 7, 3, 4));


}
END_TEST


START_TEST (diagonalQueenNotInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','q'},
            {'q',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ',' ',' ','P',' ',' '},
            {'q',' ',' ',' ',' ',' ','q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!diagonalCheckChecker(board, 1, 0, 1, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 1, 7, 0, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 1, 0, 7, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 1, 6, 7, 3, 4));


}
END_TEST


START_TEST (diagonalQueenNotInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ','Q'},
            {'Q',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','p',' ',' ',' ','p',' ',' '},
            {'Q',' ',' ',' ',' ',' ','Q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!diagonalCheckChecker(board, 0, 0, 1, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 0, 7, 0, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 0, 0, 7, 3, 4));

    ck_assert(!diagonalCheckChecker(board, 0, 6, 7, 3, 4));



}
END_TEST


START_TEST (lineRookInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','r',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'r',' ',' ','K',' ',' ',' ','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','r',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(lineCheckChecker(board, 1, 3, 1, 3, 4));

    ck_assert(lineCheckChecker(board, 1, 7, 4, 3, 4));

    ck_assert(lineCheckChecker(board, 1, 3, 7, 3, 4));

    ck_assert(lineCheckChecker(board, 1, 0, 4, 3, 4));


}
END_TEST

START_TEST (lineRookInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','R',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R',' ',' ','k',' ',' ',' ','R'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','R',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(lineCheckChecker(board, 0, 3, 1, 3, 4));

    ck_assert(lineCheckChecker(board, 0, 7, 4, 3, 4));

    ck_assert(lineCheckChecker(board, 0, 3, 7, 3, 4));

    ck_assert(lineCheckChecker(board, 0, 0, 4, 3, 4));


}
END_TEST


START_TEST (lineRookNotInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','r',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'r','P',' ','K',' ',' ','P','r'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ','r',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!lineCheckChecker(board, 1, 3, 1, 3, 4));
    
    ck_assert(!lineCheckChecker(board, 1, 7, 4, 3, 4));

    ck_assert(!lineCheckChecker(board, 1, 3, 7, 3, 4));

    ck_assert(!lineCheckChecker(board, 1, 0, 4, 3, 4));



}
END_TEST


START_TEST (lineRookNotInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','R',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'R','p',' ','k',' ',' ','p','R'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ','R',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!lineCheckChecker(board, 0, 3, 1, 3, 4));
    
    ck_assert(!lineCheckChecker(board, 0, 7, 4, 3, 4));

    ck_assert(!lineCheckChecker(board, 0, 3, 7, 3, 4));

    ck_assert(!lineCheckChecker(board, 0, 0, 4, 3, 4));



}
END_TEST




START_TEST (lineQueenInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q',' ',' ','K',' ',' ',' ','q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(lineCheckChecker(board, 1, 3, 1, 3, 4));

    ck_assert(lineCheckChecker(board, 1, 7, 4, 3, 4));

    ck_assert(lineCheckChecker(board, 1, 3, 7, 3, 4));

    ck_assert(lineCheckChecker(board, 1, 0, 4, 3, 4));


}
END_TEST

START_TEST (lineQueenInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','Q',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q',' ',' ','k',' ',' ',' ','Q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','Q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(lineCheckChecker(board, 0, 3, 1, 3, 4));

    ck_assert(lineCheckChecker(board, 0, 7, 4, 3, 4));

    ck_assert(lineCheckChecker(board, 0, 3, 7, 3, 4));

    ck_assert(lineCheckChecker(board, 0, 0, 4, 3, 4));


}
END_TEST


START_TEST (lineQueenNotInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q','P',' ','K',' ',' ','P','q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ','q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!lineCheckChecker(board, 1, 3, 1, 3, 4));
    
    ck_assert(!lineCheckChecker(board, 1, 7, 4, 3, 4));

    ck_assert(!lineCheckChecker(board, 1, 3, 7, 3, 4));

    ck_assert(!lineCheckChecker(board, 1, 0, 4, 3, 4));



}
END_TEST


START_TEST (lineQueenNotInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','Q',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q','p',' ','k',' ',' ','p','Q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ','Q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!lineCheckChecker(board, 0, 3, 1, 3, 4));
    
    ck_assert(!lineCheckChecker(board, 0, 7, 4, 3, 4));

    ck_assert(!lineCheckChecker(board, 0, 3, 7, 3, 4));

    ck_assert(!lineCheckChecker(board, 0, 0, 4, 3, 4));



}
END_TEST


START_TEST (findKingWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    char *pos = malloc(sizeof(char)*3);


    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "32");
    

    *(board+(8*2)+3)=' ';
    *(board+(8*5)+6)='K';

    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "65");

    *(board+(8*5)+6)=' ';
    *(board+(8*2)+4)='K';

    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "42");

    *(board+(8*2)+4)=' ';
    *(board+(8*3)+7)='K';

    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "73");


    free(pos);

}
END_TEST


START_TEST (findKingBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    char *pos = malloc(sizeof(char)*3);


    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "32");
    

    *(board+(8*2)+3)=' ';
    *(board+(8*5)+6)='k';

    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "65");

    *(board+(8*5)+6)=' ';
    *(board+(8*2)+4)='k';

    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "42");

    *(board+(8*2)+4)=' ';
    *(board+(8*3)+7)='k';

    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "73");


    free(pos);

}
END_TEST


START_TEST (findBorderKingWhite)
{
    char chess[8][8] = {
            {'K',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    char *pos = malloc(sizeof(char)*3);


    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "00");
    

    *(board+(8*0)+0)=' ';
    *(board+(8*0)+7)='K';

    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "70");

    *(board+(8*0)+7)=' ';
    *(board+(8*7)+0)='K';

    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "07");

    *(board+(8*7)+0)=' ';
    *(board+(8*7)+7)='K';

    memset(pos, '\0', 3);

    findKing(board, 1, pos);

    ck_assert_str_eq(pos, "77");


    free(pos);

}
END_TEST

START_TEST (findBorderKingBlack)
{
    char chess[8][8] = {
            {'k',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    char *pos = malloc(sizeof(char)*3);


    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "00");
    

    *(board+(8*0)+0)=' ';
    *(board+(8*0)+7)='k';

    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "70");

    *(board+(8*0)+7)=' ';
    *(board+(8*7)+0)='k';

    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "07");

    *(board+(8*7)+0)=' ';
    *(board+(8*7)+7)='k';

    memset(pos, '\0', 3);

    findKing(board, 0, pos);

    ck_assert_str_eq(pos, "77");


    free(pos);

}
END_TEST


START_TEST (inSelfCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ','q'},
            {'q',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q',' ',' ','K',' ',' ',' ','q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q',' ',' ','q',' ',' ','q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(selfCheckChecker(board, 1, 2, 4));

    ck_assert(selfCheckChecker(board, 1, 2, 3));

    ck_assert(selfCheckChecker(board, 1, 3, 3));

    ck_assert(selfCheckChecker(board, 1, 4, 3));

    ck_assert(selfCheckChecker(board, 1, 4, 4));
    
    ck_assert(selfCheckChecker(board, 1, 4, 5));

    ck_assert(selfCheckChecker(board, 1, 3, 5));

    ck_assert(selfCheckChecker(board, 1, 2, 5));
    

}
END_TEST

START_TEST (inSelfCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','Q',' ',' ',' ','Q'},
            {'Q',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q',' ',' ','k',' ',' ',' ','Q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q',' ',' ','Q',' ',' ','Q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(selfCheckChecker(board, 0, 2, 4));

    ck_assert(selfCheckChecker(board, 0, 2, 3));

    ck_assert(selfCheckChecker(board, 0, 3, 3));

    ck_assert(selfCheckChecker(board, 0, 4, 3));

    ck_assert(selfCheckChecker(board, 0, 4, 4));
    
    ck_assert(selfCheckChecker(board, 0, 4, 5));

    ck_assert(selfCheckChecker(board, 0, 3, 5));

    ck_assert(selfCheckChecker(board, 0, 2, 5));
    

}
END_TEST



START_TEST (notInSelfCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ','q'},
            {'q',' ',' ','P',' ',' ','P',' '},
            {' ','P',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q','P',' ','K',' ',' ','P','q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','P',' ','P',' ',' '},
            {'q',' ',' ','q',' ',' ','q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!selfCheckChecker(board, 1, 2, 4));

    ck_assert(!selfCheckChecker(board, 1, 2, 3));

    ck_assert(!selfCheckChecker(board, 1, 3, 3));

    ck_assert(!selfCheckChecker(board, 1, 4, 3));

    ck_assert(!selfCheckChecker(board, 1, 4, 4));
    
    ck_assert(!selfCheckChecker(board, 1, 4, 5));

    ck_assert(!selfCheckChecker(board, 1, 3, 5));

    ck_assert(!selfCheckChecker(board, 1, 2, 5));
    

}
END_TEST

START_TEST (notInSelfCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','Q',' ',' ',' ','Q'},
            {'Q',' ',' ','P',' ',' ','P',' '},
            {' ','P',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q','P',' ','k',' ',' ','P','Q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','P',' ','P',' ',' '},
            {'Q',' ',' ','Q',' ',' ','Q',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!selfCheckChecker(board, 0, 2, 4));

    ck_assert(!selfCheckChecker(board, 0, 2, 3));

    ck_assert(!selfCheckChecker(board, 0, 3, 3));

    ck_assert(!selfCheckChecker(board, 0, 4, 3));

    ck_assert(!selfCheckChecker(board, 0, 4, 4));
    
    ck_assert(!selfCheckChecker(board, 0, 4, 5));

    ck_assert(!selfCheckChecker(board, 0, 3, 5));

    ck_assert(!selfCheckChecker(board, 0, 2, 5));
    

}
END_TEST



START_TEST (inFullCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(fullCheckChecker(board, 1, 3, 4));

    *(board+(8*3)+2)=' ';
    *(board+(8*2)+2)='n';
    
    ck_assert(fullCheckChecker(board, 1, 3, 4));

    *(board+(8*2)+2)=' ';
    *(board+(8*1)+0)='b';
    
    ck_assert(fullCheckChecker(board, 1, 3, 4));

    *(board+(8*1)+0)=' ';
    *(board+(8*0)+3)='r';
    
    ck_assert(fullCheckChecker(board, 1, 3, 4));

}
END_TEST


START_TEST (inFullCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ','P',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(fullCheckChecker(board, 0, 3, 4));

    *(board+(8*3)+2)=' ';
    *(board+(8*2)+2)='N';
    
    ck_assert(fullCheckChecker(board, 0, 3, 4));

    *(board+(8*2)+2)=' ';
    *(board+(8*1)+0)='B';
    
    ck_assert(fullCheckChecker(board, 0, 3, 4));

    *(board+(8*1)+0)=' ';
    *(board+(8*0)+3)='R';
    
    ck_assert(fullCheckChecker(board, 0, 3, 4));

}
END_TEST




START_TEST (notInFullCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ','n','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ','P',' ','P',' ',' ',' ',' '},
            {'b',' ',' ','r',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!fullCheckChecker(board, 1, 3, 4));

}
END_TEST

START_TEST (notInFullCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','R',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','N','k',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ','p',' ',' ',' ',' ',' ',' '},
            {'B',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!fullCheckChecker(board, 0, 3, 4));

}
END_TEST


START_TEST (opponentInitialPosCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q',' ',' ','K',' ',' ',' ','q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 1, 'q', 2, 4, 2, 3));

    ck_assert(opponentCheckChecker(board, 1, 'q', 3, 3, 4, 3));

    ck_assert(opponentCheckChecker(board, 1, 'q', 4, 4, 4, 5));

    ck_assert(opponentCheckChecker(board, 1, 'q', 3, 5, 2, 5));

}
END_TEST

START_TEST (opponentInitialPosCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','Q',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q',' ',' ','k',' ',' ',' ','Q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','Q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 0, 'Q', 2, 4, 2, 3));

    ck_assert(opponentCheckChecker(board, 0, 'Q', 3, 3, 4, 3));

    ck_assert(opponentCheckChecker(board, 0, 'Q', 4, 4, 4, 5));

    ck_assert(opponentCheckChecker(board, 0, 'Q', 3, 5, 2, 5));

}
END_TEST



START_TEST (opponentNewPosCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q',' ',' ','K',' ',' ',' ','q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 1, 'q', 2, 3, 2, 4));

    ck_assert(opponentCheckChecker(board, 1, 'q', 4, 3, 3, 3));

    ck_assert(opponentCheckChecker(board, 1, 'q', 4, 5, 4, 4));

    ck_assert(opponentCheckChecker(board, 1, 'q', 2, 5, 3, 5));

}
END_TEST

START_TEST (opponentNewPosCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','Q',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q',' ',' ','k',' ',' ',' ','Q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','Q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 0, 'Q', 2, 3, 2, 4));

    ck_assert(opponentCheckChecker(board, 0, 'Q', 4, 3, 3, 3));

    ck_assert(opponentCheckChecker(board, 0, 'Q', 4, 5, 4, 4));

    ck_assert(opponentCheckChecker(board, 0, 'Q', 2, 5, 3, 5));

}
END_TEST

START_TEST (opponentPawnCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','p',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 1, 'p', 2, 1, 2, 3));

    *(board+(8*3)+2)=' ';
    *(board+(8*3)+4)='p';

    ck_assert(opponentCheckChecker(board, 1, 'p', 4, 1, 4, 3));

}
END_TEST

START_TEST (opponentPawnCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ','P',' ','P',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 0, 'p', 2, 6, 2, 5));

    *(board+(8*5)+2)=' ';
    *(board+(8*5)+4)='P';

    ck_assert(opponentCheckChecker(board, 0, 'p', 4, 6, 4, 5));

}
END_TEST



START_TEST (opponentKnightCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','n',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 1, 'n', 2, 1, 2, 2));

    *(board+(8*2)+2)=' ';
    *(board+(8*2)+4)='n';

    ck_assert(opponentCheckChecker(board, 1, 'n', 4, 1, 4, 2));

}
END_TEST

START_TEST (opponentKnightCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','N',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(opponentCheckChecker(board, 0, 'N', 2, 1, 2, 2));

    *(board+(8*2)+2)=' ';
    *(board+(8*2)+4)='N';

    ck_assert(opponentCheckChecker(board, 0, 'N', 4, 1, 4, 2));

}
END_TEST



START_TEST (opponentNotInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'q','P',' ','K',' ',' ','P','q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','P',' ',' ',' ',' '},
            {' ',' ',' ','q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!opponentCheckChecker(board, 1, 'q', 2, 3, 2, 4));

    ck_assert(!opponentCheckChecker(board, 1, 'q', 4, 3, 3, 3));

    ck_assert(!opponentCheckChecker(board, 1, 'q', 4, 5, 4, 4));

    ck_assert(!opponentCheckChecker(board, 1, 'q', 2, 5, 3, 5));

}
END_TEST

START_TEST (opponentNotInCheckBlack)
{
    char chess[8][8] = {
            {' ',' ',' ','Q',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {'Q','p',' ','k',' ',' ','p','Q'},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','p',' ',' ',' ',' '},
            {' ',' ',' ','Q',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!opponentCheckChecker(board, 0, 'Q', 2, 3, 2, 4));

    ck_assert(!opponentCheckChecker(board, 0, 'Q', 4, 3, 3, 3));

    ck_assert(!opponentCheckChecker(board, 0, 'Q', 4, 5, 4, 4));

    ck_assert(!opponentCheckChecker(board, 0, 'Q', 2, 5, 3, 5));

}
END_TEST


START_TEST (mateCheckerNoMovesWhite)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(mateChecker(board, 1, 0));

}
END_TEST

START_TEST (mateCheckerNoMovesBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(mateChecker(board, 0, 0));

}
END_TEST

START_TEST (mateCheckerInCheckWhite)
{
    char chess[8][8] = {
            {' ',' ',' ','q',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(!mateChecker(board, 1, 0));

}
END_TEST

START_TEST (mateCheckerInCheckBlack)
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

    ck_assert(!mateChecker(board, 0, 0));

}
END_TEST


START_TEST (mateCheckerInCheckNoMovesWhite)
{
    char chess[8][8] = {
            {' ',' ','q','q','q',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','K',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(mateChecker(board, 1, 0));

}
END_TEST

START_TEST (mateCheckerInCheckNoMovesBlack)
{
    char chess[8][8] = {
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ','k',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ',' ',' ',' ',' ',' ',' '},
            {' ',' ','Q','Q','Q',' ',' ',' '}};
					
	char *board= &chess[0][0];	

    ck_assert(mateChecker(board, 0, 0));

}
END_TEST


Suite * checker_suite(void){
    Suite *s;
    TCase *tc_core;
    s = suite_create("Chess");

    /* Core test case */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, knightInCheckWhite);
    tcase_add_test(tc_core, knightInCheckBlack);

    tcase_add_test(tc_core, knightNotInCheckWhite);
    tcase_add_test(tc_core, knightNotInCheckBlack);

    tcase_add_test(tc_core, pawnInCheckWhite);
    tcase_add_test(tc_core, pawnInCheckBlack);

    tcase_add_test(tc_core, pawnNotInCheckWhite);
    tcase_add_test(tc_core, pawnNotInCheckBlack);

    tcase_add_test(tc_core, diagonalBishopInCheckWhite);
    tcase_add_test(tc_core, diagonalBishopInCheckBlack);

    tcase_add_test(tc_core, diagonalBishopNotInCheckWhite);
    tcase_add_test(tc_core, diagonalBishopNotInCheckBlack);

    tcase_add_test(tc_core, diagonalQueenInCheckWhite);
    tcase_add_test(tc_core, diagonalQueenInCheckBlack);

    tcase_add_test(tc_core, diagonalQueenNotInCheckWhite);
    tcase_add_test(tc_core, diagonalQueenNotInCheckBlack);

    tcase_add_test(tc_core, lineRookInCheckWhite);
    tcase_add_test(tc_core, lineRookInCheckBlack);

    tcase_add_test(tc_core, lineRookNotInCheckWhite);
    tcase_add_test(tc_core, lineRookNotInCheckBlack);

    tcase_add_test(tc_core, lineQueenInCheckWhite);
    tcase_add_test(tc_core, lineQueenInCheckBlack);

    tcase_add_test(tc_core, lineQueenNotInCheckWhite);
    tcase_add_test(tc_core, lineQueenNotInCheckBlack);

    tcase_add_test(tc_core, findKingWhite);
    tcase_add_test(tc_core, findKingBlack);

    tcase_add_test(tc_core, findBorderKingWhite);
    tcase_add_test(tc_core, findBorderKingBlack);

    tcase_add_test(tc_core, inSelfCheckWhite);
    tcase_add_test(tc_core, inSelfCheckBlack);

    tcase_add_test(tc_core, notInSelfCheckWhite);
    tcase_add_test(tc_core, notInSelfCheckBlack);

    tcase_add_test(tc_core, inFullCheckWhite);
    tcase_add_test(tc_core, inFullCheckBlack);

    tcase_add_test(tc_core, notInFullCheckWhite);
    tcase_add_test(tc_core, notInFullCheckBlack);

    tcase_add_test(tc_core, opponentInitialPosCheckWhite);
    tcase_add_test(tc_core, opponentInitialPosCheckBlack);

    tcase_add_test(tc_core, opponentNewPosCheckWhite);
    tcase_add_test(tc_core, opponentNewPosCheckBlack);

    tcase_add_test(tc_core, opponentPawnCheckWhite);
    tcase_add_test(tc_core, opponentPawnCheckBlack);

    tcase_add_test(tc_core, opponentKnightCheckWhite);
    tcase_add_test(tc_core, opponentKnightCheckBlack);

    tcase_add_test(tc_core, opponentNotInCheckWhite);
    tcase_add_test(tc_core, opponentNotInCheckBlack);

    tcase_add_test(tc_core, mateCheckerNoMovesWhite);
    tcase_add_test(tc_core, mateCheckerNoMovesBlack);

    tcase_add_test(tc_core, mateCheckerInCheckWhite);
    tcase_add_test(tc_core, mateCheckerInCheckBlack);


    suite_add_tcase(s, tc_core);
    return s;
}


int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = checker_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
#include <check.h>
#include <stdbool.h>
#include "../linkedList.h"
#include "../fileHandling.h"



//linked list tests

START_TEST (listEmpty)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    ck_assert(isEmpty(linkedList));
    free(linkedList);
}
END_TEST



START_TEST (listNotEmpty)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    Node *new = (Node*)malloc(sizeof(Node));
    strcpy(new->val, "aa");
    new->next = NULL;

    *linkedList = new;

    ck_assert(!isEmpty(linkedList));

    clearList(linkedList);
   
}
END_TEST



START_TEST (listClear)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    Node *new = (Node*)malloc(sizeof(Node));
    strcpy(new->val, "aa");
    new->next = NULL;

    *linkedList = new;

    ck_assert(!isEmpty(linkedList));

    clearList(linkedList);

    ck_assert(isEmpty(linkedList));
   
}
END_TEST




START_TEST (listClearMultiple)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    add(linkedList, "aa");
    add(linkedList, "bb");
    add(linkedList, "cc");


    ck_assert(!isEmpty(linkedList));

    clearList(linkedList);

    ck_assert(isEmpty(linkedList));
   
}
END_TEST



START_TEST (listAddOne)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    ck_assert(isEmpty(linkedList));

    add(linkedList, "ab");

    ck_assert(!isEmpty(linkedList));

    if(*linkedList != NULL){
      Node *node= *linkedList;
      ck_assert_str_eq(node->val, "ab");

      if(node->next != NULL){
        ck_assert(0);
      }
      
    }else{
      ck_assert(0);
    }



    clearList(linkedList);

   
}
END_TEST



START_TEST (listAddMultiple)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    ck_assert(isEmpty(linkedList));

    add(linkedList, "ab");
    add(linkedList, "cd");

    ck_assert(!isEmpty(linkedList));

    if(*linkedList != NULL){
      Node *node= *linkedList;
      ck_assert_str_eq(node->val, "ab");

      if(node->next == NULL){
        ck_assert(0);
      }
      node=node->next;
      ck_assert_str_eq(node->val, "cd");

      if(node->next != NULL){
        ck_assert(0);
      }
      
    }else{
      ck_assert(0);
    }



    clearList(linkedList);

   
}
END_TEST

START_TEST (listAddOneFront)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    ck_assert(isEmpty(linkedList));

    addToFront(linkedList, "ab");

    ck_assert(!isEmpty(linkedList));

    if(*linkedList != NULL){
      Node *node= *linkedList;
      ck_assert_str_eq(node->val, "ab");

      if(node->next != NULL){
        ck_assert(0);
      }
      
    }else{
      ck_assert(0);
    }



    clearList(linkedList);

   
}
END_TEST

START_TEST (listAddMultipleFront)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    ck_assert(isEmpty(linkedList));

    addToFront(linkedList, "ab");
    addToFront(linkedList, "cd");

    ck_assert(!isEmpty(linkedList));

    if(*linkedList != NULL){
      Node *node= *linkedList;
      ck_assert_str_eq(node->val, "cd");

      if(node->next == NULL){
        ck_assert(0);
      }
      node=node->next;
      ck_assert_str_eq(node->val, "ab");

      if(node->next != NULL){
        ck_assert(0);
      }
      
    }else{
      ck_assert(0);
    }



    clearList(linkedList);

   
}
END_TEST


START_TEST (listRemoveAfterZero)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    ck_assert(isEmpty(linkedList));

    add(linkedList, "ab");
    add(linkedList, "cd");


    removeAfter(linkedList,0);


    ck_assert(!isEmpty(linkedList));

    if(*linkedList != NULL){
      Node *node= *linkedList;
      ck_assert_str_eq(node->val, "ab");

      if(node->next != NULL){ //nothing exists after ab
        ck_assert(0);
      }
      
    }else{
      ck_assert(0);
    }



    clearList(linkedList);

   
}
END_TEST


START_TEST (listRemoveAfterOne)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    ck_assert(isEmpty(linkedList));

    add(linkedList, "ab");
    add(linkedList, "cd");
    add(linkedList, "ef");

    removeAfter(linkedList, 1);

    ck_assert(!isEmpty(linkedList));

    if(*linkedList != NULL){
      Node *node= *linkedList;
      ck_assert_str_eq(node->val, "ab");

      if(node->next == NULL){
        ck_assert(0);
      }
      node=node->next;
      ck_assert_str_eq(node->val, "cd");

      if(node->next != NULL){ //nothing after cd
        ck_assert(0);
      }
      
    }else{
      ck_assert(0);
    }



    clearList(linkedList);

   
}
END_TEST

START_TEST (listRemoveAfterMultiple)
{
    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    add(linkedList, "ab");
    add(linkedList, "cd");
    add(linkedList, "ef");
    add(linkedList, "gh");
    add(linkedList, "ij");
    add(linkedList, "kl");

    removeAfter(linkedList, 3);


    List correctList = malloc(sizeof(List));
    *correctList=NULL;

    add(correctList, "ab");
    add(correctList, "cd");
    add(correctList, "ef");
    add(correctList, "gh");
    

    if(*linkedList != NULL){
      Node *node = *linkedList;
      Node *correctNode = *correctList;

      while (node != NULL){
          ck_assert_str_eq(node->val, correctNode->val);

          if((node->next != NULL && correctNode->next == NULL) || (node->next == NULL && correctNode->next != NULL)){
            ck_assert(0);
          }
          node = node->next;
          correctNode = correctNode->next;
          
      }
    }else{
      ck_assert(0);
    }
}
END_TEST




START_TEST (listGridNormal)
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

    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    add(linkedList, "23");
    add(linkedList, "56");
    add(linkedList, "17");
    add(linkedList, "44");

    listToGrid(linkedList, board);

    ck_assert(*(board+(8*3)+2) == 'X');
    ck_assert(*(board+(8*6)+5) == 'X');
    ck_assert(*(board+(8*7)+1) == 'X');
    ck_assert(*(board+(8*4)+4) == 'X');

}
END_TEST




START_TEST (listGridCorners)
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

    List linkedList = malloc(sizeof(List));
    *linkedList=NULL;

    add(linkedList, "00");
    add(linkedList, "07");
    add(linkedList, "70");
    add(linkedList, "77");

    listToGrid(linkedList, board);

    ck_assert(*(board) == 'X');
    ck_assert(*(board+(8*7)) == 'X');
    ck_assert(*(board+7) == 'X');
    ck_assert(*(board+(8*7)+7) == 'X');

}
END_TEST




Suite * list_suite(void){
  Suite *s;
  TCase *tc_core;
  s = suite_create("Chess");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, listEmpty);
  tcase_add_test(tc_core, listNotEmpty);

  tcase_add_test(tc_core, listClear);
  tcase_add_test(tc_core, listClearMultiple);

  tcase_add_test(tc_core, listAddOne);
  tcase_add_test(tc_core, listAddMultiple);

  tcase_add_test(tc_core, listAddOneFront);
  tcase_add_test(tc_core, listAddMultipleFront);

  tcase_add_test(tc_core, listRemoveAfterZero);
  tcase_add_test(tc_core, listRemoveAfterOne);
  tcase_add_test(tc_core, listRemoveAfterMultiple);

  tcase_add_test(tc_core, listGridNormal);
  tcase_add_test(tc_core, listGridCorners);


  suite_add_tcase(s, tc_core);
  return s;
}


int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = list_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
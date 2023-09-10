#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include  <stdlib.h>

#include "linkedList.h"



//add to end of a linked list
void add(List list, char value[]){
  Node *new = (Node*)malloc(sizeof(Node));
  strcpy(new->val, value);
  new->next = NULL;

  if(*list == NULL){
    *list = new;
    return;
  }

  Node *node = *list;
  while (node->next != NULL){
    node = node->next;
  }

  node->next = new;
}



//add to front of a linked list
void addToFront(List list, char value[]){
  Node *new = (Node*)malloc(sizeof(Node));
  strcpy(new->val, value);
  new->next = NULL;

  if(*list == NULL){
    *list = new;
    return;
  }

  Node *node = *list;
  *list=new;

  new->next = node;

}



//removes everything from linked list
void clearList(List list){
	if(*list==NULL){
		return;
	}
    Node *current=*list;
    Node *next;  
    

    while (current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }
    *list = NULL;
    


}


//removes everything after selected amount
void removeAfter(List list, int amount){
  int index = 0;

  if(*list != NULL){

    Node *node = *list;
    while (node != NULL & index<amount){
      node = node->next; 
      index++;
    }

    if(index==amount){
      node->next = NULL;

      Node *removedNode = node->next;

      while (removedNode != NULL){
        free(removedNode);
        removedNode = removedNode->next; 
      }

    }

  }
  
}


//checks if list is empty
bool isEmpty(List list){

  if(*list == NULL){
    return true;
  }else{
    return false;
  }


}


//prints the history in a readable form
void printHistory(List list){
  char* pos;

  if(*list != NULL){

    Node *node = *list;
    while (node != NULL){
        printf("%s ", node->val);
        node = node->next; 
    }

    printf("\n");

  }else{
    printf("\nNo history! \n");
  }
}


//prints a list
void printList(List list){
  char pos[3];

  if(*list != NULL){
    printf("\nPossible moves: ");

    Node *node = *list;
    while (node != NULL){
        pos[0]= (node->val[0] -'0') + 'A';
        pos[1]= ('7' - node->val[1]) + '1';
        printf("%s ", pos);
        node = node->next; 
    }

    printf("\n");

  }else{
    printf("\nNo possible moves! \n");
  }
}



//converts the history list to a grid
void listToGrid(List list, char* grid){
  int x;
  int y;

  if(*list != NULL){

    Node *node = *list;
    while (node != NULL){
        x = (node->val[0] -'0');
        y = (node->val[1] -'0');

        *(grid + (8*y) +x) = 'X';

        node = node->next; 
    }
  }
}




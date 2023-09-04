#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

  typedef struct n{
      char val[25];
      struct n *next;
  } Node;

  typedef Node** List;

  void add(List list, char value[]);

  void addToFront(List list, char value[]);


  void clearList(List list);

  void removeAfter(List list, int amount);

  bool isEmpty(List list);


  void printHistory(List list);

  void printList(List list);

  void listToGrid(List list, char* grid);




#endif
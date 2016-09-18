#ifndef linkedlist
#define  linkedlist

struct Node{
  int data;
  Node *next;
};

typedef Node node;

//fonksiyon prototipleri
void Display(node *);
void AddLast(node *, int );
node *AddSequential(node *, int );
node *Delete(node *, int );
#endif

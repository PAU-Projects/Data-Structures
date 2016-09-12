/* NOTES:
  listeler sequential(sıralı erişim), diziler ramdom

*/
#include "stdio.h"
#include "stdlib.h"

struct Node{
  int data;
  Node *next;
};

typedef Node node;


//fonksiyon prototipleri
void Display(node *toor);
void AddLast(node *toor, int value);
node *AddSequential(node *toor, int value);

int main(int argc, char const *argv[]) {
  node *root;
  root=NULL;
  root=AddSequential(root,16);
  root=AddSequential(root,22);
  root=AddSequential(root,12);
  root=AddSequential(root,18);
  Display(root);
  return 0;
}

void Display(node *toor){
  while (toor != NULL) {
    printf("-->%d", toor->data);
    toor=toor->next;
  }
}
//Listenin sonun eleman ekle
void AddLast(node *toor, int value) {
  while (toor->next != NULL) {
    toor=toor->next;
  }
  toor->next= (node *)malloc(sizeof(node));
  toor->next->data= value;
  toor->next->next=NULL;
}
//sıralı ekleme
node *AddSequential(node *toor, int value) {
  if (toor == NULL) { //liste boşsa
    toor=(node *)malloc(sizeof(node));
    toor->next=NULL;
    toor->data=value;
    return toor;
  }
  if (toor->data > value) { //ilk eleman kücük durumu
    node *temp = (node *)malloc(sizeof(node));
    temp->data=value;
    temp->next=toor;
    return temp;
  }
  //diğer durumlar için
  node *iterator=toor;
  while (iterator->next != NULL && iterator->next->data < value) {
    iterator=iterator->next;
  }
  node *temp = (node *)malloc(sizeof(node));
  temp->next=iterator->next;
  iterator->next=temp;
  temp->data=value;
  return toor;
}

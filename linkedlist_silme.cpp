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
node *Delete(node *toor, int value);

int main(int argc, char const *argv[]) {
  node *root;
  root=NULL;
  root=AddSequential(root,16);
  root=AddSequential(root,22);
  root=AddSequential(root,12);
  root=AddSequential(root,18);
  Display(root);
  root=Delete(root,12); //baştan silme
  root=Delete(root,16); //ortadan
  root=Delete(root,22); //sondan
  root=Delete(root,164); //olmayan eleman
  Display(root);
  return 0;
}

void Display(node *toor){
  while (toor != NULL) {
    printf("-->%d", toor->data);
    toor=toor->next;
  }
  printf("\n");
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
//silme işlemi
node *Delete(node * toor, int value) {
    node *temp, *iterator=toor;
  while (iterator->next != NULL && iterator->next->data != value) {
    iterator=iterator->next;
  }
  if (toor->data == value) { //silinecek elemanın root olma ihtimali
    temp=toor;
    toor=toor->next;
    free(temp);
    return toor;
  }
  if (iterator->next ==  NULL) { //silinecek eleman yoxdusa
    return toor;
  }
  temp=iterator->next;
  iterator->next=iterator->next->next;
  free(temp);
  return toor;
}

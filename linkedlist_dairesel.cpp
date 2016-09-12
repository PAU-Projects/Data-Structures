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
void Add(node *toor, int value);
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

//Display fonksiyonu
void Display(node *toor){
  node *iterator=toor;
  printf("-->%d", iterator->data);
  iterator=iterator->next;
  while (iterator != toor) {
    printf("-->%d", iterator->data);
    iterator=iterator->next;
  }
}
//Listenin sonun eleman ekle dairesel
void Add(node *toor, int value) {
  node *iterator=toor;
  while (iterator->next != toor) {
    iterator=iterator->next;
  }
  iterator->next= (node *)malloc(sizeof(node));
  iterator->next->data= value;
  iterator->next->next=toor;
}
//sıralı ekleme dairesel
node *AddSequential(node *toor, int value) {
  if (toor == NULL) { //liste boşsa
    toor=(node *)malloc(sizeof(node));
    toor->next=toor;
    toor->data=value;
    return toor;
  }
  if (toor->data > value) { //ilk eleman kücük durumu
    node *temp = (node *)malloc(sizeof(node));
    temp->data=value;
    temp->next=toor;
    node *iterator=toor;
    while (iterator->next != toor) {
      iterator=iterator->next;
    }
    iterator->next=temp;
    return temp;
  }
  //diğer durumlar için
  node *iterator=toor;
  while (iterator->next != toor && iterator->next->data < value) {
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
  if (toor->data == value) { //silinecek elemanın root olma ihtimali
    while (iterator->next != toor) {
      iterator=iterator->next;
    }
    iterator->next=toor->next;
    free(toor);
    return iterator->next;
  }
  while (iterator->next != toor && iterator->next->data != value) {
    iterator=iterator->next;
  }
  if (iterator->next == toor) { //silinecek eleman yoxdusa
    return toor;
  }
  temp=iterator->next;
  iterator->next=iterator->next->next;
  free(temp);
  return toor;
}

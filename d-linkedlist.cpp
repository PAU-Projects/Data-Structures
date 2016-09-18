#include "stdio.h"
#include "stdlib.h"

struct Node{
  int data;
  Node *next;
  Node *prev;
};

typedef Node node;

//fonksiyon prototipleri
void Display(node *toor);
node *AddSequential(node *toor, int value);
node *Delete(node *toor, int value);

int main(int argc, char const *argv[]) {
  node *root = (node *)malloc(sizeof(node));
  root->next=NULL;
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
  while (iterator->next != NULL) {
    printf("-->%d", iterator->next->data);
    iterator=iterator->next;
  }
}

node *AddSequential(node *toor, int value) {
    if (toor == NULL) { //liste boşsa
      toor=(node *)malloc(sizeof(node));
      toor->next=NULL;
      toor->prev=NULL;
      toor->data=value;
      return toor;
    }
    if (toor->data > value) { //ilk eleman kücük durumu,başa ekleme
      node *temp = (node *)malloc(sizeof(node));
      temp->data=value;
      temp->next=toor;
      temp->prev=NULL;
      toor->prev=temp;
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
    temp->prev=iterator;
    if (temp->next != NULL)
      temp->next->prev=temp;
    temp->data=value;
    return toor;
  }

  //silme işlemi
  node *Delete(node * toor, int value) {
    node *temp, *iterator=toor;
    if (toor->data == value) { //silinecek elemanın root
      iterator->next=toor->next;
      free(toor);
      return iterator->next;
    }
    while (iterator->next != NULL  && iterator->next->data != value) {
      iterator=iterator->next;
    }
    if (iterator->next == NULL) { //silinecek eleman yoxdusa
      printf("\nDeğer bulunmamakta\n");
      return toor;
    }
    temp=iterator->next;
    iterator->next=iterator->next->next;
    free(temp);
    if(iterator->next != NULL)
      iterator->next->prev=iterator;
    return toor;
  }

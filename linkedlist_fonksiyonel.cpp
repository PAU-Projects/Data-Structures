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
//main
int main(int argc, char const *argv[]) {
  node *root;
  root=(node *)malloc(sizeof(node)); //hafizada node boyutunda root için hüçre oluştur.
  root->next=NULL;
  root->data=16;

  //listenin sonuna 3 eleman eklemek
  for (int i = 1; i < 9; i++) {
    AddLast(root,i);
  }
   //
   node *iterator=root;
   for (int i = 0; i < 3; i++) {
     iterator=iterator->next;
   }
    //Araya eleman eklemek
   node *temp=(node *)malloc(sizeof(node));
   temp->next=iterator->next;
   iterator->next=temp;
   temp->data=444;

   Display(root);
  return 0;
}
//Display
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

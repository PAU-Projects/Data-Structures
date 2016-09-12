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
void Display(node *iterator);

int main(int argc, char const *argv[]) {
  node *root, *iterator;
  root=(node *)malloc(sizeof(node)); //hafizada node boyutunda root için hüçre oluştur.
  root->data=16;
  root->next=(node *)malloc(sizeof(node));
  root->next->data=12;
  root->next->next=(node *)malloc(sizeof(node));
  root->next->next->data=18;
  root->next->next->next=NULL;
  iterator=root;
  //printf("iterator data:%d\n", iterator->data);
  //iterator= iterator->next;
  //printf("iterator next data: %d\n", iterator->data);

  while (iterator->next != NULL) {
    printf("%d\n", iterator->data);
    iterator = iterator->next;
  }
  printf("---------------\n" );
  //listenin sonuna 3 eleman eklemek
  for (int i = 1; i < 4; i++) {
    iterator->next=(node *)malloc(sizeof(node));
    iterator= iterator->next;
    iterator->data=2*i;
    iterator->next=NULL;
  }
  //Araya eleman eklemek
  node *temp=(node *)malloc(sizeof(node));
  temp->next=iterator->next;
  iterator->next=temp;
  temp->data=444;
  Display(root);
  return 0;
}
//Display fonksiyonu
void Display(node *iterator){
  while (iterator != NULL) {
    printf("-->%d", iterator->data);
    iterator=iterator->next;
  }
}

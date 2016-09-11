#include "stdio.h"
#include "stdlib.h"

struct Node{
  int data;
  Node *next;
};

typedef Node node;
int main(int argc, char const *argv[]) {
  node *root, *iterator;
  root=(node *)malloc(sizeof(node)); //hafizada node boyutunda root için hüçre oluştur.
  iterator=root;
  root->data=16;
  root->next=(node *)malloc(sizeof(node));
  root->next->data=12;
  root->next->next=(node *)malloc(sizeof(node));
  root->next->next->data=8;
  printf("iterator data:%d\n", iterator->data);
  iterator= iterator->next;
  printf("iterator next data: %d\n", iterator->data);
  return 0;
}

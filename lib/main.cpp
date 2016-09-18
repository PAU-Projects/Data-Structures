/*
 * Kütüphane heder kullanarak linkedlist programı
 *
 *
**/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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

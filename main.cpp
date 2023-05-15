#include <iostream>
#include "BSTree.h"

int main() {
//  BSTree* tr = new BSTree();
//  tr->setup();
//  tr->rsearch(10);
//  tr->rsearch(5);
//  tr->rsearch(-20);
//  std::cout << tr->rsearch(30) << "\n";
  auto tr2 = new BSTree();
  tr2->insert(100);
  tr2->insert(20);
  tr2->rdelete(20);
  auto tr1 = new BSTree();
  tr1->insert(100);
  tr1->insert(500);
  tr1->insert(20);
  tr1->insert(30);
  tr1->insert(10);
  tr1->insert(40);
  tr1->insert(25);
  tr1->insert(21);
  std::cout << tr1->height() << "\n";
//  tr1->rdelete(30);
  std::cout << "hello\n";
  //tr->rsearch(-1);
  return 0;
}

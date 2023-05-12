#include <iostream>
#include "BSTree.h"

int main() {
  BSTree* tr = new BSTree();
  tr->setup();
  tr->rsearch(10);
  tr->rsearch(5);
  tr->rsearch(-20);
  std::cout << tr->rsearch(30) << "\n";
  //tr->rsearch(-1);
  return 0;
}

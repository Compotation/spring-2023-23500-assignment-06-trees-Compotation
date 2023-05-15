#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"

class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();

  void setup();

  std::string get_debug_string();
  

  
  int search(int value);
  int rsearch(int value);
  int rsearch(int value, Node *p);
  void insert(int value);
  int rinsert(int value);
  int rinsert(int value, Node *p);
//  Node* rdelete(Node *parent, int data, Node *upParent);
//  Node* rdelete(int data);
  Node* rdelete(Node* root, int value);
  Node* rdelete(int value);
  Node* findMin(Node *parent);
  Node* findMax(Node *parent);
  int countLeaves();
  int countLeaves(Node* root);
  int height(Node* root);
  int height();
  int treesum();
  int treesum(Node *n);
  int countodds();
  int countodds(Node *n);
  int oddsum();
  int oddsum(Node *n);
  // int searchr(int value);
  // int searchr(int value, Node *n);
  
};

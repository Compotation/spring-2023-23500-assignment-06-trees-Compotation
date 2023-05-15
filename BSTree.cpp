#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree() {
  root = nullptr;
}

int BSTree::rinsert(int value) {
  return rinsert(value, root);
}

int BSTree::rinsert(int value, Node *n) {
  if (value < n->getData()) {
    if (n->getLeft() == nullptr) {
      auto insertedNode = new Node(value);
      n->setLeft(insertedNode);
      return value;
    }
    return rinsert(value, n->getLeft());
  } else {
    if (n->getRight() == nullptr) {
      auto insertedNode = new Node(value);
      n->setRight(insertedNode);
      return value;
    }
    return rinsert(value, n->getRight());
  }
}

int BSTree::rsearch(int value) {
  return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p) {
  if (value == p->getData()) {
    return value;
  }
  if (value < p->getData()) {
    if (p->getLeft() != nullptr) {
      return rsearch(value, p->getLeft());
    }
  } else {
    if (p->getRight() != nullptr) {
      return rsearch(value, p->getRight());
    }
  }
  throw 1;
}

// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n) {
  std::string a, b, c;

  if (n == nullptr) {
    return "";
  } else {


    /*
     *  pre-order traversal
     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree

     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());


     * post-order traversal

     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node
      
     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());

    */

    /*  
	in-order traversal

	1. recurse left subtree
	2. process node
	3. recurse right subtree
    */

    a = traverse(n->getLeft());
    b = std::to_string(n->getData());
    c = traverse(n->getRight());


    return a + ", " + b + ", " + c;


  }
}

std::string BSTree::get_debug_string() {
  return traverse(root);
}

/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)

*/
int BSTree::search(int n) {
  Node *current = root;


  while (current != nullptr) {
    int node_val = current->getData();
    if (n == node_val) {
      return node_val;
    } else if (n < node_val) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  throw 1; // returning a not found value would be better

}

/*
  if the BST is full/balanced
  this will behave like a binary search - remove 1/2
  the data set each time through
  so O(lgn) preformance

  IF THE tree isn't full/balanced it degenerates
  into a linked list and you only get O(n)
*/
void BSTree::insert(int n) {
  Node *new_node = new Node(n);

  // special case if the tree is empty
  if (root == nullptr) {
    root = new_node;
    return;
  }

  // search for the insertion point
  Node *current = root;
  Node *trailer = nullptr;
  while (current != nullptr) {
    trailer = current; // catch the trailer up
    int val = current->getData();
    if (n == val) {
      // update the node with the additional stuff
      return;
    } else if (n < val) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  // if we get here, trailer points to the
  // node above the new node's location
  if (n < trailer->getData()) {
    trailer->setLeft(new_node);
  } else {
    trailer->setRight(new_node);
  }

}

int BSTree::treesum(Node *n) {
  if (n == nullptr) {
    return 0;
  } else {
    int value = n->getData();
    return value + treesum(n->getLeft())
           + treesum(n->getRight());
  }
}

int BSTree::treesum() {
  return treesum(root);
}

int BSTree::countodds(Node *n) {
  if (n == nullptr) {
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data % 2 == 0) {
      value = 0;
    } else {
      value = 1;
    }
    return value + countodds(n->getLeft())
           + countodds(n->getRight());
  }
}

int BSTree::countodds() {
  return countodds(root);
}

int BSTree::oddsum(Node *n) {
  if (n == nullptr) {
    return 0;
  } else {
    int data = n->getData();
    int value;
    if (data % 2 == 0) {
      value = 0;
    } else {
      value = data;
    }
    return value + oddsum(n->getLeft())
           + oddsum(n->getRight());
  }
}

int BSTree::oddsum() {
  return oddsum(root);
}


void BSTree::setup() {
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);

}

Node* BSTree::rdelete(Node* root, int value) {
  if (root == nullptr) {
    return root;
  }
  if (value < root->getData()) {
    root->setLeft(rdelete(root->getLeft(), value));
  } else if (value > root->getData()) {
    root->setRight(rdelete(root->getRight(), value));
  } else {
    if (root->getLeft() == nullptr) {
      Node* temp = root->getRight();
      delete root;
      return temp;
    } else if (root->getRight() == nullptr) {
      Node* temp = root->getLeft();
      delete root;
      return temp;
    } else {
      Node* temp = findMin(root->getRight());
      root->setData(temp->getData());
      root->setRight(rdelete(root->getRight(), temp->getData()));
    }
  }
  return root;
}

Node* BSTree::findMin(Node *parent) {
  if (parent == nullptr) {
    return nullptr;
  }
  if (parent->getLeft() != nullptr) {
    return findMin(parent->getLeft());
  }
  return parent;
}


Node* BSTree::findMax(Node *parent) {
  if (parent == nullptr) {
    return nullptr;
  }
  if (parent->getRight() != nullptr) {
    return findMax(parent->getRight());
  }
  return parent;
}

int BSTree::countLeaves(Node* root) {
  if (root == nullptr) {
    return 0;
  } else if (root->getLeft() == nullptr && root->getRight() == nullptr) {
    // Node is a leaf
    return 1;
  } else {
    return countLeaves(root->getLeft()) + countLeaves(root->getRight());
  }
}

int BSTree::countLeaves() {
  return countLeaves(root);
}

int BSTree::height() {
  return height(root);
}

int BSTree::height(Node *root) {
  if (root == nullptr) {
    // Base case: empty tree has height of 0
    return 0;
  } else {
    // Recursive case: height is 1 + max height of subtrees
    int leftHeight = height(root->getLeft());
    int rightHeight = height(root->getRight());
    return 1 + std::max(leftHeight, rightHeight);
  }
}

Node *BSTree::rdelete(int value) {
  return rdelete(root, value);
}


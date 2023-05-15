#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <vector>
#include <random>
#include "BSTree.h"

TEST_CASE("search") {
  std::vector<int> nums;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);

  auto tr = new BSTree();

  for (int i = 0; i < 10; i++) {
    int random_number = dis(gen);
    nums.push_back(random_number);
    tr->insert(random_number);
  }

  CHECK_EQ(tr->rsearch(nums[2]), nums[2]);
  CHECK_EQ(tr->rsearch(nums[9]), nums[9]);
  CHECK_THROWS(tr->rsearch(-1));
}

TEST_CASE("insert") {
  auto tr = new BSTree();
  tr->insert(100);
  tr->insert(50);
  tr->insert(20);
  CHECK_EQ(tr->get_debug_string(), ", 20, , 50, , 100, ");

  auto tr2 = new BSTree();
  tr2->insert(100);
  CHECK_EQ(tr2->get_debug_string(), ", 100, ");
}

TEST_CASE("delete") {
  auto tr1 = new BSTree();
  tr1->insert(100);
  tr1->insert(500);
  tr1->insert(20);
  tr1->insert(30);
  tr1->insert(10);
  tr1->insert(40);
  tr1->insert(25);
  tr1->insert(21);
  tr1->rdelete(30);
  CHECK_EQ(tr1->get_debug_string(), ", 10, , 20, , 21, , 25, , 40, , 100, , 500, ");

  auto tr2 = new BSTree();
  tr2->insert(2);
  tr2->insert(5);
  tr2->rdelete(5);
  CHECK_EQ(tr2->get_debug_string(), ", 2, ");
}

TEST_CASE("count leaves") {
  auto tr1 = new BSTree();
  tr1->insert(100);
  tr1->insert(20);
  tr1->insert(500);
  CHECK_EQ(tr1->countLeaves(), 2);

  auto tr2 = new BSTree();
  tr2->insert(2);
  CHECK_EQ(tr2->countLeaves(), 1);

  auto tr3 = new BSTree();
  tr3->insert(100);
  tr3->insert(20);
  tr3->insert(120);
  tr3->insert(110);
  tr3->insert(150);
  CHECK_EQ(tr3->countLeaves(), 3);
}
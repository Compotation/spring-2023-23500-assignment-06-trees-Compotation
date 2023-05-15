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
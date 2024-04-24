#include "linked_list.hpp"
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, InitializedAndChecked) {
  int x = 5;
  DoublyLinkedList<int> ll(&x);
  int *data = ll.get_data_at_head();
  ASSERT_EQ(*data, x);
}

TEST(DoublyLinkedListTest, NullptrInitializedAndChecked) {
  DoublyLinkedList<int> ll(nullptr);
  int *data = ll.get_data_at_head();
  ASSERT_EQ(data, nullptr);
}

TEST(DoublyLinkedListTest, PushToFront) {
  int a = 5;
  int b = 7;
  DoublyLinkedList<int> ll(&a);
  ll.push_front(&b);
  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, b);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, a);
}

TEST(DoublyLinkedListTest, PushToFrontOfNullptrInitiated) {
  int b = 7;
  DoublyLinkedList<int> ll(nullptr);
  ll.push_front(&b);
  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, b);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(tail, nullptr);
}

// purposefully try to index past length

// test with different data types

//test each function individually

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
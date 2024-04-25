#include "linked_list.hpp"
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, InitializedAndChecked) {
  int x = 5;
  DoublyLinkedList<int> ll(&x);
  int *data = ll.get_data_at_head();
  ASSERT_EQ(*data, x);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 1);
}

TEST(DoublyLinkedListTest, NullptrInitializedAndChecked) {
  DoublyLinkedList<int> ll(nullptr);
  int *data = ll.get_data_at_head();
  ASSERT_EQ(data, nullptr);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 1);
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
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 2);
}

TEST(DoublyLinkedListTest, PushToFrontOfNullptrInitiated) {
  int b = 7;
  DoublyLinkedList<int> ll(nullptr);
  ll.push_front(&b);
  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, b);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(tail, nullptr);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 2);
}

TEST(DoublyLinkedListTest, PushToBack) {
  int a = 5;
  int b = 7;
  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, b);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 2);
}

TEST(DoublyLinkedListTest, PushToIndex) {
  int a = 5; // index 0
  int b = 7; // index 1
  int c = 1; // index 2

  int x = 2; // to be inserted at index 2

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);
  ll.push_to_index(&x, 2);

  int *index_2 = ll.get_data_at_index(2);
  ASSERT_EQ(*index_2, x);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 4);
}

TEST(DoublyLinkedListTest, PushToIndexFront) {
  int a = 5; // index 0
  int b = 7; // index 1
  int c = 1; // index 2

  int x = 2; // to be inserted at index 0

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);
  ll.push_to_index(&x, 0);

  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, x);
  int *index_1 = ll.get_data_at_index(1);
  ASSERT_EQ(*index_1, a);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 4);
}

TEST(DoublyLinkedListTest, PopFromFront) {
  int a = 5;
  int b = 7;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);

  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, b);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 2);

  ll.pop_front();
  int *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, b);
  int *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, b);
  unsigned short int length2 = ll.get_length();
  ASSERT_EQ(length2, 1);
}

TEST(DoublyLinkedListTest, PopFromBack) {
  int a = 5;
  int b = 7;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);

  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, b);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 2);

  ll.pop_back();
  int *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, a);
  int *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, a);
  unsigned short int length2 = ll.get_length();
  ASSERT_EQ(length2, 1);
}

TEST(DoublyLinkedListTest, PopFromMiddle) {
  int a = 5;
  int b = 7;
  int c = 4;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);

  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  int *middle = ll.get_data_at_index(1);
  ASSERT_EQ(*middle, b);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 3);

  ll.pop_from_index(1);
  int *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, a);
  int *middle2 = ll.get_data_at_index(1);
  ASSERT_EQ(*middle2, c);
  int *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, c);
  unsigned short int length2 = ll.get_length();
  ASSERT_EQ(length2, 2);
}

TEST(DoublyLinkedListTest, PopFromFrontUsingIndex) {
  int a = 5;
  int b = 7;
  int c = 4;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);

  int *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  int *middle = ll.get_data_at_index(1);
  ASSERT_EQ(*middle, b);
  int *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  unsigned short int length = ll.get_length();
  ASSERT_EQ(length, 3);

  ll.pop_from_index(0);
  int *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, b);
  int *middle2 = ll.get_data_at_index(1);
  ASSERT_EQ(*middle2, c);
  int *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, c);
  unsigned short int length2 = ll.get_length();
  ASSERT_EQ(length2, 2);
}

// purposefully try to index past length

// test with different data types

// test each function individually

// test multiple push and pop
// test lengths maintained properly
// test pop_from_index at front and back to test proper handling of nullptrs
// test popping the last node and adding a new one

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
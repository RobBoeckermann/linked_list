#include "linked_list.hpp"
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, InitializedAndChecked) {
  int x = 5;
  DoublyLinkedList<int> ll(&x);
  auto *data = ll.get_data_at_head();
  ASSERT_EQ(*data, x);
  auto length = ll.get_length();
  ASSERT_EQ(length, 1);
}

TEST(DoublyLinkedListTest, NullptrInitializedAndChecked) {
  DoublyLinkedList<int> ll(nullptr);
  auto *data = ll.get_data_at_head();
  ASSERT_EQ(data, nullptr);
  auto length = ll.get_length();
  ASSERT_EQ(length, 1);
}

TEST(DoublyLinkedListTest, PushToFront) {
  int a = 5;
  int b = 7;
  DoublyLinkedList<int> ll(&a);
  ll.push_front(&b);
  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, b);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, a);
  auto length = ll.get_length();
  ASSERT_EQ(length, 2);
}

TEST(DoublyLinkedListTest, PushToFrontOfNullptrInitiated) {
  int b = 7;
  DoublyLinkedList<int> ll(nullptr);
  ll.push_front(&b);
  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, b);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(tail, nullptr);
  auto length = ll.get_length();
  ASSERT_EQ(length, 2);
}

TEST(DoublyLinkedListTest, PushToBack) {
  int a = 5;
  int b = 7;
  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, b);
  auto length = ll.get_length();
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

  auto *index_2 = ll.get_data_at_index(2);
  ASSERT_EQ(*index_2, x);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  auto length = ll.get_length();
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

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, x);
  auto *index_1 = ll.get_data_at_index(1);
  ASSERT_EQ(*index_1, a);
  auto length = ll.get_length();
  ASSERT_EQ(length, 4);
}

TEST(DoublyLinkedListTest, PopFromFront) {
  int a = 5;
  int b = 7;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, b);
  auto length = ll.get_length();
  ASSERT_EQ(length, 2);

  ll.pop_front();
  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, b);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, b);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 1);
}

TEST(DoublyLinkedListTest, PopFromBack) {
  int a = 5;
  int b = 7;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, b);
  auto length = ll.get_length();
  ASSERT_EQ(length, 2);

  ll.pop_back();
  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, a);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, a);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 1);
}

TEST(DoublyLinkedListTest, PopFromMiddle) {
  int a = 5;
  int b = 7;
  int c = 4;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *middle = ll.get_data_at_index(1);
  ASSERT_EQ(*middle, b);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  auto length = ll.get_length();
  ASSERT_EQ(length, 3);

  ll.pop_from_index(1);
  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, a);
  auto *middle2 = ll.get_data_at_index(1);
  ASSERT_EQ(*middle2, c);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, c);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 2);
}

TEST(DoublyLinkedListTest, PopFromFrontUsingIndex) {
  int a = 5;
  int b = 7;
  int c = 4;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *middle = ll.get_data_at_index(1);
  ASSERT_EQ(*middle, b);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  auto length = ll.get_length();
  ASSERT_EQ(length, 3);

  ll.pop_from_index(0);
  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, b);
  auto *middle2 = ll.get_data_at_index(1);
  ASSERT_EQ(*middle2, c);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, c);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 2);
}

TEST(DoublyLinkedListTest, PopFromInvalidIndexHasNoChange) {
  int a = 5;
  int b = 7;
  int c = 4;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *middle = ll.get_data_at_index(1);
  ASSERT_EQ(*middle, b);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  auto length = ll.get_length();
  ASSERT_EQ(length, 3);

  ll.pop_from_index(3);
  ll.pop_from_index(-1);
  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, a);
  auto *middle2 = ll.get_data_at_index(1);
  ASSERT_EQ(*middle2, b);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, c);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 3);
}

TEST(DoublyLinkedListTest, PushToInvalidIndexHasNoChange) {
  int a = 5;
  int b = 7;

  DoublyLinkedList<int> ll(&a);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, a);
  auto length = ll.get_length();
  ASSERT_EQ(length, 1);

  ll.push_to_index(&b, 3);
  ll.push_to_index(&b, -1);

  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, a);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, a);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 1);
}

TEST(DoublyLinkedListTest, GetDataAtInvalidIndex) {
  int a = 5;

  DoublyLinkedList<int> ll(&a);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, a);
  auto length = ll.get_length();
  ASSERT_EQ(length, 1);

  auto *invalid = ll.get_data_at_index(1);
  ASSERT_EQ(invalid, nullptr);
  auto *invalid2 = ll.get_data_at_index(-1);
  ASSERT_EQ(invalid2, nullptr);
}

TEST(DoublyLinkedListTest, PopLastNodeAndAddNewOne) {
  int a = 5;
  int b = 7;

  DoublyLinkedList<int> ll(&a);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, a);
  auto length = ll.get_length();
  ASSERT_EQ(length, 1);

  ll.pop_front();

  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(head2, nullptr);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(tail2, nullptr);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 0);

  ll.push_front(&b);

  auto *head3 = ll.get_data_at_head();
  ASSERT_EQ(*head3, b);
  auto *tail3 = ll.get_data_at_tail();
  ASSERT_EQ(*tail3, b);
  auto length3 = ll.get_length();
  ASSERT_EQ(length3, 1);
}

TEST(DoublyLinkedListTest, PushPastLengthLimitIsIgnored) {
  size_t max_size = std::numeric_limits<unsigned short int>::max();
  int arr[max_size];
  for (size_t i = 0; i < max_size; i++) {
    arr[i] = i;
  }
  DoublyLinkedList<int> ll(&arr[0]);
  for (size_t i = 1; i < max_size; i++) {
    ll.push_back(&arr[i]);
  }

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, arr[0]);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, arr[max_size - 1]);
  auto length = ll.get_length();
  ASSERT_EQ(length, max_size);

  int overflow = 42;
  ll.push_back(&overflow);
  ll.push_front(&overflow);
  ll.push_to_index(&overflow, 555);
  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, arr[0]);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, arr[max_size - 1]);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, max_size);
}

TEST(DoublyLinkedListTest, TestChar) {
  char a = 'a';
  char b = 'b';
  char c = 'c';

  DoublyLinkedList<char> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *middle = ll.get_data_at_index(1);
  ASSERT_EQ(*middle, b);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  auto length = ll.get_length();
  ASSERT_EQ(length, 3);

  ll.pop_from_index(1);
  ll.pop_back();
  ll.pop_front();
  ll.push_front(&b);

  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, b);
  auto *middle2 = ll.get_data_at_index(0);
  ASSERT_EQ(*middle2, b);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, b);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 1);
}

TEST(DoublyLinkedListTest, TestString) {
  std::string a = "Hello, ";
  std::string b = "World";
  std::string c = "!";

  DoublyLinkedList<std::string> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);

  auto *head = ll.get_data_at_head();
  ASSERT_EQ(*head, a);
  auto *middle = ll.get_data_at_index(1);
  ASSERT_EQ(*middle, b);
  auto *tail = ll.get_data_at_tail();
  ASSERT_EQ(*tail, c);
  auto length = ll.get_length();
  ASSERT_EQ(length, 3);

  ll.pop_from_index(1);
  ll.pop_back();
  ll.pop_front();
  ll.push_front(&b);

  auto *head2 = ll.get_data_at_head();
  ASSERT_EQ(*head2, b);
  auto *middle2 = ll.get_data_at_index(0);
  ASSERT_EQ(*middle2, b);
  auto *tail2 = ll.get_data_at_tail();
  ASSERT_EQ(*tail2, b);
  auto length2 = ll.get_length();
  ASSERT_EQ(length2, 1);
}

TEST(DoublyLinkedListTest, Listception) {
  int a = 5;
  int b = 7;
  int c = 4;
  int d = 8;
  int e = 0;
  int f = 9;

  DoublyLinkedList<int> ll(&a);
  ll.push_back(&b);
  ll.push_back(&c);
  DoublyLinkedList<int> ll2(&d);
  DoublyLinkedList<int> ll3(&e);
  ll3.push_back(&f);

  DoublyLinkedList<DoublyLinkedList<int>> ll_ll(&ll);
  ll_ll.push_back(&ll2);
  ll_ll.push_back(&ll3);

  auto *head = ll_ll.get_data_at_head();
  ASSERT_EQ(head, &ll);
  auto *middle = ll_ll.get_data_at_index(1);
  ASSERT_EQ(middle, &ll2);
  auto *tail = ll_ll.get_data_at_tail();
  ASSERT_EQ(tail, &ll3);
  auto length = ll_ll.get_length();
  ASSERT_EQ(length, 3);

  ll_ll.pop_from_index(1);
  ll_ll.pop_back();
  ll_ll.pop_front();
  ll_ll.push_front(&ll3);

  auto *head2 = ll_ll.get_data_at_head();
  ASSERT_EQ(head2, &ll3);
  auto *middle2 = ll_ll.get_data_at_index(0);
  ASSERT_EQ(middle2, &ll3);
  auto *tail2 = ll_ll.get_data_at_tail();
  ASSERT_EQ(tail2, &ll3);
  auto length2 = ll_ll.get_length();
  ASSERT_EQ(length2, 1);

  auto head3 = head2->get_data_at_head();
  ASSERT_EQ(*head3, e);
  auto tail3 = head2->get_data_at_tail();
  ASSERT_EQ(*tail3, f);
  auto length3 = head2->get_length();
  ASSERT_EQ(length3, 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
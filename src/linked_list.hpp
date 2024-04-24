#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory> //for std::unique_ptr

template <typename T> class Node {
  T *data;
  Node *next;
  Node *previous;

public:
  Node() : data(nullptr), next(nullptr), previous(nullptr) {}
  Node(T *value) : data(value), next(nullptr), previous(nullptr) {}

  T *get_data() { return data; }
  void set_data(T *new_data) { data = new_data; }
  Node *get_next() { return next; }
  void set_next(Node<T> *node) { next = node; }
  Node *get_previous() { return previous; }
  void set_previous(Node<T> *node) { previous = node; }
};

template <typename T> class DoublyLinkedList {
  Node<T> *head;
  Node<T> *tail;
  unsigned short int length = 0;

public:
  DoublyLinkedList(T *value) : head(nullptr), tail(nullptr) {
    // TODO: use std::unique_ptr to prevent memory leaks
    head = new Node<T>(value);
    tail = head;
  }

  // get node at index (head = index 0)
  Node<T> *getNodeAtIndex(unsigned short int desired_index) {
    unsigned short int current_index;
    Node<T> *current_node = nullptr;
    if (desired_index > length) {
      // TODO: throw error
      // nullptr could be a valid return
      return nullptr;
    }
    if (desired_index < ((length + 1) / 2)) {
      // start from head
      current_node = head;
      current_index = 0;
      while (current_index != desired_index) {
        current_node = current_node->get_next();
        current_index++;
      }
    } else {
      // start from tail
      current_node = tail;
      current_index = length;
      while (current_index != desired_index) {
        current_node = current_node->get_previous();
        current_index--;
      }
    }

    return current_node;
  }

  T *get_data_at_index(unsigned short int desired_index) {
    Node<T> *node = getNodeAtIndex(desired_index);
    return node->get_data();
  }

  T *get_data_at_head() {
    return get_data_at_index(0);
  }

  T *get_data_at_tail() {
    return get_data_at_index(length);
  }

  //  add to front
  void push_front(T *value) {
    // TODO: use std::unique_ptr to prevent memory leaks
    Node<T> *new_head = new Node<T>(value);
    new_head->set_next(head);
    head->set_previous(new_head);
    head = new_head;
    length++;
  }
  // add to back
  // remove from front
  // remove from back
  // remove from index
  // remove first of value
  // remove all of value
};

//TODO: doxygen comments?

#endif /* LINKED_LIST_HPP */

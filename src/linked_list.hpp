#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename T> class Node {
  T *data;
  Node *next;
  Node *previous;

public:
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
    head = new Node<T>(value);
    tail = head;
    length++;
  }

  unsigned short int get_length() { return length; }

private:
  Node<T> *get_node_at_index(unsigned short int desired_index) {
    unsigned short int current_index;
    Node<T> *current_node = nullptr;
    if (desired_index < 0 || desired_index > length - 1) {
      return nullptr;
    }
    if (desired_index < ((length) / 2)) {
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
      current_index = length - 1;
      while (current_index != desired_index) {
        current_node = current_node->get_previous();
        current_index--;
      }
    }

    return current_node;
  }

public:
  T *get_data_at_index(unsigned short int desired_index) {
    Node<T> *node = get_node_at_index(desired_index);
    return node->get_data();
  }

  T *get_data_at_head() { return get_data_at_index(0); }

  T *get_data_at_tail() { return get_data_at_index(length - 1); }

  void push_to_index(T *value, unsigned short int desired_index) {
    Node<T> *new_node = new Node<T>(value);
    Node<T> *node_before_desired = get_node_at_index(desired_index - 1);
    Node<T> *node_after_desired = nullptr;
    if (node_before_desired)
      node_after_desired = node_before_desired->get_next();
    else
      node_after_desired = get_node_at_index(desired_index);

    new_node->set_next(node_after_desired);
    new_node->set_previous(node_before_desired);
    if (node_before_desired) {
      if (node_after_desired) {
        // new node is in the middle somewhere
        node_before_desired->set_next(new_node);
        node_after_desired->set_previous(new_node);
      } else {
        // new node is the tail
        node_before_desired->set_next(new_node);
        tail = new_node;
      }
    } else {
      if (node_after_desired) {
        // new node is the head
        node_after_desired->set_previous(new_node);
        head = new_node;
      } else {
        // list is empty
        head = new_node;
        tail = new_node;
      }
    }
    length++;
  }

  void push_front(T *value) { push_to_index(value, 0); }

  void push_back(T *value) { push_to_index(value, length); }

  void pop_from_index(unsigned short int index) {
    Node<T> *node = get_node_at_index(index);
    Node<T> *node_before = node->get_previous();
    Node<T> *node_after = node->get_next();

    if (node_before) {
      if (node_after) {
        // node is in the middle somewhere
        node_before->set_next(node_after);
        node_after->set_previous(node_before);
      } else {
        // node is the tail
        node_before->set_next(nullptr);
        tail = node_before;
      }
    } else {
      if (node_after) {
        // node is the head
        node_after->set_previous(nullptr);
        head = node_after;
      } else {
        // node is the only node in the list
        head = nullptr;
        tail = nullptr;
      }
    }
    delete node;
    length--;
  }

  void pop_front() { pop_from_index(0); }

  void pop_back() { pop_from_index(length - 1); }
};

#endif /* LINKED_LIST_HPP */

#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {

  struct Node {
    T data;
    Node* next;
  };

  int size = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

  Node* copy(Node* n) {
    return new Node {n->data, n->next ? copy(n->next) : nullptr};
  }

public:

  ~Queue() {
    while (head != nullptr) {
      dequeue();
    }
  }

  Queue() = default;

  Queue(const Queue& q) = delete;
  Queue& operator=(const Queue& q) = delete;

  Queue(Queue&& q): size(q.size), head(q.head), tail(q.tail) {
    q.tail = nullptr;
    q.head = nullptr;
    q.size = 0;
  }

  Queue& operator=(Queue&& q) {
    if (&q != this) {
      size = q.size;
      tail = q.tail;
      q.tail = nullptr;
      q.size = 0;
    }
    return *this;
  }

  int get_size() {
    return size;
  }

  T get_head() {
    return head->data;
  }

  T get_tail() {
    return tail->data;
  }

  void enqueue(T x) {
    if(size == 0){
        head = new Node {x, nullptr};
        tail = head;
    }
    Node *temp = new Node {x, nullptr};
    tail->next = temp;
    tail = temp;
    size++;
  }

  T dequeue() {
    if(size == 0){
        throw underflow_error("Queue Underflow");
    } else if (size == 1) {
      T valueToReturn = head->data;
      delete head;
      head = nullptr;
      size--;
      return valueToReturn;
    }else{
      Node* nodeToDelete = tail;
      T valueToReturn = head->data;
      head = head->next;
      size--;
      delete nodeToDelete;
      return valueToReturn;
    }
  }
};

  Queue<int> oneTwoThree() {
    Queue<int> z;
    z.enqueue(3);
    z.enqueue(2);
    z.enqueue(1);
    return z;
  }

#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {

  struct Node {
    T data;
    Node* prev;
    Node * next;
  };

  int size = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

  Node* copy(Node* n) {
    return new Node {n->data, n->next ? copy(n->next) : nullptr};
  }

public:

  ~Queue() {
    while (tail != nullptr) {
      dequeue();
    }
  }

  Queue() = default;

  Queue(const Queue& q) = delete;
  Queue& operator=(const Queue& q) = delete;

  Queue(Queue&& q): size(q.size), tail(q.tail) {
    q.tail = nullptr;
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
        head = new Node {x, head, nullptr};
    }
    tail = new Node {x, tail, nullptr};
    size++;
  }

  T dequeue() {
    if(size == 0){
        throw underflow_error("Queue Underflow");
    }
    Node* nodeToDelete = head;
    T valueToReturn = head->data;
    head = head->next;
    size--;
    delete nodeToDelete;
    return valueToReturn;
  }
};

int main() {
  Queue<int> s;
  assert(s.get_size() == 0);
  s.enqueue(100);
  assert(s.get_head() == 100);
  cout << "All tests passed\n";
}

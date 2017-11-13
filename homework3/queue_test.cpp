#include "queue.h"

int main() {
  Queue<int> s;
  assert(s.get_size() == 0);
  s.enqueue(100);
  assert(s.get_head() == 100);
  assert(s.get_size() == 1);
  s.enqueue(200);
  assert(s.get_tail() == 200);
  assert(s.get_size() == 2);
  assert(s.dequeue() == 100);
  assert(s.get_size() == 1);

  Queue<int> q = oneTwoThree();

  q = oneTwoThree();

  q.dequeue();

  cout << "All tests passed\n";
}

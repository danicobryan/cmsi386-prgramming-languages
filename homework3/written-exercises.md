# Problem 1.
##### 1. On your machine, find the address of A[0][0] and A[3][7]. Explain why these values are what you found them to be.

- The address of A[0][0] is 0x7fff5c3717d0 and the address of A[3][7] is 0x7fff5c3718f8. These values are located in the stack and are the address of the first element in the arrays. A[3][7] takes up 21*8 gb of space in the stack.

# Problem 2.
##### 2. Explain the meaning of the following C++ declarations:
```cpp
double *a[n];
```
- this is a pointer to the array a of size n.

 ```cpp
 double (*b)[n];
 ```
- b is a pointer to the int array of doubles of size n.

```cpp
double (*c[n])();
```
- c is an array of pointers to functions that return doubles.

```cpp
double (*d())[n];
```
- d is a function returning a pointer to an array of n doubles.

# Problem 3.
##### 3. Describe rigorously, in English, the type of f.
```cpp
double (*f(double (*)(double, double[]), double)) (double, ...);
```
- f is a pointer to a function that takes in 2 arguments: 1) another function that takes a double as the first argument and an array of doubles as the second argument. 2) a double. This function returns another function that passes in at least one double, and then returns a double.

# Problem 4.
##### 4. Suppose we have this code. Does the representation of a Derived object contain one b field or two? If two, are both accessible, or only one? Under what circumstances? Tell the story of how things are.
```cpp
class Base {
public:
  int a;
  std::string b;
};

class Derived: Base {
public:
  float c;
  int b;
};
```
- The Derived base object only contains the int b object and not the std::string b. If you were to add the line using base; to the derived base class, the a and std::string b fields.

# Problem 5.
##### 5. What does the following C++ program output?
```cpp
#include <iostream>
int x = 2;
void f() { std::cout << x << '\n'; }
void g() { int x = 5; f(); std::cout << x << '\n'; }
int main() {
  g();
  std::cout << x << '\n';
}
```
- the program outputs 2, then 5 on the next line, and then 2 again on the third line.
- If C++ used dynamic scoping the output would be 5 on the first line, 5 on the second line, and 5 on the third line.

# Problem 6.
##### 6. Suppose you were asked to write a function to scramble (shuffle) a given array, in a mutable fashion. Give the function signature for a shuffle function for (a) a raw array (b) a std::array

(a)
```cpp
void shuffle(auto &arr);
```
(b)
```cpp
template<typename T, size_t SIZE> void shuffle(std::array<T,s> &&arr);
```

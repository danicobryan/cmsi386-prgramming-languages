# Problem 1.
1. On your machine, find the address of A[0][0] and A[3][7]. Explain why these values are what you found them to be. ...

- The address of A[0]\[0] is 0x7fff5c3717d0 and the address of A[3][7] is 0x7fff5c3718f8.

# Problem 2.
2. Explain the meaning of the following C++ declarations:
```cpp
double \*a[n];
```
- this is a pointer to the array a of size n.

 ```cpp
 double (\*b)[n];
 ```
- b is a pointer to the int array of doubles of size n.

```cpp
double (\*c[n])();
```
-

```cpp
double (\*d())[n];
```
-

# Problem 3.
3. Describe rigorously, in English, the type of f.
```cpp
double (*f(double (*)(double, double[]), double)) (double, ...);
```
- f is a pointer to a function that takes in 2 arguments: 1) another function that takes a double as the first argument and an array of doubles as the second argument. 2) a double. The function call takes a double as the first argument, and an unlimited amount of arguments after that.

# Problem 4.
4. Suppose we have this code. Does the representation of a Derived object contain one b field or two? If two, are both accessible, or only one? Under what circumstances? Tell the story of how things are.
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

# Problem 5.
5. What does the following C++ program output?
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
- If C++ used dynamic scoping the output would be 5 on the first, line, 5 on the second line, and 5 on the third line.

# Problem 6.
###### 6. Suppose you were asked to write a function to scramble (shuffle) a given array, in a mutable fashion. Give the function signature for a shuffle function for
+ a raw array
+ a std::array

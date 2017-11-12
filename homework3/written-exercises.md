1. On your machine, find the address of A[0][0] and A[3][7]. Explain why these values are what you found them to be.
 
 The address of A[0]\[0] is 0x7fff5c3717d0 and the address of A[3][7] is 0x7fff5c3718f8.

2. Explain the meaning of the following C++ declarations:
```cpp
double \*a[n];
```


 ```cpp
 double (\*b)[n];
 ```

```cpp
double (\*c[n])();
```

```cpp
double (\*d())[n];
```

3. Describe rigorously, in English, the type of f.
```double (*f(double (*)(double, double[]), double)) (double, ...);
```

4. Suppose we have:
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
Does the representation of a Derived object contain one b field or two? If two, are both accessible, or only one? Under what circumstances? Tell the story of how things are.

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

6. Suppose you were asked to write a function to scramble (shuffle) a given array, in a mutable fashion. Give the function signature for a shuffle function for
...(a) a raw array..
...(b) a std::array..

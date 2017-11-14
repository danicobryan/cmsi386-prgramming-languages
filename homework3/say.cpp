#include <iostream>
#include <cassert>
#include<string>

using namespace std;

struct Say {
private:
  std::string result;
public:
  Say(std::string s = ""): result(s) {}

  Say operator()(std::string value) {
    if(result.size() > 0){
        return Say(result + " " + value);
    }else{
     return Say(result + value);
    }
  }

  std::string operator()() {
    return result;
  }
};

Say f;

int main() {
  string hi = std::string("hello");
  assert(f() == "");
  assert(f("hello")().compare(hi) == 0);
  assert(f("hello")("my")("name")("is")("emily")().compare("hello my name is emily") == 0);
  assert(f("ryan")("is")("not")("cool")().compare("ryan is not cool") == 0);
  cout << "Yep, all tests passed, LIT AF!\n";
}

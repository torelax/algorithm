#include <iostream>
using namespace std;

class A {
private:
 const int i1 = 1;
 int i2 = 2;
 static const int i3 = 3; 
 
public:
  int a;
 A() {
  a = 1;
  cout << "A::a" << endl;
 }
 
 ~A() {}
 
 void getI() {
  cout << "i1 = " << i1 << "   "
       << "i2 = " << i2 << "   "
       << "i3 = " << i3 << endl;
 }
};

int main(int argc, char const *argv[])
{
    A a;
    a.getI();
    return 0;
}

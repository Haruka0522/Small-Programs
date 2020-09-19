#include<iostream>

using namespace std;

class MyClass{
  public:
    int getI();
    void setI(int i);
  private:
    int i;
};

int MyClass::getI(){
  return i;
}

void MyClass::setI(int i){
  this->i = i;
}

void value(int i){
  i++;
  cout << "Value in value: " << i << "\n";    // この関数内のiの値、main関数内のものとは別物。
  cout << "Address in value: " << &i << "\n"; // この関数内のiのアドレス。上記同様main関数のものとは別物。
  cout << "\n";
}

void pointer(int *i){
  // *i++; できない
  *i += 1;
  cout << "Value in pointer: " << i << "\n";     // main関数内のiのアドレス。
  cout << "Address in pointer: " << &i << "\n";  // この関数内のmain関数内のiを指すポインタのアドレス。
  cout << "Pointer in pointer: " << *i << "\n";  // main関数内のiのアドレスに格納された値。
  cout << "\n";
}

void reference(int &i){
  i++;
  cout << "Value in reference: " << i << "\n";    // main関数内のiのアドレスに格納された値, すなわちpointerの1番下のやつと同じ
  cout << "Address in reference: " << &i << "\n"; // main関数内のiのアドレス。
  cout << "\n";
}

void objectValue(MyClass c){
  c.setI(c.getI()+1);
  cout << "Address in objectValue: " << &c << "\n";    // mainとは別物。
  cout << "Value of MyClass::i: " << c.getI() << "\n";
  cout << "\n";
}

void objectPointer(MyClass *c){
  c->setI(c->getI()+1);
  cout << "Address in objectPointer: " << &c << "\n";   // なぜかobjectValueと同じになる。
  // cout << "Pointer in objecPointer: " << *c << "\n"; できない。
  cout << "Value of MyClass::i: " << c->getI() << "\n"; // 逆参照演算子*がいらない。
  cout << "\n";
}

void objectReference(MyClass &c){
  c.setI(c.getI()+1);
  cout << "Address in objectReference: " << &c << "\n"; // main関数と同じ。
  cout << "Value of MyClass::i: " << c.getI() << "\n";
  cout << "\n";
}

int main(){
  int i = 10;
  cout << "Value in main: " << i << "\n";
  cout << "Address in main: " << &i << "\n";
  cout << "\n";
  value(i);
  pointer(&i);
  reference(i);

  MyClass c;
  c.setI(10);
  cout << "Object address in main: " << &c << "\n";
  cout << "Value of i in main: " << c.getI() << "\n";
  cout << "\n";
  objectValue(c);
  objectPointer(&c);
  objectReference(c);
  return 0;
}

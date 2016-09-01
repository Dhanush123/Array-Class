#include<iostream>
using namespace std;

#include<cassert>

class Array{
  int values[100];
  int dummy;

  public:
  Array();
  int capacity( ) const {return 100;}
  int operator[ ](int) const;
  int& operator[ ](int);
};

Array::Array(){
  for (int index = 0; index < 100; index++)
    values[index] = 0;
}

int Array::operator[ ](int index) const{
  if (index < 0 || index >= 100)
    return 0; // a copy
  return values[index]; // a copy
}

int& Array::operator[ ](int index){
  if (index < 0 || index >= 100)
    return dummy; // a mutable reference
  return values[index]; // a mutable reference
}

int main(){
  Array a;

  cout << "\nTesting Array::Array\n";
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == 0);

  cout << "\nTesting the Array::operator[ ] setter\n";
  a[1] = 123;
  a[2] = 546;
  cout << "EXPECTED: 123 for a[1]\n";
  cout << "ACTUAL: " << a[1] << endl;
  assert(123 == a[1]);
  cout << "EXPECTED: 546 for a[2]\n";
  cout << "ACTUAL: " << a[2] << endl;
  assert(546 == a[2]);
  a[-1000] = 222;
  cout << "EXPECTED: 111 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(123 == a[1]);
  assert(546 == a[2]);
  assert(222 == a[-3]);
  assert(222 == a[100]);
  assert(222 != a[11]);
  assert(222 != a[0]);

  cout << "\nTesting the Array::operator[ ] getter\n";
  const Array b = a;
  for (int i = 0; i < 10; i++)
    assert(a[i] == b[i]);


  cout << "\nConst object test\n";
  const Array c;
  assert(c.capacity());
  assert(c[0] == c[0]);
}

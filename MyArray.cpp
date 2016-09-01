#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include<cstdlib>

class Array
{
  int values[100];
  int dummy;

  public:
  Array();
  int capacity( ) const {return 100;}
  int operator[ ](int) const;
  int& operator[ ](int);
};

vector<string> parseString(string);

const int PLACED = 200;

int main(){
  Array valStore;
  Array storeStatus;
  int storeTotal = 0;
  string index;
  string value;
  vector<string> tokens;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q"){
      break;
    }
    cin >> value;
    cin.ignore(1000,10);
    valStore[atoi(index.c_str())] = atoi(value.c_str());
    storeStatus[atoi(index.c_str())] = PLACED;
  }while(index != "Q" || index != "q");
  cout << endl;

  for(int i = 0; i < 100; i++){
    if(storeStatus[i] == PLACED){
      storeTotal++;
    }
  }
  cout << "You stored this many values: " << storeTotal << endl;

  cout << "The index-value pairs are:" << endl;
  for(int i = 0; i < 100; i++){
    if(storeStatus[i] != 0){
      cout << i << " => " << valStore[i] << endl;
    }
  }
  cout << endl;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q"){
      break;
    }
    if(storeStatus[atoi(index.c_str())] == PLACED && atoi(index.c_str()) >=0 && atoi(index.c_str()) < 100){
      int valFind = valStore[atoi(index.c_str())];
      cout << "Found it -- the value stored at " << index << " is " << valFind << "\n";
    }
    else{
      cout << "I didn't find it\n";
    }
  }while(index != "Q" || index != "q");
}

Array::Array()
{
  for (int index = 0; index < 100; index++)
    values[index] = 0;
}

int Array::operator[ ](int index) const
{
  if (index < 0 || index >= 100)
    return 0; // a copy
  return values[index]; // a copy
}

int& Array::operator[ ](int index)
{
  if (index < 0 || index >= 100)
    return dummy; // a mutable reference
  return values[index]; // a mutable reference
}

vector<string> parseString(string str){
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

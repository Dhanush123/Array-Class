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

int main(){
  Array valStore;
  Array storeStatus;
  int storeIndex = 0;
  string input;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    getline(cin,input);
    vector<string> tokens = parseString(input);
    if(tokens.at(0) == "Q" || tokens.at(0) == "q"){
      break;
    }
    int index = atoi(tokens.at(0).c_str());
    int value = atoi(tokens.at(1).c_str());

    valStore[index] = value;
    storeStatus[storeIndex] = index;
    storeIndex++;
  }while(input!="Q" || input!="q");

  cout << "You stored this many values: " << storeIndex << endl;
  cout << "The index-value pairs are:" << endl;
  for(int i = 0; i < storeIndex; i++){
    cout << storeStatus[i] << " => " << valStore[storeStatus[i]] << endl;;
  }

  do{
    cout << "Input an index and a value [Q to quit]: ";
    getline(cin,input);
    cout << endl;
    vector<string> tokens = parseString(input);
    if(tokens.at(0) == "Q" || tokens.at(0) == "q"){
      break;
    }
    int index = atoi(tokens.at(0).c_str());
    if(index < 100 && index >=0){
      bool isUsed = false;
      for(int i = 0; i < storeIndex; i++){
        if(storeStatus[i]==index){
          isUsed = true;
        }
      }
      if(isUsed){
        int valFind = valStore[index];
        cout << "The value at this index is: " << valFind << "\n";
      }
      else{
        cout << "This index has not been used. Try another index. \n";
      }
    }
    else{
      cout << "Invalid index. Please try another index." << endl;
    }
  }while(input!="Q" || input!="q");
}

Array::Array()
{
  int dummy;
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

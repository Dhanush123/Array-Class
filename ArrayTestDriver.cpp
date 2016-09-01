//class Array
//{
//  int values[100];
//  int dummy;
//
//  public:
//  Array();
//  int capacity( ) const {return 10;}
//  int operator[ ](int) const;
//  int& operator[ ](int);
//};
//
//Array::Array()
//{
//  for (int index = 0; index < 10; index++)
//    values[index] = 0;
//}
//
//int Array::operator[ ](int index) const
//{
//  if (index < 0 || index >= 10)
//    return 0; // a copy
//  return values[index]; // a copy
//}
//
//int& Array::operator[ ](int index)
//{
//  if (index < 0 || index >= 10)
//    return dummy; // a mutable reference
//  return values[index]; // a mutable reference
//}

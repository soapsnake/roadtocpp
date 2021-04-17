//
// Created by soapsnake@gmail.com on 4/6/21.
//
#include "iostream"

using namespace std;

int main() {

  int var1;
  char var2[10];

  cout << "var1 变量的地址";
  cout << &var1 << endl;

  cout << "var2 变量的地址" << &var2 << endl;

  int var = 20;

  int *ip;

  ip = &var;  //指针指向内存地址, 指针可以接受两种赋值: 1.另外一个指针 2.一个内存地址

  cout << "value of var variable " << var << endl;
  cout << "address stored in ip variable " << ip << endl;
  cout << "value of *ip variable " << *ip << endl;

  return 0;
}

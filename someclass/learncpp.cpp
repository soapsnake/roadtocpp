//
// Created by soapsnake@gmail.com on 2019/11/9.
//
#include "iostream"
#include <cmath>

using namespace std;
const double PI = 3.1415926;

void displayResult();

int compare(int x, int y, int z);

int main(void) {
    int b(5);
    int a = b;

    displayResult();

    int res = compare(1, 2, 3);
    cout << "res = " << res << endl;

    int arr[4] = {1, 2, 3, 4};
    int arr2[3] = {1, 2};
    cout << "arr = " << arr2 << endl;

    int arr3[] = {1, 2, 3, 4};  //c++同样允许这样初始化
    int arr4[4];

    typedef int boolean;

}

void displayResult() {

}

int compare(int x, int y, int z) {
    int res = x > y > z;
    int c = 9 + (x == y);   //c++ 中,true == 1, false == 0
    if (x == y) {

    }
    if (x = y) {   //c++中, 整数也可以被当做判断条件

    }

}



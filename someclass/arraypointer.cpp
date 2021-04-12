//
// Created by soapsnake@gmail.com on 19/11/19.
//
#include <iostream>
using namespace std;

int main() {
    cout << "hello world" << endl;

    //数组名字意味数组第一个元素的地址
    char buf[6], data[6], *p, *q;
    int i;
    p = &buf[0];    //数组首元素地址赋给指针
    q = &data[0];   //数组首元素地址赋给指针
    for (int j = 0; j < 6; ++j) {
        p[j] = 'A' + j;
        q[j] = 'a' + j;
    }

    p = &buf[3];
    for (int k = 0; k < 3; ++k) {
        p[k] = q[k];
    }


    return 0;
}


//
// Created by soapsnake@gmail.com on 2018/11/3.
//

#include "myfirst.h"

#include <iostream>
int wocao(int);   //要调用一个函数必须先声明函数原型

int main() {
    using namespace std;   //名称空间编译指令,这个是函数级别的,也可以声明在👆,那么就是全局级别的
    cout << "come up and c++ me some time";   //<<符号实际上是运算符的重载,它也有按位操作的意思,这里则是把字符串赋给输出流
    cout << endl;
    cout << "you won't regret it!" << endl;
//    cin.get();
    int caores = wocao(2);
    cout << "caores is:" << caores << endl;

    char ch;
//    cout << "Enter a character: " << endl;
//    cin >> ch;
//    cout << "Hola! ";
//    cout << "Thank u for the " << ch << " character." << endl;


    int donuts = 6;
    cout << "donuts value = " << donuts << endl;
    cout << "donuts address = " << &donuts << endl;    //&变量可以取到变量的内存地址
    cout << "get donuts from pointer,donuts = " << *&donuts << endl;   //用指针取donuts内存地址处的值


    int updates = 7;
    int *p_updates;  //p_updates变量的类型是指针,这里*前面的int表明这个指针指向的是一个int型变量,这个指针只能指向int值

    cout << "the p_updates = " << p_updates << endl;

    p_updates = &updates;
    cout << "the p_updates = " << p_updates << endl;
    cout << "the *p_updates = " << *p_updates << endl;
    cout << "the *p_updates + 1 = " << *p_updates + 1 << endl;
    cout << "the updates = " << updates << endl;

    cout << "the p_updates + 1) = " << p_updates + 1 << endl;
    cout << "the *(p_updates + 1) = " << *(p_updates + 1) << endl;   //内存地址加1,值是多少?

    long updates2 = 10;
//    p_updates = updates2;    //不能把int型指针指向一个long类型变量

    int nights = 1001;
    int *pt = new int;
    *pt = 1001;
    cout << "the nights address = " << &nights << endl;
    cout << "the pt = " << pt << endl;   //很有意思,pt指针指向的值和nights一样,但是他们的内存地址不一样

    int *parr = new int[3];   //无名数组,只有一个指针指向它
    parr[0] = 7;      //指针当成数组名字使用
    parr[1] = 24;
    parr[2] = 83;
    cout << "arr[0] = " << *parr << endl;
    cout << "arr[1] = " << *(parr + 1) << endl;   //指针偏移


    return 0;
}

int wocao(int n) {
    std::cout << "n is " << n << std::endl;
    return n * 2;
}
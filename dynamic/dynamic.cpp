//
// Created by soapsnake@gmail.com on 2018/11/11.
//
#include <iostream>
#include <cstring>
using namespace std;
char * getname(void);

//宏函数,实现了函数的可替换,如果是在java中,可以使用多态实现同样的功能
#define MEAN(X,Y) (((X)+(Y))/2)

int main() {

    char * name;
    name = getname();
    cout << name << " at " << (int *) name << endl;
    delete [] name;  //正常情况下new 和delete必须成对出现

    cout << name << " at " << (int *) name << endl;

    name = getname();
    cout << name << " at " << (int *) name << endl;
    delete [] name;   //运行后观察程序会发现,哪怕两次输入的name一样,内存地址也会变


    int res = 0;
    res = MEAN(2,8);
    cout << "res = " << res;
    return 0;
}

char * getname() {
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    return pn;
}



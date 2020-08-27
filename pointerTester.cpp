//
// Created by soapsnake@gmail.com on 16/11/19.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int * pi;
    char * pc;

    pi = new int;
    if (pi == NULL) {
        cout << "out of memory/n" << endl;
        return 0;
    }

    pc = new char;
    if (pc == 0) {
        cout << "out of memory/n" << endl;
        return 0;
    }

    *pi = 8432984;
    if (*pi > 0) {
        cout << "can here" << endl;
        *pc = 'a';
    }

    cout << "integer on the heap: " << *pi << endl;

    cout << "char on the heap: " << *pc << endl;
    delete pi;
    delete pc;


    cout << "after delete the pointer  int = " << *pi << " char = " << *pc << endl;




    pi = (int *)malloc(sizeof(int));   //c风格的申请动态内存方式,注意这种方式不要和new delete的方式混用,否则容易产生各种问题
    *pi = 123432;
    cout << "after second malloc int pointer *pi = " << *pi << endl;
    free(pi);   //不知道为啥没有效果
    cout << "after second free int pointer *pi = " << *pi << endl;

    return 0;

}
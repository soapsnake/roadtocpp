//
// Created by 刘盾 on 2019-05-18.
//
#include <iostream>
#include <cmath>
#include "function.h"

void arr_test(const int arr[]);  //定义函数的地方必须和实际函数完全一致,这里有cosnt,下边也一定得有

int sum_arr(const int *begin, const int *end);  //参数为数组的开始和结束位指针

int c_in_str(const char *str);  //c风格的字符串,其实就是一个字符数组

char * build_str(char c, int n);


struct travel_time {  //结构体与对象最大的不同,就是调用函数时传递的是结构体的一份副本,而不像对象那样传递的是引用
    int hours;
    int range;
};
travel_time deal_travel(travel_time t1, travel_time t2);  //传递结构体

//polar结构体的定义位于function.h中
void deal_polar(const polar * p,  polar * pda);   //传递结构体的地址指针

using namespace std;
int main() {

    int arr[3] = {2,2,3};   //c++ 初始化数组的方法,不能像java一样写int[], arr[3]定义数组长度而不是取值
    arr_test(arr);
    int total = 0;
    total = sum_arr(arr, arr + 3);
    cout << "total = " << total << endl;

    char mm[10] = "nijiushig";
    int res = c_in_str(mm);

    char  *str = "jidsaida";
    int res1 = c_in_str(str);

    char  *charpt = build_str('a', 10);
    cout << charpt << endl;

//    delete [] charpt;   //这种释放指针内存的方法也可以
    delete charpt;

    travel_time time1 = {10, 20};
    travel_time time2 = {11, 30};
    travel_time res2 = deal_travel(time1, time2);
    cout << "total travel " << res2.hours << endl;
    cout << "total travel " << res2.range << endl;

    double angle = 0.32131;
    double range = 0.3232;
    polar polar1 = {angle, range};
//    polar res3;
//    cout << "test polar &address" << endl;
//    deal_polar(&polar1, &res3);
//    cout << "res3.distance: " << res3.distance << endl;
//    cout << "res3.angle: " << res3.angle << endl;


    polar * ppointer; //实验发现单独只声明一个指针而不进行初始化是没有办法使用的

    //是不是指针的使用一定要先进行初始化了???
    polar res4;
    ppointer = &res4;   //指针指向一个结构变量的地址,没有这个后面的运算会没有结果,对指针的理解还是不够啊...
    cout << "test polar *pointer"<< endl;
    deal_polar(&polar1, ppointer);
    cout << "ppointer->angle: " << ppointer->angle << endl;
    cout << "ppointer->distance: " << ppointer->distance << endl;


    string * strpt;
    string str123 = "123";
    strpt = &str123;
    cout << "strpt = " << strpt << endl;
    cout << "*strpt = " << *strpt << endl;


}

void arr_test(const int arr[]) {
    cout << "heere is test arr!!!" << endl;
//    arr[0] = 1;   //编译错误,arr[]在这个函数里是只读的,不能修改值
}

int sum_arr(const int * begin, const int * end) {  //只传两个指针进来,完全看不到数组
    const int *p;
    int total = 0;
    for (p = begin; p < end ; p++) {
        total = total + *p;
    }
    return total;
}

int c_in_str(const char *str) {
    cout << str << endl;
    cout << *str << endl;
    return 0;
}

char * build_str(char c, int n) {
    char *pstr = new char[n+1];  //pstr指针的作用域为这个函数,因此在这个函数返回后其指向的内存将被回收

    pstr[n] = '\0';   //c风格字符串最后一位一定是\0

    while (n-- > 0)
        pstr[n] = c;
    return pstr;
}

travel_time deal_travel(travel_time t1, travel_time t2) {
    travel_time total{};
    total.hours = t1.hours + t2.hours;
    total.range = t1.range + t2.range;
    return total;
}

void deal_polar(const polar * p, polar * pda) {
    pda->angle = sqrt(p->angle);
    pda->distance = sqrt(p->distance);
}


//
// Created by soapsnake@gmail.com on 4/6/21.
//

#include "iostream"
using namespace std;


class Box {

 public:
  double length{};
  double breadth{};
  double height{};
  Box() = default;  //默认构造函数,好像这个default是必须写的,不然编译不通过
  Box(double len, double bre, double hei);  //构造函数同样可以声明和定义分开

  ~Box() = default;  //析构函数,就是对象销毁时会被自动调用的函数,可用来销毁对象时释放资源

  double getVolume() {
    return length * breadth * height;
  }

  double getSpace();  //c++可以在类里面声明成员函数,但是在类外面用::定义该函数

 protected:
  double square{};   //protected变量只能被子类访问

};

double Box::getSpace() {
  return length * height;
}

//带参构造函数
Box::Box(double len, double bre, double hei) {
  length = len;
  breadth = bre;
  height = hei;
}

//c++中的子类这样生名,:的作用取代了java中的extends
class SmallBox:Box {

 public:
  double getParentSquare() {
    square = 18;
    return square;
  }
};


int main() {
  Box box{};
//  box.height = 2;
//  box.length = 3;
//  box.breadth = 4;
  cout << box.getVolume() << endl;
  cout << box.getSpace() << endl;

  //下面这个不能编译通过,因为square不是public的,这个比Java的要狠啊
//  cout << box.square << endl;

  SmallBox small_box;  //子类
  cout << small_box.getParentSquare() << endl;

  Box box1{7, 8, 9};
  cout << "this is box1 " <<  box1.getVolume() << endl;

}



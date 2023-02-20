#include<iostream>
using namespace std;
/*
* function:To test the static member variables and functions using a typical example,and detect the function of disstructor
* author:linlulu
* realizing:实现一个Rectangle类，类中定义声明静态的成员函数与成员变量
* rseults:
* 1.普通成员变量每个对象都拥有一个，而静态成员变量一个类作用域内，仅有一份----因此，属于“全局变量”
*		注意：a.通过类名加作用域符“::”加静态成员变量名即可访问该变量，不需要事先实例化对象，自然“对象.static variable”也可以访问
*					b.用sizeof作用于实例化对象时，static variable的所占空间字节数并不计算在内
* 2.普通成员函数一定作用于某个具体对象，而static member function却属于类，可以不实例化对象即可访问
* 3.静态成员函数只能访问静态变量，原因就是：
* 普通成员函数可以访问所有成员（包括成员变量和成员函数），静态成员函数只能
访问静态成员。. 编译器在编译一个普通成员函数时，会隐式地增加一个形参 this，
并把当前对象的地址赋值给 this，所以普通成员函数只能在创建对象后通过对象来调
用，因为它需要当前对象的地址。. 而静态成员函数可以通过类来直接调用，编译器
不会为它增加形参 this，它不需要当前对象的地址，所以不管有没有创建对象，都可
以调用静态成员函数。. 普通成员变量占用对象的内存，静态成员函数没有 this 指针 ，
不知道指向哪个对象，无法访问对象的成员变量，也就是说静态成员函数不能访问普
通成员变量，只能访问静态成员变量。
*		注意：静态成员变量的值多数情况下需要在析构函数和构造函数中指明其值的增减情况
*/
//定义类Rectangle
class Rectangle {
private:
	double length=0.0;
	double width = 0.0;
	static int totalRectangle;//必须类外初始化，表明其是一个“全局变量---类域内”
	static double totalArea;
public:
	Rectangle();
	Rectangle(double length, double width);
	~Rectangle();
	static void showTotalRectangle();
};
int Rectangle::totalRectangle = 0;
double Rectangle::totalArea = 0.0;
Rectangle::Rectangle(double length, double width) {
	this->length = length;
	this->width = width;
	totalRectangle++;//新建一个矩形，数目加1
	totalArea += length * width;
}
Rectangle::~Rectangle() {//在这里就体现了析构函数是如何进行收尾工作的
	totalRectangle--;//销毁对象，矩形数目减1
	totalArea -= this->length * this->width;
}
void Rectangle::showTotalRectangle() {
	cout << "总的矩形数目：" << totalRectangle
		<< "所有矩形的面积：" << totalArea << endl;
}
//写测试函数
void test() {
	Rectangle r1(3.00, 4.00);
	Rectangle r2 = Rectangle(4.00, 5.00);
	Rectangle Rectangle(5.00, 6.00);
	Rectangle::showTotalRectangle();//通过类名调用静态成员函数
	r1.showTotalRectangle();//通过对象调用静态成员函数
}

//main 函数
int main(int argc, char* argv[]) {
	test();
	system("pause");
	return 0;
}

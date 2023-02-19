#include<iostream>
using namespace std;
/*
* function:To test the functions and usages of reference and discuss the essence of reference
* author:linlulu
* results:----引用	
* Format：type & = variable;//就是给一个内存空间起了一个别名，更加方便的可以对其进行管理
* Essence:引用的本质是一个“指针常量----int a=10;int * const b=a <==>int &p=a“，只不过是compiler
* 在操作引用变量时隐藏了那个”*“
* Applications:
* 1.作函数形参；
* 2.作函数返回值；
* 3.
* Warnings:
* 1.引用必须初始化，且不能在指向其他变量；
* 2.不要返回局部变量的引用作”左值“，可以返回静态变量的引用；
* 3.返回的静态变量的引用可做左值；
* 4.常量引用----用在函数参数时可防止函数内误操作（即：不允许修改其值）
*/

//定义一个函数，引用作为其参数
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//定义一个函数，使得其返回值类型是引用类型
int& func() {
	int a = 10;
	static int b = 10;
	//return a;
	return b;
}
//Statement
int addInteger(const int& a, int b);
void test() {
	int* p1 = new int(10);
	int* p2 = new int(20);
	int sum = 0;
	cout << "*p1与*p2在交换前，*p1=" << *p1<<"\t*p2="<<*p2<<endl;
	swap(*p1,*p2);//注意，这是啥？？？
	cout << "*p1与*p2在交换后，*p1=" << *p1 << "\t*p2=" << *p2 << endl;
	int temp=func();
	cout << "func()=" <<temp<< endl;
	cout << "func()=" << temp << endl;
	func() = 20;
	func() = 100;//局部变量的引用不能作”左值“
	cout << "func()=" << func() << endl;//出错，编译没问题，但运行结果，逻辑有问题，改进：就是将局部变量的引用改为静态变量的引用
	sum = addInteger(*p1,func());
	cout << "*p1 + func() = " << sum << endl;
	sum = addInteger( func(),*p2);
	cout << "func() + *p2 = " << sum << endl;
}

//定义一个常量引用作为函数参数的例子
int addInteger(const int& a, int b) {
	//a = 10;//会报错”表达式必须是可修改的左值“
	b = 10;
	int temp = a + b;
	return temp;
}
//main函数
int main(int argc,char *argv[]) {
	test();
	system("pause");
	return 0;
}

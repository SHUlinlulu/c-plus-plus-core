#include<iostream>
using namespace std;
/*
* function:To test the improvemnts of function
* author：linlulu
* results:
* 1.带有默认参数的函数（Functions with default parameters）
*		注意事项：a.自第一个默认参数到parameters list 最后的参数都要带默认参数，否则容易造成二义性
*                           b.函数的声明与函数的定义只能有一方带有默认参数（同一参数而言），否则编译器区分不了，二义性
* 2.函数的占位参数-----最常见的就是函数的声明部分一般可以只写参数列表对应位置的参数类型
*		注意事项：a.占位参数也可以带有默认参数，比如：int add(int=10,int);//这一函数声明中第一个参数就有了默认参数10
* 3.函数的重载（区分度：参数列表的结构：参数的个数，类型，顺序----不常见的：比如static与const修饰的也算类型）
*		注意事项：a.函数的返回值类型不可以作为函数重载的条件
*						     b.若想对某个函数进行重载，就尽量不要有默认参数，否则很容易造成错误
*/
//写一个带有默认参数累加求和的函数
int sum(int a=1, int b=2) {
	return a + b;
}
//写一个上面函数的带有占位参数的函数，实现相同的功能
int sum1(int, int=10);//原来占位参数的默认参数是这样写
//重载函数sum
double sum(double a, double b) {
	return a + b;
}
//重载函数sum
int sum(int a, int b, int c) {
	return a + b + c;
}
//重载函数sum
double sum(int a, double b) {
	return a + b;
}
//重载函数sum
double sum(double a, int b) {
	return a + b;
}
void test() {
	int temp = 0;
	temp= sum1(10,20);
	cout << "sum1 = " << temp << endl;
	temp = sum(10, 90);
	cout << "sum = " << temp << endl;
}
int sum1(int a, int b) {//这里若 int b=20，编译器会提示”sum1:重定义默认参数“报错
	return a + b;
}

//main 函数
int main(int argc, char* argv[]) {

	test();
	system("pause");
	return 0;
}
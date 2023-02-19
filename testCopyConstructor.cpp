#include<iostream>
using namespace std;
/*
* function:To have a try for copy constructors
* author：linlulu
* results:
* 1.构造函数的分类按参数列表可分类，按照功能也可以划分----普通构造函数&&拷贝构造函数
* 2.所谓的拷贝构造函数----copy---就是复制出来一份一摸一样的
*		适用场景：a.对象做形参；b.以值返回的形式；c.使用一个已经创建完毕的对象来初始化另一个对象
* 3.当一个类中有静态成员变量时，需要在类内声明，必须类外定义；
* 4.深拷贝与浅拷贝（系统提供的拷贝构造函数&&“="运算符重载函数）----只是简单的复制（copy--一模一样）
* 解决浅拷贝：---->采用深拷贝
* 补充：
* 1.构造函数的三种调用方式
*		a.括号法；b.显示法；c.隐式转换法
* 注意事项：
*		a.若程序员提供有参构造函数，则C++就不提供无参构造函数，但会提供默认拷贝构造函数；
*		b.若程序员定义了拷贝构造函数，则C++不会提供任何一种构造函数了
*			形式：Person(const Person & person){。。。。。};
*			深拷贝：在堆区重新申请空间，进行拷贝工作
*/
//定义类Person
class Person {
private:
	string name;
	int age;
	static string sex;//必须在类外进行初始化
	float* height;//将身高声明为了float的指针类型了
public:
	Person(string name,int age,string sex,float height) {
		this->name = name;
		this->age = age;
		this->sex = sex;
		//this->height = height;
		this->height = new float(height);//这里就是动态申请空间，对”堆“操作，进而实现了”深拷贝“
	}
	Person(const Person& person) {//拷贝构造函数
		this->name = person.name;
		this->age = person.age;
		this->sex = person.sex;
		//this->height = person.height;//这就出错了，对于指针类型的成员变量，不能简单的值拷贝，否则就会造成空间重复释放的错误
		this->height = new float(*person.height);//这就是对的，在堆中重新申请了一个空间，给了当前对象
		//就不会造成后续析构函数调用时的对于指针空间的重复释放
	}
	~Person() {
		if (!height) {
			delete height;//释放height指示的空间
			height = NULL;//指针置空，防止产生”野指针“
		}
		cout << "调用析构函数！！！！！！！！！！！！！！" << endl;
	}
};
string Person::sex = "男";

void test() {
	float h = 169.25;//身高
	Person p1("林露露",23,"男",h);
	Person p2(p1);//等价于Person p2 = p1;调用拷贝构造函数
}
int main(int argc, char* argv[]) {
	test();
	system("pause");
	return 0;
}
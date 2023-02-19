#include<iostream>
#include<string>
using namespace std;
/*
* function:To check the encapsulation of C-plus-plus
* author:
* results：
* 1.C++的三大特性----封装（类与对象）；继承（：）；多态（虚函数，抽象类）
* 2.C++类中的成员-----成员变量&成员函数（默认访问权限是private）；
* 3.通过限制访问权限，可以实现----成员变量的可读，可写，可写可读；
* 4.C++非常支持引用作为函数形参，毕竟：引用的本质就是一个指针常量，说实话就是一块内存空间的符号表示，
* 比起”传值“，引用显然对系统的消耗较少（地址：编码位数都是一样的）------而传值的内部实现
* 我们都晓得，系统要复制一份相同的内容，建立内部临时变量，这。。。。太耗了！！！！！！！！
* 5.一个类在定义时，系统会自动为其创建四个函数-----无参空构造函数；无参空析构函数；拷贝构造函数（const int &）
*/
//定义一个person类
class person {
private:
	string name;
	int age=0;
	float height=0.0;//这两个尽量初始化，否则会有小警告
	//char* address;
public:
	person() {}
	person(string name):name(name){}//有时候只需要知道对方姓名就行了
	person(string name, int age, float height);
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setHeight(float height) {
		this->height = height;
	}
	void show();
	~person();//析构函数，完成清理工作
};
person::person(string name, int age, float height) {
	this->name = name;
	this->age = age;
	this->height = height;
}
void person::show() {
	cout << "姓名：" << this->name<<"\t年龄：" <<this->age<<"\t身高："<<this->height << endl;
}
person::~person() {
	cout << "调用析构函数！！！！！！！！！" << endl;
}

//写测试函数
void test() {
	person p;
	p.setName("林露露");
	p.setAge(23);
	p.setHeight(170.0);
	p.show();

	person p2("王可可", 23, 160.5);
	p2.show();
	
}

//main函数
int main(int argc, char* argv[]) {
	test();
	system("pause");
	return 0;
}
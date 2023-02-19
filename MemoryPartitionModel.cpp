#include<iostream>
using namespace std;
/*
* function:To detect/test which part of memory those codes||variables||constants are in
* author:linlulu
* results：
* 1.C++程序在编译后会处于内存的全局区（静态区）和代码区-----.exe执行前；
* 2.代码区存放的是0/1二进制程序源码（预编译（复制替代代码的过程）---连接），不允许修改和访问；
* 3.全局区（静态区）存放的是“全局变量”，“全局常量”，“静态变量”...由OS进行管理；
* 4.执行.exe文件后，内存中又会多出两部分“栈区”和“堆区”；
* 5.“栈区”存放那些程序执行过程中的局部变量，局部常量，如：函数返回时Compiler临时创建的
* temp变量，函数调用时，参数亦或递归函数执行时的临时参数等皆在这个区内，由Compiler管理
* 6.C++中的“堆区”，由程序员管理和回收，主要使用关键字"new"和“delete”
* 注意：
* 1.“堆区管理”，程序员必须铭记要在申请的堆空间变量使用完后，及时释放（面试常考）;
* 2."栈区管理"注意：“不要返回局部变量的地址，比如：函数调用返回值是一个地址（函数内部变量）”
* 就会造成错误，当然，compiler会做一次暂时的保留，下次再用就会出错
*/
//定义一个全局变量
int g_v = 10;
//定义一个全局常量
const double g_c = 3.1415;
//定义一个全局静态变量
static int g_s = 50;
void static demo();
void Heap();
void test2();
int* localAddreRet();
int main(int argc, char* argv[]);//没这一行，complier找不到main,会报错（因main声明在后）
//写一个测试函数
void test() {
	//定义一个局部变量
	int l_v = 10;
	//定义一个局部常量
	const int l_c = 100;
	//定义一个局部静态变量
	static long l_s = 70100;
	cout << "g_v的地址：" <<(int) &g_v << endl;
	//int 其实就够，占了4个字节，不信后面可以用long测试
	cout << "g_c的地址：" << (int)&g_c << endl;
	cout << "g_s的地址：" << (int)&g_s << endl;
	cout << "l_v的地址：" << (long)&l_v << endl;//经测试，int其实就已足够
	cout << "l_c的地址：" << (int)&l_c << endl;
	cout << "l_s的地址：" << (int)&l_s << endl;
	cout << "函数main的地址：" << (int)main << endl;
	cout << "函数test的地址：" << (int)test << endl;
	cout << "静态函数demo的地址：" << (int)demo << endl;
	Heap();
}
//定义一个静态函数
void static demo(){}
//main函数
int main(int argc, char *argv[]) {
	/*test();*/
	test2();
	//int* temp;
	//temp = localAddreRet();//直接报错
	//cout << "*temp=" << *temp << endl;
	system("pause");
	return 0;
}

//定义一个堆的使用的函数Heap
void Heap() {
	int* p = new int(10);
	int* p2 = new int [10] {0};//必须指定分配的存储空间的大小
	cout << "*p=" <<(int) *p << "\t*p的地址为：" << (int) & (*p) << "\tp的地址" << (int) & p << endl;
	cout << "p2[0]=" << p2[0] << "\tp2的地址为：" << (int)p2 << endl;
	delete p;
	p = NULL;//正确的规范，防止产生“野指针”----指向未知区域（无权限）
	delete[]p2;//一定要记得使用完释放空间，毕竟这是在堆里自己开辟的
	p2 = NULL;
}

//定义一个返回局部变量地址的函数,此时局部变量内存开辟在栈区
int* localAddreRet() {
	int a = 10;
	cout << "a=" <<*&a<< endl;//Attention
	return &a;
}
//定义一个返回局部变量地址的函数,此时局部变量内存开辟在堆区
int* localAddreRet2() {
	int* p = new int(10);
	cout << "*p=" << *p << endl;
	return p;
}
//写一个测试函数
void test2() {
	int* temp;
	temp = localAddreRet();//直接报错
	cout << "*temp=" << *temp << endl;//不行了，现在VS的C++ Compiler好像不对返回的局部变量地址做一次保留了
	cout << "*temp=" << *temp << endl;//出错，无权访问，程序调用结束后局部变量在栈中的空间就被释放掉了

	temp = localAddreRet2();//直接报错
	cout << "*temp=" << *temp << endl;//正确，因：程序员未将开辟的堆区空间释放掉，在程序整体没有完成前，该内存空间地址一直被占用
	cout << "*temp=" << *temp << endl;
	if (!temp) {
		delete temp;
		temp = NULL;//置空，免（“野指针”）
	}
}
#include<iostream>
using namespace std;
/*
* function:To test the functions and usages of reference and discuss the essence of reference
* author:linlulu
* results:----����	
* Format��type & = variable;//���Ǹ�һ���ڴ�ռ�����һ�����������ӷ���Ŀ��Զ�����й���
* Essence:���õı�����һ����ָ�볣��----int a=10;int * const b=a <==>int &p=a����ֻ������compiler
* �ڲ������ñ���ʱ�������Ǹ���*��
* Applications:
* 1.�������βΣ�
* 2.����������ֵ��
* 3.
* Warnings:
* 1.���ñ����ʼ�����Ҳ�����ָ������������
* 2.��Ҫ���ؾֲ�����������������ֵ�������Է��ؾ�̬���������ã�
* 3.���صľ�̬���������ÿ�����ֵ��
* 4.��������----���ں�������ʱ�ɷ�ֹ������������������������޸���ֵ��
*/

//����һ��������������Ϊ�����
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//����һ��������ʹ���䷵��ֵ��������������
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
	cout << "*p1��*p2�ڽ���ǰ��*p1=" << *p1<<"\t*p2="<<*p2<<endl;
	swap(*p1,*p2);//ע�⣬����ɶ������
	cout << "*p1��*p2�ڽ�����*p1=" << *p1 << "\t*p2=" << *p2 << endl;
	int temp=func();
	cout << "func()=" <<temp<< endl;
	cout << "func()=" << temp << endl;
	func() = 20;
	func() = 100;//�ֲ����������ò���������ֵ��
	cout << "func()=" << func() << endl;//��������û���⣬�����н�����߼������⣬�Ľ������ǽ��ֲ����������ø�Ϊ��̬����������
	sum = addInteger(*p1,func());
	cout << "*p1 + func() = " << sum << endl;
	sum = addInteger( func(),*p2);
	cout << "func() + *p2 = " << sum << endl;
}

//����һ������������Ϊ��������������
int addInteger(const int& a, int b) {
	//a = 10;//�ᱨ�����ʽ�����ǿ��޸ĵ���ֵ��
	b = 10;
	int temp = a + b;
	return temp;
}
//main����
int main(int argc,char *argv[]) {
	test();
	system("pause");
	return 0;
}

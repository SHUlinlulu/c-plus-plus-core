#include<iostream>
using namespace std;
/*
* function:To test the improvemnts of function
* author��linlulu
* results:
* 1.����Ĭ�ϲ����ĺ�����Functions with default parameters��
*		ע�����a.�Ե�һ��Ĭ�ϲ�����parameters list ���Ĳ�����Ҫ��Ĭ�ϲ���������������ɶ�����
*                           b.�����������뺯���Ķ���ֻ����һ������Ĭ�ϲ�����ͬһ�������ԣ���������������ֲ��ˣ�������
* 2.������ռλ����-----����ľ��Ǻ�������������һ�����ֻд�����б��Ӧλ�õĲ�������
*		ע�����a.ռλ����Ҳ���Դ���Ĭ�ϲ��������磺int add(int=10,int);//��һ���������е�һ������������Ĭ�ϲ���10
* 3.���������أ����ֶȣ������б�Ľṹ�������ĸ��������ͣ�˳��----�������ģ�����static��const���ε�Ҳ�����ͣ�
*		ע�����a.�����ķ���ֵ���Ͳ�������Ϊ�������ص�����
*						     b.�����ĳ�������������أ��;�����Ҫ��Ĭ�ϲ����������������ɴ���
*/
//дһ������Ĭ�ϲ����ۼ���͵ĺ���
int sum(int a=1, int b=2) {
	return a + b;
}
//дһ�����溯���Ĵ���ռλ�����ĺ�����ʵ����ͬ�Ĺ���
int sum1(int, int=10);//ԭ��ռλ������Ĭ�ϲ���������д
//���غ���sum
double sum(double a, double b) {
	return a + b;
}
//���غ���sum
int sum(int a, int b, int c) {
	return a + b + c;
}
//���غ���sum
double sum(int a, double b) {
	return a + b;
}
//���غ���sum
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
int sum1(int a, int b) {//������ int b=20������������ʾ��sum1:�ض���Ĭ�ϲ���������
	return a + b;
}

//main ����
int main(int argc, char* argv[]) {

	test();
	system("pause");
	return 0;
}
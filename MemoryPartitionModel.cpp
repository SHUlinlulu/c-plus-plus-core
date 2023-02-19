#include<iostream>
using namespace std;
/*
* function:To detect/test which part of memory those codes||variables||constants are in
* author:linlulu
* results��
* 1.C++�����ڱ����ᴦ���ڴ��ȫ��������̬�����ʹ�����-----.exeִ��ǰ��
* 2.��������ŵ���0/1�����Ƴ���Դ�루Ԥ���루�����������Ĺ��̣�---���ӣ����������޸ĺͷ��ʣ�
* 3.ȫ��������̬������ŵ��ǡ�ȫ�ֱ���������ȫ�ֳ�����������̬������...��OS���й���
* 4.ִ��.exe�ļ����ڴ����ֻ��������֡�ջ�����͡���������
* 5.��ջ���������Щ����ִ�й����еľֲ��������ֲ��������磺��������ʱCompiler��ʱ������
* temp��������������ʱ���������ݹ麯��ִ��ʱ����ʱ�����Ƚ���������ڣ���Compiler����
* 6.C++�еġ����������ɳ���Ա����ͻ��գ���Ҫʹ�ùؼ���"new"�͡�delete��
* ע�⣺
* 1.����������������Ա��������Ҫ������Ķѿռ����ʹ����󣬼�ʱ�ͷţ����Գ�����;
* 2."ջ������"ע�⣺����Ҫ���ؾֲ������ĵ�ַ�����磺�������÷���ֵ��һ����ַ�������ڲ���������
* �ͻ���ɴ��󣬵�Ȼ��compiler����һ����ʱ�ı������´����þͻ����
*/
//����һ��ȫ�ֱ���
int g_v = 10;
//����һ��ȫ�ֳ���
const double g_c = 3.1415;
//����һ��ȫ�־�̬����
static int g_s = 50;
void static demo();
void Heap();
void test2();
int* localAddreRet();
int main(int argc, char* argv[]);//û��һ�У�complier�Ҳ���main,�ᱨ����main�����ں�
//дһ�����Ժ���
void test() {
	//����һ���ֲ�����
	int l_v = 10;
	//����һ���ֲ�����
	const int l_c = 100;
	//����һ���ֲ���̬����
	static long l_s = 70100;
	cout << "g_v�ĵ�ַ��" <<(int) &g_v << endl;
	//int ��ʵ�͹���ռ��4���ֽڣ����ź��������long����
	cout << "g_c�ĵ�ַ��" << (int)&g_c << endl;
	cout << "g_s�ĵ�ַ��" << (int)&g_s << endl;
	cout << "l_v�ĵ�ַ��" << (long)&l_v << endl;//�����ԣ�int��ʵ�����㹻
	cout << "l_c�ĵ�ַ��" << (int)&l_c << endl;
	cout << "l_s�ĵ�ַ��" << (int)&l_s << endl;
	cout << "����main�ĵ�ַ��" << (int)main << endl;
	cout << "����test�ĵ�ַ��" << (int)test << endl;
	cout << "��̬����demo�ĵ�ַ��" << (int)demo << endl;
	Heap();
}
//����һ����̬����
void static demo(){}
//main����
int main(int argc, char *argv[]) {
	/*test();*/
	test2();
	//int* temp;
	//temp = localAddreRet();//ֱ�ӱ���
	//cout << "*temp=" << *temp << endl;
	system("pause");
	return 0;
}

//����һ���ѵ�ʹ�õĺ���Heap
void Heap() {
	int* p = new int(10);
	int* p2 = new int [10] {0};//����ָ������Ĵ洢�ռ�Ĵ�С
	cout << "*p=" <<(int) *p << "\t*p�ĵ�ַΪ��" << (int) & (*p) << "\tp�ĵ�ַ" << (int) & p << endl;
	cout << "p2[0]=" << p2[0] << "\tp2�ĵ�ַΪ��" << (int)p2 << endl;
	delete p;
	p = NULL;//��ȷ�Ĺ淶����ֹ������Ұָ�롱----ָ��δ֪������Ȩ�ޣ�
	delete[]p2;//һ��Ҫ�ǵ�ʹ�����ͷſռ䣬�Ͼ������ڶ����Լ����ٵ�
	p2 = NULL;
}

//����һ�����ؾֲ�������ַ�ĺ���,��ʱ�ֲ������ڴ濪����ջ��
int* localAddreRet() {
	int a = 10;
	cout << "a=" <<*&a<< endl;//Attention
	return &a;
}
//����һ�����ؾֲ�������ַ�ĺ���,��ʱ�ֲ������ڴ濪���ڶ���
int* localAddreRet2() {
	int* p = new int(10);
	cout << "*p=" << *p << endl;
	return p;
}
//дһ�����Ժ���
void test2() {
	int* temp;
	temp = localAddreRet();//ֱ�ӱ���
	cout << "*temp=" << *temp << endl;//�����ˣ�����VS��C++ Compiler���񲻶Է��صľֲ�������ַ��һ�α�����
	cout << "*temp=" << *temp << endl;//������Ȩ���ʣ�������ý�����ֲ�������ջ�еĿռ�ͱ��ͷŵ���

	temp = localAddreRet2();//ֱ�ӱ���
	cout << "*temp=" << *temp << endl;//��ȷ���򣺳���Աδ�����ٵĶ����ռ��ͷŵ����ڳ�������û�����ǰ�����ڴ�ռ��ַһֱ��ռ��
	cout << "*temp=" << *temp << endl;
	if (!temp) {
		delete temp;
		temp = NULL;//�ÿգ��⣨��Ұָ�롱��
	}
}
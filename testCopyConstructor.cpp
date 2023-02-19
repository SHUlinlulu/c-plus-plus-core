#include<iostream>
using namespace std;
/*
* function:To have a try for copy constructors
* author��linlulu
* results:
* 1.���캯���ķ��ఴ�����б�ɷ��࣬���չ���Ҳ���Ի���----��ͨ���캯��&&�������캯��
* 2.��ν�Ŀ������캯��----copy---���Ǹ��Ƴ���һ��һ��һ����
*		���ó�����a.�������βΣ�b.��ֵ���ص���ʽ��c.ʹ��һ���Ѿ�������ϵĶ�������ʼ����һ������
* 3.��һ�������о�̬��Ա����ʱ����Ҫ�������������������ⶨ�壻
* 4.�����ǳ������ϵͳ�ṩ�Ŀ������캯��&&��="��������غ�����----ֻ�Ǽ򵥵ĸ��ƣ�copy--һģһ����
* ���ǳ������---->�������
* ���䣺
* 1.���캯�������ֵ��÷�ʽ
*		a.���ŷ���b.��ʾ����c.��ʽת����
* ע�����
*		a.������Ա�ṩ�вι��캯������C++�Ͳ��ṩ�޲ι��캯���������ṩĬ�Ͽ������캯����
*		b.������Ա�����˿������캯������C++�����ṩ�κ�һ�ֹ��캯����
*			��ʽ��Person(const Person & person){����������};
*			������ڶ�����������ռ䣬���п�������
*/
//������Person
class Person {
private:
	string name;
	int age;
	static string sex;//������������г�ʼ��
	float* height;//���������Ϊ��float��ָ��������
public:
	Person(string name,int age,string sex,float height) {
		this->name = name;
		this->age = age;
		this->sex = sex;
		//this->height = height;
		this->height = new float(height);//������Ƕ�̬����ռ䣬�ԡ��ѡ�����������ʵ���ˡ������
	}
	Person(const Person& person) {//�������캯��
		this->name = person.name;
		this->age = person.age;
		this->sex = person.sex;
		//this->height = person.height;//��ͳ����ˣ�����ָ�����͵ĳ�Ա���������ܼ򵥵�ֵ����������ͻ���ɿռ��ظ��ͷŵĴ���
		this->height = new float(*person.height);//����ǶԵģ��ڶ�������������һ���ռ䣬���˵�ǰ����
		//�Ͳ�����ɺ���������������ʱ�Ķ���ָ��ռ���ظ��ͷ�
	}
	~Person() {
		if (!height) {
			delete height;//�ͷ�heightָʾ�Ŀռ�
			height = NULL;//ָ���ÿգ���ֹ������Ұָ�롰
		}
		cout << "����������������������������������������" << endl;
	}
};
string Person::sex = "��";

void test() {
	float h = 169.25;//���
	Person p1("��¶¶",23,"��",h);
	Person p2(p1);//�ȼ���Person p2 = p1;���ÿ������캯��
}
int main(int argc, char* argv[]) {
	test();
	system("pause");
	return 0;
}
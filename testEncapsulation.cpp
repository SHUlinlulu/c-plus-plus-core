#include<iostream>
#include<string>
using namespace std;
/*
* function:To check the encapsulation of C-plus-plus
* author:
* results��
* 1.C++����������----��װ��������󣩣��̳У���������̬���麯���������ࣩ
* 2.C++���еĳ�Ա-----��Ա����&��Ա������Ĭ�Ϸ���Ȩ����private����
* 3.ͨ�����Ʒ���Ȩ�ޣ�����ʵ��----��Ա�����Ŀɶ�����д����д�ɶ���
* 4.C++�ǳ�֧��������Ϊ�����βΣ��Ͼ������õı��ʾ���һ��ָ�볣����˵ʵ������һ���ڴ�ռ�ķ��ű�ʾ��
* ���𡱴�ֵ����������Ȼ��ϵͳ�����Ľ��٣���ַ������λ������һ���ģ�------����ֵ���ڲ�ʵ��
* ���Ƕ����ã�ϵͳҪ����һ����ͬ�����ݣ������ڲ���ʱ�������⡣������̫���ˣ���������������
* 5.һ�����ڶ���ʱ��ϵͳ���Զ�Ϊ�䴴���ĸ�����-----�޲οչ��캯�����޲ο������������������캯����const int &��
*/
//����һ��person��
class person {
private:
	string name;
	int age=0;
	float height=0.0;//������������ʼ�����������С����
	//char* address;
public:
	person() {}
	person(string name):name(name){}//��ʱ��ֻ��Ҫ֪���Է�����������
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
	~person();//�������������������
};
person::person(string name, int age, float height) {
	this->name = name;
	this->age = age;
	this->height = height;
}
void person::show() {
	cout << "������" << this->name<<"\t���䣺" <<this->age<<"\t��ߣ�"<<this->height << endl;
}
person::~person() {
	cout << "������������������������������" << endl;
}

//д���Ժ���
void test() {
	person p;
	p.setName("��¶¶");
	p.setAge(23);
	p.setHeight(170.0);
	p.show();

	person p2("���ɿ�", 23, 160.5);
	p2.show();
	
}

//main����
int main(int argc, char* argv[]) {
	test();
	system("pause");
	return 0;
}
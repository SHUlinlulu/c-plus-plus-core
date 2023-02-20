#include<iostream>
using namespace std;
/*
* function:To test the static member variables and functions using a typical example,and detect the function of disstructor
* author:linlulu
* realizing:ʵ��һ��Rectangle�࣬���ж���������̬�ĳ�Ա�������Ա����
* rseults:
* 1.��ͨ��Ա����ÿ������ӵ��һ��������̬��Ա����һ�����������ڣ�����һ��----��ˣ����ڡ�ȫ�ֱ�����
*		ע�⣺a.ͨ�����������������::���Ӿ�̬��Ա���������ɷ��ʸñ���������Ҫ����ʵ����������Ȼ������.static variable��Ҳ���Է���
*					b.��sizeof������ʵ��������ʱ��static variable����ռ�ռ��ֽ���������������
* 2.��ͨ��Ա����һ��������ĳ��������󣬶�static member functionȴ�����࣬���Բ�ʵ�������󼴿ɷ���
* 3.��̬��Ա����ֻ�ܷ��ʾ�̬������ԭ����ǣ�
* ��ͨ��Ա�������Է������г�Ա��������Ա�����ͳ�Ա����������̬��Ա����ֻ��
���ʾ�̬��Ա��. �������ڱ���һ����ͨ��Ա����ʱ������ʽ������һ���β� this��
���ѵ�ǰ����ĵ�ַ��ֵ�� this��������ͨ��Ա����ֻ���ڴ��������ͨ����������
�ã���Ϊ����Ҫ��ǰ����ĵ�ַ��. ����̬��Ա��������ͨ������ֱ�ӵ��ã�������
����Ϊ�������β� this��������Ҫ��ǰ����ĵ�ַ�����Բ�����û�д������󣬶���
�Ե��þ�̬��Ա������. ��ͨ��Ա����ռ�ö�����ڴ棬��̬��Ա����û�� this ָ�� ��
��֪��ָ���ĸ������޷����ʶ���ĳ�Ա������Ҳ����˵��̬��Ա�������ܷ�����
ͨ��Ա������ֻ�ܷ��ʾ�̬��Ա������
*		ע�⣺��̬��Ա������ֵ�����������Ҫ�����������͹��캯����ָ����ֵ���������
*/
//������Rectangle
class Rectangle {
private:
	double length=0.0;
	double width = 0.0;
	static int totalRectangle;//���������ʼ������������һ����ȫ�ֱ���---�����ڡ�
	static double totalArea;
public:
	Rectangle();
	Rectangle(double length, double width);
	~Rectangle();
	static void showTotalRectangle();
};
int Rectangle::totalRectangle = 0;
double Rectangle::totalArea = 0.0;
Rectangle::Rectangle(double length, double width) {
	this->length = length;
	this->width = width;
	totalRectangle++;//�½�һ�����Σ���Ŀ��1
	totalArea += length * width;
}
Rectangle::~Rectangle() {//�������������������������ν�����β������
	totalRectangle--;//���ٶ��󣬾�����Ŀ��1
	totalArea -= this->length * this->width;
}
void Rectangle::showTotalRectangle() {
	cout << "�ܵľ�����Ŀ��" << totalRectangle
		<< "���о��ε������" << totalArea << endl;
}
//д���Ժ���
void test() {
	Rectangle r1(3.00, 4.00);
	Rectangle r2 = Rectangle(4.00, 5.00);
	Rectangle Rectangle(5.00, 6.00);
	Rectangle::showTotalRectangle();//ͨ���������þ�̬��Ա����
	r1.showTotalRectangle();//ͨ��������þ�̬��Ա����
}

//main ����
int main(int argc, char* argv[]) {
	test();
	system("pause");
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	float num1 = 0.0, num2 = 0.0;
	float w1 = 0.6, w2 = 0.4;//ШЈжи
	float result = 0.0;
	while (true) {
		cout << "Enter A0(L):";
		cin >> num1;
		cout << "Enter A0(R):";
		cin >> num2;
		result = num1 * w1 + num2 * w2;
		printf("Final result: %.3f", result);
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}
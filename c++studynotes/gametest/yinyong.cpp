#include <iostream>

using namespace std;
//���õı�����c++�е�ʵ����һ��ָ�볣��  ָ�����޸ģ�����ָ���ֵ���ԸĶ�

void func(int& reg) {
	reg = 100;
}

//���ô��� �β�Ҳ������ʵ��
void myswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;

}


//�����������ķ���ֵ

//1.��Ҫ���ؾֲ�����������
int& test01() {
	int a = 10;//�ֲ���������������е� ջ��   ִ�����Ժ���ͷŵ���
	return a;
}

//2.�����ĵ��ÿ�����Ϊ��ֵ�����и�������ֵ�Ĳ���   ���磺test02() = 1000
int& test02() {
	static int a = 10;//��̬��������������е� ȫ����   �ڳ��������ϵͳ�ͷ�
	return a;
}


//��������

int main() {
	
	int a = 10;
	int &b = a;
	int c = 20;

	cout << "a = " << &a << endl;
	cout << "b = " << &b << endl;

	//���ñ����ʼ������ʼ���Ժ�Ͳ��������ı�
	//b = c���ԣ���Ϊ�Ǹ�ֵ����������&b���ܸı�
	b = c;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	system("pause");
	

	int x = 10, y = 100;
	myswap(x, y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	system("pause");


	int &ref = test01();
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;
	system("pause");


	int &ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;
	system("pause");


	int la = 5;
	int&ret = la;
	ret = 20;
	cout << "la = " << la << endl;
	cout << "ret = " << ret << endl;
	func(ret);
	cout << "la = " << la << endl;
	cout << "ret = " << ret << endl;

}

#include <iostream>

using namespace std;
//引用的本质在c++中的实现是一个指针常量  指向不能修改，但是指向的值可以改动

void func(int& reg) {
	reg = 100;
}

//引用传递 形参也会修饰实参
void myswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;

}


//引用做函数的返回值

//1.不要返回局部变量的引用
int& test01() {
	int a = 10;//局部变量存放在四区中的 栈区   执行完以后就释放掉了
	return a;
}

//2.函数的调用可以作为左值，进行给函数赋值的操作   例如：test02() = 1000
int& test02() {
	static int a = 10;//静态变量存放在四区中的 全局区   在程序结束后系统释放
	return a;
}


//常量引用

int main() {
	
	int a = 10;
	int &b = a;
	int c = 20;

	cout << "a = " << &a << endl;
	cout << "b = " << &b << endl;

	//引用必须初始化，初始化以后就不能有所改变
	//b = c可以，因为是赋值操作，但是&b不能改变
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

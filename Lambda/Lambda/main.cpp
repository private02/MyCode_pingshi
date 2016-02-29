#include <iostream>
#include <string>
using namespace std;

int main()
{
	[]()
	{
		cout << "Hello GitHub!\n" << endl;
	}();
	
	auto p = []() -> void 
	{
		cout << "I love GitHub!\n" << endl;
	};
	for (int i = 1;i < 1000;i++)
	{
		p();
	}

	auto p01 = [](string a, string b) -> string
	{
		return a + b;
	};

	for (int i = 1;i < 1000;i++)
	{
		cout << p01("I love", " GitHub(string)!\n") << endl;
	}

	auto p02 = [](int a, int b) -> int
	{
		return a + b;
	};

	for (int i = 1;i < 1000;i++)
	{
		cout << p01("GitHub::1", "2") << endl;
		cout << p02(1 * 10, 2) << endl;
	}

	int a, b;
	cin >> a >> b;
	cout << [](int a, int b) -> int 
	{
		return a + b;
	}(a, b) << endl;

	cout << [&a, &b]() -> int //����� mutable
	{
		a = 3;b = 4;
		cout << a << " " << b << endl;
		return a + b;
	}() << endl;

	cout << [a, b]() mutable //�� mutable
		  -> int
	{
		a = 3;b = 4;
		cout << a << " " << b << endl;
		return a + b;
	}() << endl;
	for (int i = 0;i < 1000;i++)
	{
		cout << [i, &a, &b]() -> int /*�����mutable,��Ҫ��i����*/
		{
			a = i + 3;b = i + 4;
			cout << a << " " << b << endl;
			return a + b;
		}() << endl;
		cout << [i, a, b]()mutable -> int /*�����mutable,��Ҫ��i����*/
		{
			a = i + 5;b = i + 4;
			cout << a << " " << b << endl;
			return a + b;
		}() << endl;
	}
	/*
	[&]() {} 
	[=]() {} 
	�Զ����񡣡�
	
	
	
	*/
	for (int i = 0;i < 1000;i++)
	{
		cout << [&]() -> int /*�����mutable�����ã�*/
		{
			a = i + 3;b = i + 4;
			cout << a << " " << b << endl;
			return a + b;
		}() << endl;
		cout << [=]()mutable -> int /*�����mutable*/
		{
			a = i + 5;b = i + 4;
			cout << a << " " << b << endl;
			return a + b;
		}() << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
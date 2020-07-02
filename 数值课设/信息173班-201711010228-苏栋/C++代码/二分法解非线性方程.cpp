#include <iostream>
#include <cmath>
using namespace std;

double g(double x)
{
	return x*x*x - x - 1;
}

int main8()
{
	double ga, gb, gc, a, b, c, eps;
	cout << "�ö��ַ�Ѱ�ҷ���x^3-x-1=0�ĸ�" << endl;
	cout << "���������eps:";
	cin >> eps;
	cout << "�����������[a,b]:";
	cin >> a >> b;
	ga = g(a);
	gb = g(b);
	while ((b - a)>eps)
	{
		c = (a + b) / 2;
		gc = g(c);
		if (gc == 0)
			break;
		else if (gc*gb<0)
		{
			a = c;
			ga = gc;
		}
		else
		{
			b = c;
			gb = gc;
		}
	}
	cout << "���̵ĸ�Ϊ:X=" << b << endl;
	system("pause");
	return 0;
}

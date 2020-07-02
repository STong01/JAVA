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
	cout << "用二分法寻找方程x^3-x-1=0的根" << endl;
	cout << "输入误差限eps:";
	cin >> eps;
	cout << "输入求根区间[a,b]:";
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
	cout << "方程的根为:X=" << b << endl;
	system("pause");
	return 0;
}

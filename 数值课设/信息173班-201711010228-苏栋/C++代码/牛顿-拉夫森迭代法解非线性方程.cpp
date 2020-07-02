#include<iostream>
#include<cmath>
using namespace std;
float f(float x)
{
	float Y;
	Y = x*x*x + 5 * x*x + 16 * x - 60;
	return(Y);
}
float df(float x)
{
	float y;
	y = 3 * x*x + 10 * x + 16;
	return(y);
}

void main()
{
	int i, n = 50;
	float p0, p1, Y, y, err = 0.001, relerr = 0.001, delta = 0.001;
	cout << "input the initial approximation to a zero of f:" << endl;
	cin >> p0;
	for (i = 0; i<n; i++)
	{
		Y = f(p0);
		y = df(p0);
		if (y != 0) p1 = p0 - Y / y;
		err = fabs(p1 - p0);
		relerr = 2 * err / (fabs(p1) + delta);
		if (err<delta || relerr<delta || fabs(Y)<delta)
			break;
		p0 = p1;
	}
	cout << "the root of the f(x)=0 is:" << p0 << endl;
	system("pause");
}
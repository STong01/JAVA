#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14156
float cosx(float x);
float fun_cos(float x, int m);

float cosx(float x)
{
	float ret_val = 1.0;
	float temp_ret;
	int m = 1;
	float Pi = 3.1415926;
	if (x > 2 * Pi || x < -2 * Pi)
	{
		x = x - ((int)(x / (2 * Pi)))*(2 * Pi);
	}
	do
	{
		temp_ret = fun_cos(x, m++);
		ret_val += temp_ret;
	} while (temp_ret>0.00005 || temp_ret<-0.00005);
	return ret_val;
}

float fun_cos(float x, int m)
{
	float ret_val;
	int i;
	if (m % 2 == 0)
	{
		ret_val = 1.0;
	}
	else
	{
		ret_val = -1.0;
	}
	for (i = 1; i <= 2 * m; i++)
	{
		ret_val = ret_val * x / i;
	}
	return ret_val;
}

int main9()
{
	float x = PI / 2;
	printf("cos(%f)=%f\t使用系统函数cos计算\n", x, cos(x));//使用系统函数cos计算
	printf("cos(%f)=%f\t使用泰勒公式计算\n", x, cosx(x));//使用泰勒公式计算


	system("pause");
	return 0;
}


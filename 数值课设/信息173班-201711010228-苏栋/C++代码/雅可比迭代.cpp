#include <iostream>
#include <cmath>
using namespace std;
#define delta 0.0000001
#define n 3
#define max1 1000

int main7()
{
	int i, j, k;
	double err, norm, A[n][n], B[n], P[n], X[n];
	cout << "输入系数矩阵A" << n << "*" << n << "：" << endl;
	/* 输入矩阵A,B,P */
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		cin >> A[i][j];
	cout << "输入矩阵B" << n << "*" << 1 << "：" << endl;
	for (i = 0; i<n; i++)
		cin >> B[i];
	cout << "输入初始向量P" << n << "*" << 1 << endl;
	for (i = 0; i<n; i++)
		cin >> P[i];
	for (k = 0; k<max1; k++)
	{
		for (j = 0; j<n; j++)
		{
			X[j] = B[j];
			for (i = 0; i<n; i++)
				X[j] = X[j] - A[j][i] * P[i];
			X[j] = (X[j] + A[j][j] * P[j]) / A[j][j];
		}
		norm = 0;
		for (i = 0; i<n; i++)
			norm = norm + pow((X[i] - P[i]), 2);
		norm = pow(norm, 0.5);
		err = fabs(norm);
		for (i = 0; i<n; i++)
			P[i] = X[i];
		if (err<delta)
			goto loop;
	}
	loop:cout << "方程组解矩阵X为: " << endl;
	for (i = 0; i<n; i++)

		/* 输出X */
		cout << X[i]<<endl;
	system("pause");
	return 0;
}
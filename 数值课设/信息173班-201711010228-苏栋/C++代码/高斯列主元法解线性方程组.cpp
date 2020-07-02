#include <iostream>
#include <math.h>
using namespace std;

int n;
float a[100][100], b[100];
void Output()
{
	int i, j;
	cout << "增广矩阵[a|b]为:" << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			printf("%-10f", a[i][j]);
		printf("%-10f", b[i]);
		printf("\n");
	}
}

void Input()
{
	int i, j;
	cout << "输入方阵a的维数:";
	cin >> n;
	cout << "输入矩阵a:" << endl;
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		cin >> a[i][j];
	cout << "输入矩阵b:" << endl;
	for (i = 0; i < n; i++)
		cin >> b[i];
}

void Gaosi()
{
	int k, i, j, max;
	float ta, tb, m;
	for (k = 0; k<n; k++)
	{
		max = k;
		for (i = k + 1; i<n; i++)
		{
			if (fabs(a[i][k])>fabs(a[max][k]))
				max = i;
		}
		if (i != k)
		{
			for (j = 0; j<n; j++)
			{
				ta = a[k][j]; a[k][j] = a[max][j]; a[max][j] = ta;
			}
			tb = b[k]; b[k] = b[max]; b[max] = tb;
		}
		Output();
		for (i = k + 1; i<n; i++)
		{
			m = a[i][k] / a[k][k];
			for (j = k; j<n; j++)
				a[i][j] = a[i][j] - a[k][j] * m;
			b[i] = b[i] - m*b[k];
			Output();
		}
	}
}

void Qiujie()
{
	int i, j;
	float sum;
	b[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		sum = 0;
		for (j = i + 1; j<n; j++)
			sum = sum + a[i][j] * b[j];
		b[i] = (b[i] - sum) / a[i][i];
	}
	printf("方程组的解为:\n");
	for (i = 0; i<n; i++)
		printf("x%d=%f\n", i + 1, b[i]);
}

int main()
{
	Input();
	Gaosi();
	Qiujie();
	system("pause");
	return 0;
}
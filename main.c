#define _CRT_SECURE_NO_WARNINGS // для возможнности использовать scanf
#include <stdio.h>
#define PI 3.1415926535
#define e 0.0000000001 //задаем точность вычисления элемента суммы

float fuTransform(float de)
{
	float rad = de * PI / 180; // перевод из градусов в радианы
	return rad;
}

double abs(double p)
{
	if (p >= 0)
		return p;
	else return p * (-1);
}

double fucos_de1(double deg)// в функцию передается одно число (значение в радианах)
{
	int n = 1;
	double cos_de = 1,
		   part = 1,
		   k = 0;

	while (part > e)// 
	{

		part *= deg * deg / (2 * n * (2 * n - 1));
		if (n % 2 == 1)
		{
			k = -part;
		}
		else
		{
			k = part;
		}
		cos_de += k;
		n++;

	}
	return cos_de;
}

int main()
{

	float degree[5] = {0, 30, 45, 60, 90};
	float ref = 0.001;
	float cos_reference[5] = {1, 0.866025, 0.707107, 0.5, 0}; 
	int n = 1;
	int i; 
	int otv;
	float cos_deg;
	float kos[5];
	for (i = 0; i < 5; i++)
	{
		float rad = fuTransform(degree[i]);
		cos_deg = fucos_de1(rad);
		if (abs(cos_deg - cos_reference[i]) <= ref)
		{
			otv = 0;
			kos[i] = cos_reference[i];
		}
		else otv = 1;
		if (otv == 1)
			break;
	}
	if (i == 5)
	{
		for (i = 0; i < 5; i++ )
			printf("Received value is correct: %.10f\n", kos[i]);
	}
	else
		printf("Received value isn't corrected\n");
	return otv;
}
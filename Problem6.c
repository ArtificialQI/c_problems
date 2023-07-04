#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define M 100
int* A;
//float a;
int Fmax(int x, int y)
{
	for (int i = 0; i < x; i++)
		if (y < *(A + i))
			y = *(A + i);


	return printf("max = %d\t", y);       // ���� �� ������ return �� ��� ����� ���������� y, ������?
}
int Fmin(int x, int y)
{
	for (int i = 0; i < x; i++)
		if (y > * (A + i))
			y = *(A + i);

	return printf("min = %d\t", y);
}
float FAvr(float x, float y)
{
	y = 0;
	for (int i = 0; i < x; i++)
		y = y + (*(A + i) / x);

	return y;
}
float Fdev(int x, float y, float a)
{
	y = 0;
	for (int i = 0; i < x; i++)
		y = y + (*(A + i) - a) * (*(A + i) - a);
	y = sqrt(y / x);
	return printf("dev = %f", y);
}

int main()
{

	int N;
	printf("Max size of array is %d\n", M);
	printf("Enter size of array to create\n");
	scanf_s("%d", &N);
	if (N <= M)
	{
		A = (int*)malloc(N * sizeof(int));

		printf("Enter array elements\n");

		for (int i = 0; i < N; i++)
		{
			scanf_s("%d", (A + i));
		}

		printf("array successfully created\n\n");

		for (int i = 0; i < N; i++)
			printf("%d\t", *(A + i));      // *(A+i)

		int max = *A;
		Fmax(N, max);

		int min = *A;
		Fmin(N, min);

		int Avr = 0;
		float b = FAvr(N, Avr);
		printf(" Avr = %f\t", b);

		float dev = 0;
		Fdev(N, dev, b);

		free(A);
	}
	else
		printf("array don't created");


	printf("\n%d", _CrtDumpMemoryLeaks());

	return 0;
}
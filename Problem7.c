#include <stdio.h>
#include <math.h>
#define M 5
int A[M];
int Fmax(int x, int y)
{
	for (int i = 0; i < x; i++)
		if (y < A[i])
			y = A[i];


	return printf("max = %d\t", y);       
}
int Fmin(int x, int y)
{
	for (int i = 0; i < x; i++)
		if (y > A[i])
			y = A[i];

	return printf("min = %d\t", y);
}
float FAvr(float x, float y)
{
	y = 0;  
	for (int i = 0; i < x; i++) 
		y = y + (A[i] / x);

	return y;
}
float Fdev(float x, float y, float a)
{
	y = 0;
	for (int i = 0; i < x; i++)
		y = y + (A[i] - a) * (A[i] - a);
	y = sqrt(y / x);
	return printf("dev = %f", y);
}

int main()
{
	printf("max size of array is %d\n", M);

	/*int A[M] = { 0 };
	for (int i = 0; i < M; i++)
		printf("%d ", A[i]);*/


	printf("Enter elements of array\n");
	for(int i = 0; i < M; i++)

		scanf_s("%d", &A[i]);
	
	for (int i = 0; i < M; i++)

		printf("A[%d] = %d\n", i, A[i]);

	int max = A[0];
	Fmax(M, max);

	int min = A[0];
	Fmin(M, min);

	int Avr = 0;
	float b = FAvr(M, Avr);
	printf(" Avr = %f\t", b);

	int dev = 0;
	Fdev(M, dev, b);

	return 0;
}
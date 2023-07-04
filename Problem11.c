#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include <math.h>


#define M 1000
#define K 3
#define H 25
#define W 25


typedef float mtr[H][W];

mtr A;
mtr B;
mtr C;
mtr D;
mtr T;
mtr I;
mtr F;
mtr Q;

void static_array_print(mtr A, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%3f ", A[i][j] );

		printf("\n");
	}
}

void input_array_console(mtr A, int N)
{
	printf("Enter 3x3 array elements:\n");

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%f", &A[i][j]);

	printf("\n");
	
	static_array_print(A, N);
}

void input_array_file(mtr A, FILE* f, int N)
{
	char fname[M];
	printf("Enter file adress:\t");
	scanf_s("%s", fname, M);

	fopen_s(&f, fname, "r");
	if (f == NULL)
		printf("Error");

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			fscanf_s(f, "%f", &A[i][j]);

	static_array_print(A, N);

	fclose(f);
}

void init_matrix(mtr A, FILE* f, int N)
{
	int x;
	printf("Select input method: '0' - console / '1' - file: \n");

	scanf_s("%d", &x);
	if (x == 0)
		input_array_console(A, N);

	else if (x == 1)
		input_array_file(A, &f, N);

	else (printf("Error"));

}

int sum_matrix(mtr A, mtr B, mtr C, int N)
{
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			C[i][j] = (A[i][j] + B[i][j]);
		
	printf("Sum:\n");
	static_array_print(C, N);
	
}

void mult_matrix(mtr A, mtr B, mtr D, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp = 0;
			for (int k = 0; k < N; k++)
				tmp = tmp + A[i][k] * B[k][j];
			D[i][j] = tmp;	                                    
		}
	}

	printf("Mult:\n");
	static_array_print(D, N);	
}

float det_matrix(mtr a, int k)
{

	float s = 1, det = 0, b[25][25];
	int m, n;
	if (k == 1)
	{
		return (a[0][0]);
	}
	else
	{
		det = 0;
		for (int c = 0; c < k; c++)
		{
			m = 0;
			n = 0;
			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					b[i][j] = 0;
					if (i != 0 and j != c)
					{
						b[m][n] = a[i][j];
						if (n < (k - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * det_matrix(b, k - 1));
			s = -1 * s;
		}
	}

	return (det);
}
void cofactor(mtr A, int f)
{
	int s = 1;
	float b[25][25], fac[25][25];
	int m, n;
	for (int q = 0; q < f; q++)
	{
		for (int p = 0; p < f; p++)
		{
			m = 0;
			n = 0;
			for (int i = 0; i < f; i++)
			{
				for (int j = 0; j < f; j++)
				{
					if (i != q and j != p)
					{
						b[m][n] = A[i][j];
						if (n < (f - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			fac[q][p] = pow(-1, q + p) * det_matrix(b, f - 1);
		}	
	}
	

	float q[25][25], inverse[25][25], d;

	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < f; j++)
		{
			q[i][j] = fac[j][i];
		}
	}
	d = det_matrix(A, f);
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < f; j++)
		{
			inverse[i][j] = q[i][j] / d;
		}
	}
	printf("\n\n\nThe inverse of matrix is : \n");

	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < f; j++)
		{
			printf("\t%f", inverse[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	FILE* f;

	init_matrix(A, &f, K);

	init_matrix(B, &f, K);

	sum_matrix(A, B, C, K);

	mult_matrix(A, B, D, K);

	printf("det = %f\n", det_matrix(A, K));

	cofactor(A, K);
	
	return 0;
}
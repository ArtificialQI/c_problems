#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
#include <math.h>
#include <malloc.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


#define M 1000
#define K 3
#define H 25
#define W 25


typedef struct Matrix
{
	int rows;
	int cols;
	double** x;

} Matrix;

Matrix A, B, C, D, I;

void static_array_print(Matrix* A)
{
	for (int i = 0; i < A->rows; i++)
	{
		for (int j = 0; j < A->cols; j++)
			printf("%3lf ", A->x[i][j]);

		printf("\n");
	}
}

void input_array_console(Matrix* A)
{
	printf("Enter NxM array elements:\n");

	for (int i = 0; i < A->rows; i++)
		for (int j = 0; j < A->cols; j++)
			scanf_s("%lf", &A->x[i][j]);       

	printf("\n");

	static_array_print(A);
}

void input_array_file(Matrix* A, FILE* f)
{
	char fname[M];
	printf("Enter file adress:\t");
	scanf_s("%s", fname, M);

	fopen_s(&f, fname, "r");
	if (f == NULL)
		printf("Error");

	for (int i = 0; i < A->rows; i++)
		for (int j = 0; j < A->cols; j++)
			fscanf_s(f, "%lf", &A->x[i][j]);    

	static_array_print(A);

	fclose(f);
}

void init_matrix(Matrix* A, FILE* f)
{
	printf("\nEnter rows and cols of Matrix:\n");

	printf("\nRows:\n");
	scanf_s("%d", &A->rows);

	printf("\nCols:\n");
	scanf_s("%d", &A->cols);

	A->x = (double**)malloc(A->rows*sizeof(double*));

	for (int i = 0; i < A->rows; i++)
		A->x[i] = (double*)malloc(A->cols*sizeof(double));

	int x;
	printf("Select input method: '0' - console / '1' - file: \n");

	scanf_s("%d", &x);
	if (x == 0)
		input_array_console(A);

	else if (x == 1)
		input_array_file(A, &f);

	else (printf("Error"));

}

void sum_matrix(Matrix* A, Matrix* B, Matrix* C)
{

	if (A->rows == B->rows and A->cols == B->cols)
	{
		C->rows = A->rows;
		C->cols = A->cols;

		C->x = (double**)malloc(C->rows * sizeof(double*));

		for (int i = 0; i < C->rows; i++)
			C->x[i] = (double*)malloc(C->cols * sizeof(double));

		for (int i = 0; i < A->rows; i++)
			for (int j = 0; j < A->cols; j++)
				C->x[i][j] = (A->x[i][j] + B->x[i][j]);

		printf("\nSum:\n");
		static_array_print(C);

		for (int i = 0; i < A->rows; i++)
			free(C->x[i]);
		free(C->x);
	}

	else(printf("\nSum indefine: Matrix size incompatible\n"));
}

void mult_matrix(Matrix* A, Matrix* B, Matrix* D)
{

	if (A->cols == B->rows and A->rows == B->cols)
	{
		D->rows = B->rows;
		D->cols = A->cols;

		D->x = (double**)malloc(B->rows * sizeof(double*));

		for (int i = 0; i < B->rows; i++)
			D->x[i] = (double*)malloc(A->cols * sizeof(double));

		for (int i = 0; i < A->rows; i++)
		{
			for (int j = 0; j < A->cols; j++)
			{
				int tmp = 0;
				for (int k = 0; k < A->rows; k++)
					tmp = tmp + A->x[i][k] * B->x[k][j];
				D->x[i][j] = tmp;
			}
		}

		printf("\nMult:\n");
		static_array_print(D);

		for (int i = 0; i < B->rows; i++)
			free(D->x[i]);
		free(D->x);
	}

	else(printf("\nMult indefine: Matrix sise incompatible\n"));
}

float det_matrix(Matrix* A, int rows)
{

	
	Matrix E;

	E.rows = A->rows;
	E.cols = A->cols;

	E.x = (double**)malloc(E.rows * sizeof(double*));

	for (int i = 0; i < E.rows; i++)
		E.x[i] = (double*)malloc(A->cols * sizeof(double));

	float s = 1, det = 0;
	int m, n;
	if (rows == 1)
	{
		return (A->x[0][0]);
	}
	else
	{
		det = 0;
		for (int c = 0; c < rows; c++)
		{
			m = 0;
			n = 0;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < rows; j++)
				{
					E.x[i][j] = 0;
					if (i != 0 and j != c)
					{
						E.x[m][n] = A->x[i][j];
						if (n < (rows - 2))
							n++;
						else
						{
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (A->x[0][c] * det_matrix(&E, rows - 1));
			s = (-1) * s;
		}
	}

	for (int i = 0; i < E.rows; i++)
		free(E.x[i]);
	free(E.x);

	return (det);
	
}

void inv_matrix(Matrix* A, Matrix* I, int f)
{	

	int s = 1;
	float b[25][25], fac[25][25];

	Matrix B;

	B.rows = A->rows;
	B.cols = A->cols;

	B.x = (double**)malloc(B.rows * sizeof(double*));

	for (int i = 0; i < B.rows; i++)
		B.x[i] = (double*)malloc(A->cols * sizeof(double)); 

	Matrix F;

	F.rows = A->rows;
	F.cols = A->cols;

	F.x = (double**)malloc(F.rows * sizeof(double*));

	for (int i = 0; i < F.rows; i++)
		F.x[i] = (double*)malloc(A->cols * sizeof(double));


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
						B.x[m][n] = A->x[i][j];
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
			F.x[q][p] = pow(-1, q + p) * det_matrix(&B, f - 1);
		}
	}

	Matrix T;

	T.rows = A->rows;
	T.cols = A->cols;

	T.x = (double**)malloc(T.rows * sizeof(double*));

	for (int i = 0; i < T.rows; i++)
		T.x[i] = (double*)malloc(A->cols * sizeof(double));



	I->rows = A->rows;
	I->cols = A->cols;

	I->x = (double**)malloc(I->rows * sizeof(double*));

	for (int i = 0; i < I->rows; i++)
		I->x[i] = (double*)malloc(I->cols * sizeof(double));

	double q[25][25], inverse[25][25], d;

	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < f; j++)
		{
			T.x[i][j] = F.x[j][i];
		}
	}

	d = det_matrix(A, f);

	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < f; j++)
		{
			I->x[i][j] = (T.x[i][j] / d);
		}
	}
	printf("\n\n\nThe inverse of matrix is : \n");

	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < f; j++)
		{
			printf("\t%f", I->x[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < B.rows; i++)
		free(B.x[i]);
	free(B.x);

	for (int i = 0; i < F.rows; i++)
		free(F.x[i]);
	free(F.x);

	for (int i = 0; i < T.rows; i++)
		free(T.x[i]);
	free(T.x);

	for (int i = 0; i < I->rows; i++)
		free(I->x[i]);
	free(I->x);
	
}

int main()
{
	FILE* f;

	init_matrix(&A, &f);

	init_matrix(&B, &f);

	sum_matrix(&A, &B, &C);

	mult_matrix(&A, &B, &D);
	
	if (A.rows == A.cols)
	{
		printf("det = %f\n", det_matrix(&A, A.rows));

		inv_matrix(&A, &I, A.rows);
	}
	else(printf("\nIndefine determinant\n\nMatrix uninvertible\n"));


	for (int i = 0; i < A.rows; i++)
		free(A.x[i]);
	free(A.x);

	for (int i = 0; i < B.rows; i++)
		free(B.x[i]);
	free(B.x);


	printf("\n%d", _CrtDumpMemoryLeaks());

	return 0;
}
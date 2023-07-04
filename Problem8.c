#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <time.h>
#include <stdlib.h>
#define M 100

int compare1(int a, int b)
{
	return a > b;
}
int compare2(int a, int b)
{
	return a < b;
}
int compare3(int a, int b)
{
	return abs(a) < abs(b);
}

int replace(int *a, int *b)
{
	int tmp = *a; // меняем их местами
	*a = *b;
	*b = tmp;
}

int input_array(int A[], int max_size)
{
	int top = 0;

	while (true) 
	{
		int x;
		scanf_s("%d", &x);
		if (x == 0 or top == max_size) break;
		A[top] = x;
		top++;
	}
	return top;
}

void sort_array(int A[], int N)
{
	for (int i = 0; i < N; ++i)
	{
		int k = i;
		while (k > 0 and A[k - 1] > A[k])
		{
			int tmp = A[k - 1];
			A[k - 1] = A[k];
			A[k] = tmp;
			k -= 1;
		}

	}

}

void bubble_sort(int A[], int N, int(*compare)(int, int))
{
	// Для всех элементов
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = (N - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (compare(A[j - 1], A[j])) // если текущий элемент меньше предыдущего
			{

				replace(&A[j - 1], &A[j]);
				/*int tmp = A[j - 1]; // меняем их местами
				A[j - 1] = A[j];
				A[j] = tmp;*/
			}
		}
	}
}

void print_array(int A[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%3d ", A[i]);
	printf("\n");
}

int main()
{
	printf("Enter Size, Range of array from '' to ''\n");
	int N, R, L;
	scanf_s("%d%d%d", &N, &R, &L);

	printf("\n");
	
	int* Arr = (int*)calloc(N, sizeof(int));

	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		Arr[i] = rand() % (R - L + 1) + L;
		printf("%d ", Arr[i]);
	}
	printf("\n\n");
	
	int x = 0;
	printf("enter direction of sort 1, 2, 3\n");
	scanf_s("%d",&x);


	if (x == 1)
		bubble_sort(Arr, N, compare1);
	else if (x == 2)
		bubble_sort(Arr, N, compare2);
	else if (x == 3)
		bubble_sort(Arr, N, compare3);
	else printf("Error");

	print_array(Arr, N);

	return 0;
}
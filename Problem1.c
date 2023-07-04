#include<stdio.h>
#include<malloc.h>

//#define N 100

int main()
{
	int N, y;
	do {
		printf("enter N to type all prime numbers\t");
		scanf_s("%d", &N);
		int* A;
		A = (int*)calloc(N, sizeof(int));




		//int A[N] = { 0 };
		int k = 0;
		for (int i = 2; i * i < N; ++i)
			if (A[i] == 0)
				for (int j = i * i; j < N; j += i)
				{
					k++;
					A[j] = 1;
				}



		for (int i = 0; i < N; ++i)
			printf("%3d", i);
		printf("\n");
		for (int i = 0; i < N; ++i)
			printf("%3d", A[i]);
		printf("\n");

		printf("Prime numbers:\n");
		for (int i = 2; i < N; ++i)
			if (A[i] == 0)
				printf("%d ", i);
		printf("\n");
		printf("%d", k);



		printf("One more iteration?\n\n Type 1 - means yes or 0 - means not\n");
		scanf_s("%d", &y);
		free(A);

	}

	while (y == 1);



	return 0;
}
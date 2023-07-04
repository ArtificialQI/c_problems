#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define _CRT_SECURE_NO_WARNINGS

char* getstr(int* n)
{
	int v = 1;

	char* str = (char*)malloc(v * sizeof(char));
	
	char c;
	
	*n = -1;
	c = getchar();
	
	while (c != '#')
	{
		str[(*n)++] = c;

		if (*n >= v)
		{
			v *= 2;
			char* t = (char*)malloc(v * sizeof(char));
			for (int i = 0; i < v; i++) 
				t[i] = str[i];
			
			char* str = (char*)malloc(v * sizeof(char));
			for (int j = 0; j < v; j++) 
				str[j] = t[j];
			
			free(t);
		}
		
		
		c = getchar();
		
	}

	str[*n] = '\0';

	return str;
}

int input_array(char* A, int max_size)
{
	char top = 0;

	while (true)
	{
		char x;
		scanf_s("%d", &x);
		if (x == 0 or top == max_size) break;
		A[top] = x;
		top++;
	}
	return top;
}

int remove_n(char* str, int len) {
	int len2 = len - 1;

	if ('\n' == str[len2])
		str[len2] = 0;

	return 0;
}

void remove_spc(char* str, int S)
{
	for (int i = 0; i < S; i++)
		while (((int)str[i] == 32 and (int)str[i + 1] == 32) or ((int)str[i] == 46 and (int)str[i + 1] == 46) or ((int)str[i] == 44 and (int)str[i + 1] == 44) or ((int)str[i] == 44 and (int)str[i + 1] == 46) or ((int)str[i] == 46 and (int)str[i + 1] == 44))
		{
			int j = 0;
			for (int i = 0; i < S; i++)
			{
				j++;
				if (((int)str[i] == 32 and (int)str[i + 1] == 32) or ((int)str[i] == 46 and (int)str[i + 1] == 46) or ((int)str[i] == 44 and (int)str[i + 1] == 44) or ((int)str[i] == 44 and (int)str[i + 1] == 46) or ((int)str[i] == 46 and (int)str[i + 1] == 44))
					break;
			}
			//printf("%d\n", j);

			for (int i = j; i < S; i++)
				str[i] = str[i + 1];
		}
	puts(str);
}

void delete_symb(char* str, int S)
{

	for (int i = 0; i < S; i++)
		while (((int)str[i + 1] == 46 or (int)str[i + 1] == 44) and (int)str[i] == 32)
		{
			int j = 0;
			for (int i = 0; i < S; i++)
			{
				j++;
				if (((int)str[i + 1] == 46 or (int)str[i + 1] == 44) and (int)str[i] == 32)
					break;
			}
			printf("%d\n", j);

			for (int i = j - 1; i < S; i++)
				str[i] = str[i + 1];
			puts(str);
		}

	puts(str);
}

void insert_symb(char* str, int S)
{
	char tmp;
	for (int i = 0; i < S; i++)
		while ((((int)str[i] == 46 or (int)str[i] == 44) and (int)str[i + 1] != 32))
		{


			int j = 0;
			for (int i = 0; i < S; i++)
			{
				j++;
				if ((((int)str[i] == 46 or (int)str[i] == 44) and (int)str[i + 1] != 32))
					break;
			}
			printf("%d\n", j);

			tmp = str[S - 1];
			for (int i = S - 1; i >= j; --i)
				str[i] = str[i - 1];
			str[j] = 32;

		}
	//for (int i = 0; i < S; i++)
		//printf("%c", str[i]);
	puts(str);
	//printf("%c", tmp);

}

int _CrtDumpMemoryLeaks(void)
{
	return 0;
}

char replace(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void correct_str(char* str, int S)
{

	for (int i = 0; i < S; i++)
		if ((int)str[i] != 46 and (int)str[i + 1] == 46 and (int)str[i + 2] == 46 and (int)str[i + 3] == 46 and (int)str[i + 4] != 46)
		{
			str[i + 1] = (int)str[i + 1] - 100;

			str[i + 2] = (int)str[i + 2] - 100;

			str[i + 3] = (int)str[i + 3] - 100;
		}

	remove_spc(str, S);

	for (int i = 0; i < S; i++)
		if ((int)str[i] > 64 and (int)str[i] < 91)
			str[i] = str[i] + 32;

	if ((int)str[0] > 96 and (int)str[0] < 123)
		str[0] = str[0] - 32;

	for (int i = 0; i < S; i++)
		if ((int)str[i] == 46 and ((int)str[i + 1] > 96 and (int)str[i + 1] < 123))
			str[i + 1] = str[i + 1] - 32;

	delete_symb(str, S);

	insert_symb(str, S);


	for (int i = 0; i < S; i++)
		if ((int)str[i] == -54 and (int)str[i + 1] == -54 and (int)str[i + 2] == -54)
		{
			str[i] = (int)str[i] + 100;

			str[i + 1] = (int)str[i + 1] + 100;

			str[i + 2] = (int)str[i + 2] + 100;
		}

	for (int i = 0; i < S; i++)
		if (((int)str[i] == 46 and (int)str[i + 1] == 32) and ((int)str[i + 2] > 96 and (int)str[i + 2] < 123))
			str[i + 2] = str[i + 2] - 32;

	char tmp;
	for (int i = 0; i < S; i++)
		while (((int)str[i] == 46 and (int)str[i + 1] == 46 and (int)str[i + 2] == 46 and (int)str[i + 3] != 32))
		{


			int j = 0;
			for (int i = 0; i < S; i++)
			{
				j++;
				if (((int)str[i] == 46 and (int)str[i + 1] == 46 and (int)str[i + 2] == 46 and (int)str[i + 3] != 32))
					break;
			}
			printf("%d\n", j);

			tmp = str[S - 1];
			for (int i = S - 1; i >= j; --i)
				str[i] = str[i - 1];
			str[j + 2] = 32;

		}


	printf("STRING:\t");
	puts(str);
}

int main()
{
	int n;
	
	printf(" end of string write: #\n");
	printf("Enter string:\n");


	char* str = getstr(&n);


	printf("\n0");

	correct_str(str, n);

	
	printf("\n%d", _CrtDumpMemoryLeaks());

	return 0;
}
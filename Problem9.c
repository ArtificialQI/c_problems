#include <stdio.h>
#include <string.h>
#include <iso646.h>
#include <stdbool.h>
#define M 1000

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
		while (((int)str[i+1] == 46 or (int)str[i+1] == 44) and (int)str[i] == 32)
		{
			int j = 0;
			for (int i = 0; i < S; i++)
			{
				j++;
				if (((int)str[i+1] == 46 or (int)str[i+1] == 44) and (int)str[i] == 32)
					break;
			}
			printf("%d\n", j);

			for (int i = j-1; i < S; i++)
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

char replace(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void correct_str(char* str, int S)                      
{

	for (int i = 0; i < S; i++)
		if ((int)str[i] != 46 and (int)str[i+1] == 46 and (int)str[i + 2] == 46 and (int)str[i + 3] == 46 and (int)str[i + 4] != 46 )
		{
			str[i + 1] = (int)str[i+1] - 100;

			str[i + 2] = (int)str[i+2] - 100;

			str[i + 3] = (int)str[i+3] - 100;
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
		if ((int)str[i] == -54 and (int)str[i + 1] == -54 and (int)str[i + 2] == -54 )
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
	

	printf("SRTING:\t");
	puts(str);
}



int main()
{
	printf("Max size of string is 500 characters\n");

	char str[M];
	printf("Enter string\n");

	fgets(str, M, stdin);

	int S = strlen(str);
	printf("lenght of string is %d\n", S);

	remove_n(str, S);

	printf("you entered:\n");
	puts(str);

	correct_str(str, M);
	
	return 0;
}
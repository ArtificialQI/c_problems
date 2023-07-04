#include<stdio.h>
#include<math.h>
int main()
{
	float a, b, c, d, x0, x, x1, x2;
	printf("to solve ax^2+bx+c - please enter coef a, b, c\n");
	scanf_s("%f%f%f", &a, &b, &c);
	printf("a = %f\tb = %f\tc = %f\n\n", a, b, c);
	d = (b * b - 4 * a * c);
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				printf("inf solutions");
			else
				printf("no solutions");
		}
		else
		{
			x0 = -c/a;
			printf("x = %f", x0);
		}


	}
	else
	{
		if (d < 0)
			printf("no solutions");
		else
		{
			if (d == 0)
			{
				x = -b / 2 * a;
				printf("x = %f", x);
			}
			else
			{
				x1 = (-b + sqrt(d)) / 2 * a;
				x2 = (-b - sqrt(d)) / 2 * a;
				printf("x1 = %f\t x2 = %f", x1, x2);
			}
		}

	}


		



		




	
	return 0;
}
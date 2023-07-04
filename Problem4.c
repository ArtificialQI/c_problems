#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double f(double x)
{
	return x*x+1;

}

double df(double x)
{
	return 2*x;
}

double rec(double x)
{
	double xk;
	double e = 0.0001;
	int j = 0;
	if (df(x) == 0)
	{
		x = x - 1;
	}
	xk = x - (f(x) / df(x));
	for (int i = 0; i < 10000; i++)
	{

		if (df(xk) != 0)
		{
			xk = xk - (f(xk) / df(xk));
			double xk1 = xk - (f(xk) / df(xk));
			if (fabs(xk1 - xk) < e)
			{
				return printf("%lf\n", xk);
			}
		}
		else
		{
			xk = xk - e;
			j++;
			printf("%lf", xk);
		}
		if ((j > 0) && (df(xk) == 0))
		{
			return printf("undefined derivative or roots not exist");
		}
	}
	double xk2 = xk - (f(xk) / df(xk));
	if (fabs(xk2 - xk) > e) {
		printf("%lf\n", xk);
		printf("%lf\n", xk2);
		return printf("equation have no root\n");
	}
	else {
		return printf("%lf\n", xk);
	}

}

int main()
{
	int m = 1;
	do
	{
		double x, xk, a, b;

		printf("Enter suspicios x of root locality\n");
		scanf_s("%lf", &x);
		a = f(x);
		b = df(x);
		printf("func(x0) = %lf,\tfunc_d(x0) = %lf\n\n", a, b);

		rec(x);

		printf("One more iteration?\n\n Type 1 - means yes or 0 - means not\n");
		scanf_s("%d", &m);

	} while (m == 1);

	return 0;
}


/*
double f(double x) 
{
	double y = x * x * x;
	return y;

}

double df(double x)
{
	double y_d = 3 * x * x;
	return y_d;
}
*/

/*
double rec(double x) {
	double xk;
	double e = 0.001;
	for (long long int i = 0; i < 10000000; i++) {

		if (df(x) != 0) {
			xk = x - (f(x) / df(x));
			if (fabs(x - xk) < e) {
				return xk;
			}
		}
		else {
			return printf("undefined derivative or roots not exist");
		}
	}

	if (fabs(xk - x) > e) {
		printf("%lf", xk);
		printf("%lf", x);
		return printf("govno\n");
	}
	else {
		return printf("%lf\n", xk);
	}
	*/


/*
int a, b, t;
 t = scanf_s("%d", &a);
if (t == 1) {
	printf("correct\n");
}
else {
	printf("NO");
}

while (getchar() != "\n");

t = scanf_s("%d", &b);
if (t == 1) {
	printf("correct\n");
}
else {
	printf("NO");
}
*/
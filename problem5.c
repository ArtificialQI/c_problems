#include <stdio.h>
#include <math.h>

double f(double x)
{
	double y;
	y = sin(x);
	return y;
}
double df(double x)
{
	double dy;
	dy = cos(x);
	return dy;
}
double df2(double x, double dh)
{
	double d2y;
	d2y = (df(x + dh) - (double)df(x)) / (dh);
	return d2y;

}

int main()
{

	double I, N, a, b;
	printf("Enter number of fragmentation\n");
	scanf_s("%lf", &N);
	printf("Enter limits of integration from a to b\n");
	scanf_s("%lf\t%lf", &a, &b);
	printf("N = %lf\ta = %lf\tb = %lf\n", N, a, b);

	double x, h, x1, x2;
	h = (b - a) / N;

	double add = 0;
	double dh = 0;
	double max = 0;
	for (int i = 0; i <= N; i++)
	{

		x1 = a + i * h;
		//x2 = a + (i + 1) * h;
		double e = 0.001;
	    max = df2(x1, e);
		if ((df2(x1+h, e) > df2(x1, e)) && (df2(x1+h, e) > max))
		{
			max = df2(x1+h, e);
		}
		if ((df2(x1, e) > df2(x1+h, e)) && (df2(x1, e) > max))
		{
			max = df2(x1, e);
		}

		dh = (h * h * (b - a) * fabs(max)/12);
			

		//printf("x1\t%d = %f\n", i, x1);
		//printf("x2\t%d = %f\n", i, x2);
		add = add +  h * (f(x1) + (double)f(x1+h)) / 2;
		//printf("add%d = %f\n", i, add);
	}
	printf(" sum = %lf", add);
	printf(" dh = %lf\t", dh);
	printf(" max = %lf", max);

	return 0;
}


/*float x;
scanf_s("%f", &x);

printf("%f\t%f", function(x), function(x + 1));*/
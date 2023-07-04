#include<stdio.h>
#include<malloc.h>
//# define N 20

int main()
{
    int a, i, p, sum = 10;
    double pi;
    pi = 0;

    printf("enter decimal places\t");
    scanf_s("%d", &a);

    for (i = 0; i <= a; i++) {
        sum = sum * 10;           // to get a new dp
    }

    int  d, c = -1;
    for (i = 0; i <= sum; i++) {
        c = c * (-1);
        d = (2 * i + 1);
        pi = pi + (double)c / d;
    }
    pi = pi * 4;

    printf("%.*lf", a, pi);

    //int* cq;
    //int b;
    //cq = (int*)malloc((a + 1) * sizeof(int));

    // b = (int)pi;
    //b = (int)pi;

    //pi = pi - (double)b;
    //pi = pi * 10;

    //for (int i = 0; i <= a; i++) {
      //  b = (int)pi;
        //cq[i] = b;
        //pi = pi - (double)b;
        //pi = pi * 10;
    //}

    //if (a > 0)
      //  printf("3,");
    
    //else 
       //printf("3");

    //for (i = 0; i < a; i++)

      //   printf("%d", cq[i]);

    //free(cq);
    return 0;

    

}


// A[N] = {1, 2, 3};












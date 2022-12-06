#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

double f(double x);
double halfed(double x1, double x2, int N_count, int N, const double e);
double chord(double x1, double x2, int N_count, int N, const double e);

double f (double x)
{
    return (-4*pow(x,3)-3*pow(x,2)+2*pow(x,2)-5*x-25);
}

int main()
{

    int N, method, N_count=0;
    double x1, x2;
    const double e=0.001;
    double result;

    printf("\t choose method:");
    printf("\n\t 1. halfed");
    printf("\n\t 2. chord\n");
    scanf("%u", &method);

    while (method!=1&&method!=2)
    {
       printf("\t please choose right method (1 or 2)!\n");
       scanf("%u", &method);
    }

    printf("enter the data:");
    do
    {
       printf("\n\tx1: ");
       scanf("%lf", &x1);
       printf("\n\tx2: ");
       scanf("%lf", &x2);
    }
    while (f(x1)*f(x2) <= 0);

    printf("\n\tN: ");
    scanf("%u", &N);
    system("cls");

    switch(method)
    {
        case 1:
        {
           result = halfed(x1,x2, N_count, N, e);
        }
        break;

        case 2:
        {
           result = chord(x1, x2, N_count, N, e);
        }
        break;
    }
return 0;
}

double halfed(double x1, double x2, int N_count, int N, const double e) {

    double xi;
    unsigned int choice, const_n;
    const_n=N;
    while(fabs(x1-x2)>=e)
        {
        N_count++;
        xi=(x1+x2)/2;
        if(f(xi)*f(x1)>0) {
            x1=xi;
        }
        else {
            x2=xi;
        }

        if (N_count%N==0) {

            printf ("number of iterations: %u", N_count);
            printf ("\n current Õ: %.3lf", xi);
            printf ("\n current f(x)= %.3lf", f(xi));
            printf ("\n\nchoose next option:");

            printf ("\n\t 1 continue until program find answer");
            printf ("\n\t 2 continue with same number of iterations");
            printf ("\n\t 3 finish the program\n");

            scanf ("%u", &choice);
            printf ("==============================================================\n");

            while (choice!=1&&choice!=2&&choice!=3) {
                scanf("%u", &choice);
            }

            switch(choice) {
                case 1:
                {
                    N=N+const_n;
                }
                case 2:
                {
                    N=N+N_count;
                }
                case 3:
                {
                    break;
                }
            }

        }
    }
    printf("\n\tX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

double chord (double x1, double x2, int N_count, int N, const double e) {

    double xi, xl;
    unsigned int choice, const_n;
    const_n=N;

    do{
        N_count++;
        xl=xi;
        xi=x2-f(x2)*(x1-x2)/(f(x1)-f(x2));
        x1=x2;
        x2=xl;

        if (N_count%N==0) {

            printf ("number of iterations: %u", N_count);
            printf ("\n current Õ: %.3lf", xi);
            printf ("\n current f(x)= %.3lf", f(xi));
            printf ("\n\nchoose next option:");

            printf ("\n\t 1 continue until program find answer");
            printf ("\n\t 2 continue with same number of iterations");
            printf ("\n\t 3 finish the program\n");
            scanf ("%u", &choice);

            while (choice!=1&&choice!=2&&choice!=3) {
                scanf("%u", &choice);
            }

            switch(choice) {
                case 1:
                {
                    N=N+const_n;
                }
                case 2:
                {
                    N=N+N_count;
                }
                case 3:
                {
                    break;
                }
            }
        }
    }while(fabs(xi-x2)>e);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

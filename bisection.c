#include<stdio.h>
#include<math.h>
float fun (float x)
{
    //Equation f(x)=x^3-x^2-5*x+4
    return (x*x*x - x*x - 5*x + 4);
}
void bisection (float *x, float xl, float xu, int *itr)
/* this function performs and prints the result of one iteration */
{
    *x=(xl+xu)/2;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}
int main ()
{
    int itr = 0, maxmitr;
    float x, xl, xu, allerr, x1;
    printf("\nEnter the values of xl, xu, allowed error and maximum iterations:\n");
    scanf("%f %f %f %d", &xl, &xu, &allerr, &maxmitr);
    bisection (&x, xl, xu, &itr);
    do
    {
        if (fun(xl)*fun(x) < 0)
            xu=x;
        else
            xl=x;
        bisection (&x1, xl, xu, &itr);
        if ((fabs(((x1-x)/x1))*100) < 0.5)
        {
            printf("After %d iterations, root = %6.4f\n", itr, x1);
            return 0;
        }
        x=x1;
    }
    while (itr < maxmitr);
    printf("The solution does not converge or iterations are not sufficient");
    return 0;
}

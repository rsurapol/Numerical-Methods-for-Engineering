#include<stdio.h>
#include<math.h>
float f(float x)
{
    return(x*x*x - x*x - 5*x + 4); //Equation f(x)=x^3-x^2-5*x+4
}
float df (float x)
{
    return(3*x*x - 2*x - 5); //Equation f'(x)=3*x^2-2*x-5
}
int main()
{
    int itr, maxmitr;
    float x0, x1, ea, es;
    printf("\nEnter x0, allowed error and maximum iterations\n");
    scanf("%f %f %d", &x0, &es, &maxmitr);
    for (itr=1; itr<=maxmitr; itr++)
    {
        x1 = x0 - (f(x0)/df(x0));
        ea= fabs(((x1-x0)/x1) * 100);
        printf(" At Iteration no. %3d, x = %9.4f\tea = %9.4f %%\n", itr, x1, ea);

        if ( ea < es )
        {
            printf(" After %3d iterations, root = %8.4f\n", itr, x1);
            return 0;
        }
        x0=x1;
    }
    printf(" The required solution does not converge or iterations are insufficient\n");
    return 0;
}

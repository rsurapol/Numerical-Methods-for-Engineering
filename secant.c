#include<stdio.h>
#include<math.h>
float f(float x)
{
    return(x*x*x - x*x - 5*x + 4); //Equation f(x)=x^3-x^2-5*x+4
}
int main()
{
    float x0,x1,xi,d,ea,es;
    int count=1,n;
    printf("\n\nEnter the values of x0 and x1:\n"); //(a,b) must contain the solution.
    scanf("%f%f",&x0,&x1);
    printf("Enter the values of es and maximun number of iterations:\n");
    scanf("%f %d",&es,&n);
    do
    {
        if(f(x0)==f(x1))
        {
            printf("\nSolution cannot be found as the values of x0 and x1 are same.\n");
        return 0;
        }
        //c=(a*f(b)-b*f(a))/(f(b)-f(a));
        xi=(x0-((f(x0)*(x0-x1))/(f(x0)-f(x1))));
        ea= (fabs((xi-x1)/xi)*100);
        x0=x1;
        x1=xi;

        printf("Iteration No-%d    x = %.4f ea = %9.4f%% fx = %9.4f\n",count+1,xi,ea,f(xi));
        count++;
        if(count==n)
        {
        break;
        }
    } while(ea > es);
    printf("\n The required solution is %.4f\n",xi);

    return 0;
}

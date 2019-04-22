#include<stdio.h>

int main()
{
    int i;
    float sum;
    for(i=0;i<10000;i++)
    {
        sum=sum+0.0001;
        printf("sum[%d] = %-5.8f\n",i,sum);

    }

    return 0;
}

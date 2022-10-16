#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double a,b,c,s,p,x1,x2;
    scanf("%lf%lf%lf",&a,&b,&c);
    p=b*b-4*a*c;
    x1=(-b+sqrt(p))/2*a;
    x2=(-b-sqrt(p))/2*a;
    printf("%lf\n%lf",x1,x2);
    return 0;
}

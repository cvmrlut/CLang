#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
int main()
{
    char b;double a,c;
    loop:
    scanf("%lf%c%lf",&a,&b,&c);
    switch(b)
    {
        case '*':printf("%lf",a*c);break;
        case '+':printf("%lf",a+c);break;
        case '-':printf("%lf",a-c);break;
        case '/':printf("%lf",a/c);break;
    }
    goto loop;
    //printf("%C",ch);
    return 0;
}

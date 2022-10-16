#include<stdio.h>
#include<math.h>
//#include<float.h>
//#define LDBL_DIG 19//长双精度小数点19
int main()
{
	long double a=1,s=1,d=1,pi=0;
	for(;/*fabs(d)>1e-6*/;pi=pi+d,a=a+2,s=-s,d=s/a)
    {
	printf("%lf\n",pi*4);
    }
    system("pause");
	return 0;
}

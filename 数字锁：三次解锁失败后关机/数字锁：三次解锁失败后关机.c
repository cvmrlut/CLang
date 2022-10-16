#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color f5");
    int a,b,sum;
    a=24;
    sum=3;
    printf("\n\n	键入生日（月份+日的合数)以回车键结束\n	3次机、答错将关机！-_-\n\n	");
    while(1)
		{
		sum--;
        scanf("%d",&b);
    if(b!=a)
		{
        printf("	You Wrong Windows Will Shutdown 还剩下%d次机会，请继续\n",sum);
        }
    if(b==a)
		{
        while(1014==1014)
            printf(" 取消关机");
        }
    if(sum==0)
		{
        printf("	没有机会了~~~");
        system("shutdown -s -t 1");
        }
        }
    system("pause");
	return 0;
}

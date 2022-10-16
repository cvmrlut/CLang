#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color f0");
    long long i,j,n=0,a[128][128]={0};
	while(n<1 || n>64)
	{
		printf("\n\n	请输入杨辉三角形的行数:");
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
	a[i][0]=1; /*第一列全置为一*/
	for(i=1;i<n;i++)
	for(j=1;j<=i;j++)
	a[i][j]=a[i-1][j-1]+a[i-1][j];/*每个数是上面两数之和*/
	for(i=0;i<n;i++) /*输出杨辉三角*/
	{
		for(j=0;j<=i;j++)
		printf("%6d ",a[i][j]);
        printf("\n");
	}
	system("pause");
	return 0;
}

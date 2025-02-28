#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Algebra
void CalculatePi(){
	double a=1,s=1,d=1,pi=0;
	for(;/*fabs(d)>1e-6*/;pi=pi+d,a=a+2,s=-s,d=s/a){
		printf("%.51lf\n",pi*4);
    }
}
//linear equation
void qer(){ //Quadratic equation in two roots
    printf("\n(ax² + bx + c = 0) please input a,b,c:\n");
    double a,b,c,s,p,x1,x2;
    scanf("%lf%lf%lf",&a,&b,&c);
    p=b*b-4*a*c;
    x1=(-b+sqrt(p))/2*a;
    x2=(-b-sqrt(p))/2*a;
    printf("%lf\n%lf",x1,x2);
}
//Series of numbers
void pascal_triangle() {
    long long i,j,n=0,a[128][128]={0};
	while(n<1 || n>64)
	{
		printf("please input 杨辉三角(Pascal's triangle) triangle:");
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
		a[i][0]=1; /*first column all set to 1*/
	for(i=1;i<n;i++)
		for(j=1;j<=i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];/*each number is the sum of the two numbers above*/	
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			printf("%6d ",a[i][j]);
		printf("\n");
	}
}

void menu() {
    while (1) {
        printf("[Other Options] Exit Program\n"
        "[1] Pascal's Triangle\n"
        "[2] Solve a linear equation\n"
        "[3] Calculate Pi\n");
        int choice;
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer

        switch(choice) {
            case 1:
                pascal_triangle();
                break;
            case 2:
                qer();
                break;
            case 3:
                CalculatePi();
                break;
            default:
                printf("Exit Program\n");
                return;
        }        
    }
}

void main(){
    menu();
}
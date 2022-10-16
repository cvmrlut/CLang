#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int main()
{
    int shoot,i,hits=0,target=0;
    float result;
    char ch;
	system("color f0");
    printf("\n\n\n				靶刺激");
    printf("\n                             |\n                      “     |     ”");
    printf("\n  程序规则：出现（靶） — — + — — 标志后单击字符“；”+1，未出现（靶）时-1");
    printf("\n                             |\n                             |");
    printf("\n	分数用于最后测评成果；按“；”来开始（测试将在屏幕变黑1秒之后开始）");
    ch==getch();
    if(ch=';')
        Sleep(1);
    system("color 0f");
    Sleep(1000);
    system("cls");//对说明进行清屏
	for(i=0;i<=20;i++)//测试共有20次
		{
        srand((unsigned)time(NULL));//以时间为种子去随机数
		shoot=rand()%1024;//取随机数
        //printf("%d",shoot);//测试时候用的
        if(shoot<=512)
            {
            printf("\n\n\n\n\n\n\n					|\n					|\n		  		  — — + — —\n					|\n					|");
            printf("\a");
            target++;//靶子出现的次数
            Sleep(100);
            if(ch==';')//规定时间内反应+1否则-1
				hits++;
            system("cls");
            }
        else
			{
            printf("\a");
            ch==';';
            hits--;
            }
        Sleep(3000);
        }
    system("color f0");
    printf("\n\n\n		mark:%d%\n\n	",result=hits/target*100);//计算百分比作为成绩
    //printf("\n\n\n			重新测试按“；”	或者以任意键结束");
    system("pause");
    return 0;
}

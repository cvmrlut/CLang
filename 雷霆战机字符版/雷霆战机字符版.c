#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color f0");
    printf("用英文小写”w“ ”a“ ”s“ ”d“代表上下左右\n\n");
    int b,i,l,h,p=0,q=0,e,g=48,x=14,y=48;
    char c[27][48]={"                           ",
					"                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "                           ",
                    "            A              ",};
    while(1)
		{
        srand((unsigned)time(NULL));
    e=rand()%27;
        }
    while(1)
			{
            system("cls");
            printf("#",c[e][g]);
            g--;
            Sleep(1000);
            }
    char ch;
    for(i=0;i<48;i++)
    puts(c[i]);
    while(1)
	{
		ch=getch();
		if(ch=='s')
		{
			if(c[x+1][y]!='#')
			{
				c[x][y]=' ';
                x++;
                c[x][y]='A';
            }
        }
        if(ch=='w')
        {
			if(c[x-1][y]!='#')
            {
				c[x][y]=' ';
                x--;
                c[x][y]='A';
            }
        }
        if(ch=='a')
        {
			if(c[x][y-1]!='#')
            {
				c[x][y]=' ';
                y--;
                c[x][y]='A';
            }
        }
        if(ch=='d')
        {
			if(c[x][y+1]!='#')
            {
				c[x][y]=' ';
                y++;
                c[x][y]='A';
            }
        }
        system("cls");
        for(i=0;i<=48;i++)
        puts(c[i]);
    }
	system("pause");
	return 0;
}

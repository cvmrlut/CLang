#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define Higt 15
#define Width 25
#define EnemyNum 5

int position_x,position_y ;
int enemy_x[EnemyNum],enemy_y[EnemyNum] ;
int canvas[Higt][Width] = {0} ;

int score ;
int BulletWidth ;
int EnemyMoveSpeed ;

void gotoxy (int ,int ) ;
void startup() ;
void show() ;
void updateWithoutInput() ;
void updateWithInput() ;

int main()
{
    system("color f0");
    startup();

    while(1)
    {
        show();

        updateWithoutInput();

        updateWithInput();
    }
    return 0;
}

void gotoxy (int x,int y)
{

    HANDLE handle =
    GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos ;
    pos.X = x ;
    pos.Y = y ;
    SetConsoleCursorPosition(handle , pos);

}
void startup()
{
    int k ;
    position_x = Higt - 1 ;
    position_y = Width/2 ;
    canvas[position_x][position_y] = 1 ;
    for (k = 0 ; k < EnemyNum ; k++)
    {
        enemy_x[k] = rand()%2;
        enemy_y[k] = rand()%Width;
        canvas[enemy_x[k]][enemy_y[k]]=3;
    }
    score = 0 ;
    BulletWidth = 0 ;
    EnemyMoveSpeed = 20 ;
}

void show()
{
    int i , j ;

    gotoxy(0,0);

    for (i = 0 ;i < Higt ; i++)
    {
        for(j=0;j<Width;j++)//打印横排
        {
            if (canvas[i][j]==0)//零代表空
            {
                printf(" ");
            }
            else if(canvas[i][j]==1)//1代表自己的战机
            {
                printf("A");
            }
            else if(canvas[i][j]==2)//2代表子弹
            {
                printf("|");
            }
            else if (canvas[i][j]==3)//3代表敌机
            {
                printf("#");
            }
        }
        printf("\n");

    }

    printf(" Score:%d\n ",score);

    Sleep(20);//每20毫秒更新一次

}

void updateWithoutInput()
{
    int i ,j ,k ;

    static int speed = 0;

    for (i=0;i<Higt;i++)
    {
        for(j=0;j<Width;j++)//全排扫描
        {
            if(canvas[i][j]==2)//对子弹进行判断
            {
                for(k=0;k<EnemyNum;k++)//对每一个敌机扫描
                {
                    if((i==enemy_x[k])&&(j==enemy_y[k]))//子弹和敌机碰撞
                    {
                       score++;

                       if(score%5==0&&EnemyMoveSpeed>3)
                       {
                           EnemyMoveSpeed--;
                       }

                       if(score%5==0)
                       {
                           BulletWidth++;
                       }

                       canvas[enemy_x[k]][enemy_y[k]]=0;//敌机消失

                       enemy_x[k]=rand()%2;//重置敌机位置

                       enemy_y[k]=rand()%Width;

                       canvas[enemy_x[k]][enemy_y[k]]=3;

                       canvas[i][j] = 0 ;
                    }
                }

                canvas[i][j]=0;

                if(i>0)
                canvas[i-1][j] = 2 ;
            }
        }
    }

    if(speed<EnemyMoveSpeed)
        speed++;

    for(k=0;k<EnemyNum;k++)
    {
        if((position_x==enemy_x[k])&&(position_y==enemy_y[k]))
        {
            printf("Fail!\n");

            Sleep(3000);

            system("pause");

            exit(0);
        }

        if(enemy_x[k]>Higt)
        {
            canvas[enemy_x[k]][enemy_y[k]] = 0;

            enemy_x[k]=rand()%2;

            enemy_y[k]=rand()%Width;

            canvas[enemy_x[k]][enemy_y[k]] = 3;

            score--;
        }

        if(speed == EnemyMoveSpeed)
        {
            for(k=0;k<EnemyNum;k++)
            {
                canvas[enemy_x[k]][enemy_y[k]] = 0 ;

                enemy_x[k]++;

                speed = 0;

                canvas[enemy_x[k]][enemy_y[k]] = 3;
            }
        }
    }
}

void updateWithInput()
{
    char input ;

    if(kbhit())
    {
            int k ;

        input=getch();
        if (input == 'a'&&position_y>0)
        {
            canvas[position_x][position_y] = 0;

            position_y--;

            canvas[position_x][position_y] = 1;
        }
        else if(input == 'd'&&position_y<Width-1)
        {
            canvas[position_x][position_y] = 0;

            position_y++;

            canvas[position_x][position_y] = 1;
        }
        else if(input=='w')
        {
            canvas[position_x][position_y] = 0;

            position_x--;

            canvas[position_x][position_y] = 1;
        }
        else if (input == 's')
        {
            canvas[position_x][position_y] = 0;

            position_x++;

            canvas[position_x][position_y] = 1;
        }
        else if (input = ' ')
        {

            int left = position_y - BulletWidth;
            int right = position_y + BulletWidth;

            if(left < 0)
                left = 0 ;

            if(right > Width-1)
                right = Width -1 ;

            for (k=left; k<=right; k++)
                canvas[position_x-1][k] = 2;
        }
    }
}

#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
void print_target(){
    printf("\n"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t------------------------+------------------------"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n\t\t\t\t                        |"
    "\n");
}
void Instructions(){
    system("color f0");
    printf("\tTargettimulus rules:\n"
    "After the target appears, quickly press the character [j] or [J]\n"
    "Press any key to start (after the screen turns black for 1 second)");
    print_target();
    _getch();
    system("color 0f");
    Sleep(1000);
}
void target_stimulation(){
    int appear=0,hit=0,mistakenly_hit=0;
    char acquire='j';
    for(int i=0;i<10;i++){
        srand((unsigned)time(NULL));//以时间为种子去随机数
        system("cls");
        if(rand()%2){//取随机数
            appear++;//靶子出现的次数
            print_target();
            printf("\a");
            acquire=_getch();
            Sleep(222);
            if(acquire=='j'||acquire=='J')//规定时间内反应
                hit++;
        }
        else{
            printf("\a");
            acquire=_getch();
            Sleep(222);
            if(acquire=='j'||acquire=='J')//规定时间内反应
                mistakenly_hit++;
        }
        system("cls");
        Sleep(2000);
    }
    system("color f0");
    printf("appear:%d\n"
    "hits:%d\n"
    "mistakenly_hit:%d",appear,hit,mistakenly_hit);//grade
}
void main(){
    Instructions();
    target_stimulation();
}
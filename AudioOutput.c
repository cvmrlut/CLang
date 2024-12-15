#include<stdio.h>
#include<windows.h>

void beep(int hz,int t){
    Beep(hz,t);
    return;
}

int main(){
    long hz,t;
    system("mode con cp select=65001");
    printf("输入声音频率;声音时间(';'分隔)");
    scanf("%d;%d",&hz,&t);//输入声音频率;声音时长

    beep(hz,t);//输出音频函数

    return 0;
}
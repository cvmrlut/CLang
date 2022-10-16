#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#define T32 3200
#define T24 2400
#define T16 1600
#define T12 1200
#define T8 800
#define T6 600
#define T4 400
#define T2 200
#define T1 100
//低
#define D1 349
#define D2 392
#define D3 440
#define D4 466
#define D5 523
#define D6 587
#define D7 659
//中
#define Z1 698
#define Z2 784
#define Z3 880
#define Z4 988
#define Z5 1046
#define Z6 1175
#define Z7 1318
//高
#define G1 1397

#define I 20
#define R 340

void birthday_song() {
    printf("\n\t祝泽琦\n");
    Beep(D5, T4);
    Beep(D5, T4);
    Beep(D6, T8);
    Beep(D5, T8);
    Beep(Z1, T8);
    Beep(D7, T16);
    printf("\t2021 June 618 19岁\n");
    Beep(D5, T4);
    Beep(D5, T4);
    Beep(D6, T8);
    Beep(D5, T8);
    Beep(Z2, T8);
    Beep(Z1, T16);
    printf("\t生日快乐\n");
    Beep(D5, T4);
    Beep(D5, T4);
    Beep(Z5, T8);
    Beep(Z3, T8);
    Beep(Z1, T8);
    Beep(D7, T16);
    printf("\t！！！\n");
    Beep(Z4, T4);
    Beep(Z4, T4);
    Beep(Z3, T8);
    Beep(Z1, T8);
    Beep(Z2, T8);
    Beep(Z1, T16);
}

//3D爱心定义开始
float f(float x, float y, float z)
{
	float a;
	a = x * x + 9.0f / 4.0 * y * y + z * z - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}
float h(float x, float z)
{
	float y;
	for (y = 1.0f; y >= 0.0f; y -= 0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;
	return 0.0f;
}

void heart() {
	float z, x, v, y0, ny, nx, nz, nd, d;
	for (z = 1.5f; z > -1.5f; z -= 0.05f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.025f)
		{
			v = f(x, 0.0f, z);
			if (v <= 0.0f)
			{
				y0 = h(x, z);
				ny = 0.01f;
				nx = h(x + ny, z) - y0;
				nz = h(x, z + ny) - y0;
				nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
				d = (nx + ny - nz) * nd * 0.5f + 0.5f;
				putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
			}
			else putchar(' ');
		}
		putchar('\n');
	}
}
//3D爱心定义结束


void drew_heart(int wait) {
	int sign = 0;
	int i, j, e;
	int a;
	long time;
	birthday_song();//调用上边的创建的"birthday_song"(生日歌)
	for (i = 1, a = I; i < I / 2; i++, a--)
	{
		for (j = (int)(I - sqrt(I * I - (a - i) * (a - i))); j > 0; j--)
			printf(" ");
		for (e = 1; e <= 2 * sqrt(I * I - (a - i) * (a - i)); e++)
			printf("\3");
		for (j = (int)
			(2 * (I - sqrt(I * I - (a - i) * (a - i)))); j > 0; j--)
			printf(" ");
		for (e = 1; e <= 2 * sqrt(I * I - (a - i) * (a - i)); e++)
			printf("\3");
		printf("\n");
	}
	for (i = 1; i < 80; i++)
	{
		if (i == 25)
		{
			printf("  ☆  祝泽琦  生日快乐!   ☆  ");
			i += 30;
		}
		printf("\3");
	}
	printf("\n");
	for (i = 1; i <= R / 2; i++)
	{
		if (i % 2 || i % 3)
			continue;
		for (j = (int)(R - sqrt(R * R - i * i)); j > 0; j--)
			printf(" ");
		for (e = 1; e <= 2 * (sqrt(R * R - i * i) - (R - 2 * I)); e++)
			printf("\3");
		printf("\n");
	}
}

void drew_color() {//色彩变化
	char color[] = "color f";
	int len=7, k=5;
	len = strlen(color);
	char font_color[] = { "0123456789abcde" };//字体颜色
	char cl[20];//system("此处9个字符")
	
	char back_color[] = { "ffffffffffffff" };//背景颜色推荐"123456789abcdef"
	srand((unsigned int)time(NULL));
	k = rand() % strlen(back_color);//随机背景色
	
	strcpy(cl, color);
	cl[len] = back_color[k];//修改背景色
	srand((unsigned int)time(NULL));
	k = rand() % strlen(font_color);//随机字体色
	cl[len] = font_color[k];
	cl[len + 1] = '\0';
	system(cl);
	/*
	for (; k < 16; k++) {//遍历色彩
		cl[7] = font_color[k];
		cl[8] = '\0';
	}
	system("color f7");
	system(cl);
	*/
}

void lock() {
	int ina, sum;
	sum = 5;
	printf("\n\n\t\t☆(建议全屏)\n\n\t\tLogin\n\n\t$ user (gid=0): Drew\n\n\t$ Password == (You Birthday):");
	while (1)
	{
		sum--;
		scanf_s("%d", &ina);

		if (sum == 0){//判断还有没有机会啦!
			printf("	没有机会了~~~ ciao bella");
			Sleep(1111);
			system("shutdown -s -t 1");
		}

		if (19 == ina) {
			printf("\t今天如此美好\a\n\n");
			Sleep(511);
			break;//输入正确跳出
		}
		else printf("\n\t这不是在做PWN啊,宝贝!!! 还剩下%d次，再错关机!!!\a\n\n\t", sum--); //输入错会会减少机会
	}
}

void scroll() {
	char zqsr[15][193] = {
{"  .:`    .''''''''''''''''.                        |$.                          :!                                                    `$!          ;$'                                   .';;`  "},
{"   :@&'   .!$:..........`!#&'    .;!!!!!!!:.!###############%.        :$:       !$`                   !#####################|         `$!          ;$'                 .!&@@########&$%!;'`     "},
{"     '&@:   !#!         '&$`         !$`          :@&:                |%.       !$`                  .%|                   |%.        `$!     `''''|&!'''''`          :&;                       "},
{"       .`    .%#;     `&#;           !$`        !#%. '$#$'           '&|```````'%&;``````````        .%|                   |%.    '$; `$!.%|  .````|&;`````%&:        |%.       .%|             "},
{" :$:           `$#|.;@@:             !$`    ;@#$'        !@@:       .%%'````````%&:`````````.        .%|                   |%.    '&; `$! :$:      ;$'     :$:       `$!        .%|             "},
{"  `$#|           '&##|               !$`                            |$`         !$`                  .%|                   |%.    ;&: `$! .%!      ;$'     :$:       :$:        .%|             "},
{"    .%#!     '%##$'  ;@##|.          !$`   '!!!!!!!!!!!!!!$@%!;.  .%$`          !$`                  .%|                   |%.    |$` `$!  ``      ;$'     :$:       !$`        .%|             "},
{"        `$##&;.   `$!    '%###|  .;!|&@%!!`   .:;;;;;:.   :$:     %%.           !$`                  .%&|!!!!!!!!!!!!!!!!!|&%.   '&!  `$!   .......!&;.....!&;..     |#&%$$$$$$$$@@$$$$$$$$$$$$|"},
{"      :'          `$!                !$`    .%&'     .%&' :$:         ..........|$'.........         .%|                   |%.   !$`  `$!  `'''''''%&$@|''''''''.               .%|             "},
{"     :&;  `$################&'       !$`    `$!       ;$' :$:        '''''''''':$&;'''''''''`        .%|                   |%.        `$!         `$! !$`                |%.    .%|    `$%.     "},
{"    .%%.          `$!                !$`    `$!       ;$' :$:                   !$`                  .%|                   |%.        `$!        `$%.  |$`              |$`     .%|     .%@'    "},
{"    !&:           `$!                !$` ': .%%.      !&' :$:                   !$`                  .%|                   |%.        `$!       :@|     |&'           .%$.      .%|       !#;   "},
{"   ;@;  `%@@@@@@@@###@@@@@@@@@%`     !##@;    :%%%%%%%;.  :$:                   !$`                  .%|                   |%.        `$!     `$@:       ;@!         '&|        .%|        ;@!  "},
{"  ;@!             `$!            `%##|.                   :$:                   !$`                   |#@&@@@@@@@@@@@@@@@&@#%         `$!   ;@@;           |#|.     |@:         .%|         :@! "},
{" !#;              `$!                               .%#####|     `$############################;                                      `$! !#!                '&&'  ';     `%#####$`          `: "}
	};

	for (int i = 0; i < 15; i++) {
		puts(zqsr[i]);
		drew_color();
		Sleep(111);
	}
}

void ageline(){
	printf("\n\t长按20进制的'j'!\n\n\t");
	char age[279] = "0岁  >  1岁  >  2岁  >  3岁  >  4岁  >  5岁  >  6岁  >  7岁  >  8岁  >  9岁  >  10岁  >  11岁  >  12岁  >  13岁  >  14岁  >  15岁  >  16岁  >  17岁  >  18岁  >  19生日:\
生日快乐，永远快乐。愿你眼中有星光，杯中常有酒，好友伴身旁。至于其他，你早已在你的路上,灿烂人生从此有了我们!!!";
	char ch;
	for (int x = 0; x < 279; x++) {
		ch = getch();
		if (ch == 'j')
			printf("%c",age[x]);
	}
}

int main() {
    system("title 2021 June 18th 泽琦 Happy Birthday");
	system("mode con cols=191 lines=40 ");
	system("color f3");
	lock();
	heart();
	srand((unsigned int)time(NULL));
	scroll();
	drew_color();
	system("color f3");
	Sleep(1000);
	ageline();
	printf("\n");
	drew_heart(1);
	printf("\tby 德全°编写\n\t审阅:√成成,ΘDana,¤豪豪,§幻夜,φBiboli,媛媛 For №Drew\n\t2021 June 618 (辛丑年 夏 五月初九)");
	printf("");
	return 0;
}
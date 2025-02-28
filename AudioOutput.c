#include<stdio.h>
#include<windows.h>
#define T32 3200
#define T24 2400
#define T16 1600
#define T12 1200
#define T8 800
#define T6 600
#define T4 400
#define T2 200
#define T1 100
#define D1 349
#define D2 392
#define D3 440
#define D4 466
#define D5 523
#define D6 587
#define D7 659
#define Z1 698
#define Z2 784
#define Z3 880
#define Z4 988
#define Z5 1046
#define Z6 1175
#define Z7 1318
#define G1 1397
#define I 20
#define R 340

void birthday_song() {
    // note array
    int notes[] = {
        D5, D5, D6, D5, Z1, D7,
        D5, D5, D6, D5, Z2, Z1,
        D5, D5, Z5, Z3, Z1, D7,
        Z4, Z4, Z3, Z1, Z2, Z1
    };
    
    // duration array
    int durations[] = {
        T4, T4, T8, T8, T8, T16,
        T4, T4, T8, T8, T8, T16,
        T4, T4, T8, T8, T8, T16,
        T4, T4, T8, T8, T8, T16
    };
    
    // loop to play
    for(int i = 0; i < sizeof(notes)/sizeof(notes[0]); i++) {
        Beep(notes[i], durations[i]);
    }
}

void play_audio(){
    long hz,t;
    system("mode con cp select=65001");
    printf("Input the sound frequency;sound time(';'separated)");
    scanf("%d;%d",&hz,&t);
    Beep(hz,t);    
}

void menu() {
    while (1) {
        printf("[Other Options] Exit Program\n"
        "[1] Play Birthday Song\n"
        "[2] Custom Audio\n");
        int choice;
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer

        switch(choice) {
            case 1:
                birthday_song();
                break;
            case 2:
                play_audio();
                break;
            default:
                printf("Exit Program\n");
                return;
        }        
    }
}

void main() {
    menu();
}
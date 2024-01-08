#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100 // 最大可存储的学生数量
#define FILE_NAME "student.txt" // 数据存储文件名称

// 定义一个结构体来存储学生信息
typedef struct {
    int id; // 学号
    float math; // 高等数学成绩
    float english; // 大学英语成绩
    float c_programming; // C语言程序设计成绩
    float os; // 操作系统成绩
    float ds; // 数据结构成绩
} Student;

// 定义一个全局变量来存储所有学生信息
Student students[MAX_NUM];

// 定义一个全局变量来记录当前的学生数量
int num_of_students = 0;

// 定义函数来保存学生信息到文件中
void save_to_file() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", FILE_NAME);
        return;
    }
    for (int i = 0; i < num_of_students; i++) {
        fprintf(fp, "%d %.1f %.1f %.1f %.1f %.1f\n", 
            students[i].id, students[i].math, students[i].english, 
            students[i].c_programming, students[i].os, students[i].ds);
    }
    fclose(fp);
}

// 定义函数来从文件中读取学生信息
void load_from_file() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", FILE_NAME);
        return;
    }
    while (!feof(fp)) {
        int id;
        float math, english, c_programming, os, ds;
        fscanf(fp, "%d %f %f %f %f %f\n", &id, &math, &english, &c_programming, &os, &ds);
        if (id != 0) {
            // 读取到有效的学生信息
            Student student = {id, math, english, c_programming, os, ds};
            students[num_of_students++] = student;
        }
    }
    fclose(fp);
}

// 定义函数来添加新学生
void add_student() {
    if (num_of_students >= MAX_NUM) {
        printf("Error: The number of students exceeds the limit!\n");
        return;
    }
    printf("Please input the student's information:\n");
    printf("ID: ");
    scanf("%d", &students[num_of_students].id);
    printf("Math score: ");
    scanf("%f", &students[num_of_students].math);
    printf("English score: ");
    scanf("%f", &students[num_of_students].english);
    printf("C programming score: ");
    scanf("%f", &students[num_of_students].c_programming);
    printf("Operating system score: ");
    scanf("%f", &students[num_of_students].os);
    printf("Data structure score: ");
    scanf("%f", &students[num_of_students].ds);
    num_of_students++;
    save_to_file(); // 保存学生信息到文件中
    printf("Add student successfully!\n");
}

// 定义函数来查找学生
void find_student() {
    int id;
    printf("Please input the student's ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].id == id) {
            printf("Student's information:\n");
            printf("ID: %d\n", students[i].id);
            printf("Math score: %.1f\n", students[i].math);
            printf("English score: %.1f\n", students[i].english);
            printf("C programming score: %.1f\n", students[i].c_programming);
            printf("Operating system score: %.1f\n", students[i].os);
            printf("Data structure score: %.1f\n", students[i].ds);
            return;
        }
    }
    printf("Error: No such student!\n");
}

// 定义函数来删除学生
void delete_student() {
    int id, index = -1;
    printf("Please input the student's ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: No such student!\n");
    } else {
        for (int i = index; i < num_of_students - 1; i++) {
            students[i] = students[i + 1];
        }
        num_of_students--;
        save_to_file(); // 保存学生信息到文件中
        printf("Delete student successfully!\n");
    }
}

// 定义函数来修改学生的成绩信息
void modify_student() {
    int id, index = -1;
    printf("Please input the student's ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: No such student!\n");
    } else {
        printf("Please input the new scores:\n");
        printf("Math score: ");
        scanf("%f", &students[index].math);
        printf("English score: ");
        scanf("%f", &students[index].english);
        printf("C programming score: ");
        scanf("%f", &students[index].c_programming);
        printf("Operating system score: ");
        scanf("%f", &students[index].os);
        printf("Data structure score: ");
        scanf("%f", &students[index].ds);
        save_to_file(); // 保存学生信息到文件中
        printf("Modify student successfully!\n");
    }
}

// 定义函数来打印所有学生的信息
void print_all_students() {
    printf("All students' information:\n");
    for (int i = 0; i < num_of_students; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Math score: %.1f\n", students[i].math);
        printf("English score: %.1f\n", students[i].english);
        printf("C programming score: %.1f\n", students[i].c_programming);
        printf("Operating system score: %.1f\n", students[i].os);
        printf("Data structure score: %.1f\n", students[i].ds);
        printf("--------------------\n");
    }
}

int main() {
    // 读取学生信息文件
    load_from_file();

    printf("-----------------------------------\n");
    printf("    Student Score Management System\n");
    printf("-----------------------------------\n");
    printf("1. Add a new student\n");
    printf("2. Find a student\n");
    printf("3. Delete a student\n");
    printf("4. Modify a student's score\n");
    printf("5. Print all students' information\n");
    printf("0. Exit\n");

    int option;
    do {
        printf("Please input your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_student();
                break;
            case 2:
                find_student();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                modify_student();
                break;
            case 5:
                print_all_students();
                break;
            case 0:
                break;
            default:
                printf("Error: Invalid option!\n");
                break;
        }
    } while (option != 0);

    return 0;
}
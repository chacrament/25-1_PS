#include <stdio.h>

int main() {
    int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
    int sum_student[5]; // 학생별 총점
    float average_student[5];  // 학생별 평균
    char grade[5]; // 학생별 등급 

    int sum_class[3]; // 과목별 총점
    float average_class[3]; // 과목별 평균
    char class_name[3][20] = {"Korean", "English", "Math"};

    for (int i=0; i<5; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &jumsu[i][j]);
        }
    }

    for(int i=0; i<5; i++) {
        sum_student[i] = 0;
        for(int j=0; j<3; j++) {
            sum_student[i] += jumsu[i][j];
        }
        average_student[i] = sum_student[i] / 3.0;
        if(average_student[i] >= 90) {
            grade[i] = 'A';
        } else if(average_student[i] >= 80) {
            grade[i] = 'B';
        } else if(average_student[i] >= 70) {
            grade[i] = 'C';
        } else if(average_student[i] >= 60) {
            grade[i] = 'D';
        } else {
            grade[i] = 'F';
        }
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
    }

    for(int j=0; j<3; j++) {
        sum_class[j] = 0;
        for(int i=0; i<5; i++) {
            sum_class[j] += jumsu[i][j];
        }
        average_class[j] = sum_class[j] / 5.0;
        if(j == 2) {
            printf("%s %d %.1f", class_name[j], sum_class[j], average_class[j]);
        } else {
            printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
        }
    }
}
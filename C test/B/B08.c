#include <stdio.h>

struct st_jumsu{
    char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
    int jumsu[3]; // 3과목 점수 (국, 영, 수)
    int sum;	// 총점
    float avg;	// 평균
    char grade;	// 평균에 대한 등급
  };

char getGrade(float score) {
    if(score >= 90) {
        return 'A';
    } else if(score >= 80) {
        return 'B';
    } else if(score >= 70) {
        return 'C';
    } else if(score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    struct st_jumsu one; // one의 점수 데이터

    scanf("%s %d %d %d", &one.name, &one.jumsu[0], &one.jumsu[1], &one.jumsu[2]);
    
    one.sum = 0;
    for(int i=0; i<3; i++) {
        one.sum += one.jumsu[i];
    }
    one.avg = one.sum / 3.0;
    one.grade = getGrade(one.avg);
    
    printf("%s %d %.1f %c", one.name, one.sum, one.avg, one.grade);
}
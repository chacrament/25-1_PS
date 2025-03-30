#include <stdio.h>

int main() {
    int kor, eng, math; // 국어점수, 영어점수, 수학점수
    int total; // 총점
    float average;  // 평균점수

    scanf("%d %d %d", &kor, &eng, &math);
    total = kor + eng + math;
    average = total / 3.0;

    printf("%d %.1f\n", total, average);

    if (kor >= 90) {
        printf("Korean ");
    }
    if (eng >= 90) {
        printf("English ");
    }
    if (math >= 90) {
        printf("Math");
    }
}
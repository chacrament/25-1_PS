#include <stdio.h>

int main() {
    int jumsu[5][3];  // 5명의 3과목 점수를 저장하는 2차원 배열
    int sum[5];  // 학생별 총점
    float average[5];  // 학생별 평균

    for (int i=0; i<5; i++) {
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
        sum[i] = jumsu[i][0] + jumsu[i][1] + jumsu[i][2];
        average[i] = sum[i] / 3.0;
    }

    for (int i=0; i<5; i++) {
        
        if (i==4) {
            printf("%d) %d %.1f", i+1, sum[i], average[i]);
        } else {
            printf("%d) %d %.1f\n", i+1, sum[i], average[i]);
        }
    }
}
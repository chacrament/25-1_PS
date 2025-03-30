#include <stdio.h>

int main() {
    int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
    float bmi[10]; // 10명의 비만도 수치
    int count; // 비만인 사람의 숫자

    for (int i=0; i<10; i++) {
        scanf("%d %d", &height[i], &weight[i]);

        bmi[i] = weight[i] / (height[i]*0.01*height[i]*0.01);    
    }
    
    count = 0;
    for (int i=0; i<10; i++) {
        if (bmi[i] >= 25) {
            count++;
            printf("%d ", i+1);
        }
    }
    printf("\n%d", count);
}
#include <stdio.h>

int bmiLevel(int height, int weight) {
    float bmi;
    bmi = weight / (height*0.01*height*0.01);

    if (bmi < 18.5) {
        return 0;
    } else if (bmi < 23) {
        return 1;
    } else if (bmi < 25) {
        return 2;
    } else if (bmi < 30) {
        return 3;
    } else {
        return 4;
    }
}

int main() {
    int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
    int bmi_level[10]; // 10명의 비만등급(0~4)
    int count; // 비만인 사람의 숫자

    for (int i=0; i<10; i++) {
        scanf("%d %d", &height[i], &weight[i]);

        bmi_level[i] = bmiLevel(height[i], weight[i]);    
    }
    
    count = 0;
    for (int i=0; i<10; i++) {
        if (bmi_level[i] >= 3) {
            count++;
            printf("%d ", i+1);
        }
    }
    printf("\n%d", count);
}
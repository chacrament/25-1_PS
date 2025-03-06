#include <stdio.h>

int main(){
    int height, weight; // 신장(cm), 체중(kg)
    float bmi; // 비만도 수치

    scanf("%d %d", &height, &weight);

    bmi = weight / (height*0.01*height*0.01);

    printf("%.1f", bmi);
    
    return 0;
}
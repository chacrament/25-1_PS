#include <stdio.h>
int main(){
    int height, weight; // 신장(cm), 체중(kg)
    float bmi; // 비만도 수치 

    scanf("%d %d", &height, &weight);
    //비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.
    bmi = weight / (height*0.01*height*0.01);
    printf("%.1f ", bmi);

    //단, 비만 여부판정 기준은 비만도 수치가 25 이상인 경우에 “Overweight”, 그 외의 경우에 “Normal” 이라고 판단한다.
    if (bmi >= 25) {
        printf("Overweight");
    } else {
        printf("Normal");
    }
}
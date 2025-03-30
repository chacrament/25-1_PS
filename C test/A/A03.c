#include <stdio.h>
int main(){
    int count;
    scanf("%d", &count);
    
    int height[count], weight[count]; // 신장(cm), 체중(kg)
    float bmi; // 비만도 수치 

    int num = 0;

    for(int i=0 ; i<count; i++) {
        scanf("%d %d", &height[i], &weight[i]);
        bmi = weight[i] / (height[i]*0.01*height[i]*0.01);
        if (bmi >= 25) {
            num++;
        }
    }
    
    printf("%d", num);
    
}
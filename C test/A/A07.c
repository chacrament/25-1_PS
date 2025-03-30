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

int main(){
	int height[20], weight[20]; // 최대 20명의 신장(cm), 체중(kg)
	int bmi_level[20]; // 최대 20명의 비만등급(0~4)
	int count, all; // 비만인 사람의 숫자, 총 인원수

	// Your code here.
    scanf("%d", &all);

    count = 0;
    for (int i=0; i<all; i++) {
        scanf("%d %d", &height[i], &weight[i]);

        bmi_level[i] = bmiLevel(height[i], weight[i]);

        if (bmi_level[i] >= 3) {
            count++;
        }
    }

    printf("%d/%d", count, all);

	return 0;
}
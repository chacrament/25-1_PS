#include <stdio.h>

struct bmi_struct{
    char name[20];  // 이름 (공백 없이 영어 알파벳으로 구성)
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    int bmi_level; // 비만등급 0~4
};

void bmiResolve(struct bmi_struct* sp) {
    (sp->bmi) = (sp->weight)/(sp->height*0.01*sp->height*0.01);

    if (sp->bmi < 18.5) {
        sp->bmi_level = 0;
    } else if (sp->bmi < 23) {
        sp->bmi_level = 1;
    } else if (sp->bmi < 25) {
        sp->bmi_level = 2;
    } else if (sp->bmi < 30) {
        sp->bmi_level = 3;
    } else {
        sp->bmi_level = 4;
    }
}

int main(){
    struct bmi_struct data;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

    scanf("%s %d %d", data.name, &data.height, &data.weight);
    bmiResolve(&data);
    printf("%s, You are %s.\n", data.name, bmi_string[data.bmi_level]);
    return 0;
}
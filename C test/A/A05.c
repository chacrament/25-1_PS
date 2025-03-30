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
    int h, w, i;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

    scanf("%d %d", &h, &w);
    i = bmiLevel(h, w);
    printf("%s (%d)", bmi_string[i], i);
}
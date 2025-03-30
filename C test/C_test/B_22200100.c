/*
[Full Name]: 김성찬
[Student ID]: 22200100
[Honor Code Pledge]: 나 김성찬은 하나님과 사람 앞에서 정직하고 성실하게 테스트를 수행하겠습니다.
*/

#include <stdio.h>

int main() {
    const char *monthnames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char name[100][20];
    int birthdate[100];

    int count;
    int age[100], birthyear[100], birthmonth[100], birthday[100];

    scanf("%d", &count);

    for(int i=0; i<count; i++) {
        scanf("%s %d", name[i], &birthdate[i]);
        birthyear[i] = birthdate[i]/10000;
        birthmonth[i] = (birthdate[i] % 10000)/100;
        birthday[i] = birthdate[i] % 100;

        age[i] = 2025 - birthyear[i];
    }
    
    int top = 0;
    int top_index = 0;
    for(int i=0; i<count; i++) {
        if(age[i] >= top) {
            if(age[i] == top) {
                if(birthmonth[i] <= birthmonth[top_index]) {
                    if(birthmonth[i] == birthmonth[top_index]) {
                        if(birthday[i] < birthday[top_index]) {
                            top = age[i];
                            top_index = i;
                        }
                    } else {
                        top = age[i];
                        top_index = i;
                    }
                }
            } else {
                top = age[i];
                top_index = i;
            }
        }
    }

    printf("%s - %d (%s %d, %d)", name[top_index], age[top_index], monthnames[birthmonth[top_index]-1], birthday[top_index], birthyear[top_index]);

    return 0;
}
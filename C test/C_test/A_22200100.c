/*
[Full Name]: 김성찬
[Student ID]: 22200100
[Honor Code Pledge]: 나 김성찬은 하나님과 사람 앞에서 정직하고 성실하게 테스트를 수행하겠습니다.
*/

#include <stdio.h>

int main() {
    const char *monthnames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char name[20];
    int birthdate;
    int age;

    int birthyear, birthmonth, birthday;

    scanf("%s %d", name, &birthdate);

    birthyear = birthdate/10000;
    birthmonth = (birthdate % 10000)/100;
    birthday = birthdate % 100;

    age = 2025 - birthyear;

    printf("%s - %d (%s %d, %d)", name, age, monthnames[birthmonth-1], birthday, birthyear);

    return 0;
}
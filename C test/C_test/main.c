/*
[Full Name]: 김성찬
[Student ID]: 22200100
[Honor Code Pledge]: 나 김성찬은 하나님과 사람 앞에서 정직하고 성실하게 테스트를 수행하겠습니다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct st_person {
    char name[20];         // 이름 (빈칸없는 영어문자열)
    int birthdate;         // 생년월일 (8자리 숫자)
    int age;               // 나이
    int year, month, day;  // 생년, 월, 일
} PERSON;

const char* monthnames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void setPerson(PERSON* p);                                 // 구조체 포인터 p 내의 멤버변수 값을 계산해서 넣는 함수
int loadPersons(PERSON* list[]);                           // list의 모든 인원 이름과 생년월일 입력받는 함수 (총 개수 리턴)
void printBirthdays(PERSON* list[], int size, int month);  // 특정 월이 생일인 사람 출력하는 함수

int main() {
    PERSON* persons[100];
    int count = loadPersons(persons);

    for (int month = 1; month <= 12; month++) {
        printBirthdays(persons, count, month);
    }
    return 0;
}

void setPerson(PERSON* p) {
    p->year = p->birthdate / 10000;
    p->month = (p->birthdate % 10000) / 100;
    p->day = p->birthdate % 100;
    p->age = 2025-(p->year);
}


int loadPersons(PERSON* list[]) {
    int count;
    scanf("%d", &count);

    for(int i=0; i<count; i++) {
        list[i] = (PERSON*)malloc(sizeof(PERSON));
        scanf("%s %d", list[i]->name, &(list[i]->birthdate));

        setPerson(list[i]);
    }

    return count;
}

void printBirthdays(PERSON* list[], int size, int month) {
    int count_month = 0;
    int birthday_index[size];
    int temp=0;

    for(int i=0; i<size; i++) {
        if(list[i]->month == month) {
            count_month++;
            birthday_index[temp] = i;
            temp++;
        }
    }

    printf("[%s] ", monthnames[month-1]);

    if(count_month == 0) {
        printf("- 0\n");
    } else {
        for(int i=0; i<count_month; i++) {
            printf("%s(%d) ", list[birthday_index[i]]->name, list[birthday_index[i]]->day);
        }
        printf("- %d\n", count_month);
    }
}
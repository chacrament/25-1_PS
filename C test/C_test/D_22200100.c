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

void setPerson(PERSON* p);                         // 구조체 포인터 p 내의 멤버변수 값을 계산해서 넣는 함수
void printPerson(PERSON* p);                       // 구조체 포인터 p 내용을 출력하는 함수
int loadPersons(PERSON* list[]);                   // list의 모든 인원 이름과 생년월일 입력받는 함수 (총 개수 리턴)
PERSON* oldestPerson(PERSON* list[], int size);    // list에서 가장 나이가 많은 사람을 찾아 구조체 포인터를 리턴
PERSON* youngestPerson(PERSON* list[], int size);  // list에서 가장 나이가 적은 사람을 찾아 구조체 포인터를 리턴

int main() {
    PERSON* persons[100];
    int count = loadPersons(persons);
    printf("Oldest: ");
    printPerson(oldestPerson(persons, count));
    printf("Youngest: ");
    printPerson(youngestPerson(persons, count));

    return 0;
}

void setPerson(PERSON* p) {
    p->year = p->birthdate / 10000;
    p->month = (p->birthdate % 10000) / 100;
    p->day = p->birthdate % 100;
    p->age = 2025-(p->year);
}

void printPerson(PERSON* p) {
    printf("%s - %d (%s %d, %d)\n", p->name, p->age, monthnames[p->month-1], p->day, p->year);
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

PERSON* oldestPerson(PERSON* list[], int size) {
    int top = 0;
    int top_index = 0;
    for(int i=0; i<size; i++) {
        if(list[i]->age >= top) {
            if(list[i]->age == top) {
                if(list[i]->month <= list[top_index]->month) {
                    if(list[i]->month == list[top_index]->month) {
                        if(list[i]->day < list[top_index]->day) {
                            top = list[i]->age;
                            top_index = i;
                        }
                    } else {
                        top = list[i]->age;
                        top_index = i;
                    }
                }
            } else {
                top = list[i]->age;
                top_index = i;
            }
        }
    }

    return list[top_index];
}

PERSON* youngestPerson(PERSON* list[], int size) {
    int low = 100;
    int low_index = 0;
    for(int i=0; i<size; i++) {
        if(list[i]->age <= low) {
            if(list[i]->age == low) {
                if(list[i]->month >= list[low_index]->month) {
                    if(list[i]->month == list[low_index]->month) {
                        if(list[i]->day > list[low_index]->day) {
                            low = list[i]->age;
                            low_index = i;
                        }
                    } else {
                        low = list[i]->age;
                        low_index = i;
                    }
                }
            } else {
                low = list[i]->age;
                low_index = i;
            }
        }
    }

    return list[low_index];
}
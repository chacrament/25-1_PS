#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person{
	char name[20]; 	// Name (single word, no duplicates)
	int gender;  	// 0 - Female, 1 - Male
	int country;	// Country code (index of COUNTRY_NAME 0~5)
	int birthyear; 	// Birthyear
};

int getCountry(char* str) {
    if(strcmp(str, "KR") == 0) return 0;
    else if(strcmp(str, "US") == 0) return 1;
    else if(strcmp(str, "JP") == 0) return 2;
    else if(strcmp(str, "CN") == 0) return 3;
    else if(strcmp(str, "FR") == 0) return 4;
    else return 5;
}

void printInfo(struct st_person* p) {
    char* gender_str = (p->gender == 1) ? "Male" : "Female";
    char* COUNTRY_NAME[6] = {"KR", "US", "JP", "CH", "FR", "-"};

    printf("%s (%s, age:%d, from %s)", p->name, gender_str, 2025-(p->birthyear), COUNTRY_NAME[p->country]);
}

int main() {
    struct st_person* one; // 학생 1명의 데이터
    char country[5]; // 국적입력을 위한 문자열

    one = (struct st_person*)malloc(sizeof(struct st_person));

    scanf("%s %d %s %d", one->name, &one->gender, country, &one->birthyear);

    one->country = getCountry(country);
    printInfo(one);

    free(one);
}
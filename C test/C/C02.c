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
    char gender_name[2][10] = {"Female", "Male"};
    char country_name[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};

    printf("%s (%s, age:%d, from %s)\n", p->name, gender_name[p->gender], 2025-(p->birthyear), country_name[p->country]);
}

int countGender(struct st_person* data[], int size, int gender) {
    int count=0;

    for(int i=0; i<size; i++) {
        if(data[i]->gender == gender) count++;
    }

    return count;
}

int main() {
    struct st_person* pdata[20]; // 최대 20명의 데이터
    char country[5]; // 국적입력을 위한 문자열
    char count_gender[2]; // 성별 인원수
    int count;  // 인원수

    scanf("%d", &count);

    for(int i=0; i<count; i++) {
        pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));
        
        scanf("%s %d %s %d", pdata[i]->name, &(pdata[i]->gender), country, &(pdata[i]->birthyear));

        pdata[i]->country=getCountry(country);
    }

    for(int i=0; i<count; i++) {
        printf("%d) ", i+1);
        printInfo(pdata[i]);
    }

    for(int i=0; i<2; i++) {
        count_gender[i] = countGender(pdata, count, i);
    }
    
    printf("Female:%d Male:%d", count_gender[0], count_gender[1]);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_person{
	char name[20]; 	// Name (single word, no duplicates)
	int gender;  	// 0 - Female, 1 - Male
	int country;	// Country code (index of COUNTRY_NAME 0~5)
	int birthyear; 	// Birthyear
};

int getCountry(char* str);
void printInfo(struct st_person* p);
void printCountry(struct st_person* p, int country);

int main() {
    struct st_person* pdata[20]; // 최대 20명의 데이터
    char country[5]; // 국적입력을 위한 문자열
    int count;  // 인원수
    int count_m, count_f;
    int sum_age;
    float avg_age[5];

    scanf("%d", &count);
    for(int i=0; i<count; i++) {
        pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));

        scanf("%s %d %s %d", pdata[i]->name, &(pdata[i]->gender), country, &(pdata[i]->birthyear));

        pdata[i]->country = getCountry(country);
    }

    for(int i=0; i<count; i++) {
        printf("%d) ", i+1);
        printInfo(pdata[i]);
    }

    for(int j=0; j<6; j++) {
        char ncountry[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};
    
        count_m = 0;
        count_f = 0;
        sum_age = 0;
    
        for(int i=0; i<count; i++) {
            if(pdata[i]->country == j) {
                if(pdata[i]->gender == 0) {
                    count_f++;
                } else {
                    count_m++;
                }
                sum_age += (2025 - (pdata[i]->birthyear));
            }
        }
    
        if (count_m + count_f == 0) { 
            avg_age[j] = 0;  // 0으로 설정하여 NaN 방지
        } else {
            avg_age[j] = sum_age / (float)(count_m + count_f);
        }
    
        printf("[%s] Female:%d Male:%d average age:%.1f\n", ncountry[j], count_f, count_m, avg_age[j]);
    }
}

int getCountry(char* str) {
    if(strcmp(str, "KR") == 0) return 0;
    else if(strcmp(str, "US") == 0) return 1;
    else if(strcmp(str, "JP") == 0) return 2;
    else if(strcmp(str, "CN") == 0) return 3;
    else if(strcmp(str, "FR") == 0) return 4;
    else return 5;
}

void printInfo(struct st_person* p) {
    char gender[2][10] = {"Female", "Male"};
    char country[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};

    printf("%s (%s, age:%d, from %s)\n", p->name, gender[p->gender], 2025-(p->birthyear), country[p->country]);
}
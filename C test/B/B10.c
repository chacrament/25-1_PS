#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{
	char name[20]; // 이름 (공백 없이 영어 알파벳으로 구성)
	int jumsu[3]; // 3과목 점수 (국, 영, 수)
	int sum;	// 총점
	float avg;	// 평균
	char grade;	// 평균에 대한 등급
};

char getGrade(float score);
void makeJumsu(struct st_jumsu* p);
void printJumsu(struct st_jumsu* p);
struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index);
int countGrade(struct st_jumsu* data[], int size, char grade);

int main(){
	struct st_jumsu* jdata[20]; // 최대 20명의 점수 데이터
	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};
	struct st_jumsu* first[3];
	char grades[5] = "ABCDF";
	int count_grade[5];
	int count;

    // Your code here.
    scanf("%d", &count);
    for(int i=0; i<count; i++) {
        jdata[i] = (struct st_jumsu*)malloc(sizeof(struct st_jumsu));

        scanf("%s %d %d %d", jdata[i]->name, &(jdata[i]->jumsu[0]), &(jdata[i]->jumsu[1]), &(jdata[i]->jumsu[2]));

        makeJumsu(jdata[i]);
    }

    for(int i=0; i<count; i++) {
        printf("%d) ", i+1);
        printJumsu(jdata[i]);
    }
    
    

    for(int i=0; i<3; i++) {
        first[i] = firstRanking(jdata, count, i);
        printf("[%s] %s %d\n", class_name[i], first[i]->name, first[i]->jumsu[i]);
    }

    for(int i=0; i<5; i++) {
        count_grade[i] = countGrade(jdata, count, grades[i]);
        printf("[%c] %d\n", grades[i], count_grade[i]);
    }

	return 0;
}

char getGrade(float score) {
    if(score >= 90) return 'A';
    else if(score >= 80) return 'B';
    else if(score >= 70) return 'C';
    else if(score >= 60) return 'D';
    else return 'F';
}

void makeJumsu(struct st_jumsu* p) {
    p->sum = 0;
    for(int i=0; i<3; i++) {
        p->sum += p->jumsu[i];
    }
    p->avg = p->sum / 3.0;
    p->grade = getGrade(p->avg);
}

void printJumsu(struct st_jumsu* p) {
    printf("%s - %d %.1f %c\n", p->name, p->sum, p->avg, p->grade);
}

struct st_jumsu* firstRanking(struct st_jumsu* data[], int size, int index){
    int top = -1;
    struct st_jumsu* first;

    for(int i=0; i<size; i++) {
        if((data[i]->jumsu[index]) > top) {   
            top = data[i]->jumsu[index];
            first = data[i];
        }
    }

    return first;
}

int countGrade(struct st_jumsu* data[], int size, char grade) {
    int count = 0;
    for(int i=0; i<size; i++) {
        if(data[i]->grade == grade) count++;
    }
    return count;
}
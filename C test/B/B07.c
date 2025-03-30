#include <stdio.h>

int studentSum(int s[20][3], int size, int index) {
    int total = 0;
    for (int i=0; i<3; i++) {
        total += s[index][i];
    }
    return total;
}

char getGrade(float score) {
    if(score >= 90) {
        return 'A';
    } else if(score >= 80) {
        return 'B';
    } else if(score >= 70) {
        return 'C';
    } else if(score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int classSum(int s[20][3], int size, int index) {
    int total = 0;
    for(int i=0; i<size; i++) {
        total += s[i][index];
    }

    return total;
}

int firstRanking(int s[20], int size) {
    //top 변수에 0 저장
    int top = 0;
    
    //인원수 만큼 반복
    for(int i=1; i<size; i++) {
        //만약 그 다음 점수가 score 값보다 크다면 그 인덱스 값을 top 변수에 저장.
        if(s[i] > s[top]) {
            top = i;
        }
    }
    return top;
}

int main(){
	int jumsu[20][3]; // 최대 20명의 3과목 점수를 저장하고 있는 2차원 배열 
	int sum_student[20]; // 최대 20명의 학생별 총점
	float average_student[20];  // 최대 20명의 학생별 평균
	char grade[20]; // 최대 20명의 학생별 등급 
	int first;	// 1등 학생 번호
	int all;	// 인원수
	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};

	// Your code here.
    scanf("%d", &all);

    for(int i=0; i<all; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &jumsu[i][j]);
        }
    }

    for(int i=0; i<all; i++) {
        sum_student[i] = studentSum(jumsu, all, i);
        average_student[i] = sum_student[i]/3.0;
        grade[i] = getGrade(average_student[i]);
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
        first = firstRanking(sum_student, all) + 1;
    }

    for(int j=0; j<3; j++) {
        sum_class[j] = classSum(jumsu, all, j);
        average_class[j] = sum_class[j] / (float)all;
        printf("%s %d %.1f\n", class_name[j], sum_class[j], average_class[j]);
    }

    printf("1st Ranking: %d", first);

	return 0;
}
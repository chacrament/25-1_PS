#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_movie{
	char title[100];
	int year, genre, playtime, viewers;
	char description[255];
} MOVIE;

const char* genre_name[] = {
	"Sci-Fi",
	"Thriller",
	"Action",
	"Romance",
	"Musical",
	"Drama",
	"Animation",
	"War"
};

int loadRecords(MOVIE* list[]);
void printMovie(MOVIE* p);
void printReport(MOVIE* list[], int size);
int indexGenre(char* name);
void printGenreCount(MOVIE* list[], int size);
int maxViewers(MOVIE* list[], int size);
int maxPlaytime(MOVIE* list[], int size);

int main() {
    MOVIE* mlist[50];
	int count;

	count = loadRecords(mlist);	
	for(int i=0; i<count; i++){
		printf("%d) ", i+1);
		printMovie(mlist[i]);
	}
	printReport(mlist, count);
	return 0;
}

int loadRecords(MOVIE* list[]) {
    int count;
    scanf("%d", &count);
    getchar();  // ✅ 개행 문자 제거 (다음 fgets() 실행을 위해)

    for (int i = 0; i < count; i++) {
        list[i] = (MOVIE*)malloc(sizeof(MOVIE));

        fgets(list[i]->title, 100, stdin);
        list[i]->title[strcspn(list[i]->title, "\n")] = '\0';  // ✅ 개행 문자 제거

        fgets(list[i]->description, 255, stdin);
        list[i]->description[strcspn(list[i]->description, "\n")] = '\0';  // ✅ 개행 문자 제거

        char genreStr[20];
        scanf("%d %s %d %d", &(list[i]->year), genreStr, &(list[i]->playtime), &(list[i]->viewers));
        getchar();  // ✅ 개행 문자 제거

        list[i]->genre = indexGenre(genreStr);  // ✅ 문자열을 인덱스로 변환
        if (list[i]->genre == -1) {
            printf("Invalid genre: %s\n", genreStr);
            exit(1);
        }
    }

    printf("%d records loaded.\n", count);
    return count;
}

void printMovie(MOVIE* p) {
	printf("%s [%d, %s, %d min, %d viewers]\n", p->title, p->year, genre_name[p->genre], p->playtime, p->viewers);
}

void printReport(MOVIE* list[], int size) {
	printf("\n1. Number of movies by genre\n");
	printGenreCount(list, size);

	printf("\n");
	int maxTime;
	printf("2. Longest\n");
	maxTime = maxPlaytime(list, size);
	printf("%s [%d, %s, %d min, %d viewers]\n", list[maxTime]->title, list[maxTime]->year, genre_name[list[maxTime]->genre], list[maxTime]->playtime, list[maxTime]->viewers);
	printf("%s", list[maxTime]->description);

	printf("\n\n");
	int maxView;
	printf("3. Most popular\n");
	maxView = maxViewers(list, size);
	printf("%s [%d, %s, %d min, %d viewers]\n", list[maxView]->title, list[maxView]->year, genre_name[list[maxView]->genre], list[maxView]->playtime, list[maxView]->viewers);
	printf("%s", list[maxView]->description);
}

int indexGenre(char* name) {
    for(int i=0; i<8; i++) {
        if(strcmp(name, genre_name[i]) == 0) return i;  // ✅ 문자열이 같을 때만 반환
    }
    return -1;  // ✅ 유효하지 않은 경우 -1 반환
}

void printGenreCount(MOVIE* list[], int size) {
    int count[8] = {0};  // ✅ 배열 초기화

    for (int i = 0; i < size; i++) {  
        if (list[i]->genre >= 0 && list[i]->genre < 8) {
            count[list[i]->genre]++;  // ✅ 장르 인덱스를 직접 증가
        }
    }

    for (int i = 0; i < 8; i++) {
        printf("[%d] %-10s %d movies\n", i+1, genre_name[i], count[i]);
    }
}

int maxViewers(MOVIE* list[], int size) {
    int max = list[0]->viewers;
    int maxIndex = 0;

    for(int i=1; i<size; i++) {  // ✅ `i=1`부터 비교 시작
        if(list[i]->viewers > max) {
            max = list[i]->viewers;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int maxPlaytime(MOVIE* list[], int size) {
    int max = list[0]->playtime;
    int maxIndex = 0;

    for(int i=1; i<size; i++) {  // ✅ `i=1`부터 비교 시작
        if(list[i]->playtime > max) {
            max = list[i]->playtime;
            maxIndex = i;
        }
    }

    return maxIndex;
}
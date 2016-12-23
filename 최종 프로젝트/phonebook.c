#include <stdio.h>
#include <string.h>
#include "home.h"

#define MAX_NUM 100

typedef struct{
	char name[30];
	char phone[30];
}phonebook;

int saveFile(phonebook* ptr2, int* num);
int openFile(phonebook* ptr2, int* num);
void Add(phonebook* ptr2, int* num);
int deleted(phonebook* ptr2, int* num);
int search(phonebook* ptr2, int* num);
void View(phonebook* ptr2, int* num);

void Phonebook(void){
	int input;
	phonebook pb[MAX_NUM]; //사용자 정보를 저장할 구조체 배열
	int person = 0; //저장된 user수

	openFile(pb, &person);//저장된 데이터를 불러오는 함수

	//메뉴 선택
	while (1){
		printf("\n1. Add \n");
		printf("2. View \n");
		printf("3. Delete \n");
		printf("4. Search \n");
		printf("5. Home \n");
		printf("Choose the item: ");
		scanf("%d", &input);

		if (input == 1){
			printf("\n[Add] \n");
			Add(pb, &person);
		}
		else if (input == 2){
			printf("\n[View] \n");
			View(pb, &person);
		}
		else if (input == 3){
			printf("\n[Delete] \n");
			deleted(pb, &person);
		}
		else if (input == 4){
			printf("\n[Search] \n");
			search(pb, &person);
		}

		else if (input == 5){
			saveFile(pb, &person);
			return;
		}
		else
			printf("\nError! ReTry! \n\n");
	}
	return;
}

int saveFile(phonebook* ptr2, int* num){
	if (*num > 0){
		int i, state;
		FILE* fp2 = fopen("phonebookInfo.txt", "wt");

		if (fp2 == NULL){
			printf("File Open Error!\n");
			return 1;
		}
		for (i = 0; i < *num; i++){
			fprintf(fp2, "%s %s", ptr2[i].name, ptr2[i].phone);
			fputc('\n', fp2);
		}
		state = fclose(fp2);
		if (state != 0){
			printf("File Close Error!\n");
			return 1;
		}
		printf("\n  Data Save \n");
		return 0;
	}
	else{
		printf("\n  Exit \n");
		return 0;
	}
}

//파일로부터 데이터를 불러오는 함수
int openFile(phonebook* ptr2, int* num){
	int state;
	char temp;
	FILE* fp2 = fopen("phonebookInfo.txt", "rt");

	if (fp2 == NULL){
		printf("File Open Error!\n");
		return 1;
	}

	//파일에 저장된 데이터를 구조체 배열에 저장
	while (1){
		fscanf(fp2, "%s %s", ptr2[*num].name, ptr2[*num].phone);
		if (feof(fp2) != 0)
			break;
		(*num)++;
	}
	if (state != 0){
		printf("File Close Error!\n");
		return 1;
	}
	return 0;
}

//사용자의 정보를 삽입하는 함수
void Add(phonebook* ptr2, int* num){
	//유저정보가 꽉 차지 않으면
	if (*num < MAX_NUM){
		printf("저장할 번호를 입력해주세요. (최소 3자리 이상) : ");
		scanf("%s", ptr2[*num].phone);

		while( ptr2[2].phone==NULL || ptr2[1].phone==NULL) {
			printf("올바른 번호를 입력해주세요 !\n");
			printf("저장할 번호를 입력해주세요. (최소 3자리 이상) : ");
			scanf("%s", ptr2[*num].phone);
		}

		printf("저장할 이름을 입력해주세요. : ");
		scanf("%s", ptr2[*num].name);
		(*num)++;
		printf(" 저장되었습니다. \n\n");
	}
	//유저 정보가 꽉 차면
	else
		printf("  더이상 저장할 수 없습니다. \n\n");
}

//사용자의 정보를 삭제하는 함수
int deleted(phonebook* ptr2, int* num){
	char inputPhone[30];
	int i, j;

	//유저 정보가 한개라도 남아있으면
	if (*num > 0){
		printf("삭제할 전화번호를 입력해주세요: ");
		scanf("%s", inputPhone);

		for (i = 0; i < MAX_NUM; i++){
			//문자열이므로 비교하기위해 strcmp사용
			if (strcmp(inputPhone, ptr2[i].phone) == 0){
				(*num)--;
				printf("  삭제되었습니다. \n\n");
				//데이터가 가득 차지 않았다면
				if (i != MAX_NUM - 1){
					for (j = i; j < MAX_NUM; j++){
						//문자열이므로 strcpy를 사용하여 데이터 복사
						strcpy(ptr2[j].name, ptr2[j + 1].name);
						strcpy(ptr2[j].phone, ptr2[j + 1].phone);
					}
					//구조체 배열의 마지막을 NULL로 바꿈
					*ptr2[MAX_NUM - 1].name = NULL;
					*ptr2[MAX_NUM - 1].phone = NULL;
				}

				//데이터가 가득 찼다면
				else{
					//구조체 배열의 마지막을 NULL로 바꿈
					*ptr2[MAX_NUM - 1].name = NULL;
					*ptr2[MAX_NUM - 1].phone = NULL;
				}
				return 0;
			}
		}
		printf("찾지못했습니다. \n\n");
		return 0;
	}

	//저장된 유저 정보가 없다면
	else{
		printf(" 저장된 정보가 없습니다. \n\n");
		return 0;
	}
}

//사용자의 정보를 검색하는 함수
int search(phonebook* ptr2, int* num){
	char inputName[30];
	int i;

	//저장된 데이터가 있다면
	if (*num > 0){
		printf("찾을 이름을 입력해주세요. : ");
		scanf("%s", inputName);

		for (i = 0; i < MAX_NUM; i++){
			printf("%6s", "NAME ") ;
			printf("%14s", " PHONE NUMBER \n");
			if (!strcmp(inputName, ptr2[i].name)){

				printf("%6s", ptr2[i].name);
				printf("%14s\n", ptr2[i].phone);
				printf(" 검색을 완료했습니다. \n\n");
				return 0;
			}
		}
		printf("찾지못하였습니다. \n\n");
		return 0;
	}
	else{
		printf(" 저장된 정보가 없습니다. \n\n");
		return 0;
	}
}

//저장된 모든 이름과 전화번호 정보를 출력하는 함수
void View(phonebook* ptr2, int* num){
	int i = 0;
	if (*num > 0){
		printf("%6s", "NAME ") ;
		printf("%14s", " PHONE NUMBER \n");
		for (i = 0; i < *num; i++){

			printf("%6s", ptr2[i].name);
			printf("%14s\n", ptr2[i].phone);
		}
	}
	else
		printf("  저장된 정보가 없습니다. \n\n");
}
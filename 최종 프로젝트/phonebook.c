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
	phonebook pb[MAX_NUM]; //����� ������ ������ ����ü �迭
	int person = 0; //����� user��

	openFile(pb, &person);//����� �����͸� �ҷ����� �Լ�

	//�޴� ����
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

//���Ϸκ��� �����͸� �ҷ����� �Լ�
int openFile(phonebook* ptr2, int* num){
	int state;
	char temp;
	FILE* fp2 = fopen("phonebookInfo.txt", "rt");

	if (fp2 == NULL){
		printf("File Open Error!\n");
		return 1;
	}

	//���Ͽ� ����� �����͸� ����ü �迭�� ����
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

//������� ������ �����ϴ� �Լ�
void Add(phonebook* ptr2, int* num){
	//���������� �� ���� ������
	if (*num < MAX_NUM){
		printf("������ ��ȣ�� �Է����ּ���. (�ּ� 3�ڸ� �̻�) : ");
		scanf("%s", ptr2[*num].phone);

		while( ptr2[2].phone==NULL || ptr2[1].phone==NULL) {
			printf("�ùٸ� ��ȣ�� �Է����ּ��� !\n");
			printf("������ ��ȣ�� �Է����ּ���. (�ּ� 3�ڸ� �̻�) : ");
			scanf("%s", ptr2[*num].phone);
		}

		printf("������ �̸��� �Է����ּ���. : ");
		scanf("%s", ptr2[*num].name);
		(*num)++;
		printf(" ����Ǿ����ϴ�. \n\n");
	}
	//���� ������ �� ����
	else
		printf("  ���̻� ������ �� �����ϴ�. \n\n");
}

//������� ������ �����ϴ� �Լ�
int deleted(phonebook* ptr2, int* num){
	char inputPhone[30];
	int i, j;

	//���� ������ �Ѱ��� ����������
	if (*num > 0){
		printf("������ ��ȭ��ȣ�� �Է����ּ���: ");
		scanf("%s", inputPhone);

		for (i = 0; i < MAX_NUM; i++){
			//���ڿ��̹Ƿ� ���ϱ����� strcmp���
			if (strcmp(inputPhone, ptr2[i].phone) == 0){
				(*num)--;
				printf("  �����Ǿ����ϴ�. \n\n");
				//�����Ͱ� ���� ���� �ʾҴٸ�
				if (i != MAX_NUM - 1){
					for (j = i; j < MAX_NUM; j++){
						//���ڿ��̹Ƿ� strcpy�� ����Ͽ� ������ ����
						strcpy(ptr2[j].name, ptr2[j + 1].name);
						strcpy(ptr2[j].phone, ptr2[j + 1].phone);
					}
					//����ü �迭�� �������� NULL�� �ٲ�
					*ptr2[MAX_NUM - 1].name = NULL;
					*ptr2[MAX_NUM - 1].phone = NULL;
				}

				//�����Ͱ� ���� á�ٸ�
				else{
					//����ü �迭�� �������� NULL�� �ٲ�
					*ptr2[MAX_NUM - 1].name = NULL;
					*ptr2[MAX_NUM - 1].phone = NULL;
				}
				return 0;
			}
		}
		printf("ã�����߽��ϴ�. \n\n");
		return 0;
	}

	//����� ���� ������ ���ٸ�
	else{
		printf(" ����� ������ �����ϴ�. \n\n");
		return 0;
	}
}

//������� ������ �˻��ϴ� �Լ�
int search(phonebook* ptr2, int* num){
	char inputName[30];
	int i;

	//����� �����Ͱ� �ִٸ�
	if (*num > 0){
		printf("ã�� �̸��� �Է����ּ���. : ");
		scanf("%s", inputName);

		for (i = 0; i < MAX_NUM; i++){
			printf("%6s", "NAME ") ;
			printf("%14s", " PHONE NUMBER \n");
			if (!strcmp(inputName, ptr2[i].name)){

				printf("%6s", ptr2[i].name);
				printf("%14s\n", ptr2[i].phone);
				printf(" �˻��� �Ϸ��߽��ϴ�. \n\n");
				return 0;
			}
		}
		printf("ã�����Ͽ����ϴ�. \n\n");
		return 0;
	}
	else{
		printf(" ����� ������ �����ϴ�. \n\n");
		return 0;
	}
}

//����� ��� �̸��� ��ȭ��ȣ ������ ����ϴ� �Լ�
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
		printf("  ����� ������ �����ϴ�. \n\n");
}
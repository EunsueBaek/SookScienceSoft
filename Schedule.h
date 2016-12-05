void Schedule(void);
void Add(void);
void View(void);
void Home(void);
void Delete(void);

void Schedule(){
	int choice=0;
	printf("\n1.Add\n2.View\n3.Home\n원하는 작업 번호를 입력하세요.\n");
	scanf("%d", &choice);
	if(choice==1)
		Add();
	else if(choice==2)
		View();
	else
		Home();
}

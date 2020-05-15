#include<stdio.h>
#include<windows.h>

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void create(void);

//void frontpage(void)

void create(void)
{
	FILE *fp;
	char date[10];
	char cus_name[20],book_name[20];
	//int m_no.[11];
	float cost;
	
	printf("\nEnter date[DD:MM:YY]: ");
	fflush(stdin);
	scanf("%s",date);
	printf("\nEnter Book Name:      ");
	scanf("%s",book_name);
	printf("\nEnter Customer Name:  ");
	scanf("%s",cus_name);
	printf("\nEnter Cost of book:   ");
	scanf("%f",&cost);	
	fp=fopen("book.txt","a");
	fprintf(fp,"\n%s %s %s %.2f\n",date,cus_name,book_name,cost);
	printf("\n\nRecord written succesfully..");
	fclose(fp);
	getch();
}

void display_specific(void)
{
	FILE *fp;
	char date[10];
	char cus_name[20],book_name[20];
	//int m_no.[11];
	float cost;
	
	int check;
	char search[10];
	printf("\nEnter the date[DD:MM:YY]: ");
	fflush(stdin);
	scanf("%s",search);
	fp=fopen("book.txt","r");
	if(fp==NULL)printf("\n\nFile not found..");
	rewind(fp);
	while((fscanf(fp,"\n%s %s %s %.2f\n",date,cus_name,book_name,&cost))!=EOF)
	{
		check=strcmp(search,date);
		if(check==0)
		{
			printf("\nDate: %s",date);
			printf("\nName of Book: %s",book_name);
			printf("\nName of Customer: %s",cus_name);
			printf("\nCost: %.2f\n\n",cost);
			printf("\n\n");
		}
	}
	fclose(fp);
	getch();
}

void main()
{
	int ch;
	//system("cls");
	Color(4);
	do{
		system("cls");
		gotoxy(80,5);
		printf("-------Welcome to BOOKSHOP-------");
		printf("\n\n\nPress <1> to create an entry: ");
		//printf("\n\nPress <2> Display all entries: ");	
		printf("\n\nPress <2> Display books on the date: ");
		printf("\n\nPress <3> to exit: ");
		printf("\n\n\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			/*case 2:
				display_all();
				break;
			*/
			case 2:
				display_specific();
				break;
			case 3:
				exit(1);
				break;
			default:
				printf("\a");
		}
	}while(ch!=3);
	getch();
}

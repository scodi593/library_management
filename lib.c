#include<stdio.h>
#include<conio.h>
#include<string.h>

void addbook();
void deletebook();
void displaybook();
void issuebook();
void issuedlist();
void exit();
struct book
{
	int id;
	char authorname[100];
	char bookname[100];
}b;

struct student
{
	int id;
	char studentname[50];
	char bookname[100];
	float rollno;
}s;

FILE *fp;

int main()
{

	int ch;
	while(1){
	printf("\n\t\t\t  *------------------*\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  *------------------*\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
	printf("\n\n\t\tChoose one of the following\n");
	    printf("1.Add Book\n");
        printf("2.Books List\n");
        printf("3.Remove Book\n");
        printf("4.Issue Book\n");
        printf("5.Issued Book List\n");
        printf("0.Exit\n\n");
    scanf("%d",&ch);
            switch(ch)
	{
        case 0:
            exit(0);

        case 1:
            addbook();
            break;

        case 2:
            displaybook();
            break;

        case 3:
            deletebook();
            break;

        case 4:
            issuebook();
            break;

        case 5:
            issuedlist();
            break;

        default:
            printf("Invalid Choice...\n\n");
    }
}
}
    void addbook()
    {
    	fp = fopen("books.txt", "ab");
    	printf("Enter book id: ");
    	scanf("%d",&b.id);
    	printf("\nEnter author name: ");
    	fflush(stdin);
    	gets(b.authorname);
    	printf("\nEnter book name : ");
    	fflush(stdin);
        //fflush() empties the buffers related to the stream
    	gets(b.bookname);
    	fwrite(&b,sizeof(b),1,fp);
    	fclose(fp);
    	printf("Book has been added successfully\n\n");
	}
	void displaybook()
	{
		printf("\t\t\t\n////////////////////////////////////////////////////////////////\n");
		printf("\n\nBook ID\t\t Book Name\tAuthor Name\n");
		printf("\t\t\t\n////////////////////////////////////////////////////////////////\n");
		//printf("\n\n%d \t%s \t%s\t",b.id,b.bookname,b.authorname);
		fp=fopen("books.txt","rb");
	    while(fread(&b,sizeof(b),1,fp)==1)
	    {
	    	printf("\n\n%d \t\t%s \t\t%s\t",b.id,b.bookname,b.authorname);
		}
		fclose(fp);	
	}
   	void deletebook()
	{
    int id, f=0;
    system("cls");
    printf("<== Remove Books ==>\n\n");
    printf("Enter Book id to remove: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("books.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&b, sizeof(b), 1, fp) == 1){
        if(id == b.id){
            f=1;
        }else{
            fwrite(&b, sizeof(b), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nDeleted Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt");
    rename("temp.txt", "books.txt");

}
	void issuebook()
	{
	 printf("<== Issue Books ==>\n\n");
     int f=0;
    printf("Enter Book id to issue: ");
    scanf("%d", &s.id);

    //Check if we have book of given id
    fp = fopen("books.txt", "rb");

    while(fread(&b, sizeof(b), 1, fp) == 1)
	{
        if(b.id == s.id){
            strcpy(s.bookname, b.bookname);
            f=1;
            break;
        }
    }

    if(f==0){
        printf("No book found with this id\n");
        printf("Please try again...\n\n");
        return;
    }
    else{
	

    fp = fopen("issue.txt", "ab");

    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.studentname);

    fflush(stdin);

    printf("Enter Student Roll: ");
    scanf("%f", &s.rollno);

    printf("Book Issued Successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}
}
	void issuedlist()
	{
		printf("\nid\tstudentname\trollno\t\tbookname\n");
	   fp = fopen("issue.txt", "rb");
    while(fread(&s, sizeof(s), 1, fp) == 1)
	{
        printf("%d\t%s\t\t%.1f\t%s\n", s.id, s.studentname,s.rollno, s.bookname);
    }
    fclose(fp);
}

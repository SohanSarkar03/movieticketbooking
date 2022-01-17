#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"moviedetails.c"
#include"decleration.c"
struct moviedetails person[300];
int count=0;
int id2=1300;
int main()
{
	int **seat,choice,price=270,slection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	int x;
	while(x!=4)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				details();
				break;
			case 2:
				slection=movie();
				reservation(seat[slection-1],price,slection);
				count++;
				break;
			case 3:
				slection=cmovie();
				cancel(seat[slection-1]);
				break;
			case 4:
				x=4;
				break;
            case 5:
                activity();
                break;
			default:
				printf("Choice not available\n");
				break;
		}
	}
}
void activity()
{
    char str[999];
    FILE * file;
    file = fopen( "Reciept.txt" , "r");
    if (file)
        {
            while (fscanf(file, "%s", str)!=EOF)
            printf("%s\n",str);
    fclose(file);
}
}
void reservation(int *array,int price,int slection)
{
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else
				printf("*\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("Please enter your age: ");
		scanf("%u",&person[count].age);
		printf("Mention the seat number ");
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("seat1 number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		person[count].seat=j;
		if (slection==1)
			movie1(j,person[count].name,id2,price);
		else if (slection==2)
			movie2(j,person[count].name,id2,price);
		else
			movie3(j,person[count].name,id2,price);
		id2++;
}
int choice1(void)
{
	int choice;
	printf("                 Book Your Ticket              \n");
	printf("\n");
	printf("1.View the occupied seats\n");
	printf("2.Book your ticket\n");
	printf("3.Cancel your ticket\n");
	printf("4.Leave the portal\n");
	printf("5.Last Activity\n");
	printf(" Enter your choice:");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int Cseat,i,stop;
      printf(" Press 1 to cancel current ticket , Press 2 to cancel previous ticket");
      int z;
      scanf("%d",&z);
       switch (z)
       {
           case 1:
               printf("Please enter ID number of ticket: ");
               scanf("%d",&Cseat);
               for (i=0;i<300;i++)
                {
                    if(Cseat==person[i].id)
                    {
					 stop=4;
					 system("cls");
					 printf("%s your seat is %d cancelled",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
                    }
                }
                if (stop!=4)
                    printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
            break;
           case 2:
               printf("Please enter the booking ID of previous session\n");
               int curs;
               scanf("%d",curs);
               printf("Booking ID : %d has been cancelled\n",curs);
               FILE *out=fopen("Reciept.txt","w");
               fputs("NULL",out);
               fclose(out);
               choice1();
               break;
           default:
               printf("Invalid Choice");
               break;
       }
}
void details(void)
{
	int i;
	char pass[10],pak[10]="123";
	printf("Enter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s ",person[i].seat,person[i].name);
		}
	}
	else
		printf("Entered password is wrong \n");
		system("PAUSE");
		system("CLS");

}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for The Imitation Game\n\n");
	printf("\t\t\tpress 2 for The interview\n\n");
	printf("\t\t\tpress 3 for The Grand Budapest Hotel\n");
	scanf("%d",&i);
	return i;
}
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t\n\n");
	printf("\t\t\tpress 1 for The Imitation Game\n\n");
	printf("\t\t\tpress 2 for The Interview\n\n");
	printf("\t\t\tpress 3 for The Grand Budapest Hotel\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void movie1(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
		int pop,num;
		srand (time(NULL));
		int randomID = 1000+(rand()%9000);
		printf("Enter the number of people:");
		scanf("%d",&pop);
		num=price*pop;
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t\n");
        printf("The Ticket has been booked for THE IMITATION GAME on 12-9-2014 at 7:30 PM\n ");
        printf("Booking ID : %d\n",randomID);
        printf("Hall no : 02 and Seat No. %d\n",choice);
        printf("Grand Total : %d\n",num);
        person[count].id=id2;
        printf("\t------------------------------------------------------------\n");
		FILE *out=fopen("Reciept.txt","w");
        fprintf(out,"CustomerName \t %s \t BookingID \t %d \t Price \t %d \t Movie \t TheImitationGame",name,randomID,num);
        fclose(out);
        return;
}
void movie2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
		int pop,num;
		srand (time(NULL));
		int randomID = 1000+(rand()%9000);
		printf("Enter the number of people:");
		scanf("%d",&pop);
		num=price*pop;
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("The Ticket has been booked for THE INTERVIEW on 12-9-2014 at 8:30 PM\n ");
        printf("Booking ID : %d\n",randomID);
        printf("Hall no : 02 and Seat No. %d\n",choice);
        printf("Grand Total : %d\n",num);
        person[count].id=id2;
        printf("\t------------------------------------------------------------\n");
	    FILE *out=fopen("Reciept.txt","w");
        fprintf(out,"CustomerName \t %s \t BookingID \t %d \t Price \t %d \t Movie \t TheInterview",name,randomID,num);
        fclose(out);
        return;
}
void movie3(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
		int pop,num;
		srand (time(NULL));
		int randomID = 1000+(rand()%9000);
		printf("Enter the number of people:");
		scanf("%d",&pop);
		num=price*pop;
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("The Ticket has been booked for THE GRAND BUDAPEST HOTEL on 12-9-2014 at 6:30 PM\n");
        printf("Booking ID : %d\n",randomID);
        printf("Hall no : 03 and Seat No. %d\n",choice);
        printf("Grand Total : %d\n",num);
        person[count].id=id2;
        printf("\t-------------------------------------------------------------\n");
        FILE *out=fopen("Reciept.txt","w");
        fprintf(out,"CustomerName \t %s \t BookingID \t %d \t Price \t %d \t Movie \t TheGrandBudapestHotel",name,randomID,num);
        fclose(out);

        return;
}

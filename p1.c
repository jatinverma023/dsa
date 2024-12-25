#include<stdio.h>
#include<stdlib.h>
int i;
typedef struct day
{
 char *name_day;
 int date;
 char *activity;
}calendar;
calendar *ptr;
void create()
{
 ptr=(calendar*)malloc(7*sizeof(calendar));
 for(i=0;i<7;i++)
 {
 (ptr+i)->name_day=(char*)malloc(10*sizeof(char));
 (ptr+i)->activity=(char*)malloc(10*sizeof(char));

 }
 if (ptr==NULL)
 fprintf(stderr, "Memory allocation failed\n");

}
void read()
{

 for(i=0;i<7;i++)
 {
      printf("Enter the Day:");
 scanf("%s",(ptr+i)->name_day);
 printf("Enter the Date:");
 scanf("%d",&(ptr+i)->date);
 printf("Enter the Activity:");
 scanf("%s",(ptr+i)->activity);
 }
}
void display()
{
 printf("Day\tDate\tActivity\n");
 printf("_______________________\n");
 for(i=0;i<7;i++)
 {
 printf("%s\t",(ptr+i)->name_day);
 printf("%d\t",(ptr+i)->date);
 printf("%s\n",(ptr+i)->activity);
 }
free(ptr);
}
		int main()
		{
		create();
		read();
		display();
		return 0;
		}
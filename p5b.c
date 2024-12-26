#include<stdio.h>
# include<math.h>
int count=0;
void tower(int n, char BEG, char AUX,char END)
{
if(n == 0)
return;
tower(n-1, BEG, END, AUX);
printf("\nMove disc %d from %c to %c", n, BEG, END);
count++;
tower(n-1, AUX, BEG, END);
}

int main()
{
int n;
printf("\nEnter the number of discs: \n");
scanf("%d", &n);
tower(n, 'A', 'B', 'C');
printf("\n\nTotal Number of moves are: %d",(int)pow(2,n)-1);
printf("\n\nThe value of count is: %d",count);
return 0;
}
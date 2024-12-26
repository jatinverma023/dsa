#include<stdio.h>
#include<ctype.h>
#define MAX 50
int top = -1;
char stack[MAX];
void push(char ele)
{
	stack [++top]=ele;
}
char pop()
{
	return(stack[top--]);
}
int precedence(char c)
{
switch(c)
{
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
	case '%':
		return 3;
	case '^':
	case '$':
		return 4;
	default:
		return 0;
}
}
int main()
{
char infix[MAX],postfix[MAX];
int i;
int j=0;
printf("\n Enter the infix expression:");
scanf("%s",infix);
for(i=0;infix[i]!='\0';i++)
{
	if(isalnum(infix[i]))
		postfix[j++]=infix[i];
	else if(infix[i]=='(')
		push(infix[i]);
	else if(infix[i]==')')
	{
		while(stack[top]!='(')
			postfix[j++]=pop();
		top--;	
	}
	else
	{
		while(precedence(stack[top])>=precedence(infix[i]))
			postfix[j++]=pop();
		push(infix[i]);
}
}
while(top!=-1)
	postfix[j++]=pop();
postfix[j]='\0';
printf("Postfix: %s",postfix);
return 0;
}
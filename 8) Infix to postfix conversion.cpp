//Infix to postfix conversion
// space in infix expression won't be acceptable

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define n 1000000
char a[n];
int size = -1;
 
void push(char x)
{
    if(size == n-1) printf("Full\n");
	else 
	{
		size++;
		a[size] = x;
	}
}
 
char pop()
{
    char x = -1;
    if(size == -1) printf("Empty\n");
    else 
    {
    	x = a[size];
    	size--;
	}
	return x;
}
 
 
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^') return 0;
    else if((x >= 'a' && x <='z') || (x >= 'A' && x <='Z') || (x >= '0' && x <='9')) return 1;
}
 
int pre(char x)
{
    if(x == '^') return 3;
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
    else return 0;
}
 
char *convert(char *infix)
{
    char *postfix;
    postfix = (char *) malloc(sizeof(char) * (strlen(infix) + 2));
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        if(infix[i] == '(') push(infix[i]);
        if(infix[i] == ')')
        {
            while(a[size] != '(') postfix[j++] = pop();
            pop();
        }
        if(isOperand(infix[i])) postfix[j++] = infix[i++];
        else 
        {
            if(pre(infix[i]) > pre(a[size])) push(infix[i++]);
            else postfix[j++] = pop();
        }
    }
    while(size != -1) postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}
 
int main()
{
    char in[1000];
    printf("Enter the infix expression: ");
    scanf("%s", in);
    push('.');
    char *post = convert(in);
    
    printf("The converted postfix expression is: ");
    for(int i = 0; i < strlen(post) - 1; i++) if(post[i] != '(' && post[i] != ')')printf("%c", post[i]);
    printf("\n");
}
 
//k+l-m*n+(o^p)*w/u/v*t+q
//ans: kl+mn*-op^w*u/v/t*+q+

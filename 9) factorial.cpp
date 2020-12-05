// factorial using recursion

#include<stdio.h>

int fact(int n)
{
	if(n <= 1) return 1;
	else return n * fact(n - 1);
	//printf("%d * ", fact(n));
}

int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	fact(n);
	printf("The factorial of %d is %d\n", n, fact(n));
}

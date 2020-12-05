#include<stdio.h>

int top = -1;

void push(int a[], int size)
{
	int x;
	printf("Enter the value you want to push: ");
	scanf("%d", &x);
	if(top == size-1) printf("Stack is Full\n");
	else
	{
		top++;
		a[top] = x;
	}
}


int pop(int a[], int size)
{
	int x = -1;
	if(top == -1) printf("Stack is Empty\n");
	else x = a[top--];
	printf("Deleted element is %d\n", x);
}

void display(int a[], int size)
{
	for(int i = top; i >= 0; i--) printf("%d ", a[i]);
	printf("\n");
}


int main()
{
	int choice;
	int size;
	printf("Enter the size: ");
	scanf("%d", &size);
	int a[size];
	
	printf("Enter your choice (1-4):\n1 for pushing element\n2 for popping\n3 for display\n4 for exit\n");
	while(1)
	{
		printf("Enter your choice (1-4):");
		scanf("%d", &choice);
		if(choice == 1) push(a, size);
		else if(choice == 2) pop(a, size);
		else if(choice == 3) display(a, size);
		else if(choice == 4) 
		{
			printf("End of stack operation\n");
			return 0;
		}
		else printf("Wrong choice\n");
	}
}

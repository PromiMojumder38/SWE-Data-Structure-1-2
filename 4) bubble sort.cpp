#include<stdio.h>

int main()
{
	int n;
	printf("Enter the size: ");
	scanf("%d", &n);
	
	int a[n], i, j, k, comp = 0, ic = 0;
	printf("Enter the elements: ");
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < n - i; j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				ic++;
				comp++;
				printf("Step %d: ", ic);
		        for(k = 0; k < n; k++) printf("%d ", a[k]);
		        printf("\n");
			}
			else comp++;
		}	
	}
	printf("The sorted array is: ");
	for(i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n\n");
	printf("\nThe number of comparisons is %d\n", comp);
	printf("\nThe number of interchanges is %d\n", ic);
}

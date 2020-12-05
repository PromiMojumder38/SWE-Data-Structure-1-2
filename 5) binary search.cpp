#include<stdio.h>

int Rbinary_search(int a[], int l, int r, int key)
{
	int found = 0, mid, i = 0;
	while(l <= r)
	{
		mid = (l + r) / 2;
		printf("Step %d: Left %d Mid %d Right %d\n        Mid Value: %d\n", i+1, l, mid, r, a[mid]);
		if(key == a[mid]) 
		{
			printf("%d is found\n", key);
			found = 1;
			break;
		}
		else if(key > a[mid]) l = mid + 1; //idx = Rbinary_search(a, mid+1, r, key);
		else r = mid - 1; //Rbinary_search(a, l, mid - 1, key);
		i++;
	}
	if(found == 0) printf("%d is not found\n", key);
	printf("Number of steps is %d\n", i+1);
	
}

int main()
{
	int n;
	printf("Enter the size of the array: ", &n);
	scanf("%d", &n);
	
	int a[n], i; 
	printf("Enter the elements: ");
	for(i = 0; i < n; i++) scanf("%d", &a[i]);

	int key;
	printf("Enter the value you want to search: ");
	scanf("%d", &key);
	printf("Find %d in the array:\n", key);

	Rbinary_search(a, 0, n, key);
	
}


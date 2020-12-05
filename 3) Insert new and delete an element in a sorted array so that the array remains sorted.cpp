#include<stdio.h>
 
int insert(int a[], int b[], int n)
{
    int new_ele, i, j, idx_new;
    printf("Enter the value you want to insert: ");
    scanf("%d", &new_ele);
    
    for(i = 0; i < n + 1; i++)
    {
        if(new_ele < a[i]) 
        {
            idx_new = i;
            break;
        }
    }
    
    for(i = 0, j = 0; j < idx_new; i++, j++) b[j] = a[i];
    b[idx_new] = new_ele;
    for(j = idx_new + 1; j < n + 1; i++, j++) b[j] = a[i];
    
    printf("After inserting new element, the main array will be: ");
    for(i = 0; i < n + 1; i++) printf("%d ", b[i]);
    printf("\n");
}
 
int del_value(int a[], int c[], int n)
{
    int del_ele, i, j, idx_del;
    printf("Enter the value you want to delete: ");
    scanf("%d", &del_ele);
    
    for(i = 0; i < n; i++)
    {
        if(del_ele == a[i]) 
        {
            idx_del = i;
            break;
        }
    }
    
    for(i = 0, j = 0; j < idx_del; i++, j++) c[j] = a[i];
    
    for(i = idx_del + 1; j < n - 1; i++, j++) c[j] = a[i];
    
    printf("After deleting %d, the main array will be: ", del_ele);
    for(i = 0; i < n - 1; i++) printf("%d ", c[i]);
    printf("\n");
}
 
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int a[n], b[n+1], c[n-1];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n - i; j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}	
	}
 
    insert(a, b, n);
    del_value(a, c, n);
}

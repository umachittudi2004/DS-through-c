#include<stdio.h>
void insertion_sort(char *arr,int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
	for(j=i-1;;j--)
	{
		if(arr[j]<key || j==-1)
		{
			arr[j+1]=key;
			break;
		}
		else
		{
			arr[j+1]=arr[j];
		}
	}
   }
}
int main()
{
	int n;
	printf("Enter the size of the string");
	scanf("%d",&n);
	char arr[n];
	scanf("%s",&arr);
	insertion_sort(arr,n);
	printf("%s ",arr);
}

#include<stdio.h>
#include<time.h>

void swap(int[], int, int);
void bubbleSort(int[],int);
void cocktailShakerSort(int[],int);
void insertionSort(int[],int);

int main()
{
	int i,n;
	float t1,t2,t3;
	n=10000;
	printf("Inputsize\tBubbleSort\tCocktailshakerSort\tInsertionSort\n");
	clock_t start,end;
	for(n=10000;n<=100000;n=n+10000)
	{
		int a[n],b[n],c[n];
		FILE *fp=fopen("Number.txt","r");
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d%d%d",&a[i],&b[i],&c[i]);
		}
		fclose(fp);
		
		start=clock();
		bubbleSort(a,n);
		end=clock();
		t1=(end-start) *1.0/CLOCKS_PER_SEC;
		
		start=clock();
		cocktailShakerSort(b,n);
		end=clock();
		t2=(end-start)*1.0/CLOCKS_PER_SEC;
		
		start=clock();
		insertionSort(c,n);
		end=clock();
		t3=(end-start)*1.0/CLOCKS_PER_SEC;
		printf("%d\t%0.2f\t%0.2f\t%0.2f\n",n,t1,t2,t3);
		}
		return 0;
	}
void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void bubbleSort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0; j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a,j,j+1);
			}
		}
	}
	FILE *fp=fopen("bubbleSort.txt","w");
	for(i=0;i<n;i++)
	{
	fprintf(fp,"%d\n",a[i]);
	}
	
	fclose(fp);
}

void cocktailShakerSort(int a[],int n)
{
	int i,temp,swapped=1,start=0,end=n-1;
	while(swapped)
	{
		swapped=0;
		for(i=start;i<end;i++)
		{
			if(a[i]>a[i+1])
			{
				swap(a,i,i+1);
				swapped=1;
			}
		}
		if(!swapped)
		break; 
		end--;
		
		for(i=end-1;i>=start;i--)
		{
			if(a[i]>a[i+1])
			{
				swap(a,i,i+1);
				swapped=1;
			}
		}
		start++;
	}
	FILE *fp=fopen("cocktailShakerSort.txt","w");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d\n",a[i]);
	}
	fclose(fp);
}

void insertionSort(int a[],int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&& a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	FILE *fp=fopen("insertionSort.txt","w");
	for(i=0;i<n;i++)
	{	
		fprintf(fp,"%d\n",a[i]);
	}
}
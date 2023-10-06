#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp=fopen("Matrix1.txt","w");
	srand(time(NULL));
	int i;
	for(i=0;i<10000;i++)
	{
		fprintf(fp,"%d\n",rand()%10);
	}
	fclose(fp);
	return 0;
}

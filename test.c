#include<stdio.h>

int readfile(char *filename,int size)
{
	FILE *fp;
	char ans[64];
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("wrong read file!\n");
		return -1;
	}
	fgets(ans,size,fp);
	ans[size] = '\0';
	while(!feof(fp))
	{
		printf("%s",ans);
		fgets(ans,size,fp);
		ans[size] = '\0';
	}
	fclose(fp);
	return 0;
}

int main(int argc,int argv[])
{
	char filename[] = "/home/tab/leargit/crashdump.dmp";
	int size;
	scanf("%d",&size);
	printf("***********************************************************************************************\n");
	readfile(filename,size);
	printf("***********************************************************************************************\n");
	return 0;
}

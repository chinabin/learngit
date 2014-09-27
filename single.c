#include<stdio.h>

int readfile(char *filename,int size)
{
	FILE *fp;
    char c;
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("wrong read file!\n");
		return -1;
	}
	c=fgetc(fp);
	while(!feof(fp))
	{
		printf("%c",c);
        c=fgetc(fp);
	}
	fclose(fp);
	return 0;
}

int main(int argc,int argv[])
{
	char filename[] = "C:/Users/Nibnat/Desktop/xixi/crashdump.dmp";
	int size=1;
	printf("***********************************************************************************************\n");
	readfile(filename,size);
	printf("***********************************************************************************************\n");
	return 0;
}

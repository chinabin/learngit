#include <stdio.h>
#include <time.h>

/*
remember download XnView software to see result1. PPM�Ҷ��ļ�
    �ļ�ͷ��3���ı���ɣ�����fgets����
    1����һ��Ϊ��P2"����ʾ�ļ�����
    2���ڶ���Ϊͼ��Ŀ�Ⱥ͸߶�
    3��������Ϊ��������ֵ255
    ��������ͼ�����ݿ顣����˳��洢��ÿ������ռ4���ֽڣ��Ҷ�ͨ��Ϊ4�ֽ�ASCII���ʾ��������
    ���ֽ���ǰ�����Ͻ�Ϊ����ԭ�㡣
 
2. 16λPPM�ļ������������ڶ�ȡ��DCRAW���ɵ�PPM�ļ���
    �ļ�ͷ��3���ı���ɣ�����fgets����
    1����һ��Ϊ��P6"����ʾ�ļ�����
    2���ڶ���Ϊͼ��Ŀ�Ⱥ͸߶�
    3��������Ϊ��������ֵ
    ��������ͼ�����ݿ顣����˳��洢��ÿ������ռ3���ֽڣ�����Ϊ������ͨ����ÿ��ͨ��Ϊ1�ֽ���
    �������Ͻ�Ϊ����ԭ�㡣

3. PPM��ɫ�ļ�
    �ļ�ͷ��3���ı���ɣ�����fgets����
    1����һ��Ϊ��P3"����ʾ�ļ�����
    2���ڶ���Ϊͼ��Ŀ�Ⱥ͸߶�
    3��������Ϊ��������ֵ255
    ��������ͼ�����ݿ顣����˳��洢��ÿ������ռ12���ֽڣ�����Ϊ������ͨ����ÿ��ͨ��Ϊ4�ֽ�
    ASCII���ʾ�����������ֽ���ǰ�����Ͻ�Ϊ����ԭ�㡣
*/
#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x))                           // square
#define _cb(x) abs((x)*(x)*(x))                    // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0))   // cube root

unsigned char GR(int,int);
unsigned char BL(int,int);


unsigned char RD(int i,int j){
float x=0,y=0;int k;for(k=0;k++<256;){float a=x*x-y*y+(i-768.0)/512;y=2*x*y+(j-512.0)/512;x=a;if(x*x+y*y>4)break;}return log(k)*47;
}

unsigned char GR(int i,int j){
float x=0,y=0;int k;for(k=0;k++<256;){float a=x*x-y*y+(i-768.0)/512;y=2*x*y+(j-512.0)/512;x=a;if(x*x+y*y>4)break;}return log(k)*47;
}

unsigned char BL(int i,int j){
float x=0,y=0;int k;for(k=0;k++<256;){float a=x*x-y*y+(i-768.0)/512;y=2*x*y+(j-512.0)/512;x=a;if(x*x+y*y>4)break;}return 128-log(k)*23;
}

void pixel_write(int,int);
FILE *fp;

int main()
{
   srand((unsigned int)time(NULL));
   fp = fopen("C:\\Users\\bingo\\Desktop\\MathPic.ppm","wb");
   fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
   int j = 0 , i = 0;
   for(j=0;j<DIM;j++)
       for(i=0;i<DIM;i++)
           pixel_write(i,j);
   fclose(fp);
   return 0;
}

// to test rand's quality
void pixel_write(int i, int j)
{
   static unsigned char color[3];
   //color[0] = RD(i,j)&255;
   //color[1] = GR(i,j)&255;
   //color[2] = BL(i,j)&255;
   color[0] = i;
   color[1] = i;
   color[2] = i;
   fwrite(color, 1, 3, fp);
}
/*
some my favoriteunsigned char RD(int i,int j){
One:
unsigned char RD(int i,int j){
return (char)(_sq(cos(atan2(j-512,i-512)/2))*255);
}

unsigned char GR(int i,int j){
return (char)(_sq(cos(atan2(j-512,i-512)/2-2*acos(-1)/3))*255);
}

unsigned char BL(int i,int j){
return (char)(_sq(cos(atan2(j-512,i-512)/2+2*acos(-1)/3))*255);
}
float x=0,y=0;int k;for(k=0;k++<256;){float a=x*x-y*y+(i-768.0)/512;y=2*x*y+(j-512.0)/512;x=a;if(x*x+y*y>4)break;}return log(k)*47;
}

unsigned char GR(int i,int j){
float x=0,y=0;int k;for(k=0;k++<256;){float a=x*x-y*y+(i-768.0)/512;y=2*x*y+(j-512.0)/512;x=a;if(x*x+y*y>4)break;}return log(k)*47;
}

unsigned char BL(int i,int j){
float x=0,y=0;int k;for(k=0;k++<256;){float a=x*x-y*y+(i-768.0)/512;y=2*x*y+(j-512.0)/512;x=a;if(x*x+y*y>4)break;}return 128-log(k)*23;
}

Two:unsigned char RD(int i,int j){
double a=0,b=0,c,d,n=0;
while((c=a*a)+(d=b*b)<4&&n++<880)
{b=2*a*b+j*8e-9-.645411;a=c-d+i*8e-9+.356888;}
return 255*pow((n-80)/800,3.);
}

unsigned char GR(int i,int j){
double a=0,b=0,c,d,n=0;
while((c=a*a)+(d=b*b)<4&&n++<880)
{b=2*a*b+j*8e-9-.645411;a=c-d+i*8e-9+.356888;}
return 255*pow((n-80)/800,.7);
}

unsigned char BL(int i,int j){
double a=0,b=0,c,d,n=0;
while((c=a*a)+(d=b*b)<4&&n++<880)
{b=2*a*b+j*8e-9-.645411;a=c-d+i*8e-9+.356888;}
return 255*pow((n-80)/800,.5);
}
*/

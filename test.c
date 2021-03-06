#include <stdio.h>
#include <time.h>

/*
remember download XnView software to see result1. PPM灰度文件
    文件头由3行文本组成，可由fgets读出
    1）第一行为“P2"，表示文件类型
    2）第二行为图像的宽度和高度
    3）第三行为最大的象素值255
    接下来是图像数据块。按行顺序存储。每个象素占4个字节，灰度通道为4字节ASCII码表示的整数，
    高字节在前。左上角为坐标原点。
 
2. 16位PPM文件（至少适用于读取由DCRAW生成的PPM文件）
    文件头由3行文本组成，可由fgets读出
    1）第一行为“P6"，表示文件类型
    2）第二行为图像的宽度和高度
    3）第三行为最大的象素值
    接下来是图像数据块。按行顺序存储。每个象素占3个字节，依次为红绿蓝通道，每个通道为1字节整
    数。左上角为坐标原点。

3. PPM彩色文件
    文件头由3行文本组成，可由fgets读出
    1）第一行为“P3"，表示文件类型
    2）第二行为图像的宽度和高度
    3）第三行为最大的象素值255
    接下来是图像数据块。按行顺序存储。每个象素占12个字节，依次为红绿蓝通道，每个通道为4字节
    ASCII码表示的整数，高字节在前。左上角为坐标原点。
*/
#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x))                           // square
#define _cb(x) abs((x)*(x)*(x))                    // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0))   // cube root

unsigned char GR(int,int);
unsigned char BL(int,int);

unsigned char RD(int i,int j){
return (char)(_sq(cos(atan2(j-512,i-512)/2))*255);
}

unsigned char GR(int i,int j){
return (char)(_sq(cos(atan2(j-512,i-512)/2-2*acos(-1)/3))*255);
}

unsigned char BL(int i,int j){
return (char)(_sq(cos(atan2(j-512,i-512)/2+2*acos(-1)/3))*255);
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

void pixel_write(int i, int j)
{
   static unsigned char color[3];
   //color[0] = RD(i,j)&255;
   //color[1] = GR(i,j)&255;
   //color[2] = BL(i,j)&255;
    color[0] = rand();
    color[1] = rand();
    color[2] = rand();
   fwrite(color, 1, 3, fp);
}

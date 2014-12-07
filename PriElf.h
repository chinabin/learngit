#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUFFER    1024
// const variable for LEFT
#define LEFT_LENGTH                     8
#define DISTANCE_TO_LEFT                4
#define NUM_BITS_LENGTH                 2
// const variable for MIDDLE
#define MIDDLE_LENGTH                   30
#define DISTANCE_TO_MIDDLE              12
// const variable for RIGHT
#define RIGHT_LENGTH                    12
#define DISTANCE_TO_RIGHT               2
#define NUM_BITS_RANGE                  8

#define NUM_BIT_NAME                    20

char            buffer[BUFFER];
Elf32_Ehdr *ehdr = NULL;
Elf32_Shdr *shdr = NULL;

void elf_header(char *elf_file);
void init_left( int val , int num , char (*left)[ LEFT_LENGTH ] );
void init_middle( char *str , int num , char (*middle)[ MIDDLE_LENGTH ] );
void init_right( int *arr , int num , char (*right)[RIGHT_LENGTH] );
void pri_elf( char (*str)[NUM_BIT_NAME] , int *arr_length , int *arr_range , int num );
void fun( int num );

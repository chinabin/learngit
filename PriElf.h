#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

/*
 * 
 *
+--1---++----------2-----------------++----3----+
|      ||                            ||         |
        ******************************  00000000 
        *                            *           
|  |05  *       .text                *           
+-4+5-+ *                            *           
        ******************************  00000004 

* length 1 is LEFT_LENGTH , length 2 is MIDDLE_LENGTH , length 3 is RIGHT_LENGTH .
* length 4 is DISTANCE_TO_LEFT , length 5 is NUM_BITS_LENGTH .
* so do DISTANCE_TO_MIDDLE and DISTANCE_TO_RIGHT , and so do NUM_BITS_RANGE .
*
*/


#define BUFFER    1024
// const variable for LEFT
// length for left part
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
static int num = 0;

void init_left( int val , int num , char (*left)[ LEFT_LENGTH ] );
void init_middle( char *str , int num , char (*middle)[ MIDDLE_LENGTH ] );
void init_right( int *arr , int num , char (*right)[RIGHT_LENGTH] );
void pri_elf( char (*str)[NUM_BIT_NAME] , int *arr_length , int *arr_range );
int elf_header(char *elf_file);
int init( char *elf_file );
void getthing( char (*str)[NUM_BIT_NAME] , int *length , int *range );
int showelf(void);
int Graph( void );

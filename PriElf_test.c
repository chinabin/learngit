#include<stdio.h>
#include<string.h>
#define LEFT_LENGTH 18
#define MIDDLE_LENGTH 30
#define RIGHT_LENGTH 10

//void init_left( char *str , int num , char **left );
//void init_middle( char *str , int num , char **middle );
//void init_right( char *str , int num , char **right );
//void pri_elf( char **str , int *arr_length , int *arr_range , int num );

//void init_left( char *str , int num , char **left )
void init_left( char *str , int num , char (*left)[ LEFT_LENGTH ] )
{
    int special_line = num / 2;
    int i = 0;
    int length = strlen( str );

    for( i = 0 ; i < num ; i++ )
    {
        if( i == special_line )
        {
            memset( left[ i ] , ' ' , LEFT_LENGTH );
            sprintf( &left[ i ][ 0 ] + 4 , "%s" , str );
        }
        else
        {
            memset( left[ i ] , ' ' , LEFT_LENGTH );
        }
    }
}

int main()
{
    char str[ 4 ][ 6 ] = { "this!" , "is!!!" , "a!!!!" , "test!" };
    int num = 4;
    char left[ 4 ][ LEFT_LENGTH ];
    init_left( str[0] , num , left );
    int i = 0;
    for( ; i < 4 ; i++ )
        printf( "%s\n" , left[ i ]);
    return 0;
}

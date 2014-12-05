#include<stdio.h>
#include<string.h>

#define LEFT_LENGTH 18
#define MIDDLE_LENGTH 30
#define RIGHT_LENGTH 10

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


void init_middle( char *str , int num , char (*middle)[ MIDDLE_LENGTH ] )
{
    int first_line = 0;
    int last_line = num - 1;
    int special_line = num / 2;
    int i = 0;
    int length = strlen( str );

    for( i = 0 ; i < num ; i++ )
    {
        if( i == first_line || i == last_line )
        {
            memset( middle[ i ] , '*' , MIDDLE_LENGTH );
            middle[ 0 ] = '*';
            middle[ MIDDLE_LENGTH - 1 ] = '*';
        }
        else if( i == special_line )
        {
            memset( middle[ i ] , ' ' , MIDDLE_LENGTH );
            middle[ 0 ] = '*';
            middle[ MIDDLE_LENGTH - 1 ] = '*';
            sprintf( &middle[ i ][ 0 ] + 12 , "%s" , str );
        }
        else
        {
            memset( middle[ i ] , ' ' , MIDDLE_LENGTH );
            middle[ 0 ] = '*';
            middle[ MIDDLE_LENGTH - 1 ] = '*';
        }
    }
}

void init_right( char (*str)[2] , int num , char (*right)[RIGHT_LENGTH] )
{
    int first_line = 0;
    int last_line = num - 1;
    int i = 0;
    int length = strlen( str );

    for( i = 0 ; i < num ; i++ )
    {
        if( i == first_line   )
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
            sprintf( &middle[ i ][ 0 ] + 2 , "%s" , str[0] );
        }
        else if( i == last_line )
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
            sprintf( &middle[ i ][ 0 ] + 2 , "%s" , str[ 1 ] );
        }
        else
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
        }
    }
}

void pri_elf( char **str , int *arr_length , int *arr_range , int num )
{
    int i , ops = 0 , j;
    int height = arr_range[ 2 * i + 1 ] - arr_range[ 2 * i ] + 1;
    int width = LEFT_LENGTH + MIDDLE_LENGTH + RIGHT_LENGTH;  
    char line[ width ];
    char left[ height ][ LEFT_LENGTH ] , middle[ height ][ MIDDLE_LENGTH ] , right[ height ][ RIGHT_LENGTH ];

    for( i = 0 ; i < num ; i++ )
    {
        char tmp[2][4] = {"8df2","6abc"};
        init_left( "0x123456" , arr_length[ i ] , left );
        init_middle( str[ i ] , arr_length[ i ] , middle );
        init_right( tmp[ i ] , arr_length[ i ] , right );

        for( j = 0 ; j < ; j++ )
        {
            sprintf( line , "%s" , left[ j ] );
            ops += LEFT_LENGTH;
            sprintf( line + ops , "%s" , middle[ j ] );
            ops += MIDDLE_LENGTH;
            sprintf( line + ops , "%s" , right[ j ] );
            ops+= RIGHT_LENGTH;

            line[ ops - 1 ] = '\0';
            printf( "%s\n" , line );
            ops = 0;
        }
    }
}

int main()
{
    return 0;
}

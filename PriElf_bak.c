#include<stdio.h>
#include<string.h>

#define LEFT_LENGTH 18
#define MIDDLE_LENGTH 30
#define RIGHT_LENGTH 10

void init_left( int val , int num , char (*left)[ LEFT_LENGTH ] )
{
    int special_line = num / 2;
    int i = 0;

    for( i = 0 ; i < num ; i++ )
    {
        if( i == special_line )
        {
            memset( left[ i ] , ' ' , LEFT_LENGTH );
            sprintf( &left[ i ][ 0 ] + 4 , "%d" , val );
            left[ i ][ 5 ] = ' ';
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
        }
        else if( i == special_line )
        {
            memset( middle[ i ] , ' ' , MIDDLE_LENGTH );
            middle[ i ][ 0 ] = '*';
            middle[ i ][ MIDDLE_LENGTH - 1 ] = '*';
            sprintf( &middle[ i ][ 0 ] + 12 , "%s" , str );
            middle[ i ][ 12 + length ] = ' ';
        }
        else
        {
            memset( middle[ i ] , ' ' , MIDDLE_LENGTH );
            middle[ i ][ 0 ] = '*';
            middle[ i ][ MIDDLE_LENGTH - 1 ] = '*';
        }
    }
}

void init_right( int *arr , int num , char (*right)[RIGHT_LENGTH] )
{
    int first_line = 0;
    int last_line = num - 1;
    int i = 0;

    for( i = 0 ; i < num ; i++ )
    {
        if( i == first_line   )
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
            sprintf( &right[ i ][ 0 ] + 2 , "%0*d" , 2 , arr[0] );
            right[ i ][ 4 ] = ' ';
        }
        else if( i == last_line )
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
            sprintf( &right[ i ][ 0 ] + 2 , "%0*d" , 2 , arr[ 1 ] );
            right[ i ][ 4 ] = ' ';
        }
        else
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
        }
        right[ i ][ RIGHT_LENGTH - 1 ] = '\0';
    }
}

void pri_elf( char (*str)[6] , int *arr_length , int *arr_range , int num )
{
    int i , ops = 0 , j;
    int height;
    int width = LEFT_LENGTH + MIDDLE_LENGTH + RIGHT_LENGTH;  
    char line[ width ];

    for( i = 0 ; i < num ; i++ )
    {
        int tmp[ 2 ];
        tmp[ 0 ] = arr_range[ 2 * i ]; 
        tmp[ 1 ] = arr_range[ 2 * i + 1 ]; 
        height = arr_range[ 2 * i + 1 ] - arr_range[ 2 * i ] + 1;
        char left[ height ][ LEFT_LENGTH ] , middle[ height ][ MIDDLE_LENGTH ] , right[ height ][ RIGHT_LENGTH ];
        init_left( arr_length[ i ] , arr_length[ i ] , left );
        // PrintArr( (char **)left , num );
        init_middle( str[ i ] , arr_length[ i ] , middle );
        // PrintArr( (char **)middle , num );
        init_right( tmp , arr_length[ i ] , right );
        // PrintArr( (char **)right , num );

        for( j = 0 ; j < height ; j++ )
        {
            // sprintf( line , "%s" , left[ j ] );
            strncpy( line , left[ j ] , LEFT_LENGTH );
            ops += LEFT_LENGTH;
            // sprintf( line + ops , "%s" , middle[ j ] );
            strncpy( line + ops , middle[ j ] , MIDDLE_LENGTH );
            ops += MIDDLE_LENGTH;
            // sprintf( line + ops , "%s" , right[ j ] );
            strcpy( line + ops , right[ j ] );

            printf( "%s\n" , line );
            ops = 0;
        }
    }
}

int main()
{
    char str[ 4 ][ 6 ] = { "Leve1" , "Leve2" , "Leve3" , "Leve4" };
    int num = 4;
    char left[ 4 ][ LEFT_LENGTH ];
    int length[ 4 ] = { 3 , 4 , 8 , 9 };
    int range[ 8 ] = { 3 , 5 , 4 , 7 , 8 , 15 , 90 , 98 };
    pri_elf( str , length , range , num );
    return 0;
}

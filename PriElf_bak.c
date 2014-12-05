#include<stdio.h>

void init_left( char *str , int num , char **left );
void init_middle( char *str , int num , char **middle );
void init_right( char *str , int num , char **right );
void pri_elf( char **str , int *arr_length , int *arr_range , int num );

void init_left( char *str , int num , char **left )
{
    int special_line = num / 2;
    int i = 0;
    int length = strlen( str );

    for( i = 0 ; i < num ; i++ )
    {
        if( i == special_line )
        {
            memset( left[ i ] , ' ' , LEFT_LENGTH );
            sprintf( left[ i ] + 4 , "%s" , str );
        }
        else
        {
            memset( left[ i ] , ' ' , LEFT_LENGTH );
        }
    }
}

void init_middle( char *str , int num , char **middle )
{
    int special_line = num / 2;
    int i = 0;

    for( i = 0 ; i < num ; i++ )
    {
        if( i == special_line )
        {
            a
        }
    }

}

void init_right( char *str , int num , char **right )
{
    int special_line = num / 2;
    int i = 0;

    for( i = 0 ; i < num ; i++ )
    {
        if( i == special_line )
        {
            a
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
        init_left( str[ i ] , arr_length[ i ] , left );
        init_middle( str[ i ] , arr_length[ i ] , middle );
        init_right( str[ i ] , arr_length[ i ] , right );

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

#include<stdio.h>
#include<string.h>

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

#define NUM_BIT_NAME                    6

void init_left( int val , int num , char (*left)[ LEFT_LENGTH ] )
{
    int special_line = num / 2;
    int i = 0;

    for( i = 0 ; i < num ; i++ )
    {
        if( i == special_line )
        {
            memset( left[ i ] , ' ' , LEFT_LENGTH );
            sprintf( &left[ i ][ 0 ] + DISTANCE_TO_LEFT , "%0*d" , NUM_BITS_LENGTH , val );
            left[ i ][ DISTANCE_TO_LEFT + NUM_BITS_LENGTH ] = ' ';
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
            sprintf( &middle[ i ][ 0 ] + DISTANCE_TO_MIDDLE , "%s" , str );
            middle[ i ][ DISTANCE_TO_MIDDLE + length ] = ' ';
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
        if( i == first_line )
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
            sprintf( &right[ i ][ 0 ] + DISTANCE_TO_RIGHT , "%0*d" , NUM_BITS_RANGE    , arr[ 0 ] );
            right[ i ][ DISTANCE_TO_RIGHT + NUM_BITS_RANGE ] = ' ';
        }
        else if( i == last_line )
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
            sprintf( &right[ i ][ 0 ] + DISTANCE_TO_RIGHT , "%0*d" , NUM_BITS_RANGE   , arr[ 1 ] );
            right[ i ][ DISTANCE_TO_RIGHT + NUM_BITS_RANGE  ] = ' ';
        }
        else
        {
            memset( right[ i ] , ' ' , RIGHT_LENGTH );
        }
        right[ i ][ RIGHT_LENGTH - 1 ] = '\0';
    }
}

void pri_elf( char (*str)[NUM_BIT_NAME] , int *arr_length , int *arr_range , int num )
{
    int i , ops = 0 , j;
    int height;
    int width = LEFT_LENGTH + MIDDLE_LENGTH + RIGHT_LENGTH;  
    char line[ width ];

    for( i = 0 ; i < num ; i++ )
    {
        int tmp[ 2 ];
        height = arr_range[ 2 * i + 1 ] - arr_range[ 2 * i ] + 1;
        char left[ height ][ LEFT_LENGTH ] , middle[ height ][ MIDDLE_LENGTH ] , right[ height ][ RIGHT_LENGTH ];

        init_left( arr_length[ i ] , arr_length[ i ] , left );
        init_middle( str[ i ] , arr_length[ i ] , middle );
        tmp[ 0 ] = arr_range[ 2 * i ];
        tmp[ 1 ] = arr_range[ 2 * i + 1 ];
        init_right( tmp , arr_length[ i ] , right );

        for( j = 0 ; j < height ; j++ )
        {
            strncpy( line , left[ j ] , LEFT_LENGTH );
            ops += LEFT_LENGTH;
            strncpy( line + ops , middle[ j ] , MIDDLE_LENGTH );
            ops += MIDDLE_LENGTH;
            strcpy( line + ops , right[ j ] );

            printf( "%s\n" , line );
            ops = 0;
        }
    }
}

void fun( int num )
{
    char str[ 7 ][ NUM_BIT_NAME ] = { "Leve1" , "Leve2" , "Leve3" , "e4" , "Lee5" , "Leve6" , "Le7" };
    char left[ num  ][ LEFT_LENGTH ];
    int length[ 7 ] = { 3 , 4 , 8 , 9 , 1 , 2 , 20 };              // 每个数字代表单个显示表的高度

    // 每个显示表的上下范围，注意：下限减去上线加1必须等于相应的length项
    int range[ 7 * 2 ] = { 125673 , 125675 , 125674 , 125677 , 125680 , 125687 , 125690 , 125698 , 123456 , 123456 , 123459 , 123460 , 123481 , 123500 };        
    pri_elf( str , length , range , num );
}

int main()
{
    fun( 7 );
    return 0;
}

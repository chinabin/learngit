#include"PriElf.h"

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

    Elf32_Ehdr *ehdr = NULL;
    Elf32_Shdr *shdr = NULL;

void init( void );

void elf_header(char *elf_file)
{
    struct stat elf_stat;
    int fd = open(elf_file,O_RDWR);

    if( fd == -1 )
    {
        perror("elf_file");
        return;
    }
    if( fstat(fd,&elf_stat) == -1 )
    {
        perror("fstat");
        return;
    }
    ehdr = mmap(0, elf_stat.st_size, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    if(ehdr == MAP_FAILED)
    {
        perror("mmap ehdr");
        return;
    }

    init();
}

void init( void )
{
    Elf32_Shdr        *shstrtab = NULL;
    int                shstrtab_off,shstrtab_len,shstrtab_num;
    char            *Real_strtab = NULL;
    char            buffer[BUFFER];
    int num = ehdr->e_shnum;
    int i = 0;
    char str[ num ][ NUM_BIT_NAME ]; 
    int length[ num ]; 
    int range[ num * 2 ]; 

    shdr = (Elf32_Shdr *)( (unsigned long)ehdr + ehdr->e_shoff );

    // get section string location
    shstrtab = &shdr[ehdr->e_shstrndx];
    // from section get real string table location
    shstrtab_off = (unsigned int)shstrtab->sh_offset;
    // get string table size
    shstrtab_len = shstrtab->sh_size;
    // endr is base address , and shstrtab_off is offset address
    Real_strtab = (char *)( (unsigned long)ehdr + shstrtab_off );
    memcpy(buffer,Real_strtab,shstrtab_len + 1);

    while( i < num )
    {
       strcpy( str[i] , buffer + (shdr + i)->sh_name  );
       length[ i ] =  (shdr+i)->sh_size;
       range[ 2 * i ] = (shdr+i)->sh_offset;
       range[ 2 * i + 1 ] = (shdr+i)->sh_offset + 3;
       // strcpy( str[i] , buffer + (shdr + i)->sh_name  );
       // length[ i ] =  (shdr+i)->sh_size;
       // range[ 2 * i ] = (shdr+i)->sh_offset;
       // range[ 2 * i + 1 ] = (shdr+i)->sh_offset + 3;
       printf("%d  %s   %d   %d\n" , i , buffer + (shdr + i)->sh_name , (shdr+i)->sh_size , (shdr+i)->sh_offset );
        i++;
    }
    pri_elf( str , length , range , num );
}

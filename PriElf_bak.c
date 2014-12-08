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

// print elf
void pri_elf( char (*str)[NUM_BIT_NAME] , int *arr_length , int *arr_range )
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

// get elf from file
int elf_header(char *elf_file)
{
    struct stat elf_stat;
    int fd = open(elf_file,O_RDWR);

    if( fd == -1 )
    {
        perror("elf_file");
        return -1;
    }
    if( fstat(fd,&elf_stat) == -1 )
    {
        perror("fstat");
        return -1;
    }
    ehdr = mmap(0, elf_stat.st_size, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    if(ehdr == MAP_FAILED)
    {
        perror("mmap ehdr");
        return -1;
    }

}

int init( char *elf_file )
{
    int ret = -1;

    ret = elf_header( elf_file  );
    num = ehdr->e_shnum;
    if( ret == -1 )
    {
        printf("can't get %s eelf file\n" , elf_file );
        return -1;
    }
    shdr = (Elf32_Shdr *)( (unsigned long)ehdr + ehdr->e_shoff );
}

void getthing( char (*str)[NUM_BIT_NAME] , int *length , int *range )
{
    Elf32_Shdr        *shstrtab = NULL;
    int                shstrtab_off,shstrtab_len,shstrtab_num;
    char            *Real_strtab = NULL;
    int i = 0;

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

       // *********** you should change the data size begin
       // length[ i ] =  (shdr+i)->sh_size;
       length[ i ] = i % 5 + 5;
       range[ 2 * i ] = (shdr+i)->sh_offset;
       range[ 2 * i + 1 ] = (shdr+i)->sh_offset + length[i] - 1;
       // *********** you should change the data size end
       
       // strcpy( str[i] , buffer + (shdr + i)->sh_name  );
       // length[ i ] =  (shdr+i)->sh_size;
       // range[ 2 * i ] = (shdr+i)->sh_offset;
       // range[ 2 * i + 1 ] = (shdr+i)->sh_offset + 3;
       // printf("%d  %s   %d   %d\n" , i , buffer + (shdr + i)->sh_name , (shdr+i)->sh_size , (shdr+i)->sh_offset );
       // printf("%d  %s   %d   %d\n" , i , str[i] , length[i] , range[2*i]);
        i++;
    }
}

int showelf(void)
{
    char str[ num ][ NUM_BIT_NAME ]; 
    int length[ num ]; 
    int range[ num * 2 ]; 

    if( num == 0)
    {
        printf("please call init()\n");
        return -1;
    }
    else
    {
        getthing( str , length , range );
        pri_elf( str , length , range );
    }
}

// only real size == 0 printf NULL
// tmp != length[i] , for tmp is real size and length[i] is desigened by me
int Graph( void )
{
    // 10
    // char str[] = "**********";
    char name[ num ][ NUM_BIT_NAME ]; 
    int length[ num ]; 
    int size;
    int total = 0;
    int range[ num * 2 ]; 

    char str[] = "****************************************************************************************************";
    int i = 0;
    int tmp;
    if( num == 0)
    {
        printf("please call init()\n");
        return -1;
    }
    getthing( name , length , range );
    for( i = 0 ; i < num ; i++ )
        total += length[ i ];

    i = 0;
    while( i < ehdr->e_shnum  )
    {
       tmp  = (shdr+i)->sh_size;
       size = tmp;
       tmp = tmp / total;

       if( size == 0 )
           printf("%0*d  %4d   %15s :  NULL\n", 2 , i , size , name[ i ] );
       else if( tmp == 0 )
           printf("%0*d  %4d   %15s :  *\n", 2 , i , size , name[ i ] );
       else
           printf("%0*d  %4d   %15s :  %s\n", 2 , i , size  ,  name[ i ] , str + 100 - tmp);
       i++;
    }
}

void help()
{
    printf("Pri_elf [-pg]\n");
}

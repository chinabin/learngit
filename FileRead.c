#include "PriElf.c"
// #include "new.c"

int main( int argc , char *argv[] )
{
    int choice = 0;

    if( argc == 2 )
    {
        choice = 1;
        init(argv[1]);
    }
    else if( argc == 3 )
    {
        choice = 2;
        init(argv[2]);
    }
    else
    {
        choice = 0;
    }
    

    switch( choice )
    {
        case 1:
            showelf();
            break;
        case 2:
            Graph();
            break;
        default:
            help();
            break;
    }
    return 0;
}

#include "VimNote.h"

// get the count of NOTES
int GetNumOfNote()
{
    int nNumOfQuestion = sizeof( cQuestion ) / sizeof( cQuestion[0] );
    int nNumOfAnswer = sizeof( cAnswer ) / sizeof( cAnswer[0] );
    return nNumOfAnswer == nNumOfQuestion ? nNumOfQuestion : -1;
}

void ShowAll( int flag )
{
    int nNumOfRandom = sizeof( cQuestion ) / sizeof( cQuestion[0] );
    int i;
    for( i = 0 ; i < nNumOfRandom ; i++ )
    {
        if( !flag )
            printf("%-64s\t%s\n",cQuestion[i],cAnswer[i]);
        else if( flag == 1 )
            printf("%d %s\n", i + 1 ,cAnswer[i]);
        else if( flag == 2 )
            printf("%d %s\n", i + 1 ,cQuestion[i]);
        else
        {
            printf("FUCK!DONT YOU FUCK KIDDING ME!!!\n");
            break;
        }
    }
    
}

void GetRandow( int nNumOfRandom , int nUperBound , int *pResult ,int seed )
{
    int i = 0, j;
    int pTmp[ nUperBound + 1 ];
    srand((unsigned int)time(NULL));

    for( i = 0 ; i < nUperBound ; i++ )
    {
        pTmp[ i ] = -1;
    }
    for( i = 0 ; i < nUperBound ; )
    {
        j = rand() % nUperBound;
        if( j >= 0 && pTmp[ j ] == -1 )
        {
           pTmp[ j ] = i ;
           i++;
        }
    }
    for( i = 0 ; i < nNumOfRandom ; i++ )
    {
        pResult[ i ] = pTmp[ i ];
       printf("%d\n",pTmp[i]);
    }
}

void SeeWhereYouWrong( int nWrongNum , int *pWhereYouWrong )
{
    if( nWrongNum )
    {
        printf("************************************************\n");
        printf("*                                              *\n");
        printf("*              See What You Learn              *\n");
        printf("*                                              *\n");
        printf("************************************************\n\n");

        printf("You have wronged %d times!Fuck!\n\n" , nWrongNum);
        int i = 0;
        for( i = 0 ; i < nWrongNum ; i++ )
        {
            if( pWhereYouWrong[i] != -1 )
                printf("%s\n%s\n\n" , cQuestion[ pWhereYouWrong[ i ] ] , cAnswer[ pWhereYouWrong[ i ] ] );
        }
    }
    else
    {
        printf("You made it!\n");
    }
}

int AnsCmp( char *str1 ,char *str2 )
{
    while( *str1++ == *str2++ )
    {
        if( *str1 == '\0' && *str2 == '\0' )
            return 0;
    }
    return 1;
}
void SeeWhatYouLearn(int seed )
{
    int nNum = GetNumOfNote();
    if( nNum == -1 )
    {
        printf("Fuck!They are even not equal!!!!!\n\n");
    }
    int nNumOfQuestion = ( nNum / 3 ) * 2;
    int ResultOfRand[nNumOfQuestion];
    int Wrong[nNumOfQuestion] , nWrong = 0 , i = 0 ;
    char cMyInput[ 64 ] = {'\0'};

    GetRandow( nNumOfQuestion , nNum - 1 , ResultOfRand , seed );
    for( i = 0 ; i < nNumOfQuestion ; i++ )
    {
        printf("%s\n" , cQuestion[ ResultOfRand[ i ] ]);
        scanf("%s",cMyInput);
        if( AnsCmp( cAnswer[ ResultOfRand[ i ] ] , cMyInput ) )
        {
            Wrong[ nWrong++ ] = ResultOfRand[ i ];
        }
    }
    SeeWhereYouWrong( nWrong , Wrong );
}

void ShowHelp()
{
    printf("learnvim [-a][-h][-s]:\n");
    printf("-a:Show all quetions and answers.\n");
    printf("-h:Show help as you can see.\n");
    printf("-s num:Give seed to initniaze question liabrary!default is 2737\n");
}

int StrToInt( char *pStr )
{
    int nLength = 0;
    char *pStrBak = pStr;
    while( *pStr++ )
        nLength++;
    pStr = pStrBak;
    int tmp = 0 , a = 1 , ans = 0;
    while( nLength-- )
    {
        tmp = pStr[ nLength ] - '0';
        tmp *= a;
        ans += tmp;
        a *= 10;
    }
    return ans;
}

int main(int argc , char* argv[])
{
    int seed = 2737;
    char c = '0';
    if( argc > 1  )
    {
        int i;
        for( i = 1 ; i < argc ; i++ )
        {
            switch(argv[i][1])
            {
                case 'a':
                    c = '0';
                    while( c != 'q' )
                    {
                        ShowAll( c - '0' );
                        printf("Do you want to see other things?\n(input '1' to see QUESTION '2' to see ANSWERS or 'q' to quit...)");
                        scanf("%c" , &c);
                        fflush(stdin);      // always remember this or scanf will be affected.
                    }
                    break;
                case 'h':
                    ShowHelp();
                    break;
                default:
                    SeeWhatYouLearn(0);
                    break;
            }
        }
    }
    else
    {
        SeeWhatYouLearn(seed);
    }
    return 0;
}

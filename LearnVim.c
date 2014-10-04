#include <stdio.h>
#include <string.h>
#include "VimNote.h"

int GetNumOfNote()
{
    int nNumOfQuestion = sizeof( cQuestion ) / sizeof( cQuestion[0] );
    int nNumOfAnswer = sizeof( cAnswer ) / sizeof( cAnswer[0] );
    return nNumOfAnswer == nNumOfQuestion ? nNumOfQuestion : -1;
}

void ShowAll()
{
    int nNumOfRandom = sizeof( cQuestion ) / sizeof( cQuestion[0] );
    int i;
    for( i = 0 ; i < nNumOfRandom ; i++ )
    {
        printf("%-64s\t%s\n",cQuestion[i],cAnswer[i]);
    }
    
}

void GetRandow( int nNumOfRandom , int nUperBound , int *pResult ,int seed )
{
    int i = 0;
    srand((unsigned int)time(NULL));
    for( i = 0 ; i < nNumOfRandom ; i++ )
    {
       pResult[ i ] = rand() % nUperBound;
       printf("%d\n",pResult[i]);
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
    int nNumOfQuestion = nNum / 2;
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
    if( argc > 0  )
    {
        int i;
        for( i = 1 ; i < argc ; i++ )
        {
            switch(argv[i][1])
            {
                case 'a':
                    ShowAll();
                    break;
                case 'h':
                    ShowHelp();
                    break;
                case 's':
                    printf("Thanks for seed!\nYou are a good person\n\n");
                    seed = StrToInt(argv[i+1]);
                    SeeWhatYouLearn(seed);
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

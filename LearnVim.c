#include <stdio.h>
#include <string.h>
#include <time.h>
#include "VimNote.h"

int GetNumOfNote()
{
    int nNumOfQuestion = sizeof( cQuestion ) / sizeof( cQuestion[0] );
    int nNumOfAnswer = sizeof( cAnswer ) / sizeof( cAnswer[0] );
    return nNumOfAnswer == nNumOfQuestion ? nNumOfQuestion : -1;
}

void GetRandow( int nNumOfRandom , int nUperBound , int *pResult )
{
    int i = 0;
    for( i = 0 ; i < nNumOfRandom ; i++ )
    {
        //made by myself
       srand( i * 2737 );
       pResult[ i ] = rand() % nUperBound;
    }
}

void SeeWhereYouWrong( int nWrongNum , int *pWhereYouWrong )
{
    if( nWrongNum )
    {
        printf("************************************************\n");
        printf("You have wronged %d times!Fuck!\n" , nWrongNum);
        int i = 0;
        for( i = 0 ; i < nWrongNum ; i++ )
        {
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
void SeeWhatYouLearn()
{
    int nNum = GetNumOfNote();
    if( nNum == -1 )
    {
        printf("Fuck!They are even not equal!\n");
    }
    int nNumOfQuestion = nNum / 2;
    int ResultOfRand[nNumOfQuestion];
    int Wrong[nNumOfQuestion] , nWrong = 0 , i = 0;
    char cMyInput[ 64 ] = {'\0'};

    GetRandow( nNumOfQuestion , nNum - 1 , ResultOfRand );
    for( i = 0 ; i < nNumOfQuestion ; i++ )
    {
        printf("%s\n" , cQuestion[ ResultOfRand[ i ] ]);
        scanf("%s",cMyInput);
        if( AnsCmp( cAnswer[ ResultOfRand[ i ] ] , cMyInput ) )
        {
            Wrong[ i ] = ResultOfRand[ i ];
            nWrong++;
        }
    }
    SeeWhereYouWrong( nWrong , ResultOfRand );
}

int main()
{
    int tmp[10];
    SeeWhatYouLearn();
    return 0;
}

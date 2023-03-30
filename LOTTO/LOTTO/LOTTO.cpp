
#include "defs.h"
#include "Data.h"
#include "Print.h"


void CalcStat( int* pNums49, Player** pPlayers, int nPlayersNo );
void Sort( Player** pPlayers, int nPlayersNo );
void HeapCheck();

int CmpStr( char* s1, char* s2 );
void switchPlayers( Player* a, Player* b );

#define DEBUG

int main( int argc, char* argv[] )
{
    Player** pAllPlayers = NULL;

    int nPlayersNo = ReadData( &pAllPlayers, argv[1] );
    HeapCheck();

    if( nPlayersNo == 0 ) {
        printf( "Players have not been loaded\n" );
        return 2;
    }

    int* pNums49 = ( int* )calloc( TAB, sizeof( int ) );

    if(!pNums49) {
        printf( "pNums49 memory allocation error\n" );
        return -1;
    }

    CalcStat( pNums49, pAllPlayers, nPlayersNo );

    Sort( pAllPlayers, nPlayersNo );

    PrintResults( pNums49, pAllPlayers, nPlayersNo );

    

#ifdef DEBUG
    Player** pDraws = pAllPlayers;

    for(int i = 0; i < nPlayersNo; i++) {

        printf("%s %s \n", ((*pAllPlayers)->sSName), ((*pAllPlayers)->sFName));

        for(int i = 0; i < (**pAllPlayers).BetsMax; i++) {
            for(int j = 0; j < MAXBETS; j++) {
                printf("%d\t", ((*pAllPlayers)->pBets[i][j]));
            }
            printf("\n");

        }
        (pAllPlayers)++;
        if(i == (nPlayersNo - 1))    pAllPlayers = pDraws;
    }
#endif

    FreeMem( &pAllPlayers, nPlayersNo );
    if( !pAllPlayers ) printf( "Memory deallocated\n" );
    
    HeapCheck();

    return 0;
}



void CalcStat( int* pNumsAll, Player** pPlayers, int nPlayersNo ) {
  
    if( !pNumsAll ) {
        perror( "pNumsAll memory allocation error\n" );
        return;
    }

    for( int i = 0; i < nPlayersNo; i++ ) {

         int** p = pPlayers[i]->pBets;

        for( int j = 0; j < pPlayers[i]->BetsMax; j++ ) {

            int* v = p[j];
            if(!v) break;
            for( int z = 0; z < MAXBETS; z++ ) {

                pNumsAll[*(v++)-1 ]++;                               
                
            }
        }
    }
}



void switchPlayers( Player* a, Player* b ) {                        //funkcja pomocnicza do sortowania, zamienia playerów pod odpowiednimi adresami

    Player temp = *a;
    *a = *b;
    *b = temp;
}



int CmpStr( char* s1, char* s2 ) {
    
    char* str1 = ( char* )calloc( strlen( s1 ) + 1, sizeof(char) );

    if( !str1 ) {
        printf( "memory allocation error: str1\n" );
        return 0;
    }
    char* str2 = ( char* )calloc( strlen( s2 ) + 1, sizeof(char) );

    if( !str2 ) {
        printf( "memory allocation error: str2\n" );
        return 0;
    }
     strcpy( str1, s1 );
     strcpy( str2, s2 );
    
    _strlwr( str1 );
    _strlwr( str2 );

    int res = strcmp( str1, str2 );
  
    free( str1 );
    free( str2 );

    return res;
}



void Sort( Player** pPlayers, int nPlayersNo ) {                      //Selection sort

    Player** p = pPlayers;

    for( int i = 0; i < nPlayersNo; i++ ) {

        Player* min = p[i];
        

        for( int j = i + 1; j < nPlayersNo; j++ ) {

            if( CmpStr( p[j]->sSName, min->sSName ) == 0 ) {           //jak nazwiska takie same to porownanie imion

                if( CmpStr(p[j]->sFName, min->sFName) == -1 ) {
                    min = p[j];
                }
            }
            else {

                if( CmpStr(p[j]->sSName, min->sSName) == -1 ){
                    min = p[j];
                }
            }
        }
        switchPlayers( min, p[i] );
    }
}



void HeapCheck() {

    int heapstatus = _heapchk();

    switch(heapstatus)
    {
    case _HEAPOK:       printf(" OK - heap is fine\n");         break;

    case _HEAPEMPTY:    printf(" OK - heap is empty\n");        break;

    case _HEAPBADBEGIN: printf("ERROR - bad start of heap\n");  break;

    case _HEAPBADNODE:  printf("ERROR - bad node in heap\n");   break;

    }
}







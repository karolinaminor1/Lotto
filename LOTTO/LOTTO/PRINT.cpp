#include "defs.h"
#include "Print.h"



void PrintResults( int* pNums49, Player** pPlayers, int nPlayersNo ) {

	FILE* fout = fopen( "wyniki", "w" );

	if( !fout ) {
		perror( "ERROR: OPEN FILE\n" );
		return;
	}


	for( int i = 0; i < nPlayersNo; i++ ) {

		Player* p = pPlayers[i];

		fwrite( p->sSName, sizeof(char), strlen( p->sSName ), fout );
		fputc( '\t', fout );
		fwrite( p->sFName, sizeof(char), strlen( p->sFName ), fout );
		fputc( '\t', fout );
		
		fprintf( fout, "%.4s %.2s %.2s %.3s\t%.2s %.2s %.8s %.16s\t", p->AccNumber.SwiftNum.INST, p->AccNumber.SwiftNum.NAT, p->AccNumber.SwiftNum.CITY,
			p->AccNumber.SwiftNum.BRANCH, p->AccNumber.Iban.NAT, p->AccNumber.Bban.cBAN, p->AccNumber.Bban.BANK, p->AccNumber.AccNum );



		PrintSex( fout, p );
		PrintDate( fout, p );
		PrintHour( fout, p );

		fprintf( fout, "%.11s\t", ( *p ).pesel );
		fprintf( fout, "\n\n" );

		PrintBets( fout, p );
		fprintf( fout, "\n\n" );
		
	}
	

	fprintf( fout, "\n\n---------------------------STATISTICS------------------------------\n" );

	for( int i = 1; i <= TAB; i++ ) {

		fprintf( fout, "%d: %d", i, pNums49[i-1] );
		fprintf( fout, " " );
		if( i % 10 == 0 ) fprintf( fout, "\n" );
	}

	fclose( fout );
}


void PrintSex( FILE* fout, Player* p ) {

	if( ( *p ).Sex == MALE ) {
		fprintf( fout, "MALE\t" );
		return;
	}

	fprintf( fout, "FEMALE\t" );
}



void PrintHour( FILE* fout, Player* p ) {

	fprintf( fout, "%d:%d\t", (*p).BetsHour.nHour, (*p).BetsHour.nMin );
}



void PrintBets( FILE* fout, Player* p ) {

	for( int i = 0; i < p->BetsMax; i++ ) {

		int* v = p->pBets[i];

		for( int j = 0; j < MAXBETS; j++ ) {
			
			fprintf( fout, "%d\t", *(v++) );
		}
		fprintf( fout, "\n" );
	}
}



void PrintDate( FILE* fout, Player* p ) {

	fprintf( fout, "%s\t%d/%d/%d\t", p->BetsDate.weekDay, p->BetsDate.nDay, p->BetsDate.Month, p->BetsDate.nYear );
}

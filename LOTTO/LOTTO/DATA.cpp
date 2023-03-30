#include "defs.h"
#include "Data.h"




int AllocAddMem( Player*** pTab, int nCurrSize ) {

	Player** temp = *pTab;
	temp = ( Player** )realloc( *pTab, (nCurrSize + ALLOCPLAYER ) * sizeof( Player* ) );

	if( temp ) {
		*pTab = temp;
		memset( *pTab + nCurrSize, 0, ALLOCPLAYER * sizeof(Player*) );

	}

	else {
		perror( "MemoryAlloc error\n" );
		return 0;
	}

	return ALLOCPLAYER;
}



int AllocAddMemBets( int*** pBets, int nBets ) {

	int** temp = *pBets;
	temp = ( int** )realloc( *pBets, ( nBets + ALLOCBET ) * sizeof( int* ) );

	if( temp ) {
		*pBets = temp;
		memset( ( *pBets + nBets ), 0, ALLOCBET * sizeof( int* ) );
	}

	else {
		perror( "BetsMemoryAlloc error\n" );
		return 0;
	}


	return ALLOCBET;
}



int SetSex( Player* p, char c ){

	switch( c ) {
	case 'f': (*p).Sex = FEMALE;	 return 1;
	case 'F': (*p).Sex = FEMALE;	 return 1;
	case 'm': (*p).Sex = MALE;		 return 1;
	case 'M': (*p).Sex = MALE;	     return 1;

	}

	printf( "Incorrect gender designation\n" );
	return 0;
}



int SetHour( Player* p, int hh, int mm ) {

	if( hh < 0 || hh>23 ) {
		printf( "Incorrect time: hour\n" );
		return 0;
	}
	p->BetsHour.nHour = hh;

	if( mm < 0 || mm>59 ) {
		printf( "Incorrect time: minutes\n" );
		return 0;
	}
	p->BetsHour.nMin = mm;

	return 1;
}



int  SetDate( Player* p, int d, int m, int y ) {

	struct tm* data = ( tm* )calloc( 1, 44 );  //44 == sizeof(tm)
	if( data ) {
		(*data).tm_year = y - 1900;
		(*data).tm_mon = m - 1;
		(*data).tm_mday = d;
		mktime( data );

		if( y < 1900 || y > 2022 ) {
			return 0;
		}

		p->BetsDate.nYear = y;

		if( (*data).tm_mon < Jan || (*data).tm_mon > Dec ) {
			return 0;
		}

		p->BetsDate.Month = m;

		if( d < 0 || d>31 ) {
			return 0;
		}

		p->BetsDate.nDay = d;

		switch( data->tm_wday ) {
		case Sun: p->BetsDate.weekDay = "Sun"; break;
		case Mon: p->BetsDate.weekDay = "Mon"; break;
		case Tue: p->BetsDate.weekDay = "Tue"; break;
		case Wed: p->BetsDate.weekDay = "Wed"; break;
		case Thu: p->BetsDate.weekDay = "Thu"; break;
		case Fri: p->BetsDate.weekDay = "Fri"; break;
		case Sat: p->BetsDate.weekDay = "Sat"; break;
		}
	}

	free( data );
	return 1;
}



int  ReadData( Player*** pAllPlayers, const char* sfileName ) {

	FILE* fin = fopen( sfileName, "r" );

	if( !fin ) {
		perror( "ERROR: OPEN FILE" );
		return 0;
	}

	Player** pDraws = NULL;
	int nData = 0;
	int MaxSize = 0;



	char sex = ' ';
	int hour = 0; int  day = 0; int month = 0; int year = 0; int minutes = 0;
	

	Player** pPlayers = *pAllPlayers;
	
	
	while( !feof( fin ) ) {


		Player*** adr = &pPlayers;
		if( nData == MaxSize ) {
			
			MaxSize += AllocAddMem( adr, MaxSize );
			
			if( nData == MaxSize ) break;
		}

	
		Player* p=pPlayers[ nData ] = ( Player* )calloc( 1, sizeof( Player ) );
		
		if( !p )  break;

		
			if( !fscanf( fin, "%s %s %c %4c %2c %2c %3c %2c %2c %8c %16c %d:%d %d/%d/%d %11c", p->sSName, p->sFName, &sex,
				p->AccNumber.SwiftNum.INST, p->AccNumber.SwiftNum.NAT, p->AccNumber.SwiftNum.CITY,
				p->AccNumber.SwiftNum.BRANCH, p->AccNumber.Iban.NAT, p->AccNumber.Bban.cBAN,
				p->AccNumber.Bban.BANK, p->AccNumber.AccNum, &hour, &minutes, &day, &month, &year, p->pesel ) ) {

				perror( "fscanf error\n" );
				return nData;
			}


		if( !SetSex( p, sex ) ) {
			printf( "SetSex error\n" );
			return nData;
		}

		if( !SetHour( p, hour, minutes ) ) {
			printf( "SetHour error\n" );
			return nData;
		}

		if( !SetDate( p, day, month, year ) ) {
			printf( "SetDate error\n" );
			return nData;
		}


		int nDataBets = -1;
		int nBets = 0;
		int k = 0;

		char c;
		char flag = 0;

		while(1) {

			nDataBets++;
			if( nDataBets == nBets ) {

				nBets += AllocAddMemBets( &(p->pBets), nBets );
				if( p->BetsMax == nBets ) break;
			}

			
			int* v = p->pBets[ nDataBets ]=(int*)calloc( 6, sizeof( int ) );
			

			for( int i = 0; i < MAXBETS; i++ ) {

				if( !fscanf( fin, "%d", v++ ) ) break;

			}

			if( ( c = fgetc( fin ) ) == '*' ) {
				ungetc( c, fin );
				flag = 1;
				break;
			}

			else if( feof( fin ) ) {
				flag = 1;   break;
			}

			else ungetc( c, fin );

		}
		
		nDataBets > MAXBETS ? p->BetsMax = MAXBETS : p->BetsMax = nDataBets;
		
		if( !flag ) break;

		nData += 1;
	}

	*pAllPlayers = pPlayers;
	fclose( fin );
	return nData;
}



void FreeMem( Player*** pTab, int nPlayersNo ) {

	Player** p = *pTab;

	for( int i = 0; i < nPlayersNo; i++ ) {

		free( p[i] );
	}
	*pTab = NULL;
}





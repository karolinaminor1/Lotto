#pragma once


int AllocAddMem( Player*** pTab, int nCurrSize );
int AllocAddMemBets( int*** pBets, int nBets );
int  ReadData( Player*** pAllPlayers, const char* sfileName );


void FreeMem( Player*** pTab, int nPlayersNo );

int  SetSex( Player* p, char c );
int  SetHour( Player* p, int hh, int mm );
int  SetDate( Player* p, int d, int m, int y );


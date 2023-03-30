#pragma once
#include "malloc.h"
#include "stdio.h"
#include "string.h"
#include "time.h"

#define MAXBETS      6     
#define ALLOCBET     2   
#define ALLOCPLAYER  3
#define MAXNAME      31  

#define TAB 49         //stala do tworzenia tablicy pNums49



typedef enum { MALE, FEMALE }    SexType;
typedef enum { Sun, Mon, Tue, Wed, Thu, Fri, Sat }    DayNames;
typedef enum { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec }  MonthNames;


typedef struct {
	char INST[4];
	char NAT[2];
	char CITY[2];
	char BRANCH[3];
}SWIFT;


typedef struct {
	char cBAN[2];
	char BANK[8];
}BBAN;


typedef struct {
	char NAT[2];
}IBAN;


typedef struct {
	SWIFT SwiftNum;
	IBAN Iban;
	BBAN Bban;

	char AccNum[16];

}AccountNumber;



typedef struct {
	int nDay;
	const char* weekDay;
	int Month;
	int nYear;
}DateType;



typedef struct {
	int nHour;
	int nMin;
}TimeType;



typedef struct {
	char sSName[MAXNAME];
	char sFName[MAXNAME];
	char pesel[11];

	TimeType BetsHour;
	DateType BetsDate;
	SexType Sex;
	int BetsMax;
	int** pBets;

	AccountNumber AccNumber;

}Player;




































































































































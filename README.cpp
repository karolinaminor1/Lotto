# Lotto

//# Lotto
/*
Obliczanie statystyk losowanych liczb z zakladow Lotto
W pliku we sa po gwiazdce nazwisko i imie gracza litera plci,
potem konto bankowe (SWIFT), potem godzina i data zawarcia zakladu i numer pesel.
Od nowej linii sa zaklady


//====================== fragment pliku wejsciowego:  ========================
*Banaszak   Lolita  f    BPHKPLPKXXX   PL61123400110011000012300678  12:34   16/12/2016 01234567890
 1 10 23 30 38  47 
 9 24 26 33 40  48 
 8 14 26 33 47  41 
 7 12 15 16 41  48
 6 14 20 27 28  40 
 
 
 //======================FUNKCJA MAIN============================
 
int main( int argc, char* argv[] )
{
  // Parametrem progrmu jest plik tekstowy z zakladami
  // definicja dynamicznej tablicy typu Player** (tabl wsk do graczy)  
  // zdefiniowana zmienna dla pamiatania ilosci wczytanych danych (ilosci gracczy)

  if( ilosc_wczytanych danych == 0  ) (funkcja czytajaca zwraca ilosc przeczytanyh nawet jesli podczas czytania wystapil blad)
  { //komunikat;
    return 2;
  }
  HeapCheck(); 

// definicja tablicy dla pamiatania statystyk dla wyboru 6 z 49                 (tak jak w Lotto)
  //przetwarzanie danych
       // obliczenie statystyk 
       // sortowanie ze wzgledu na nazwisko i imie (przestawia wskazniki w tablicy)
  // wydrukowanie danych do pliku - wyniki.txt
  
  //zwolnia pamiec
  ///HeapCheck(); 

  return 0;
}

//================================================================================




//-----------------------------FUNKJCA REALOKUJACA PAMIEC DLA GRACZY---------------------------------
int AllocAddMem( Player*** pTab, int nCurrSize )
{
  // uzywa funkcji "realloc()" i memset()
  // przy czym jesli sie nie powiodlo
  // to nie mozna stracic do tej pory czytanych danych i program ma dzialac dalej
  // z tym ze zwraca wtedy wartosc zero
  // w przypadku powodzenia realokacji zwaraca o ile realokowano

}


//------------------------------- FUNKCJA CZYTAJACA DANE Z PLIKU WEJSCIOWEGO --------------------------------
int ReadData( Player*** pAllPalyers, const char* sFileName )
{
// otwiera plik do odczytu z badaniem bledu otwarcie - gdy blad to funkcja 
  //wypisuje komunikat i zwraca zero

  // zdefiniowana zmienna liczaca ilosc wczytanych danych (poczatkowo 0) oraz 
  // zmienna aktualny maxym rozmiar tablicy pAllDraws (poczatkowo 0 )
  
  // kopia pDraws parametru *pAllPalyers  typu Player**

  while( !feof( fin ) )
  {
    // jesli trzeba to realokuje  (ilosc wczytanych danych == maxym rozmiar) 
            // dodaje do zmiennej maxym rozmiar wynik funkcji realokujacej (3- ilosc o ktora realokujemy)
            // if( (ilosc wczytanych danych == maxym rozmiar)  to koniec (przerw petli)
    // wczytuje kolejnego gracza (linia zawsze zaczyna sie od znaku '*')
          // wczytuje jedna instrukcja fscanf wszystkie dane opisujace gracza
          // przy czym dane dot. plci i daty i czasu do zmiennych pomocniczych
          // ktore beda parametrami funkcji SetSex() i SetDate() i SetHour() 
            (oblicza brakujace dane jak np dzien tygodnia)
          
          // jesli nie powiodlo sie ustawienie plci lub daty, czasu to wychodzi z funkcji
          // z odpowiednim komunikatem z dotychczas wczytanymi danymi
    
         // czytanie zakladow  - realokacja co 2 zaklady
  }  

  // przywraca wskaznik *pAllPalyers;
  //zamkniecie pliku
  return ilosc_wczytanych_danych;
}
-------------------------------------- */


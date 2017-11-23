/*

Klasa color pozwalajaca na zapis koloru R G B ze strumienia wejscia 

Data: 12.12.2016

Autor: Denis Lewko

Wartosc domyslna dla R , G , B to 0 i jest to rowniez wartosc minimalna a maksymalna to 255

Dodano rowniez funkcje porownujaca 2 kolory 


Metody klasy zostaly specjalnie napisane inline i jest to zamierzony zabieg
*/


#pragma once
#ifndef _COLOR_HEADER_
#define _COLOR_HEADER_

#include <iostream>

class color {

private:
	int R;
	int G;
	int B;

public:

	color() :R(0) , G(0) , B(0) {}
	color(color & mc) :R(mc.R) , G(mc.G) , B(mc.B) {}

	friend std::istream& operator >> (std::istream &wejscie, color& ex) {
		
		if ((ex.R < 0 || ex.R>255) || (ex.G < 0 || ex.G>255) || (ex.B < 0 || ex.B>255)) throw "Blad w odczycie koloru albo mniejszy od 0 albo wiekszy od 255";

		wejscie >> ex.R >> ex.G >> ex.B;
		return wejscie;

	}

	color&operator=(const color & mc) {

		R = mc.R;
		G = mc.G;
		B = mc.B;

		return *this;
	}


	bool operator==(const color & mc) {

		if ((R == mc.R) && (G == mc.G) && (B == mc.B)) return true;
		else return false;

	}


	// BRAK DESTRUKTORA JEST TO ZAMIERZONE DZIALANIE

};

#endif // !_COLOR_HEADER_
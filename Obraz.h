/*


Klasa obraz okreslajaca dany obraz poprzez jego szerokosc wysokosc i kolory , pozwala rowniez
na zlieczenie ilosc unikalnych kolorow na danym obrazie

Autor: Denis Lewko

Data: 12.12.2016

Wymiary obrazu musza byc rowne:
szerokosc: 512px;
wysokosc: 512px;



*/

#pragma once
#ifndef _HEADER_OBRAZ_
#define _HEADER_OBRAZ_

#include "color.h"



class Obraz {

private:

	color * tab_uniq;

	int ilun;

	inline bool przekaz(const color &);
	inline void wpisz(const color &);
	inline void przytnij();

protected:

	color tab[512][512];
	void setcolor(int, int, color);

public:


	Obraz():ilun(0) {}
	Obraz(Obraz & mc);


	int getUnique();

	Obraz& operator= (Obraz const& mc);
	
	
	~Obraz();

};

#endif // _HEADER_OBRAZ_
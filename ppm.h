/*


Klasa pozwalajaca odczytaæ plik w formie PPM ( bez naglowka , same dane )

Wymiary zdjecia musza byc rowne:
szerokosc: 512px;
wysokosc: 512px;

Autor: Denis Lewko

Data: 12.12.2016


*/

#pragma once
#ifndef _PPM_HEADER_
#define _PPM_HEADER_

#include "Obraz.h"

class ppm :public Obraz {

private:
	char * file_name;

public:
	
	ppm(char *);
	ppm(ppm & mc);


	void read();

	ppm&operator=(const ppm & mc);


	~ppm();

};


#endif // !_PPM_HEADER_
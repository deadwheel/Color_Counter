#include <fstream>
#include "ppm.h"
#include "color.h"

ppm::ppm(char * name):Obraz()
{
	if (name != "") {
	
		file_name = name;
		read();

	}

	else throw "Wpisz nazwe pliku!";

}

ppm::ppm(ppm & mc)
{

	file_name = new char[strlen(mc.file_name)];
	file_name = mc.file_name;


}


void ppm::read() {


	if (file_name == "") throw "Wpisz nazwe pliku!";

	std::ifstream in(file_name);

	if (in.good()) {

		color c;

		for (int x = 0;x < 512;x++) {

			for (int y = 0;y < 512;y++) {


				in >> c;
				setcolor(x, y, c);



			}


		}


		in.close();

	}

	else {

		throw "Nie udalo sie otworzyc pliku";
	}

}

ppm & ppm::operator=(const ppm & mc)
{
	file_name = new char[strlen(mc.file_name)];
	file_name = mc.file_name;
}

ppm::~ppm()
{


	if (file_name)
		delete[] file_name;


}

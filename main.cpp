#include <iostream>
#include "Obraz.h"
#include "ppm.h"

int liczkolory(Obraz & gr) {

	int il = gr.getUnique();
	
	return il;

}

int main() {

	try {

		Obraz * ob;
		ob = new ppm("lena_ppm.ppm");

		int k;
		k = liczkolory(*ob);

		std::cout << "Unikalnych: " << k;

		std::cout << std::endl;

		delete ob;
	}

	catch (const char *s) {

		std::cout << std::endl << "Fatal Error " << s << std::endl << std::endl;

	}

	system("PAUSE");


	return 0;

}

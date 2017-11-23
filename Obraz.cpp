#include "Obraz.h"


inline bool Obraz::przekaz(const color & pk) {


	bool jest = false;


	for (int i = 0;i<ilun;i++) {


		if (tab_uniq[i] == pk) {
		
			jest = true;
			return true;
			break;
		
		}



	}


	if (jest == false) return false;

}



inline void Obraz::wpisz(const color & tt)
{

	//	if(ilun>0) {
	//
	//	color * pom = new color[ilun];
	//
	//	for (int i = 0;i < ilun;i++) {
	//
	//		pom[i]=tab_uniq[i];
	//
	//	}
	//
	//
	//	if (tab_uniq)
	//		delete[] tab_uniq;
	//
	//
	//	tab_uniq = new color[ilun + 1];
	//
	//	for (int i = 0;i < ilun;i++) {
	//
	//		tab_uniq[i]=pom[i];
	//
	//	}
	//	
	//	
	//		 delete[] pom;
	//
	//
	//}


	if (ilun == 0) {

		//tab_uniq = new color [1];
		tab_uniq = new color[262144];

	}

	tab_uniq[ilun] = tt;

	ilun = ilun + 1;


}

inline void Obraz::przytnij()
{

	color * pom = new color[ilun];

	for (int i = 0;i < ilun;i++) {

		pom[i] = tab_uniq[i];

	}

	delete[] tab_uniq;

	tab_uniq = new color[ilun];

	for (int i = 0;i < ilun;i++) {

		tab_uniq[i] = pom[i];

	}

	delete[] pom;

}

Obraz::Obraz(Obraz & mc)
{

	ilun = mc.ilun;

	for (int x = 0;x < 512;x++) {

		for (int y = 0;y < 512;y++) {

			tab[x][y] = mc.tab[x][y];


		}

	}


		tab_uniq = new color[mc.ilun];

		for (int i = 0;i < ilun;i++)
			tab_uniq[i] = mc.tab_uniq[i];




}

void Obraz::setcolor(int x, int y, color c)
{

	tab[x][y] = c;

}

int Obraz::getUnique()
{

	bool fak;

	for (int x = 0;x < 512;x++) {

		for (int y = 0;y < 512;y++) {


			fak = przekaz(tab[x][y]);


			if (fak == false) wpisz(tab[x][y]);



		}



	}


	if (ilun > 0) przytnij();




	return ilun;
}

Obraz & Obraz::operator=(Obraz const & mc)
{

	ilun = mc.ilun;

	for (int x = 0;x < 512;x++) {

		for (int y = 0;y < 512;y++) {

			tab[x][y] = mc.tab[x][y];


		}

	}


	tab_uniq = new color[mc.ilun];

	for (int i = 0;i < ilun;i++)
		tab_uniq[i] = mc.tab_uniq[i];

}

Obraz::~Obraz()
{

	if (tab_uniq)
		delete[] tab_uniq;

}

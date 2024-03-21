#include "IteratorColectie.h"
#include "Colectie.h"
#include <stdio.h>


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	// 0(1)
	// constructorul clasei Iterator 
	// preconditii: vect este Colectie
	// postconditii: iteratorul refera primul element

	currentIndex = 0;
	currentFreq = 1;
}


void IteratorColectie::prim() {
	// 0(1)
	// reseteaza pozitia iteratorului la inceputul Colectiei
	// preconditii: vect este Colectie
	// postconditii: iteratorul a fost mutat la inceput

	currentIndex = 0;
	currentFreq = 1;
}


void IteratorColectie::urmator() {
	// 0(1)
	// mutam iteratorul inainte in Colectie
	// preconditii: it este iterator
	// postconditii: it' refera urmatorul element din Colectie dupa 
	//			     elementul referit de it sau este invalid daca nu
	//				 mai exista elemente de iterat
	// arunca exceptie daca it este invalid

	try
		{
		bool validIterator = valid();
		if (validIterator)
			if (currentFreq < col.vect[currentIndex].currentFreq)
				currentFreq++;
			else
			{
				currentFreq = 1;
				currentIndex++;
			}
		else
			throw validIterator;
		}
	
	catch (...)
	{
		printf("Iteratorul este invalid!");
	}
}


bool IteratorColectie::valid() const {
	// 0(1)
	// verificarea validitatii iteratorului 
	// preconditii: it este iterator
	// postconditii: valid <- true, daca it refera un element din vect care este valid
	//					      false, in caz contrar

	if (currentIndex < col.currentDIM)
		return true;
	else
		return false;
}



TElem IteratorColectie::element() const {
	// 0(1)
	// returneaza elementul pe care il refera iteratorul
	// preconditii: it este iterator, it este valid
	// postconditii: element <- elementul curent din colectie, referit de it
	// arunca exceptie daca it este invalid

	try
		{
		bool validIterator = valid();
		if (validIterator)
			return col.vect[currentIndex].currentElem;
		else
			throw validIterator;
		}

	catch (...) 
		{
		printf("Iteratorul este invalid!");
		return -1;
		}
}
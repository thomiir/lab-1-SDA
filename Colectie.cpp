#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>

using namespace std;


Colectie::Colectie() {
	// 0(1)
	// constructorul clasei Colectie
	// preconditii: -
	// postconditii: vect este Colectie vida

	currentDIM = 0;
	maximumDIM = 1;
	vect = new Pairs[maximumDIM];
}


void Colectie::adauga(TElem elem) {
	// caz favorabil (elementul este pe prima pozitie): O(1)
	// caz defavorabil (elementul nu exista in colectie): O(n)
	// caz mediu: O(n)
	// adaugarea unui element in Colectie
	// preconditii: vect este Colectie, elem este TElem
	// postconditii: vect' este Colectie, vect' = vect + {elem}

	int added = 0;
	for (int i = 0; i < currentDIM; i++)
		if (vect[i].currentElem == elem)
		{
			vect[i].currentFreq++;
			added = 1;
			break;
		}

	if (added == 0)
	{
		if (currentDIM == maximumDIM)
			mareste();

		vect[currentDIM].currentElem = elem;
		vect[currentDIM].currentFreq = 1;
		currentDIM++;
	}

}


void Colectie::mareste() {
	// 0(n)
	// alocarea in plus de spatiu de memorie
	// preconditii: vect este Colectie
	// postconditii: s-a alocat spatiu in plus pentru vect
 
	Pairs* vectNou = new Pairs[2 * maximumDIM];
	for (int i = 0; i < currentDIM; i++)
		vectNou[i] = vect[i];
	maximumDIM = 2 * maximumDIM;
	delete[] vect;
	vect = vectNou;
}


bool Colectie::sterge(TElem elem) {
	// caz favorabil (elementul este pe prima pozitie si are frecventa > 1): O(1)
	// caz defavorabil (elementul este pe prima pozitie si are frecventa == 1): O(n^2)
	// stergerea unei aparitii a elementului elem din Colectie
	// precondiiti: vect este Colectie, elem este TElem
	// postconditii: vect' este Colectie, vect' = vect' - {elem}
	//				 sterge <- true, daca s-a sters elementul
	//						<- false, in caz contrar

	for (int i = 0; i < currentDIM; i++)
		if (vect[i].currentElem == elem)
		{
			if (vect[i].currentFreq > 1)
				vect[i].currentFreq--;
			else
			{
				for (int j = i; j < currentDIM - 1; j++) 
					vect[j] = vect[j + 1];
				currentDIM--;
			}
			return true;
		}
	return false;
}


bool Colectie::cauta(TElem elem) const {
	// caz favorabil (elementul este pe prima pozitie): O(1)
	// caz defavorabil (elementul nu se afla in colectie): O(n)
	// caz mediu: O(n)
	// cautarea elementului elem in Colectie
	// preconditii: vect este Colectie, elem este TElem
	// postconditii: cauta <- true, daca elem apare in Colectie
	//					   <- false, in caz contrar

	for (int i = 0; i < currentDIM; i++)
		if (vect[i].currentElem == elem) return true;
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	// caz favorabil (elementul este pe prima pozitie): O(1)
	// caz defavorabil (elementul nu se afla in colectie): O(n)
	// caz mediu: O(n)
	// returnarea frecventei elementului elem in Colectie
	// preconditii: vect este Colectie, elem este TElem
	// postconditii: nrAparitii <- numarul de aparitii al lui elem in Colectie

	for (int i = 0; i < currentDIM; i++)
		if (vect[i].currentElem == elem) return vect[i].currentFreq;
	return 0;
}


int Colectie::dim() const {
	// 0(n)
	// calcularea dimensiunii Colectiei (suma frecventelor tuturor elementelor din vect)
	// preconditii: vect este Colectie
	// postconditii: dim <- numarul total de elemente

	int s = 0;
	for (int i = 0; i < currentDIM; i++)
		s = s + vect[i].currentFreq;
	return s;
}


bool Colectie::vida() const {
	// 0(1)
	// determina daca vect este Colectie vida
	// preconditii: vect este Colectie
	// postconditii: vida <- true, in cazul in care Colectia este vida
	//					  <- false, in caz contrar

	return currentDIM == 0;
}


IteratorColectie Colectie::iterator() const {
	// 0(1)
	// returnarea unui iterator pe Colectia vect
	// preconditii: vect este Colectie
	// postconditii: iterator <- un iterator pe Colectia vect

	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	// 0(n)
	// destructorul clasei Colectie
	// preconditii: vect este Colectie
	// postconditii: Colectia vect a fost distrusa (spatiul de memorie a fost dealocat)

	delete[] vect;
}
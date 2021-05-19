#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CSommet.h"
#include "CException.h"
using namespace std;


/*
##################
  CONSTRUCTEURS
##################
*/
CSommet::CSommet() {
	eIdSommet = -1;

	eSizeDispoArrivant = 0;
	eSizeArrivant = 0;
	cArcArrivant = NULL;

	eSizeDispoPartant = 0;
	eSizePartant = 0;
	cArcPartant = NULL;
}

CSommet::CSommet(int idSommet) {
	eIdSommet = idSommet;

	eSizeDispoArrivant = 0;
	eSizeArrivant = 0;
	cArcArrivant = NULL;

	eSizeDispoPartant = 0;
	eSizePartant = 0;
	cArcPartant = NULL;
}

CSommet::CSommet(int eId, int eSizeA, int eSizeP, CArc** listeArrivant, CArc** listePartant) {
	eIdSommet = eId;

	eSizeArrivant = eSizeA;
	eSizeDispoArrivant = (eSizeArrivant / 5 + 1) * 5;

	cArcArrivant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoArrivant);
	if (cArcArrivant) {
		for (int i = 0; i < eSizeArrivant; ++i) {
			cArcArrivant[i] = listeArrivant[i];
		}
	}
	else {
		//Erreur
	}

	eSizePartant = eSizeP;
	eSizeDispoPartant = (eSizePartant / 5 + 1) * 5;

	cArcPartant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoPartant);
	if (cArcPartant) {
		for (int i = 0; i < eSizeArrivant; ++i) {
			cArcPartant[i] = listePartant[i];
		}
	}
	else {
		//Erreur
	}
}	

CSommet::CSommet(const CSommet& m) {
	eIdSommet = m.eIdSommet;

	eSizeArrivant = m.eSizeArrivant;
	eSizeDispoArrivant = m.eSizeDispoArrivant;

	cArcArrivant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoArrivant);
	if (cArcArrivant) {
		for (int i = 0; i < eSizeArrivant; ++i) {
			cArcArrivant[i] = m.cArcArrivant[i];
		}
	}
	else {
		//Erreur
	}

	eSizePartant = m.eSizePartant;
	eSizeDispoPartant = m.eSizeDispoPartant;

	cArcPartant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoPartant);
	if (cArcPartant) {
		for (int i = 0; i < eSizePartant; ++i) {
			cArcPartant[i] = m.cArcPartant[i];
		}
	}
	else {
		//Erreur
	}
}

CSommet::~CSommet() {
	if (cArcArrivant) {
		for (int i = 0; i < eSizeDispoArrivant; ++i) {
			delete[] cArcArrivant[i];
		}
		delete [] cArcArrivant;
	}
	if (cArcPartant) {
		for (int i = 0; i < eSizeDispoPartant; ++i) {
			delete[] cArcPartant[i];
		}
		delete[] cArcPartant;
	}
}


/*
##################
	ACCESSORS
##################
*/
int CSommet::getIdSommet() {
	return eIdSommet;
}

void CSommet::setIdSommet(int idSommet) {
	eIdSommet = idSommet;
}


// Accessors Arrivant
int CSommet::getSizeDispoArrivant() {
	return eSizeDispoArrivant;
}

void CSommet::setSizeDispoArrivant(int sizeDispoArrivant) {
	eSizeDispoArrivant = sizeDispoArrivant;
}

int CSommet::getSizeArrivant() {
	return eSizeArrivant;
}

void CSommet::setSizeArrivant(int sizeArrivant) {
	eSizeArrivant = sizeArrivant;
}

CArc** CSommet::getArcArrivant() {
	return cArcArrivant;
}

void CSommet::setArcArrivant(CArc** liste) {
	cArcArrivant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoArrivant);
	if (cArcArrivant) {
		for (int i = 0; i < eSizeArrivant; ++i) {
			cArcArrivant[i] = liste[i];
		}
	}
	else {
		//Erreur
	}
}


// Accesseurs Partant
int CSommet::getSizeDispoPartant() {
	return eSizeDispoPartant;
}

void CSommet::setSizeDispoPartant(int sizeDispoPartant) {
	eSizeDispoPartant = sizeDispoPartant;
}

int CSommet::getSizePartant() {
	return eSizePartant;
}

void CSommet::setSizePartant(int sizePartant) {
	eSizePartant = sizePartant;
}

CArc** CSommet::getArcPartant() {
	return cArcPartant;
}

void CSommet::setArcPartant(CArc** liste) {
	cArcPartant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoPartant);
	if (cArcPartant) {
		for (int i = 0; i < eSizePartant; ++i) {
			cArcPartant[i] = liste[i];
		}
	}
	else {
		// Erreur
	}
}

/*
##################
	METHODES
##################
*/
// Arrivant
void CSommet::ajouterArcArrivant(CArc* arc) {
	if (eSizeArrivant + 1 >= eSizeDispoArrivant) {
		reallocArrivant();
	}
	eSizeArrivant += 1;
	cArcArrivant[eSizeArrivant - 1] = arc;
}

void CSommet::supprimerArcArrivant(int indiceArc) {
	if (indiceArc >= eSizeArrivant) {
		// Erreur
	}

	for (int i = indiceArc+1; i < eSizeArrivant; ++i) {
		cArcArrivant[i - 1] = cArcArrivant[i];
	}
	eSizeArrivant -= 1;
}

void CSommet::modifierArcArrivant(int indiceArc) {
	ajouterArcPartant(cArcArrivant[indiceArc]);
	supprimerArcArrivant(indiceArc);
}

void CSommet::changeListeArrivant(CArc** liste, int sizeArrivant) {
	eSizeArrivant = sizeArrivant;
	setArcArrivant(liste);
}

void CSommet::reallocArrivant() {
	eSizeDispoArrivant += 5;
	CArc** newCArcArrivant;
	if (cArcArrivant) {
		newCArcArrivant = (CArc**)realloc(cArcArrivant, sizeof(CArc*) * eSizeDispoArrivant);
	}
	else {
		newCArcArrivant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoArrivant);
	}
	if (newCArcArrivant == NULL) {
		// Erreur
	}
	setArcArrivant(newCArcArrivant);
}

void CSommet::displayArcArrivant() {
	if (eSizeArrivant == 0) {
		//Erreur
	}
	else {
		cout << "Liste Arc Arrivant : ";
		for (int i = 0; i < eSizeArrivant; ++i) {
			cout << cArcArrivant[i]->getIdDest() << " ";
		}
		cout << endl;
	}
}


// Partant
void CSommet::ajouterArcPartant(CArc* arc) {
	if (eSizePartant + 1 >= eSizeDispoPartant) {
		reallocPartant();
	}
	eSizePartant += 1;
	cArcPartant[eSizePartant-1] = arc;
}

void CSommet::supprimerArcPartant(int indiceArc) {
	if (indiceArc >= eSizePartant) {
		// Erreur
	}

	for (int i = indiceArc + 1; i < eSizePartant; ++i) {
		cArcPartant[i - 1] = cArcPartant[i];
	}
	eSizePartant -= 1;
}

void CSommet::modifierArcPartant(int indiceArc) {
	ajouterArcArrivant(cArcPartant[indiceArc]);
	supprimerArcPartant(indiceArc);
}

void CSommet::changeListePartant(CArc** liste, int sizePartant) {
	eSizePartant = sizePartant;
	setArcPartant(liste);
}

void CSommet::reallocPartant() {
	eSizeDispoPartant += 5;
	CArc** newCArcPartant;
	if (cArcPartant) {
		newCArcPartant = (CArc**)realloc(cArcPartant, sizeof(CArc*) * eSizeDispoPartant);
	}
	else {
		newCArcPartant = (CArc**)malloc(sizeof(CArc*) * eSizeDispoPartant);
	}
	if (newCArcPartant == NULL) {
		// Erreur
	}
	setArcPartant(newCArcPartant);
}

void CSommet::displayArcPartant() {
	if (eSizePartant == 0) {
		//Erreur
	}
	else {
		cout << "Liste Arc Partant : ";
		for (int i = 0; i < eSizePartant; ++i) {
			cout << cArcPartant[i]->getIdDest() << " ";
		}
		cout << endl;
	}
}
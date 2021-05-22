#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CGraphe.h"
#include "CGrapheOperation.cpp"
#include "CException.h"
using namespace std;

/*
##################
  CONSTRUCTEURS
##################
*/
CGraphe::CGraphe() {
	eSize = 0;
	eSizeDispo = 0;
	cSommetListe = NULL;
}

CGraphe::CGraphe(int size, CSommet** liste) {
	eSize = size;

	eSizeDispo = (eSize / 5 + 1) * 5;

	cSommetListe = (CSommet**)malloc(sizeof(CSommet*) * eSizeDispo);
	if (cSommetListe) {
		for (int i = 0; i < eSize; ++i) {
			cSommetListe[i] = liste[i];
		}
	}
	else {
		//Erreur
	}
}

CGraphe::CGraphe(const CGraphe& m) {
	eSize = m.eSize;
	eSizeDispo = m.eSizeDispo;

	cSommetListe = (CSommet**)malloc(sizeof(CSommet*) * eSizeDispo);
	if (cSommetListe) {
		for (int i = 0; i < eSize; ++i) {
			cSommetListe[i] = m.cSommetListe[i];
		}
	}
	else {
		//Erreur
	}
}

/*
CGraphe::~CGraphe() {
	if (cSommetListe) {
		for (int i = 0; i < eSizeDispo; ++i) {
			delete[] cSommetListe[i];
		}
		delete[] cSommetListe;
	}
} */


/*
##################
	ACCESSORS
##################
*/
CSommet** CGraphe::getSommetListe() const {
	return cSommetListe;
}

void CGraphe::setSommetListe(CSommet** liste) {
	cSommetListe = (CSommet**)malloc(sizeof(CSommet*) * eSizeDispo);
	if (cSommetListe) {
		for (int i = 0; i < eSize; ++i) {
			cSommetListe[i] = liste[i];
		}
	}
	else {
		//Erreur
	}
}

int CGraphe::getSize() const {
	return eSize;
}

void CGraphe::setSize(int size) {
	eSize = size;
}

int CGraphe::getSizeDispo() const {
	return eSizeDispo;
}

void CGraphe::setSizeDispo(int sizeDispo) {
	eSizeDispo = sizeDispo;
}


/*
##################
	METHODS
##################
*/
void CGraphe::reallocListe() {
	eSizeDispo += 5;
	CSommet** newCSommetListe;
	if (cSommetListe) {
		newCSommetListe = (CSommet**)realloc(cSommetListe, sizeof(CSommet*) * eSizeDispo);
	}
	else {
		newCSommetListe = (CSommet**)malloc(sizeof(CSommet*) * eSizeDispo);
	}
	if (newCSommetListe == NULL) {
		// Erreur
	}
	setSommetListe(newCSommetListe);
}

void CGraphe::ajouterListe(CSommet * sommet) {
	if (eSize + 1 >= eSizeDispo) {
		reallocListe();
	}
	eSize += 1;
	cSommetListe[eSize - 1] = sommet;
}

void CGraphe::supprimerListe(int indiceSommet) {
	if (indiceSommet >= eSize) {
		// Erreur
	}
	for (int i = indiceSommet + 1; i < eSize; ++i) {
		cSommetListe[i - 1] = cSommetListe[i];
	}
	eSize -= 1;
}

ostream& CGraphe::display(ostream& os) const {
	if (eSize == 0) {
		//Erreur
	}
	os << "Presentation du graphe :" << endl;
	os << "------------------------------" << endl;
	for (int i = 0; i < eSize; ++i) {
		os << *(cSommetListe[i]);
		os << "------------------------------" << endl;
	}
	return os;
}

ostream& operator<<(ostream& os, CGraphe const G) {
	G.display(os);
	return os;
}
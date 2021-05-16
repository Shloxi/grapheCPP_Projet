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
	eSizeDispoArrivant = -1;
	eSizeDispoPartant = -1;
	cArcArrivant = NULL;
	cArcPartant = NULL;
}

CSommet::CSommet(int eId, int eSizeA, int eSizeP, CArc* listeArrivant, CArc* listePartant) {
	eIdSommet = eId;
	eSizeDispoArrivant = eSizeA;
	eSizeDispoPartant = eSizeP;

	cArcArrivant = (CArc*)malloc(sizeof(CArc) * eSizeDispoArrivant);
	if (cArcArrivant) {
		for (int i = 0; i < eSizeDispoArrivant; ++i) {
			cArcArrivant[i] = listeArrivant[i];
		}
	}
	else {
		//Erreur
	}

	cArcPartant = (CArc*)malloc(sizeof(CArc) * eSizeDispoPartant);
	if (cArcPartant) {
		for (int i = 0; i < eSizeDispoPartant; ++i) {
			cArcPartant[i] = listePartant[i];
		}
	}
	else {
		//Erreur
	}
}	

CSommet::CSommet(const CSommet& m) {
	eIdSommet = m.eIdSommet;
	eSizeDispoArrivant = m.eSizeDispoArrivant;
	eSizeDispoPartant = m.eSizeDispoPartant;

	cArcArrivant = (CArc*)malloc(sizeof(CArc) * eSizeDispoArrivant);
	if (cArcArrivant) {
		for (int i = 0; i < eSizeDispoArrivant; ++i) {
			cArcArrivant[i] = m.cArcArrivant[i];
		}
	}
	else {
		//Erreur
	}

	cArcPartant = (CArc*)malloc(sizeof(CArc) * eSizeDispoPartant);
	if (cArcPartant) {
		for (int i = 0; i < eSizeDispoPartant; ++i) {
			cArcPartant[i] = m.cArcPartant[i];
		}
	}
	else {
		//Erreur
	}
}

CSommet::~CSommet() {
	if (cArcArrivant) {
		free(cArcArrivant);
	}
	if (cArcPartant) {
		free(cArcPartant);
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

int CSommet::getSizeDispoArrivant() {
	return eSizeDispoArrivant;
}

void CSommet::setSizeDispoArrivant(int sizeDispoArrivant) {
	eSizeDispoArrivant = sizeDispoArrivant;
}

int CSommet::getSizeDispoPartant() {
	return eSizeDispoPartant;
}

void CSommet::setSizeDispoPartant(int sizeDispoPartant) {
	eSizeDispoPartant = sizeDispoPartant;
}

CArc* CSommet::getArcArrivant() {
	return cArcArrivant;
}

void CSommet::setArcArrivant(CArc* liste) {
	if (cArcArrivant != NULL) {
		free(cArcArrivant);
	}

	cArcArrivant = (CArc*)malloc(sizeof(CArc) * eSizeDispoArrivant);
	if (cArcArrivant) {
		for (int i = 0; i < eSizeDispoArrivant; ++i) {
			cArcArrivant[i] = liste[i];
		}
	}
	else {
		//Erreur
	}
}

CArc* CSommet::getArcPartant() {
	return cArcPartant;
}

void CSommet::setArcPartant(CArc* liste) {
	if (cArcPartant != NULL) {
		free(cArcPartant);
	}

	cArcPartant = (CArc*)malloc(sizeof(CArc) * eSizeDispoPartant);
	if (cArcPartant) {
		for (int i = 0; i < eSizeDispoPartant; ++i) {
			cArcPartant[i] = liste[i];
		}
	}
	else {
		//Erreur
	}
}

/*
##################
	METHODES
##################
*/
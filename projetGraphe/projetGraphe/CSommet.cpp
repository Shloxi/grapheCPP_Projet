#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CSommet.h"
#include "CException.h"
#include "CListeOperation.cpp"
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

	cArcArrivant = realloc(listeArrivant, &eSizeDispoArrivant);

	eSizePartant = eSizeP;
	eSizeDispoPartant = (eSizePartant / 5 + 1) * 5;

	cArcPartant = realloc(listePartant, &eSizeDispoPartant);
}	

CSommet::CSommet(const CSommet& m) {
	eIdSommet = m.eIdSommet;

	eSizeArrivant = m.eSizeArrivant;
	eSizeDispoArrivant = m.eSizeDispoArrivant;

	cArcArrivant = realloc(m.cArcArrivant, &eSizeDispoArrivant);

	eSizePartant = m.eSizePartant;
	eSizeDispoPartant = m.eSizeDispoPartant;

	cArcPartant = realloc(m.cArcPartant, &eSizeDispoPartant);
}

/*
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
} */


/*
##################
	ACCESSEURS
##################
*/
int CSommet::getIdSommet() const {
	return eIdSommet;
}

void CSommet::setIdSommet(int idSommet) {
	eIdSommet = idSommet;
}


// Accesseurs Arrivant
int CSommet::getSizeDispoArrivant() const {
	return eSizeDispoArrivant;
}

void CSommet::setSizeDispoArrivant(int sizeDispoArrivant) {
	eSizeDispoArrivant = sizeDispoArrivant;
}

int CSommet::getSizeArrivant() const {
	return eSizeArrivant;
}

void CSommet::setSizeArrivant(int sizeArrivant) {
	eSizeArrivant = sizeArrivant;
}

CArc** CSommet::getArcArrivant() const {
	return cArcArrivant;
}

void CSommet::setArcArrivant(CArc** liste) {
	cArcArrivant = liste;
}


// Accesseurs Partant
int CSommet::getSizeDispoPartant() const {
	return eSizeDispoPartant;
}

void CSommet::setSizeDispoPartant(int sizeDispoPartant) {
	eSizeDispoPartant = sizeDispoPartant;
}

int CSommet::getSizePartant() const {
	return eSizePartant;
}

void CSommet::setSizePartant(int sizePartant) {
	eSizePartant = sizePartant;
}

CArc** CSommet::getArcPartant() const {
	return cArcPartant;
}

void CSommet::setArcPartant(CArc** liste) {
	cArcPartant = liste;
}

/*
##################
	METHODES
##################
*/
// Arrivant
void CSommet::ajouterArcArrivant(CArc* arc) {
	CArc** liste = ajouterListe(cArcArrivant, &eSizeDispoArrivant, &eSizeArrivant, arc);
	setArcArrivant(liste);
}

void CSommet::supprimerArcArrivant(int indiceArc) {
	supprimerListe(cArcArrivant, indiceArc, &eSizeArrivant);
}

void CSommet::modifierArcArrivant(int indiceArc) {
	ajouterArcPartant(cArcArrivant[indiceArc]);
	supprimerArcArrivant(indiceArc);
}


// Partant
void CSommet::ajouterArcPartant(CArc* arc) {
	CArc** liste = ajouterListe(cArcPartant, &eSizeDispoPartant, &eSizePartant, arc);
	setArcPartant(liste);
}

void CSommet::supprimerArcPartant(int indiceArc) {
	supprimerListe(cArcPartant, indiceArc, &eSizePartant);
}

void CSommet::modifierArcPartant(int indiceArc) {
	ajouterArcArrivant(cArcPartant[indiceArc]);
	supprimerArcPartant(indiceArc);
}


ostream& operator<<(ostream& os, CSommet const S) {
	if (S.getIdSommet() == -1) {
		// Erreur
	}
	else {
		os << "-------------------------------------" << endl;
		os << "Sommet " << S.getIdSommet() << ":" << endl;
		if (S.getSizeArrivant() == 0 && S.getSizePartant() == 0) {
			os << "Aucun Arc Partant ou Arrivant !" << endl;
		}
		else {
			afficherListe(S.getArcArrivant(), S.getSizeArrivant(), "Liste Arc Arrivant : ");
			afficherListe(S.getArcPartant(), S.getSizePartant(), "Liste Arc Partant : ");
		}
	}
	return os;
}
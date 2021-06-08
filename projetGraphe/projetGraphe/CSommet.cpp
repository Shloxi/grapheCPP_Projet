#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CSommet.h"
#include "CException.h"
#include "CGrapheOperation.cpp"
using namespace std;

/*
##################
  CONSTRUCTEURS
##################
*/
CSommet::CSommet() {
	eIdSommet = -1;

	eSizeDispo = 0;
	eSize = 0;
	cArcListe = createListeArc(NULL, eSizeDispo, eSize);
}

CSommet::CSommet(int idSommet) {
	eIdSommet = idSommet;

	eSizeDispo = 5;
	eSize = 0;
	cArcListe = createListeArc(NULL, eSizeDispo, eSize);
}

CSommet::CSommet(int eId, int eSize, CArc** liste) {
	eIdSommet = eId;

	eSize = eSize;
	eSizeDispo = (eSize / 5 + 1) * 5;

	cArcListe = createListeArc(liste, eSizeDispo, eSize);
}	

CSommet::CSommet(const CSommet& m) {
	eIdSommet = m.eIdSommet;

	eSize = m.eSize;
	eSizeDispo = m.eSizeDispo;

	cArcListe = createListeArc(m.cArcListe, eSizeDispo, eSize);
}


CSommet::~CSommet() {
	if (cArcListe != NULL) {
		for (int i = 0; i < eSize; ++i) {
			if (cArcListe[i]) {
				delete cArcListe[i];
			}
		}
		free(cArcListe);
	}
}


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

int CSommet::getSizeDispo() const {
	return eSizeDispo;
}

void CSommet::setSizeDispo(int sizeDispo) {
	eSizeDispo = sizeDispo;
}

int CSommet::getSize() const {
	return eSize;
}

void CSommet::setSize(int size) {
	eSize = size;
}

CArc** CSommet::getArcListe() const {
	return cArcListe;
}

void CSommet::setArcListe(CArc** liste) {
	cArcListe = liste;
}


/*
##################
	METHODES
##################
*/
// Arrivant
void CSommet::ajouterArc(CArc* arc) {
	CArc** liste = ajouterListe(cArcListe, &eSizeDispo, &eSize, arc);
	setArcListe(liste);
}

void CSommet::supprimerArc(int indiceArc) {
	supprimerListe(cArcListe, indiceArc, &eSize);
}

void CSommet::modifierListe(CArc** liste, int size) {
	eSize = size;
	eSizeDispo = (eSize / 5 + 1) * 5;
	cArcListe = createListeArc(liste, eSizeDispo, eSize);
}

ostream& CSommet::display(ostream& os) const{
	if (eIdSommet == -1) {
		throw CException(wrongIndiceSommet); // idSommet négative
	}
	else {
		os << "-------------------------------------" << endl;
		os << "Sommet " << eIdSommet << ":" << endl;
		if (eSize == 0) {
			os << "Aucun Arc Partant !" << endl;
		}
		else {
			for (int i = 0; i < eSize; i++) {
				if (cArcListe[i]->getId1() == eIdSommet) {
					os << cArcListe[i]->getId2() << " ";
				}
				else if (cArcListe[i]->getId2() == eIdSommet) {
					os << cArcListe[i]->getId1() << " ";
				}
				else {
					throw CException(wrongIndiceArc);
				}
			}
			os << endl;
		}
	}
	return os;
}


ostream& operator<<(ostream& os, CSommet* const S) {
	S->display(os);
	return os;
}
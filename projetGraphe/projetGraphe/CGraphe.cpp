#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CGraphe.h"
#include "CGrapheOperation.cpp"
#include "CListeOperation.cpp"
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

	cSommetListe = createListeSommet(liste, eSizeDispo, eSize);
}

CGraphe::CGraphe(const CGraphe& m) {
	eSize = m.eSize;
	eSizeDispo = m.eSizeDispo;

	cSommetListe = createListeSommet(m.cSommetListe, eSizeDispo, eSize);
}

CGraphe::~CGraphe() {
	if (cSommetListe) {
		for (int i = 0; i < eSize; ++i) {
			delete cSommetListe[i];
		}
		free(cSommetListe);
	}
}


/*
##################
	ACCESSORS
##################
*/
CSommet** CGraphe::getSommetListe() const {
	return cSommetListe;
}

void CGraphe::setSommetListe(CSommet** liste) {
	cSommetListe = liste;
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

void CGraphe::ajouterSommet(CSommet * sommet) {
	CSommet** liste = ajouterListe(cSommetListe, &eSizeDispo, &eSize, sommet);
	setSommetListe(liste);
}

void CGraphe::supprimerSommet(int indiceSommet) {
	supprimerListe(cSommetListe, indiceSommet, &eSize);
}

void CGraphe::modifierSommetId(int indiceSommet, int newId) {
	cSommetListe[indiceSommet]->setIdSommet(newId);
}

void CGraphe::modifierSommetListe(CSommet** sommetListe, int size) {
	eSizeDispo = (size / 5 + 1) * 5;
	eSize = size;
	cSommetListe = createListeSommet(sommetListe, eSizeDispo, eSize);
}

CSommet* CGraphe::getSommet(int idSommet) {
	for (int i = 0; i < eSize; i++) {
		if (idSommet == cSommetListe[i]->getIdSommet()) {
			return cSommetListe[i];
		}
	}
	throw CException(); // Sommet introuvable
}

ostream& CGraphe::display(ostream& os) const {
	if (eSize == 0) {
		throw CException(); // liste vide
	}
	afficherListe(cSommetListe, eSize, "Presentation du graphe :\n", os);
	return os;
}

ostream& operator<<(ostream& os, CGraphe* const G) {
	G->display(os);
	return os;
}
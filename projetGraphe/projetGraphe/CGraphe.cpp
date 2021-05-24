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

	cSommetListe = createListe(liste, eSizeDispo, eSize);
}

CGraphe::CGraphe(const CGraphe& m) {
	eSize = m.eSize;
	eSizeDispo = m.eSizeDispo;
	//afficherListe(m.cSommetListe, m.eSize, "Test");
	cSommetListe = createListe(m.cSommetListe, eSizeDispo, eSize);
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

ostream& operator<<(ostream& os, CGraphe const G) {
	if (G.getSize() == 0) {
		//Erreur
	}
	afficherListe(G.getSommetListe(), G.getSize(), "Presentation du graphe :\n");
	return os;
}
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
		for (int i = 0; i < eSize - 1; ++i) {
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
		for (int i = 0; i < eSize - 1; ++i) {
			cSommetListe[i] = m.cSommetListe[i];
		}
	}
	else {
		//Erreur
	}
}

CGraphe::~CGraphe() {
	if (cSommetListe) {
		free(cSommetListe);
	}
}


/*
##################
	ACCESSORS
##################
*/
CSommet** CGraphe::getSommetListe() {
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

int CGraphe::getSize() {
	return eSize;
}

void CGraphe::setSize(int size) {
	eSize = size;
}

int CGraphe::getSizeDispo() {
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
	CSommet** newCSommetListe = (CSommet**)realloc(cSommetListe, sizeof(CSommet*) * eSizeDispo);
	if (newCSommetListe == NULL) {
		// Erreur
	}
	setSommetListe(newCSommetListe);
}
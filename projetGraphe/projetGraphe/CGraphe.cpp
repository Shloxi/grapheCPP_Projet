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
	eSizeListe = -1;
	cSommetListe = NULL;
}

CGraphe::CGraphe(int sizeListe, CSommet* liste) {
	eSizeListe = sizeListe;

	cSommetListe = (CSommet*)malloc(sizeof(CSommet) * eSizeListe);
	if (cSommetListe) {
		for (int i = 0; i < eSizeListe; ++i) {
			cSommetListe[i] = liste[i];
		}
	}
	else {
		//Erreur
	}
}

CGraphe::CGraphe(const CGraphe& m) {
	eSizeListe = m.eSizeListe;

	cSommetListe = (CSommet*)malloc(sizeof(CSommet) * eSizeListe);
	if (cSommetListe) {
		for (int i = 0; i < eSizeListe; ++i) {
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
CSommet* CGraphe::getSommetListe() {
	return cSommetListe;
}

void CGraphe::setSommetListe(CSommet* liste) {
	if (cSommetListe) {
		free(cSommetListe);
	}
	cSommetListe = (CSommet*)malloc(sizeof(CSommet) * eSizeListe);
	if (cSommetListe) {
		for (int i = 0; i < eSizeListe; ++i) {
			cSommetListe[i] = liste[i];
		}
	}
	else {
		//Erreur
	}
}

int CGraphe::getSizeListe() {
	return eSizeListe;
}

void CGraphe::setSizeListe(int size) {
	eSizeListe = size;
}
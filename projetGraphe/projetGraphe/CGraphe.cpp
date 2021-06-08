#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CGraphe.h"
#include "CGrapheOperation.cpp"
#include "Parser.cpp"
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

CGraphe::CGraphe(const char* filename) {
	eSize = 0;
	eSizeDispo = 0;
	cSommetListe = createListeSommet(NULL, eSizeDispo, eSize);
	// On appelle d'abord le parseur pour récupérer les valeurs du fichier
	char** valeurs = parser(filename);
	
	// Analyseur syntaxique
	int indice = 6;
	int parcoursNombre = 0;
	int nombre1 = 0;
	int nombre2 = 0;
	int nbSommets = 0;
	int nbArcs = 0;
	compare(valeurs[0], "NBSommets"); // On verifie que la syntaxe du fichier est bonne
	sscanf_s(valeurs[1], "%d", &nbSommets);
	compare(valeurs[2], "NBArcs");
	sscanf_s(valeurs[3], "%d", &nbArcs);
	compare(valeurs[4], "Sommets");
	compare(valeurs[5], "[");
	// On recupere toutes les id de sommets et on les ajoutes a notre graphe
	for (int i = indice; i < indice + (2 * nbSommets); i+=2) {
		compare(valeurs[i], "Numero");
		sscanf_s(valeurs[i+1], "%d", &nombre1);
		ajouterSommetGraphe(this, nombre1);
	}
	indice += (2 * nbSommets);
	compare(valeurs[indice], "]");
	compare(valeurs[indice + 1], "Arcs");
	compare(valeurs[indice+2], "[");
	indice += 3;
	// On recupere tous les arcs et on les ajoutes a nos sommets du graphe
	for (int i = indice; i < indice + (4 * nbArcs); i += 4) {
		compare(valeurs[i], "Debut");
		sscanf_s(valeurs[i+1], "%d", &nombre1);
		compare(valeurs[i+2], "Fin");
		sscanf_s(valeurs[i+3], "%d", &nombre2);
		ajouterArcSommet(this->getSommet(nombre1), this->getSommet(nombre2));
	}
	indice += (4 * nbArcs);
	compare(valeurs[indice], "]");
	// On libère notre tableau de valeurs
	for (int i = 0; i < 100; ++i) {
		free(valeurs[i]);
	}
	free(valeurs);
}

CGraphe::~CGraphe() {
	if (cSommetListe != NULL) {
		for (int i = 0; i < eSize; ++i) {
			supprimerSommetGraphe(this, cSommetListe[i]);
			i--;
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
	METHODES
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
	throw CException(missingSommet); // Sommet introuvable
}

int CGraphe::getSommet(CSommet* sommet) {
	for (int i = 0; i < eSize; i++) {
		if (sommet == cSommetListe[i]) {
			return i;
		}
	}
	throw CException(missingSommet); // Sommet introuvable
}

ostream& CGraphe::display(ostream& os) const {
	if (eSize == 0) {
		throw CException(emptyList); // liste vide
	}
	afficherListe(cSommetListe, eSize, "Presentation du graphe :\n", os);
	return os;
}

ostream& operator<<(ostream& os, CGraphe* const G) {
	G->display(os);
	return os;
}
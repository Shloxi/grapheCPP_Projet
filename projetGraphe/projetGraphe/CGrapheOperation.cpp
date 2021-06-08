#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
#include "CListeOperation.cpp"
#include "CArc.h"
#include "CSommet.h"
#include "CGraphe.h"
using namespace std;

// Constantes d'erreurs liees aux operations sur un graphe et ses listes
#define badMalloc 1
#define nullArgument 4
#define wrongIndiceSommet 11
#define existingSommet 12
#define missingSommet 13
#define existingArc 22
#define missingArc 23

static CArc** createListeArc(CArc** liste, int sizeDispo, int size) {
	// On creer une liste d'arc en les allouant en memoire
	CArc** newListe;
	newListe = (CArc**)malloc(sizeof(CArc*) * sizeDispo);
	if (newListe) {
		for (int i = 0; i < size; ++i) {
			newListe[i] = new CArc(*liste[i]);
		}
	}
	else {
		throw CException(badMalloc); // Allocation raté
	}
	return newListe;
}

static CSommet** createListeSommet(CSommet** liste, int sizeDispo, int size) {
	// On creer une liste de sommet en les allouant en memoire
	CSommet** newListe;
	newListe = (CSommet**)malloc(sizeof(CSommet*) * sizeDispo);
	if (newListe) {
		for (int i = 0; i < size; ++i) {
			newListe[i] = new CSommet(*liste[i]);
		}
	}
	else {
		throw CException(badMalloc); // Allocation raté
	}
	return newListe;
}

static void ajouterArcSommet(CSommet* Sommet1, CSommet* Sommet2) {
	if (Sommet1 == NULL || Sommet2 == NULL) {
		throw CException(nullArgument); // Argument null
	}
	for (int i = 0; i < Sommet1->getSize(); i++) {
		if (containsListe(Sommet1->getArcListe(), Sommet1->getSize(), Sommet2->getArcListe(), Sommet2->getSize())) {
			throw CException(existingArc); // Arc déja existant
		}
	}
	// On creer un arc et on l'ajoute dans les listes correspondantes dans les sommets
	CArc* newArc = new CArc(Sommet1->getIdSommet(), Sommet2->getIdSommet());
	Sommet1->ajouterArc(newArc);
	Sommet2->ajouterArc(newArc);
}

static void supprimerArcSommet(CSommet* Sommet1, CSommet* Sommet2) {
	if (Sommet1 == NULL || Sommet2 == NULL) {
		throw CException(nullArgument); // Argument null
	}
	if (!containsListe(Sommet1->getArcListe(), Sommet1->getSize(), Sommet2->getArcListe(), Sommet2->getSize())) {
		throw CException(missingArc); // Arc introuvable
	}
	if (Sommet1 == Sommet2) {
		throw CException(); // SommetIdentique
	}
	int indice1 = 0;
	int indice2 = 0;
	for (int i = 0; i < Sommet1->getSize(); i++) {
		for (int y = 0; y < Sommet2->getSize(); y++) {
			if (Sommet1->getArcListe()[i] == Sommet2->getArcListe()[y]) {
				indice1 = i;
				indice2 = y;
			}
		}
	}
	CArc* toDelete = Sommet1->getArcListe()[indice1];
	Sommet1->supprimerArc(indice1);
	Sommet2->supprimerArc(indice2);
	delete toDelete;
}

static void ajouterSommetGraphe(CGraphe* G, int idSommet) {
	if (idSommet > 0) {
		for (int i = 0; i < G->getSize(); i++) {
			// On verifie que le sommet n'existe pas deja dans le graphe
			if (G->getSommetListe()[i]->getIdSommet() == idSommet) {
				throw CException(existingSommet);
			}
		}
		// On alloue le sommet en memoire et on l'ajoute dans la liste des sommets
		CSommet* newSommet = new CSommet(idSommet);
		G->ajouterSommet(newSommet);
	}
	// Argument mauvais
	else {
		throw CException(wrongIndiceSommet); // idSommet négative
	}
}

static void supprimerSommetGraphe(CGraphe* G, CSommet* S) {
	if (S == NULL || G == NULL) {
		throw CException(nullArgument); // Argument null
	}
	int indiceSommet = G->getSommet(S);

	
	// On parcours la liste des sommets
	for (int i = 0; i < G->getSize(); i++) {
		// On parcours la liste des arcs des autres sommets
		for (int y = 0; y < G->getSommetListe()[i]->getSize(); y++) {
			// Si un arc est en direction de notre sommet
			if (containsListe(S->getArcListe(), S->getSize(), G->getSommetListe()[i]->getArcListe(), G->getSommetListe()[i]->getSize()) && S != G->getSommetListe()[i]) {
				// On le supprime
				supprimerArcSommet(S, G->getSommetListe()[i]);
			}
		}
	}
	G->supprimerSommet(indiceSommet);
	// On supprime le sommet de la memoire apres toutes operations
	delete S;
}
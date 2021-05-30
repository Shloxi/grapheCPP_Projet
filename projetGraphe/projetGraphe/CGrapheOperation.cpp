#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
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

static void ajouterArcSommet(CSommet* SommetArrivant, CSommet* SommetPartant) {
	if (SommetArrivant == NULL || SommetPartant == NULL) {
		throw CException(nullArgument); // Argument null
	}
	for (int i = 0; i < SommetPartant->getSizePartant(); i++) {
		if (SommetPartant->getArcPartant()[i]->getIdDest() == SommetArrivant->getIdSommet()) {
			throw CException(existingArc); // Arc déja existant
		}
	}
	// On creer un arc et on l'ajoute dans les listes correspondantes dans les sommets
	CArc* newArc = new CArc(SommetArrivant->getIdSommet());
	SommetArrivant->ajouterArcArrivant(newArc);
	SommetPartant->ajouterArcPartant(newArc);
}

static void supprimerArcSommet(CSommet* SommetArrivant, CSommet* SommetPartant) {
	if (SommetArrivant == NULL || SommetPartant == NULL) {
		throw CException(nullArgument); // Argument null
	}
	CArc* toDelete = NULL;
	int indicePartant = -1;
	// On cherche l'arc dans la liste des sommetsPartants
	for (int i = 0; i < SommetPartant->getSizePartant(); ++i) {
		if (SommetPartant->getArcPartant()[i]->getIdDest() == SommetArrivant->getIdSommet()) {
			toDelete = SommetPartant->getArcPartant()[i];
			SommetPartant->supprimerArcPartant(i);
		}
	}
	// On cherche l'arc dans la liste des sommetsArrivants
	if (toDelete) {
		for (int i = 0; i < SommetArrivant->getSizeArrivant(); ++i) {
			if (SommetArrivant->getArcArrivant()[i] == toDelete) {
				SommetArrivant->supprimerArcArrivant(i);
			}
		}
		// On supprime cet arc de la memoire apres toutes les operations
		delete toDelete;
	}
	// Si on ne trouve pas l'arc on retourne une erreur
	else {
		throw CException(missingArc); // Arc introuvable
	}
	
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
	int indiceSommet = -1;
	// On parcours la liste des arcs partants de notre sommets
	for (int i = 0; i < S->getSizePartant(); i++) {
		// On les supprime un a un
		supprimerArcSommet(G->getSommet(S->getArcPartant()[i]->getIdDest()), S);
	}
	// On parcours la liste des sommets
	for (int i = 0; i < G->getSize(); i++) {
		// On recupere l'indice du sommet dans notre liste de sommets
		if (G->getSommetListe()[i]->getIdSommet() == S->getIdSommet()) {
			indiceSommet = i;
		}
		// On parcours la liste des arcs partants des autres sommets
		for (int y = 0; y < G->getSommetListe()[i]->getSizePartant(); y++) {
			// Si un arc est en direction de notre sommet
			if (S->getIdSommet() == G->getSommetListe()[i]->getArcPartant()[y]->getIdDest()) {
				// On le supprime
				supprimerArcSommet(S, G->getSommetListe()[i]);
			}
		}
	}
	// Si on a pas trouve le sommet dans le graphe
	if (indiceSommet >= 0) {
		G->supprimerSommet(indiceSommet);
	}
	// On retourne une erreur
	else {
		throw CException(missingSommet);
	}
	// On supprime le sommet de la memoire apres toutes operations
	delete S;
}


static void reverseGraphe(CGraphe* G) {
	// Pour chaque sommet dans le graphe
	for (int i = 0; i < G->getSize(); i++) {
		// On inverse les listes du sommets a l'aide de la fonction reverseArc
		G->getSommetListe()[i]->reverseArc();
	}
}
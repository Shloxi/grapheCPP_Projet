#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
#include "CArc.h"
#include "CSommet.h"
#include "CGraphe.h"
using namespace std;

static CArc** createListeArc(CArc** liste, int sizeDispo, int size) {
	CArc** newListe;
	newListe = (CArc**)malloc(sizeof(CArc*) * sizeDispo);
	if (newListe) {
		for (int i = 0; i < size; ++i) {
			newListe[i] = new CArc(*liste[i]);
		}
	}
	else {
		throw CException(); // Allocation raté
	}
	return newListe;
}

static CSommet** createListeSommet(CSommet** liste, int sizeDispo, int size) {
	CSommet** newListe;
	newListe = (CSommet**)malloc(sizeof(CSommet*) * sizeDispo);
	if (newListe) {
		for (int i = 0; i < size; ++i) {
			newListe[i] = new CSommet(*liste[i]);
		}
	}
	else {
		throw CException(); // Allocation raté
	}
	return newListe;
}

static void ajouterArcSommet(CSommet* SommetArrivant, CSommet* SommetPartant) {
	if (SommetArrivant == NULL || SommetPartant == NULL) {
		throw CException(); // Argument null
	}
	for (int i = 0; i < SommetPartant->getSizePartant(); i++) {
		if (SommetPartant->getArcPartant()[i]->getIdDest() == SommetArrivant->getIdSommet()) {
			throw CException(); // Arc déja existant
		}
	}
	CArc* newArc = new CArc(SommetArrivant->getIdSommet());
	SommetArrivant->ajouterArcArrivant(newArc);
	SommetPartant->ajouterArcPartant(newArc);
}

static void supprimerArcSommet(CSommet* SommetArrivant, CSommet* SommetPartant) {
	if (SommetArrivant == NULL || SommetPartant == NULL) {
		throw CException(); // Argument null
	}
	CArc* toDelete = NULL;
	int indicePartant = -1;
	for (int i = 0; i < SommetPartant->getSizePartant(); ++i) {
		if (SommetPartant->getArcPartant()[i]->getIdDest() == SommetArrivant->getIdSommet()) {
			toDelete = SommetPartant->getArcPartant()[i];
			SommetPartant->supprimerArcPartant(i);
		}
	}
	if (toDelete) {
		for (int i = 0; i < SommetArrivant->getSizeArrivant(); ++i) {
			if (SommetArrivant->getArcArrivant()[i] == toDelete) {
				SommetArrivant->supprimerArcArrivant(i);
			}
		}
		delete toDelete;
	}
	else {
		throw CException(); // Arc introuvable
	}
	
}

static void ajouterSommetGraphe(CGraphe* G, int idSommet) {
	if (idSommet > 0) {
		for (int i = 0; i < G->getSize(); i++) {
			if (G->getSommetListe()[i]->getIdSommet() == idSommet) {
				throw CException(); // Sommet déja existant
			}
		}
		CSommet* newSommet = new CSommet(idSommet);
		G->ajouterSommet(newSommet);
	}
	else {
		throw CException(); // idSommet négative
	}
}

static void supprimerSommetGraphe(CGraphe* G, CSommet* S) {
	if (S == NULL || G == NULL) {
		throw CException(); // Argument null
	}
	int indiceSommet = -1;
	for (int i = 0; i < S->getSizePartant(); i++) {
		supprimerArcSommet(G->getSommet(S->getArcPartant()[i]->getIdDest()), S);
	}
	for (int i = 0; i < G->getSize(); i++) {
		if (G->getSommetListe()[i]->getIdSommet() == S->getIdSommet()) {
			indiceSommet = i;
		}
		for (int y = 0; y < G->getSommetListe()[i]->getSizePartant(); y++) {
			if (S->getIdSommet() == G->getSommetListe()[i]->getArcPartant()[y]->getIdDest()) {
				supprimerArcSommet(S, G->getSommetListe()[i]);
			}
		}
	}
	if (indiceSommet >= 0) {
		G->supprimerSommet(indiceSommet);
	}
	else {
		throw CException();
	}
	delete S;
}


static void reverseGraphe(CGraphe* G) {
	for (int i = 0; i < G->getSize(); i++) {
		G->getSommetListe()[i]->reverseArc();
	}
}
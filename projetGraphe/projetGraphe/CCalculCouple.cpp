#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
#include "CCalculCouple.h"
#include "CGrapheOperation.cpp"

CCalculCouple::CCalculCouple(CGraphe* G) {
	cGraphe = G;

	// Création de la liste des arretes du graphe G
	eSizeDispo = 5;
	eSize = 0;
	listeArcGraphe = createListeArc(NULL, eSizeDispo, eSize);

	eSizeDispoCouplage = 5;
	eSizeCouplage = 0;
	listeCouplageMax = NULL;

	// Attribution des arretes du graphe dans couplageBase
	for (int i = 0; i < cGraphe->getSize(); i++) {
		for (int y = 0; y < cGraphe->getSommetListe()[i]->getSize(); y++) {
			if (containsListeElem(listeArcGraphe, eSize, cGraphe->getSommetListe()[i]->getArcListe()[y]) == 0) {
				listeArcGraphe = ajouterListe(listeArcGraphe, &eSizeDispo, &eSize, cGraphe->getSommetListe()[i]->getArcListe()[y]);
			}
		}
	}

	// Calcul du couple max
	int sizeDispoCouplage = 5;
	int sizeCouplage = 0;
	CArc** couplage = createListeArc(NULL, sizeDispoCouplage, sizeCouplage);
	calcCoupMax(couplage, sizeCouplage, sizeDispoCouplage);
}


CArc** CCalculCouple::getListeCouplageMax() {
	return listeCouplageMax;
}


int CCalculCouple::getSizeCouplage() {
	return eSizeCouplage;
}

void CCalculCouple::calcCoupMax(CArc** couplage, int sizeCouplage, int sizeDispoCouplage) {
	if (eSize == 0) {
		if (sizeCouplage > eSizeCouplage){
			// Desallocation de listeArcGraphe
			listeCouplageMax = couplage;
			eSizeCouplage = sizeCouplage;
			eSizeDispoCouplage = sizeDispoCouplage;
		}
	}
	else {
		int sizeToReput = 0;
		int sizeDispoToReput = 5;
		CArc** listeArcToReput = createListeArc(NULL, sizeDispoToReput, sizeToReput);
		for (int i = 0; i < eSize; i++) {
			CArc* newArc = new CArc(*listeArcGraphe[i]);
			couplage = ajouterListe(couplage, &sizeDispoCouplage, &sizeCouplage, listeArcGraphe[i]);
			listeArcToReput = ajouterListe(listeArcToReput, &sizeDispoToReput, &sizeToReput, listeArcGraphe[i]);
			supprimerListe(listeArcGraphe, i, &eSize);
			for (int y = 0; y < eSize; y++) {
				if (newArc->getId1() == listeArcGraphe[y]->getId1() || newArc->getId2() == listeArcGraphe[y]->getId1() ||
					newArc->getId1() == listeArcGraphe[y]->getId2() || newArc->getId2() == listeArcGraphe[y]->getId2()) {
					listeArcToReput = ajouterListe(listeArcToReput, &sizeDispoToReput, &sizeToReput, listeArcGraphe[y]);
					supprimerListe(listeArcGraphe, y, &eSize);
					y--;
				}
			}
			calcCoupMax(couplage, sizeCouplage, sizeDispoCouplage);
			i = eSize - 1;
			for (int y = 0; y < sizeToReput; y++) {
				if (containsListeElem(listeArcGraphe, eSize, listeArcToReput[y]) == 0) {
					listeArcGraphe = ajouterListe(listeArcGraphe, &eSizeDispo, &eSize, listeArcToReput[y]);
					supprimerListe(listeArcToReput, y, &sizeToReput);
					y--;
					i++;
				}
			}
		}
	}
}

CGraphe* CCalculCouple::setToGraphe() {
	CGraphe* res = new CGraphe();
	for (int i = 0; i < cGraphe->getSize(); i++) {
		ajouterSommetGraphe(res, cGraphe->getSommetListe()[i]->getIdSommet());
	}
	for (int i = 0; i < eSizeCouplage; i++) {
		ajouterArcSommet(res->getSommet(listeCouplageMax[i]->getId1()), res->getSommet(listeCouplageMax[i]->getId2()));
	}
	return res;
}

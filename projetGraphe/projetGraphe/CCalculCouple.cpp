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

// Permet de calculer le couplage maximum d'un graphe non orienté
void CCalculCouple::calcCoupMax(CArc** couplage, int sizeCouplage, int sizeDispoCouplage) {
	
	// Si la taille de la liste des arcs vaut 0
	if (eSize == 0) {
		
		// Si la taille du couplage actuelle est plus grande que le couplage max actuel
		if (sizeCouplage > eSizeCouplage){
			// Desallocation de listeArcGraphe
			
			// Le couplage max devient alors ce couplage ci
			listeCouplageMax = couplage; 
			eSizeCouplage = sizeCouplage;
			eSizeDispoCouplage = sizeDispoCouplage;
		}
	}
	
	// Sinon
	else {
		
		// On crée la liste pour les arcs qu'il faurdra ajouter de nouveau à la fin
		int sizeToReput = 0;
		int sizeDispoToReput = 5;
		CArc** listeArcToReput = createListeArc(NULL, sizeDispoToReput, sizeToReput);
		
		// Pour chaque arc du graphe
		for (int i = 0; i < eSize; i++) {
			
			// On ajoute dans le couplage un arc fait à partir du constructeur de recopie
			CArc* newArc = new CArc(*listeArcGraphe[i]);
			couplage = ajouterListe(couplage, &sizeDispoCouplage, &sizeCouplage, listeArcGraphe[i]);
			
			// On ajoute également cet arc dans la liste des arcs qui devront être remis dans le graphe à la fin de l'algo
			listeArcToReput = ajouterListe(listeArcToReput, &sizeDispoToReput, &sizeToReput, listeArcGraphe[i]);
			
			// On supprime cet arc du graphe
			supprimerListe(listeArcGraphe, i, &eSize);
			
			// On regarde si dans la liste des arcs il y a des arcs qui ont des sommets en commum avec l'arc sur lequel on travaille
			for (int y = 0; y < eSize; y++) {
				if (newArc->getId1() == listeArcGraphe[y]->getId1() || newArc->getId2() == listeArcGraphe[y]->getId1() ||
					newArc->getId1() == listeArcGraphe[y]->getId2() || newArc->getId2() == listeArcGraphe[y]->getId2()) {
					
					// On supprime également ces arcs et on les ajoute dans la liste des arcs à rajouter à la fin de l'algo
					listeArcToReput = ajouterListe(listeArcToReput, &sizeDispoToReput, &sizeToReput, listeArcGraphe[y]);
					supprimerListe(listeArcGraphe, y, &eSize);
					y--;
				}
			}
			
			// Fonction récursive
			calcCoupMax(couplage, sizeCouplage, sizeDispoCouplage);
			i = eSize - 1;
			
			// On remet dans le graphe les arcs précédemment enlevés
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

// Permet à partir d'un couplage de créer le graphe correspondant
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

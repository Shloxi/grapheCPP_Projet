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

	// Création de la liste du CouplageMax
	eSizeDispoCouplage = 5;
	eSizeCouplage = 0;
	listeCouplageMax = NULL;

	// Attribution des arretes du graphe dans A
	for (int i = 0; i < cGraphe->getSize(); i++) {
		for (int y = 0; y < cGraphe->getSommetListe()[i]->getSize(); y++) {
			if (containsListeElem(listeArcGraphe, eSize, cGraphe->getSommetListe()[i]->getArcListe()[y]) == 0) {
				listeArcGraphe = ajouterListe(listeArcGraphe, &eSizeDispo, &eSize, cGraphe->getSommetListe()[i]->getArcListe()[y]);
			}
		}
	}

	// Création de la liste du couplage en cours de calcul
	int sizeDispoCouplage = 5;
	int sizeCouplage = 0;
	CArc** couplage = createListeArc(NULL, sizeDispoCouplage, sizeCouplage);
	
	// Calcul du couple max
	calcCoupMax(couplage, sizeCouplage, sizeDispoCouplage);
}

CCalculCouple::~CCalculCouple() {
	free(listeCouplageMax);
	free(listeArcGraphe);
}


CArc** CCalculCouple::getListeCouplageMax() {
	return listeCouplageMax;
}


int CCalculCouple::getSizeCouplage() {
	return eSizeCouplage;
}



/*
##################
	METHODES
##################
*/
void CCalculCouple::calcCoupMax(CArc** couplage, int sizeCouplage, int sizeDispoCouplage) {
	
	// Si la taille de la liste des arcs vaut 0
	if (eSize == 0) {
		
		// Si la taille du couplage calcule est plus grande que notre CouplageMax
		if (sizeCouplage > eSizeCouplage){
			
			// Le CouplageMax devient alors le couplage calcule
			listeCouplageMax = couplage; 
			eSizeCouplage = sizeCouplage;
			eSizeDispoCouplage = sizeDispoCouplage;
		}
	}
	
	// Sinon
	else {
		
		// On cree la liste pour les arcs qu'il faudra ajouter de nouveau à la fin
		int sizeToReput = 0;
		int sizeDispoToReput = 5;
		CArc** listeArcToReput = createListeArc(NULL, sizeDispoToReput, sizeToReput);
		
		// Pour chaque arc du graphe
		for (int i = 0; i < eSize; i++) {
			
			// On recupere d'abord l'arc sur lequel on va travailler car il sera supprimer de A
			CArc* newArc = new CArc(*listeArcGraphe[i]);

			// On ajoute dans le couplage l'arc d'indice i dans A
			couplage = ajouterListe(couplage, &sizeDispoCouplage, &sizeCouplage, listeArcGraphe[i]);
			
			// On ajoute également cet arc dans la liste des arcs qui devront être remis dans le graphe à la fin de l'algo
			listeArcToReput = ajouterListe(listeArcToReput, &sizeDispoToReput, &sizeToReput, listeArcGraphe[i]);
			
			// On supprime cet arc de A
			supprimerListe(listeArcGraphe, i, &eSize);
			
			// On regarde si dans la liste des arcs de A, il y a des arcs qui ont des sommets en commum avec l'arc sur lequel on travaille
			for (int y = 0; y < eSize; y++) {
				if (newArc->getId1() == listeArcGraphe[y]->getId1() || newArc->getId2() == listeArcGraphe[y]->getId1() ||
					newArc->getId1() == listeArcGraphe[y]->getId2() || newArc->getId2() == listeArcGraphe[y]->getId2()) {
					
					// On supprime également ces arcs de A et on les ajoute dans la liste des arcs à rajouter à la fin de l'algo
					listeArcToReput = ajouterListe(listeArcToReput, &sizeDispoToReput, &sizeToReput, listeArcGraphe[y]);
					supprimerListe(listeArcGraphe, y, &eSize);
					y--;
				}
			}
			delete newArc;
			
			// Fonction récursive
			calcCoupMax(couplage, sizeCouplage, sizeDispoCouplage);
			i = eSize - 1;
			
			// On remet dans le graphe les arcs précédemment enlevés de A
			for (int y = 0; y < sizeToReput; y++) {
				if (containsListeElem(listeArcGraphe, eSize, listeArcToReput[y]) == 0) {
					listeArcGraphe = ajouterListe(listeArcGraphe, &eSizeDispo, &eSize, listeArcToReput[y]);
					supprimerListe(listeArcToReput, y, &sizeToReput);
					y--;
					i++;
				}
			}
			free(listeArcToReput);
		}
	}
}

// Permet a partir d'un couplage de creer le graphe correspondant
CGraphe* CCalculCouple::setToGraphe() {
	// Pas besoin de verification car cette methode ne pourra pas être appeles si on a pas appeles le constructeur qui appelle forcement calcCoupMax
	CGraphe* res = new CGraphe();
	for (int i = 0; i < cGraphe->getSize(); i++) {
		// On ajoute les sommets du graphe de base
		ajouterSommetGraphe(res, cGraphe->getSommetListe()[i]->getIdSommet());
	}
	for (int i = 0; i < eSizeCouplage; i++) {
		// On rajoute les arcs calcules par la fonction calcCoupMax
		ajouterArcSommet(res->getSommet(listeCouplageMax[i]->getId1()), res->getSommet(listeCouplageMax[i]->getId2()));
	}
	return res;
}

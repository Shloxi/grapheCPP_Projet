#ifndef CCalculCouple_h
#define CCalculCouple_h
#include "CArc.h"
#include "CSommet.h"
#include "CGraphe.h"

class CCalculCouple
{
private :
	CGraphe* cGraphe;

	CArc** listeArcGraphe; // Liste des arcs du graphe : A
	int eSize; // Taille de la liste A : |A|
	int eSizeDispo; // Taile disponible en mémoire pour la liste A

	CArc** listeCouplageMax; // Liste du CouplageMax : CMax
	int eSizeCouplage; // Taille de la liste du CouplageMax : |CMax|
	int eSizeDispoCouplage; // Taille dispo en mémoire pour la liste du CouplageMax
public :
	// Constructeur
	CCalculCouple(CGraphe* G);
	~CCalculCouple();

	// Accesseurs
	CArc** getListeCouplageMax();
	int getSizeCouplage();
	
	// Méthodes
	void calcCoupMax(CArc** couplage, int sizeCouplage, int sizeDispoCouplage); // Méthode récursive de calcul du couplageMax
	CGraphe* setToGraphe(); // Méthode de création du graphe à partir de la listeCouplageMax
};

#endif // !CCalculCouple_h


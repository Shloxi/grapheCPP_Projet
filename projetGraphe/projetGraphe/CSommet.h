#ifndef CSommet_h
#define CSommet_h
#include "CArc.h"
using namespace std;

class CSommet {

private:
	int eIdSommet; // Liste de sommets
	int eSizeDispoArrivant; // Liste des arcs dispo pour arrivant
	int eSizeDispoPartant; // Liste des arcs dispo pour partant
	CArc* cArcArrivant; // Liste des arcs arrivants
	CArc* cArcPartant; // Liste des arcs partants

	// Accessors en prive pour des raisons d'allocation
	void setArcArrivant(CArc* liste);
	void setArcPartant(CArc* liste);
	void setSizeDispoArrivant(int sizeDispoArrivant);
	void setSizeDispoPartant(int sizeDispoPartant);

public:
	// Constructors
	CSommet(); // Par défaut
	CSommet(int eId, int eSizeA, int eSizeP, CArc* listeArrivant, CArc* listePartant);
	CSommet(const CSommet& m); // Par recopie
	~CSommet(); // Destructeur

	//Accessors
	int getIdSommet();
	void setIdSommet(int idSommet);
	int getSizeDispoArrivant();
	int getSizeDispoPartant();
	CArc* getArcArrivant();
	CArc* getArcPartant();
	

	//Methods
	void changeListeArrivant(CArc* liste, int sizeDispoArrivant);
	void changeListePartant(CArc* liste, int sizeDispoPartant);
	void allocArrivant();
	void allocPartant();
};

#endif // !CSommet_h


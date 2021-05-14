#ifndef CSommet_h
#define CSommet_h
#include "CArc.h"
using namespace std;

class CSommet {

private:
	int eIdSommet; // Liste de sommets
	CArc** cArcArrivant; // Liste des arcs arrivants
	CArc** cArcPartant; // Liste des arcs partants

public:
	// Constructors
	CSommet(); // Par défaut
	CSommet(int eIdSommet, CArc** listeArrivant, CArc** listePartant);
	CSommet(const CSommet& m); // Par recopie
	~CSommet(); // Destructeur

	//Accesseurs
	int getIdSommet();
	void setIdSommet(int eIdSommet);
	CArc** getArcArrivant();
	void setArcArrivant(CArc** liste);
	CArc** getArcPartant();
	void setArcPartant(CArc** liste);
};

#endif // !CSommet_h


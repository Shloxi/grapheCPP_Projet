#ifndef CSommet_h
#define CSommet_h
#include "CArc.h"
using namespace std;

class CSommet {

private:
	int eIdSommet; // Id du sommet

	int eSizeDispoArrivant; // Place dispo pour Arrivant
	int eSizeArrivant; // Place utilisé pour Arrivant
	CArc** cArcArrivant; // Liste des arcs arrivants

	int eSizeDispoPartant; // Place dispo pour Partant
	int eSizePartant; // Place utilisé pour Partant
	CArc** cArcPartant; // Liste des arcs partants

	// Accesseurs et methodes en prive pour des raisons de sécurité de gestion de liste
	void setArcArrivant(CArc** liste);
	void setSizeDispoArrivant(int sizeDispoArrivant);
	void setSizeArrivant(int sizeArrivant);

	void setArcPartant(CArc** liste);
	void setSizeDispoPartant(int sizeDispoPartant);
	void setSizePartant(int sizePartant);

public:
	// Constructeurs
	CSommet(); // Par défaut
	CSommet(int idSommet);
	CSommet(int eId, int eSizeA, int eSizeP, CArc** listeArrivant, CArc** listePartant);
	CSommet(const CSommet& m); // Par recopie
	~CSommet(); // Destructeur

	//Accesseurs
	int getIdSommet() const;
	void setIdSommet(int idSommet);

	int getSizeDispoArrivant() const;
	int getSizeArrivant() const;
	CArc** getArcArrivant() const;

	int getSizeDispoPartant() const;
	int getSizePartant() const;
	CArc** getArcPartant() const;
	

	//Methodes
	void ajouterArcArrivant(CArc* arc);
	void supprimerArcArrivant(int indiceArc);
	void modifierArcArrivant(int indiceArc, int newId);
	void modifierListeArrivant(CArc** listeArrivant, int size);

	void ajouterArcPartant(CArc* arc);
	void supprimerArcPartant(int indiceArc);
	void modifierArcPartant(int indiceArc, int newId);
	void modifierListePartant(CArc** listePartant, int size);
	void reverseArc();
	ostream& display(ostream& os) const;
};

ostream& operator<<(ostream& os, CSommet* const S);

#endif // !CSommet_h


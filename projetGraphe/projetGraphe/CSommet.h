#ifndef CSommet_h
#define CSommet_h
#include "CArc.h"
using namespace std;

class CSommet {

private:
	int eIdSommet; // Id du sommet

	int eSizeDispoArrivant; // Place dispo pour Arrivant
	int eSizeArrivant; // Place utilis� pour Arrivant
	CArc** cArcArrivant; // Liste des arcs arrivants

	int eSizeDispoPartant; // Place dispo pour Partant
	int eSizePartant; // Place utilis� pour Partant
	CArc** cArcPartant; // Liste des arcs partants

	// Accesseurs et methodes en prive pour des raisons de s�curit�
	void setArcArrivant(CArc** liste);
	void setSizeDispoArrivant(int sizeDispoArrivant);
	void setSizeArrivant(int sizeArrivant);
	void reallocArrivant(); // Reallocation de Arrivant si eSizeDispoArrivant = eSizeArrivant

	void setArcPartant(CArc** liste);
	void setSizeDispoPartant(int sizeDispoPartant);
	void setSizePartant(int sizePartant);
	void reallocPartant(); // Reallocation de Partant si eSizeDispoPartant = eSizePartant

public:
	// Constructeurs
	CSommet(); // Par d�faut
	CSommet(int idSommet);
	CSommet(int eId, int eSizeA, int eSizeP, CArc** listeArrivant, CArc** listePartant);
	CSommet(const CSommet& m); // Par recopie
	//~CSommet() throw(); // Destructeur

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
	void modifierArcArrivant(int indiceArc); // Modification d'un arc = Changement de liste
	void changeListeArrivant(CArc** liste, int sizeArrivant);
	void displayArcArrivant() const;

	void ajouterArcPartant(CArc* arc);
	void supprimerArcPartant(int indiceArc);
	void modifierArcPartant(int indiceArc); // Modification d'un arc = Changement de liste
	void changeListePartant(CArc** liste, int sizePartant);
	void displayArcPartant() const;
	ostream& display(ostream& os) const;
};

ostream& operator<<(ostream& os, CSommet const S);

#endif // !CSommet_h


#ifndef CGraphe_h
#define CGraphe_h
#include "CSommet.h"
using namespace std;

class CGraphe {

private:
	int eSizeListe; // Taille de la liste sommets
	CSommet* cSommetListe; // Liste de sommets

	// Accessors en prive pour des raisons d'allocation
	void setSommetListe(CSommet* liste);
	void setSizeListe(int size);
public:
	// Constructors
	CGraphe(); // Par défaut
	CGraphe(int sizeListe, CSommet* liste);
	CGraphe(const CGraphe& m); // Par recopie
	CGraphe(const char* filename) throw();
	~CGraphe(); // Destructeur

	//Accessors
	CSommet* getSommetListe();
	int getSizeListe();

	// Methods
	void modifierListe(CSommet* liste, int size);
	void allocListe();
	ostream& afficherGraphe(ostream& os) const throw();
};

// Surcharge pour afficher
ostream& operator<<(ostream& os, CGraphe const G);

#endif // !CGraphe_h


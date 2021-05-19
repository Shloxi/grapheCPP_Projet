#ifndef CGraphe_h
#define CGraphe_h
#include "CSommet.h"
using namespace std;

class CGraphe {

private:
	int eSize; // Taille de la liste sommets
	int eSizeDispo; // Taille dispo de la liste sommets
	CSommet** cSommetListe; // Liste de sommets

	// Accesseurs et methodes en prive pour des raisons de sécurité
	void setSommetListe(CSommet** liste);
	void setSize(int size);
	void setSizeDispo(int sizeDispo);
	void reallocListe(); // Reallocation de liste si eSizeDispo = eSize
public:
	// Constructors
	CGraphe(); // Par défaut
	CGraphe(int size, CSommet** liste);
	CGraphe(const CGraphe& m); // Par recopie
	CGraphe(const char* filename) throw();
	~CGraphe(); // Destructeur

	//Accessors
	CSommet** getSommetListe();
	int getSize();
	int getSizeDispo();

	// Methods
	void modifierListe(CSommet** liste, int size);
	ostream& afficherGraphe(ostream& os) const throw();
};

// Surcharge pour afficher
ostream& operator<<(ostream& os, CGraphe const G);

#endif // !CGraphe_h


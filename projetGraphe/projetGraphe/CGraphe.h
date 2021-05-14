#ifndef CGraphe_h
#define CGraphe_h
#include "CSommet.h"
using namespace std;

class CGraphe {

private:
	CSommet ** cSommetListe; // Liste de sommets

public:
	// Constructors
	CGraphe(); // Par défaut
	CGraphe(CSommet** liste);
	CGraphe(const CGraphe& m); // Par recopie
	/*
	Problèmes à identifier :	-) Le fichier n'existe pas
								-) Le fichier est vide
	*/
	CGraphe(const char* filename) throw();
	~CGraphe(); // Destructeur

	//Accesseurs
	

	// Methods
	ostream& afficherGraphe(ostream& os) const throw();
};

// Surcharge pour afficher
ostream& operator<<(ostream& os, CGraphe const G);

#endif // !CGraphe_h


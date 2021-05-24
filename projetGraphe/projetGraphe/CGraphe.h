#ifndef CGraphe_h
#define CGraphe_h
#include "CSommet.h"
using namespace std;

class CGraphe {

private:
	int eSize; // Taille de la liste sommets
	int eSizeDispo; // Taille dispo de la liste sommets
	CSommet** cSommetListe; // Liste de sommets

	// Accesseurs et methodes en prive pour des raisons de sécurité de gestion de liste
	void setSommetListe(CSommet** liste);
	void setSize(int size);
	void setSizeDispo(int sizeDispo);

public:
	// Constructors
	CGraphe(); // Par défaut
	CGraphe(int size, CSommet** liste);
	CGraphe(const CGraphe& m); // Par recopie
	//CGraphe(const char* filename) throw();
	//~CGraphe(); // Destructeur

	//Accessors
	CSommet** getSommetListe() const;
	int getSize() const;
	int getSizeDispo() const;

	// Methods
	void ajouterSommet(CSommet* sommet);
	void supprimerSommet(int indiceSommet);
	void modifierSommetId(int indiceSommet, int newId);
	void modifierSommetListe(CSommet** sommetListe, int size);
	CSommet* getSommet(int idSommet);
};

// Surcharge pour afficher
ostream& operator<<(ostream& os, CGraphe const G);

#endif // !CGraphe_h


#ifndef CGraphe_h
#define CGraphe_h
#include "CSommet.h"
using namespace std;

#define missingSommet 13
#define emptyList 3

class CGraphe {

private:
	int eSize; // Taille de la liste sommets
	int eSizeDispo; // Taille dispo de la liste sommets
	CSommet** cSommetListe; // Liste de sommets

	// Accesseurs et methodes en prive pour des raisons de securite de gestion de liste
	void setSommetListe(CSommet** liste);
	void setSize(int size);
	void setSizeDispo(int sizeDispo);

public:
	// Constructeurs
	CGraphe(); // Par d�faut
	CGraphe(int size, CSommet** liste);
	CGraphe(const CGraphe& m); // Par recopie
	CGraphe(const char* filename);
	~CGraphe(); // Destructeur

	// Accesseurs
	CSommet** getSommetListe() const;
	int getSize() const;
	int getSizeDispo() const;

	// Methodes
	void ajouterSommet(CSommet* sommet);
	void supprimerSommet(int indiceSommet);
	void modifierSommetId(int indiceSommet, int newId);
	void modifierSommetListe(CSommet** sommetListe, int size);
	CSommet* getSommet(int idSommet);
	int getSommet(CSommet* sommet);
	ostream& display(ostream& os) const;
};

// Surcharge pour afficher
ostream& operator<<(ostream& os, CGraphe* const G);

#endif // !CGraphe_h


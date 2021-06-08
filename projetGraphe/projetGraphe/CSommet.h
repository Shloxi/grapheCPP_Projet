#ifndef CSommet_h
#define CSommet_h
#include "CArc.h"
using namespace std;

// Constante d'erreurs liees aux operations sur un sommet
#define wrongIndiceSommet 11
#define wrongIndiceArc 21

class CSommet {

private:
	int eIdSommet; // Id du sommet

	int eSizeDispo; // Place dispo
	int eSize; // Place utilise
	CArc** cArcListe; // Liste des arcs

	// Accesseurs et methodes en prive pour des raisons de sécurite de gestion de liste
	void setArcListe(CArc** liste);
	void setSizeDispo(int sizeDispo);
	void setSize(int size);

public:
	// Constructeurs
	CSommet(); // Par defaut
	CSommet(int idSommet);
	CSommet(int eId, int eSize, CArc** liste);
	CSommet(const CSommet& m); // Par recopie
	~CSommet(); // Destructeur

	//Accesseurs
	int getIdSommet() const;
	void setIdSommet(int idSommet);

	int getSizeDispo() const;
	int getSize() const;
	CArc** getArcListe() const;
	

	//Methodes
	void ajouterArc(CArc* arc);
	void supprimerArc(int indiceArc);
	void modifierListe(CArc** liste, int size);
	ostream& display(ostream& os) const;
};

ostream& operator<<(ostream& os, CSommet* const S);

#endif // !CSommet_h


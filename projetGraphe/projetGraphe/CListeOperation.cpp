#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
using namespace std;

// Constantes d'erreurs liees aux operations sur des listes
#define badMalloc 1
#define wrongListIndice 2
#define emptyList 3

template <typename T> static T** reallocListe(T** liste, int* sizeDispo) {
	T** newListe; // On créer un nouveau pointeur
	*sizeDispo += 5;
	if (liste) { // Si on a une liste passe en parametre
		*sizeDispo += 5;
		newListe = (T**)realloc(liste, sizeof(T*) * *sizeDispo); // On realloue cette liste avec une taille plus grande
	}
	else {
		newListe = (T**)malloc(sizeof(T*) * *sizeDispo);  // Sinon on alloue une nouvelle liste
	}
	if (newListe == NULL) { // Si l'allocation ne fonctionne pas, on oublie pas de lancer une erreur
		*sizeDispo -= 5;
		throw CException(badMalloc); // Allocation raté
	}
	return newListe;
}

template <typename T> static T** ajouterListe(T** liste, int* sizeDispo, int* size, T* elem) {
	if (*size + 1 >= *sizeDispo) { // Si cette liste est à sa taille maximale
		T** res = reallocListe(liste, sizeDispo); // On utilise notre fonction de reallocation
		*size += 1;
		res[*size - 1] = elem;
		return res;
	} // Dans les deux cas on ajoute notre objet dans la liste et on la retourne
	*size += 1;
	liste[*size - 1] = elem;
	return liste;
}

template <typename T> static void supprimerListe(T** liste, int indiceArc, int* size) { 
	// On verifie que l'indice correspond a un objet existant
	if (indiceArc >= *size) {
		throw CException(wrongListIndice); // indice supérieur à la liste
	}
	// On verifie que la liste n'est pas vide
	if (*size == 0) {
		throw CException(emptyList); // liste vide
	}
	// On supprime l'element de la liste en decalant tous les autres elements
	for (int i = indiceArc + 1; i < *size; ++i) {
		liste[i - 1] = liste[i];
	}
	*size -= 1;
}

template <typename T> static void afficherListe(T** liste, const int size, const char typeListe[], ostream& os) {
	// Si la liste n'est pas vide on l'affiche
	if (size != 0)  {
		os << typeListe;
		for (int i = 0; i < size; ++i) {
			os << liste[i];
		}
		os << endl;
	}
}


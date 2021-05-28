#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
using namespace std;

template <typename T> static T** reallocListe(T** liste, int* sizeDispo) {
	T** newListe;
	*sizeDispo += 5;
	if (liste) {
		*sizeDispo += 5;
		newListe = (T**)realloc(liste, sizeof(T*) * *sizeDispo);
	}
	else {
		newListe = (T**)malloc(sizeof(T*) * *sizeDispo);
	}
	if (newListe == NULL) {
		*sizeDispo -= 5;
		throw CException(); // Allocation raté
	}
	return newListe;
}

template <typename T> static T** ajouterListe(T** liste, int* sizeDispo, int* size, T* elem) {
	if (*size + 1 >= *sizeDispo) {
		T** res = reallocListe(liste, sizeDispo);
		*size += 1;
		res[*size - 1] = elem;
		return res;
	}
	*size += 1;
	liste[*size - 1] = elem;
	return liste;
}

template <typename T> static void supprimerListe(T** liste, int indiceArc, int* size) {
	if (indiceArc >= *size) {
		throw CException(); // indice supérieur à la liste
	}
	if (*size == 0) {
		throw CException(); // liste vide
	}
	for (int i = indiceArc + 1; i < *size; ++i) {
		liste[i - 1] = liste[i];
	}
	*size -= 1;
}

template <typename T> static void afficherListe(T** liste, const int size, const char typeListe[], ostream& os) {
	if (size != 0)  {
		os << typeListe;
		for (int i = 0; i < size; ++i) {
			os << liste[i];
		}
		os << endl;
	}
}


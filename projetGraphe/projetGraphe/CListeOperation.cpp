#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
using namespace std;

template <typename T> static T** realloc(T** liste, int* sizeDispo) {
	*sizeDispo += 5;
	T** newListe;
	if (liste) {
		newListe = (T**)realloc(liste, sizeof(T*) * *sizeDispo);
	}
	else {
		newListe = (T**)malloc(sizeof(T*) * *sizeDispo);
	}
	if (newListe == NULL) {
		*sizeDispo -= 5;
		// Erreur
	}
	return newListe;
}

template <typename T> static T** ajouterListe(T** liste, int* sizeDispo, int* size, T* elem) {
	if (*size + 1 >= *sizeDispo) {
		T** res = realloc(liste, sizeDispo);
		*size += 1;
		res[*size - 1] = elem;
		return res;
		//setArcArrivant(liste);
	}
	*size += 1;
	liste[*size - 1] = elem;
	return liste;
}

template <typename T> static void supprimerListe(T** liste, int indiceArc, int* size) {
	if (indiceArc >= *size) {
		// Erreur
	}
	if (*size == 0) {
		// Erreur
	}
	for (int i = indiceArc + 1; i < *size; ++i) {
		liste[i - 1] = liste[i];
	}
	*size -= 1;
}

template <typename T> static void afficherListe(T** liste, const int size, const char typeListe[]) {
	if (size == 0) {
		//Erreur
	}
	else {
		cout << typeListe;
		for (int i = 0; i < size; ++i) {
			cout << *(liste[i]);
		}
		cout << endl;
	}
}

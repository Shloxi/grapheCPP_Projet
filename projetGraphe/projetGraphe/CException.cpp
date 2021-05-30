#include <stdio.h>
#include "CException.h"

// Construction
CException::CException() {
	eIndexError = 0;

	errors = new const char* [100];
	for (int i = 0; i < 100; ++i) {
		errors[i] = new char[100];
	}

	// Erreurs générales
	errors[1] = "Erreur : Allocation non réussie";
	errors[2] = "Erreur : Indice supérieur à la liste";
	errors[3] = "Erreur : Liste vide";
	errors[4] = "Erreur : Argument null";

	// Erreurs liee aux sommets 
	errors[11] = "Erreur : Identifiant de sommet negatif";
	errors[12] = "Erreur : Sommet deja existant";
	errors[13] = "Erreur : Sommet introuvable";

	// Erreurs liee aux arcs
	errors[21] = "Erreur : Identifiant d'arc négatif";
	errors[22] = "Erreur : Arc déjà existant";
	errors[23] = "Erreur : Arc introuvable";

	// Erreur liee au parseur
	errors[31] = "Erreur : Erreur de syntaxe";
	errors[32] = "Erreur : Le fichier spécifié est vide";
	errors[33] = "Erreur : Flux de lecture de fichier corrompu";
}

CException::CException(int eError) {
	eIndexError = eError;

	errors = new const char* [100];
	for (int i = 0; i < 100; ++i) {
		errors[i] = new char[100];
	}

	// Erreurs générales
	errors[1] = "Erreur : Allocation non réussie";
	errors[2] = "Erreur : Indice supérieur à la liste";
	errors[3] = "Erreur : Liste vide";
	errors[4] = "Erreur : Argument null";

	// Erreurs liee aux sommets 
	errors[11] = "Erreur : Identifiant de sommet negatif";
	errors[12] = "Erreur : Sommet deja existant";
	errors[13] = "Erreur : Sommet introuvable";

	// Erreurs liee aux arcs
	errors[21] = "Erreur : Identifiant d'arc négatif";
	errors[22] = "Erreur : Arc déjà existant";
	errors[23] = "Erreur : Arc introuvable";

	// Erreur liee au parseur
	errors[31] = "Erreur : Erreur de syntaxe";
	errors[32] = "Erreur : Le fichier spécifié est vide";
	errors[33] = "Erreur : Flux de lecture de fichier corrompu";
}

// Methods
void CException::ExceptModifErrorType(int eError) {
	eIndexError = eError;
}

int CException::ExceptGetIndexError() {
	return eIndexError;
}
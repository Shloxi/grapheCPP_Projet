#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
using namespace std; 

// Constantes d'erreurs liees aux parsages d'un fichier
#define syntaxError 31
#define emptyFileError 32
#define corruptFlow 33

static char** parser(const char* filename) {
	// On verifie que le nom du fichier n'est pas null
	if (filename == NULL) {
		throw CException(emptyFileError);
	}

	// On verifie que le flux crée est fonctionnelle
	ifstream monFlux(filename);
	if (!monFlux) {
		throw CException(corruptFlow);
	}
	char** valeurs; // Tableau de valeurs a retourner
	// On alloue dans la memoire ce tableau de valeurs qui sera libere dans l'analyseur syntaxique
	valeurs = new char * [100];
	for (int i = 0; i < 100; i++) {
		valeurs[i] = new char[20];
		for (int j = 0; j < 20; j++) {
			valeurs[i][j] = 0;
		}
	}
	char sOutput[50]; // Contenu du fichier
	int i = 0; // Indice de parcours du fichier
	int y = 0; // Indice de parcours des valeurs
	do {
		monFlux >> sOutput; // On récupère une ligne
		while (sOutput[i] != '=' && sOutput[i] != '\0') { // Tant qu'on atteint pas la fin de la ligne ou le début d'un valeur
			valeurs[y][i] = sOutput[i]; // On récupère les informations pour l'analyse de la syntaxe
			i++;
		}
		if (sOutput[i] != '\0') { // Si on est pas en fin de ligne / On a une valeur
			y++;
			int ecritureNombre = i + 1;
			i += 1;
			while (sOutput[i] != '\0' && sOutput[i] != ',') { // On écrit la totalité de la valeur, pas que un chiffre mais un nombre
				valeurs[y][0 + i - ecritureNombre] = sOutput[i];
				i++;
			}
			
		}
		valeurs[y][i + 1] = '\0'; // On termine chaque valeur par un caractère de fin de ligne
		y++;
		i = 0;
	} while (sOutput[0] != '\0'); // Tant qu'on est pas a la fin du fichier
	return valeurs;
}

static void compare(const char* s1, const char* s2) {
	int indice = 0;
	do {
		if (s1[indice] != s2[indice]) {
			throw CException(syntaxError);
		}
		indice++;
	} while (s2[indice] != '\0');
	if (s1[indice] != '\0') {
		throw CException(syntaxError);
	}
}
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CException.h"
using namespace std; 

static char** parser(const char* filename) {
	// On vérifie que le nom du fichier n'est pas null
	if (filename == NULL) {
		cout << "Fichier" << endl;
		throw CException();
	}

	// On vérifie que le flux crée est fonctionnelle
	ifstream monFlux(filename);
	if (!monFlux) {
		cout << "Flux" << endl;
		throw CException();
	}
	char** valeurs;
	valeurs = new char * [100];
	for (int i = 0; i < 100; i++) {
		valeurs[i] = new char[20];
		for (int j = 0; j < 20; j++) {
			valeurs[i][j] = 0;
		}
	}
	char sOutput[50]; // Contenu du fichier
	int i = 0; // indice de parcours du fichier
	int y = 0; // indice de parcours des valeurs
	do {
		monFlux >> sOutput;
		while (sOutput[i] != '=' && sOutput[i] != '\0') {
			valeurs[y][i] = sOutput[i];
			i++;
		}
		if (sOutput[i] != '\0') {
			y++;
			int ecritureNombre = i + 1;
			i += 1;
			while (sOutput[i] != '\0' && sOutput[i] != ',') {
				valeurs[y][0 + i - ecritureNombre] = sOutput[i];
				i++;
			}
			
		}
		valeurs[y][i + 1] = '\0';
		y++;
		i = 0;
	} while (sOutput[0] != '\0');
	return valeurs;
}

static void compare(const char* s1, const char* s2) {
	int indice = 0;
	do {
		if (s1[indice] != s2[indice]) {
			cout << s1 << " != " << s2 << endl;
			throw CException(); // Erreur de syntaxe
		}
		indice++;
	} while (s2[indice] != '\0');
	if (s1[indice] != '\0') {
		cout << s1 << " != " << s2 << endl;
		throw CException(); // Erreur de syntaxe
	}
}
#include <iostream>

#include <iostream>
#include "CGraphe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CCalculCouple.h"
#include "CGrapheOperation.cpp"
#include "CException.h"

int main(int argc, char** argv)
{
    cout << "Bienvenue sur le programme de Hugo PERVEYRIE et Romuald DURET !\n";
    if (argc == 1) {
        cout << "Vous n'avez pas rentrer d'argument" << endl;
        return 0;
    }
    else if (argc > 20) {
        cout << "Vous avez rentrer plus de 20 arguments" << endl;
        return 0;
    }
    else {
        // Creation des graphes
        int cptErreur = 0;
        int tailleTableau = 0;
        CGraphe** listeGraphe = (CGraphe**)malloc(sizeof(CGraphe*) * 20);
        if (!listeGraphe) {
            cout << "Erreur d'allocation dans le main" << endl;
            return 0;
        }
        for (int i = 0; i < argc - 1; ++i) {
            try {
                listeGraphe[i - cptErreur] = new CGraphe(argv[i + 1]);
                ++tailleTableau;
            }
            catch (CException e) {
                cerr << e.errors[e.ExceptGetIndexError()] << endl << endl;
                ++cptErreur;
            }
        }
        if (tailleTableau != 0) {
            try {
                for (int i = 0; i < tailleTableau; i++) {
                    cout << listeGraphe[i] << endl;
                    CCalculCouple* calculCouple = new CCalculCouple(listeGraphe[i]);
                    CGraphe* newGraphe = calculCouple->setToGraphe();
                    cout << "GRAPHE DE COUPLAGE MAXIMAL :" << endl;
                    cout << newGraphe << endl;
                    delete newGraphe;
                    delete calculCouple;
                }
            }
            catch (CException e) {
                cerr << e.errors[e.ExceptGetIndexError()] << endl << endl;
            }
            for (int i = 0; i < tailleTableau; i++) {
                delete listeGraphe[i];
            }
            free(listeGraphe);
        }
        return 0;
    }
}

#include <iostream>

#include "windows.h"
#define _CRTDBG_MAP_ALLOC //to get more details
#include <crtdbg.h>   //for malloc and free

#include "CGraphe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CGrapheOperation.cpp"
#include "CException.h"

int main()
{
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sOld); //take a snapchot
    CGraphe* graphe = new CGraphe();
    try {
        ajouterSommet(graphe, 1);
        ajouterSommet(graphe, 2);
        ajouterSommet(graphe, 3);
        ajouterSommet(graphe, 4);
        // On ne peut pas ajouter plusieurs même sommet
        //ajouterSommet(graphe, 4);
        ajouterArc(graphe->getSommet(1), graphe->getSommet(2));
        ajouterArc(graphe->getSommet(1), graphe->getSommet(3));
        ajouterArc(graphe->getSommet(2), graphe->getSommet(3));
        ajouterArc(graphe->getSommet(2), graphe->getSommet(4));
        ajouterArc(graphe->getSommet(4), graphe->getSommet(3));
        ajouterArc(graphe->getSommet(4), graphe->getSommet(1));
        // Suppression fonctionnelle
        //supprimerArc(graphe->getSommet(4), graphe->getSommet(3));
        // Suppression introuvable avec throw()
        //supprimerArc(graphe->getSommet(4), graphe->getSommet(2));
        cout << graphe << endl;
        //reverseGraphe(graphe);
        //cout << *graphe << endl;
        //reverseGraphe(graphe);
        supprimerSommet(graphe, graphe->getSommet(2));
        cout << graphe << endl;
        delete graphe;
        _CrtMemCheckpoint(&sNew); //take a snapchot
    }
    catch (CException e) {
        cout << e.ExceptGetIndexError() << endl;
    }
    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
    {
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
        _CrtMemDumpAllObjectsSince(&sOld);
        OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();
    }
    
    std::cout << "Hello World!\n";
}

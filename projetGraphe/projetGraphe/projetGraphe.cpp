#include <iostream>

#include "windows.h"
#define _CRTDBG_MAP_ALLOC //to get more details
#include <crtdbg.h>   //for malloc and free

#include <iostream>
#include "CGraphe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CCalculCouple.h"
#include "CGrapheOperation.cpp"
#include "CException.h"

int main(int argc, char** argv)
{
    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    cout << "Bienvenue sur le programme de Hugo PERVEYRIE et Romuald DURET !\n";
    // Création des graphes
    _CrtMemCheckpoint(&sOld); //take a snapshot
    try {
        CGraphe* graphe1 = new CGraphe("grapheToWrite.txt");
        cout << graphe1 << endl;
        CCalculCouple* calculCouple = new CCalculCouple(graphe1);
        CGraphe* newGraphe = calculCouple->setToGraphe();
        cout << "GRAPHE DE COUPLAGE MAXIMAL :" << endl;
        cout << newGraphe << endl;
        delete graphe1;
        delete newGraphe;
        _CrtMemCheckpoint(&sNew); //take a snapshot
    }
    catch (CException e) {
        cerr << e.errors[e.ExceptGetIndexError()] << endl << endl;
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
    return 0;
}

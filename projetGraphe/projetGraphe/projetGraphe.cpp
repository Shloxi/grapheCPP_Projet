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
    try {
        CGraphe* graphe = new CGraphe("grapheToWrite.txt");
        cout << graphe << endl;
        reverseGraphe(graphe);
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
}

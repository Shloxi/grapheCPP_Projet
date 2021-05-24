#include <iostream>
#include "CGraphe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CGrapheOperation.cpp"
#include "CException.h"

int main()
{
    CGraphe* graphe = new CGraphe();
    try {
        ajouterSommet(graphe, 1);
        ajouterSommet(graphe, 2);
        ajouterSommet(graphe, 3);
        ajouterSommet(graphe, 4);
        // On ne peut pas ajouter plusieurs même sommet
        //ajouterSommet(graphe, 4);
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
        supprimerSommet(graphe, graphe->getSommet(2));
    }
    catch (CException e) {
        cout << e.ExceptGetIndexError() << endl;
    }
    cout << *graphe << endl;
    /*
    CArc* arc1 = new CArc(2);
    CArc* arc2 = new CArc(3);
    CArc* arc3 = new CArc(1);
    
    CSommet* sommet1 = new CSommet(1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc2);
    sommet1->ajouterArcPartant(arc2);
    sommet1->ajouterArcPartant(arc2);
    sommet1->ajouterArcPartant(arc1);
    sommet1->supprimerArcPartant(0);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcPartant(arc1);
    sommet1->ajouterArcArrivant(arc3);

    CSommet* sommet2 = new CSommet(2);
    sommet2->ajouterArcArrivant(arc1);

    CSommet* sommet3 = new CSommet(3);
    sommet3->ajouterArcArrivant(arc2);

    CSommet* sommet4 = new CSommet(4);
    sommet4->ajouterArcPartant(arc3);

    // Test recopie
    CSommet* sommet5 = new CSommet(*sommet1);
    sommet5->setIdSommet(5);
    sommet5->supprimerArcPartant(0);

    CGraphe* graphe1 = new CGraphe();
    graphe1->ajouterSommet(sommet1);
    graphe1->ajouterSommet(sommet2);
    graphe1->ajouterSommet(sommet3);
    graphe1->ajouterSommet(sommet4);
    graphe1->ajouterSommet(sommet5);

    CGraphe* graphe2 = new CGraphe(*graphe1);
    graphe2->supprimerSommet(0);
    //graphe2->modifierSommet();

    std::cout << *graphe1 << std::endl;
    std::cout << *graphe2 << std::endl;
    */
    std::cout << "Hello World!\n";
}

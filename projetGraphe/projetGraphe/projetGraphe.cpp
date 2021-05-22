#include <iostream>
#include "CGraphe.h"
#include "CException.h"

int main()
{
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

    CGraphe* graphe = new CGraphe();
    graphe->ajouterSommet(sommet1);
    graphe->ajouterSommet(sommet2);
    graphe->ajouterSommet(sommet3);
    graphe->ajouterSommet(sommet4);

    std::cout << *graphe << std::endl;
    std::cout << "Hello World!\n";
}

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
    sommet1->ajouterArcArrivant(arc3);
    std::cout << "Etat Sommet " << sommet1->getIdSommet() << std::endl;
    std::cout << "sizePartant : " << sommet1->getSizePartant() << std::endl;
    std::cout << "sizeDispoPartant : " << sommet1->getSizeDispoPartant() << std::endl;
    std::cout << "sizeArrivant : " << sommet1->getSizeArrivant() << std::endl;
    std::cout << "sizeDispoArrivant : " << sommet1->getSizeDispoArrivant() << std::endl;
    sommet1->displayArcArrivant();
    sommet1->displayArcPartant();
    std::cout << std::endl;

    CSommet* sommet2 = new CSommet(2);
    sommet2->ajouterArcArrivant(arc1);
    std::cout << "Etat Sommet " << sommet2->getIdSommet() << std::endl;
    std::cout << "sizePartant : " << sommet2->getSizePartant() << std::endl;
    std::cout << "sizeDispoPartant : " << sommet2->getSizeDispoPartant() << std::endl;
    std::cout << "sizeArrivant : " << sommet2->getSizeArrivant() << std::endl;
    std::cout << "sizeDispoArrivant : " << sommet2->getSizeDispoArrivant() << std::endl;
    sommet2->displayArcArrivant();
    sommet2->displayArcPartant();
    std::cout << std::endl;

    CSommet* sommet3 = new CSommet(3);
    sommet3->ajouterArcArrivant(arc2);

    std::cout << "Etat Sommet " << sommet3->getIdSommet() << std::endl;
    std::cout << "sizePartant : " << sommet3->getSizePartant() << std::endl;
    std::cout << "sizeDispoPartant : " << sommet3->getSizeDispoPartant() << std::endl;
    std::cout << "sizeArrivant : " << sommet3->getSizeArrivant() << std::endl;
    std::cout << "sizeDispoArrivant : " << sommet3->getSizeDispoArrivant() << std::endl;
    sommet3->displayArcArrivant();
    sommet3->displayArcPartant();
    std::cout << std::endl;

    CSommet* sommet4 = new CSommet(4);
    sommet4->ajouterArcPartant(arc3);

    std::cout << "Etat Sommet " << sommet4->getIdSommet() << std::endl;
    std::cout << "sizePartant : " << sommet4->getSizePartant() << std::endl;
    std::cout << "sizeDispoPartant : " << sommet4->getSizeDispoPartant() << std::endl;
    std::cout << "sizeArrivant : " << sommet4->getSizeArrivant() << std::endl;
    std::cout << "sizeDispoArrivant : " << sommet4->getSizeDispoArrivant() << std::endl;
    sommet4->displayArcArrivant();
    sommet4->displayArcPartant();
    std::cout << std::endl;

    std::cout << "Hello World!\n";
}

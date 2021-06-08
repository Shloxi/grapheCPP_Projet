#ifndef CCalculCouple_h
#define CCalculCouple_h
#include "CArc.h"
#include "CSommet.h"
#include "CGraphe.h"

class CCalculCouple
{
private :
	CGraphe* cGraphe;

	CArc** listeArcGraphe;
	int eSize;
	int eSizeDispo;

	CArc** listeCouplageMax;
	int eSizeCouplage;
	int eSizeDispoCouplage;
public :
	CCalculCouple(CGraphe* G);
	void calcCoupMax(CArc** couplage, int sizeCouplage, int sizeDispoCouplage);
	CArc** getListeCouplageMax();
	int getSizeCouplage();
	CGraphe* setToGraphe();
};

#endif // !CCalculCouple_h


#ifndef CArc_h
#define CArc_h
using namespace std;

// Constante d'erreurs liees aux operations sur un arc
#define wrongIndiceArc 21

class CArc {

private:
	int eIdDest; // Id du sommet de destination

public:
	// Constructeurs
	CArc(); // Par defaut
	CArc(int eId);
	CArc(const CArc& a); // Par recopie

	// Accesseurs
	int getIdDest() const;
	void setIdDest(int eId);
	ostream& display(ostream& os) const;
};

ostream& operator<<(ostream& os, CArc* const A);

#endif // !CArc_h


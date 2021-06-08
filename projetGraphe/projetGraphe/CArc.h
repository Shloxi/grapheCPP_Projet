#ifndef CArc_h
#define CArc_h
using namespace std;

// Constante d'erreurs liees aux operations sur un arc
#define wrongIndiceArc 21

class CArc {

private:
	int eIdSommet1; // Id du sommet 1
	int eIdSommet2; // Id du sommet 2

public:
	// Constructeurs
	CArc(); // Par defaut
	CArc(int eId1, int eId2);
	CArc(const CArc& a); // Par recopie

	// Accesseurs
	int getId1() const;
	void setId1(int eId);
	int getId2() const;
	void setId2(int eId);
};

#endif // !CArc_h


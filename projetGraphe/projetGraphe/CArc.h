#ifndef CArc_h
#define CArc_h
using namespace std;

class CArc {

private:
	int eIdDest; // Id du sommet de destination

public:
	// Constructeurs
	CArc(); // Par défaut
	CArc(int eId);
	CArc(const CArc& m); // Par recopie

	// Accesseurs
	int getIdDest() const;
	void setIdDest(int eId);
};

ostream& operator<<(ostream& os, CArc const A);

#endif // !CArc_h


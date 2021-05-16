#ifndef CArc_h
#define CArc_h
using namespace std;

class CArc {

private:
	int eIdDest; // Id du sommet de destination

public:
	// Constructors
	CArc(); // Par défaut
	CArc(int eId);
	CArc(const CArc& m); // Par recopie

	//Accessors
	int getIdDest();
	void setIdDest(int eId);
};

#endif // !CArc_h


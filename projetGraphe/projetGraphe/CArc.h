#ifndef CArc_h
#define CArc_h
using namespace std;

class CArc {

private:
	int eIdDest; // Id du sommet de destination

public:
	// Constructors
	CArc(); // Par défaut
	CArc(int eIdDest);
	CArc(const CArc& m); // Par recopie
	~CArc(); // Destructeur

	//Accesseurs
	int getIdDest();
	void setIdDest(int eIdDest);

	// Methods
};

#endif // !CArc_h


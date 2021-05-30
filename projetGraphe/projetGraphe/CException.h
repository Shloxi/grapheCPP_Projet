#ifndef CException_h
#define CException_h

class CException
{
private:
	int eIndexError;


public:
	const char** errors;

	// Constructeurs
	CException();
	CException(int eError);

	// Methodes 
	void ExceptModifErrorType(int eErrorType);
	int ExceptGetIndexError();

};

#endif // !CException_h

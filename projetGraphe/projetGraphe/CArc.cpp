#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CArc.h"
#include "CException.h"
using namespace std;

/*
##################
  CONSTRUCTEURS
##################
*/
CArc::CArc() {
	eIdDest = -1;
}

CArc::CArc(int eId) {
	eIdDest = eId;
}

CArc::CArc(const CArc& m) {
	eIdDest = m.eIdDest;
}

/*
##################
	ACCESSEURS
##################
*/
int CArc::getIdDest() const {
	return eIdDest;
}

void CArc::setIdDest(int eId) {
	eIdDest = eId;
}

ostream& CArc::display(ostream& os) const {
	if (eIdDest == -1) {
		throw CException(); // idArc négative
	}
	else {
		os << eIdDest << " ";
	}
}

ostream& operator<<(ostream& os, CArc* const A) {
	A->display(os);
	return os;
}
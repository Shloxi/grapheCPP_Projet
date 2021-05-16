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
	ACCESSORS
##################
*/
int CArc::getIdDest() {
	return eIdDest;
}

void CArc::setIdDest(int eId) {
	eIdDest = eId;
}
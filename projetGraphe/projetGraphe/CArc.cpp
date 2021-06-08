
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "CArc.h"
#include "CException.h"
using namespace std;

CArc::CArc() {
	eIdSommet1 = -1;
	eIdSommet2 = -1;
}

CArc::CArc(int eId1, int eId2) {
	eIdSommet1 = eId1;
	eIdSommet2 = eId2;
}

CArc::CArc(const CArc& a) {
	eIdSommet1 = a.eIdSommet1;
	eIdSommet2 = a.eIdSommet2;
}


int CArc::getId1() const {
	return eIdSommet1;
}

void CArc::setId1(int eId) {
	eIdSommet1 = eId;
}

int CArc::getId2() const {
	return eIdSommet2;
}

void CArc::setId2(int eId) {
	eIdSommet2 = eId;
}
#pragma once

#include "Includes.h"
#include "Bicicleta.h"

struct bikeHash
{
	int operator() (const Bicicleta & bic) const
	{
		string s1 = bic.getBikeName();
		int v = 0;
		for ( unsigned int i=0; i< s1.size(); i++ )
			v = 37*v + s1[i];
		return v;
	}

	bool operator() (const Bicicleta & b1, const Bicicleta & b2) const
	{
		return b1.getBikeName() == b2.getBikeName();
	}
};

typedef unordered_set<Bicicleta, bikeHash, bikeHash> tabHAbates;

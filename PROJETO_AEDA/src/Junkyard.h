#pragma once

#include "Includes.h"
#include "Bicicleta.h"

struct bikeHash
{
	int operator() (const Bicicleta & ap) const
	{
		return 0;
	}

	bool operator() (const Bicicleta & ap1, const Bicicleta & ap2) const
	{
		return true;
	}
};

typedef unordered_set<Bicicleta, bikeHash, bikeHash> tabHAbates;

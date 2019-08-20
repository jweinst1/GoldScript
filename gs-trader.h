#ifndef GOLDSCRIPT_GS_TRADER_H
#define GOLDSCRIPT_GS_TRADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct __gs_trader
{
	double cash;
	double supply;
	double demand;
	struct __gs_trader* next;
};

typedef struct __gs_trader gs_trader_t;

#endif // GOLDSCRIPT_GS_TRADER_H
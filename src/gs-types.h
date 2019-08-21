#ifndef GOLDSCRIPT_GS_TYPES_H
#define GOLDSCRIPT_GS_TYPES_H

#include <stdlib.h>


struct __gs_trader
{
	double cash;
	struct __gs_trader* next;
};

typedef struct __gs_trader gs_trader_t;

typedef enum __gs_rule_op_type
{
	GOLDSCRIPT_IS_EQ
} gs_rule_op_type_t;

struct __gs_rule_op
{
	double value;
};

#endif // GOLDSCRIPT_GS_TYPES_H
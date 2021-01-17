#include "exce.h"

void exception(const char* exce_str)
{
	fprintf(stderr, "%s\n", exce_str);
	exit(EXIT_FAILURE);
}
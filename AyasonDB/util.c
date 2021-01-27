#include "util.h"

size_t align16(size_t size)
{
	return ((size >> 4) << 4) + 16;
}

int sgn(const int value)
{
	if (value > 0)
		return 1;
	else if (value < 0)
		return -1;
	return value;
}

size_t sizet_min(const size_t a, const size_t b)
{
	return a < b ? a : b;
}

size_t sizet_max(const size_t a, const size_t b)
{
	return a > b ? a : b;
}
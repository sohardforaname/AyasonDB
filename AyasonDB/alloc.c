#include "alloc.h"

void* allocate(size_t size)
{
	return malloc(size);
}

void deallocate(void* ptr)
{
	if (ptr)
		free(ptr);
}
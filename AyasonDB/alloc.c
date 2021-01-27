#include "alloc.h"

void* allocate(size_t size)
{
	return malloc(size);
}

void* reallocate(void* buf, size_t size)
{
	return realloc(buf, size);
}

void deallocate(void* ptr)
{
	free(ptr);
}
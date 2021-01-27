#pragma once

#include <stdlib.h>

void* allocate(size_t size);
void* reallocate(void* buf, size_t size);
void deallocate(void* ptr);
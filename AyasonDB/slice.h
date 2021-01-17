#pragma once

#include <string.h>
#include "str.h"
#include "exce.h"
#include "util.h"

typedef struct slice
{
	const unsigned char* ptr;
	size_t size;
} slice;

void slice_remove_prefix(slice* sli, size_t size);
string* slice_to_string(const slice* sli);
int slice_check_prefix(
	const slice* sli,
	const unsigned char* str,
	size_t size
);
int slice_compare(const slice* lsli, const slice* rsli);
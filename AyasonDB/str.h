#pragma once

#include <string.h>
#include <stdlib.h>
#include <intrin.h>
#include "exce.h"

typedef struct string
{
	unsigned char* buf;
	size_t size, capacity;
} string;

string* string_create_by_cstr(const char* c_str);
string* string_create_by_char(const char ch, const size_t size);
string* string_copy(const string* str);
string* string_append(const string* str);
const char* string_to_cstr(const string* str);
size_t string_get_size(const string* str);
size_t string_hash(const string* str);
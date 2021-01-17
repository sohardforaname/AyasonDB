#pragma once

#include <string.h>
#include "alloc.h"
#include "exce.h"
#include "util.h"

typedef struct string
{
	unsigned char* buf;
	size_t size, capacity;
} string;

string* string_create_by_cstr(const char* c_str);
string* string_create_by_char(const char ch, const size_t size);
string* string_create_by_cstr_part(const char* c_str, size_t size);
string* string_copy(const string* str);
void string_destroy(string** str);
void string_append(string* lstr, const string* rstr);
const char* string_to_cstr(const string* str);
size_t string_get_size(const string* str);
size_t string_hash(const string* str);
int string_compare(const string* lstr, const string* rstr);
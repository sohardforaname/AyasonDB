#include "str.h"

const size_t extra_size = 16;

string* string_create(const size_t size)
{
	string* new_str = (string*)allocate(sizeof(string));
	check_pointer(new_str, "string", "create", "malloc failed");
	new_str->size = size;
	new_str->capacity = align16(new_str->size) + extra_size;
	new_str->buf = (unsigned char*)allocate(
		sizeof(unsigned char) * (new_str->capacity)
	);
	check_pointer(new_str->buf, "string", "create", "buffer malloc failed");
	return new_str;
}

void reserve(string* str, const size_t size)
{
	if (str->capacity > size)
		return;
	size_t new_capacity = align16(size) + extra_size;
	unsigned char* new_buf = (unsigned char*)reallocate(
		str->buf,
		sizeof(unsigned char) * new_capacity
	);
	check_pointer(new_buf, "string buffer", "reserve", "realloc failed");
	str->capacity = new_capacity;
	str->buf = new_buf;
}

string* string_create_by_cstr(const char* c_str)
{
	string* new_str = string_create(strlen(c_str));
	memcpy(new_str->buf, c_str, sizeof(unsigned char) * new_str->size);
	new_str->buf[new_str->size] = '\0';
	return new_str;
}

string* string_create_by_char(const char ch, const size_t size)
{
	string* new_str = string_create(size);
	memset(new_str->buf, ch, sizeof(unsigned char) * new_str->size);
	new_str->buf[new_str->size] = '\0';
	return new_str;
}

string* string_create_by_cstr_part(const char* c_str, size_t size)
{
	string* new_str = string_create(sizet_min(size, strlen(c_str)));
	memcpy(new_str->buf, c_str, sizeof(unsigned char) * new_str->size);
	new_str->buf[new_str->size] = '\0';
	return new_str;
}

string* string_copy(const string* str)
{
	string* new_str = string_create(str->size);
	memcpy(new_str->buf, str->buf, sizeof(unsigned char) * str->size);
	new_str->buf[new_str->size] = '\0';
	return str;
}

void string_destroy(string** str)
{
	if (!str || !(*str))
		return;
	deallocate((*str)->buf);
	deallocate(*str);
	*str = NULL;
}

void string_append(string* lstr, const string* rstr)
{
	check_pointer(lstr && rstr, "string", "append", NULL);
	reserve(lstr, lstr->size + rstr->size);
	memcpy(lstr->buf + lstr->size, rstr->buf, sizeof(unsigned char) * rstr->size);
	lstr->size += rstr->size;
	lstr->buf[lstr->size] = '\0';
}

const char* string_to_cstr(const string* str)
{
	return str->buf;
}

size_t string_get_size(const string* str)
{
	return str->size;
}

size_t string_hash(const string* str)
{
	if (!str)
		return 0;
	size_t hash = 0, size = str->size;
	unsigned char* ptr = str->buf;
	while (*ptr)
		hash = hash * 131 + *(ptr++);
	return hash;
} 

int string_compare(const string* lstr, const string* rstr)
{
	check_pointer(lstr && rstr, "string", "compare", NULL);
	int comp1 = sgn(lstr->size - rstr->size);
	if (comp1)
		return comp1;
	check_pointer(lstr->buf && rstr->buf, "string", "compare", "buffer nullptr");
	return sgn(
		memcmp(
		lstr->buf,
		rstr->buf,
		sizeof(unsigned char) * lstr->size
		)
	);
}
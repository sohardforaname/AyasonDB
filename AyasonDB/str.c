#include "str.h"

const size_t extra_size = 16;
inline size_t align16(size_t size)
{
	return ((size >> 4) << 4) + 16;
}

inline string* string_create(const size_t size)
{
	string* new_str = (string*)malloc(sizeof(string));
	if (!new_str)
		exception("string malloc error");
	new_str->size = size;
	new_str->capacity = align16(new_str->size) + extra_size;
	new_str->buf = (unsigned char*)malloc(
		sizeof(unsigned char) * (new_str->capacity)
	);
	if (!new_str->buf)
		exception("string buffer malloc error");
	return new_str;
}

inline void reserve(string* str, const size_t size)
{
	if (str->capacity > size)
		return;
	str->capacity = align16(size) + extra_size;
	unsigned char* new_buf = (unsigned char*)realloc(
		str->buf,
		sizeof(unsigned char) * str->capacity
	);
	if (!new_buf)
		exception("string reserve buffer error");
	str->buf = new_buf;
}

inline string* string_create_by_cstr(const char* c_str)
{
	string* new_str = string_create(strlen(c_str));
	memcpy(new_str->buf, c_str, new_str->size);
	new_str->buf[new_str->size] = '\0';
	return new_str;
}
inline string* string_create_by_char(const char ch, const size_t size)
{
	string* new_str = string_create(size);
	memset(new_str->buf, ch, sizeof(unsigned char) * new_str->size);
	new_str->buf[new_str->size] = '\0';
	return new_str;
}
inline string* string_copy(const string* str)
{
	string* new_str = string_create(str->size);
	memcpy(new_str->buf, str->buf, sizeof(str->size));
	new_str->buf[new_str->size] = '\0';
	return str;
}
inline string* string_append(const string* str)
{

}
inline const char* string_to_cstr(const string* str)
{
	return str->buf;
}
inline size_t string_get_size(const string* str)
{
	return str->size;
}
inline size_t string_hash(const string* str)
{
	if (!str)
		return 0;
	size_t hash = 0, size = str->size;
	unsigned char* ptr = str->buf;
	while (*ptr)
		hash = hash * 131 + *(ptr++);
	return hash;
} 
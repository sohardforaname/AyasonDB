#include "str.h"

int main()
{
	string* s = string_create_by_cstr("hello");
	string* s1 = string_create_by_char('c', 5);
	string* s2 = string_create_by_cstr_part(" world  ", 7);
	printf("%llu\n", string_get_size(s));
	string_append(s, s2);
	printf("%llu\n", string_hash(s));
	printf("%d\n", string_compare(s, s1));
	string_append(s, s1);
	printf("%s\n", string_to_cstr(s));
	string* ss = string_copy(s);
	printf("%s\n", string_to_cstr(ss));
	string_destroy(&s1);
	string_destroy(&s2);
	string_destroy(&ss);
	string_destroy(NULL);
	return 0;
}
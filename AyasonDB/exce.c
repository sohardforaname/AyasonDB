#include "exce.h"

void exception(const char* exce_str)
{
	fprintf(stderr, "%s\n", exce_str);
	exit(EXIT_FAILURE);
}

void check_pointer(
	void* ptr,
	const char* struct_name,
	const char* func_name,
	const char* extra_info
)
{
	if (!ptr)
	{
		fprintf(
			stderr, 
			"%s nullptr error in %s\n", 
			struct_name,
			func_name
		);
		if (extra_info)
			fprintf(stderr, "detailed info: %s\n", extra_info);
		exit(EXIT_FAILURE);
	}
}
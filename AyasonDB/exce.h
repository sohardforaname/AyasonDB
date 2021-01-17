#pragma once

#include <stdlib.h>
#include <stdio.h>

void exception(const char* exce_str);
void check_pointer(
	void* ptr, 
	const char* struct_name, 
	const char* func_name,
	const char* extra_info
);

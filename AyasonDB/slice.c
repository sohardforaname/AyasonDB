#include "slice.h"

void slice_remove_prefix(slice* sli, size_t size)
{
	check_pointer(sli, "slice", "remove prefix", NULL);
	if (sli->size < size)
		exception("slice too small size in remove perfix");
	sli->ptr += size;
	sli->size -= size;
}
string* slice_to_string(const slice* sli)
{
	check_pointer(sli, "slice", "copy", NULL);
	return string_create_by_cstr_part(sli->ptr, sli->size);
}
int slice_check_prefix(
	const slice* sli, 
	const unsigned char* str, 
	size_t size
)
{
	check_pointer(sli && str, "slice", "check_prefix", NULL);
	return sli->size >= size 
		&& !memcmp(sli->ptr, str, sizeof(unsigned char) * size);
}
int slice_compare(const slice* lsli, const slice* rsli)
{
	check_pointer(lsli && rsli, "slice", "compare", NULL);
	int comp1 = sgn(lsli->size - rsli->size);
	if (comp1)
		return comp1;
	check_pointer(lsli->ptr && rsli->ptr, "slice", "compare", "buffer nullptr");
	return sgn(
		memcmp(
			lsli->ptr,
			rsli->ptr,
			sizeof(unsigned char) * lsli->size
		)
	);
}
#include <stddef.h>
#include <stdio.h>

#define COUPON_COUNT 3

struct tree {
	size_t multi;
	struct tree **children;
	struct suborder {
		int bad;
		int *nextset;
	} solv[COUPON_COUNT];
};

struct tree *read_tree(FILE *input);
void destroy_tree(struct tree *work);

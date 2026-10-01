#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "employees.h"

struct tree *read_tree (FILE *input)
{
	int _get_num(FILE *);

	int multi, i, coupon;
	struct tree *prod;
	bool failed;

	if ((multi = _get_num(input)) < 0)
		return NULL;
	prod = malloc(sizeof(struct tree));
	prod->multi = multi;
	prod->children = multi ? malloc(sizeof(struct tree *) * multi) : NULL;
	failed = false;
	for (i = 0; i < multi; i++) {
		if (failed) {
			prod->children[i] = NULL;
			continue;
		}
		if ((prod->children[i] = read_tree(input)) == NULL)
			failed = true;
	}
	for (coupon = 0; coupon < COUPON_COUNT; coupon++) {
		prod->solv[coupon].bad = 0;
		prod->solv[coupon].nextset = NULL;
	}
	if (failed) {
		destroy_tree(prod);
		return NULL;
	}
	return prod;
}

void destroy_tree (struct tree *work)
{
        int cidx, coupon;

	if (work == NULL)
		return;

	for (cidx = 0; cidx < work->multi; cidx++)
		destroy_tree(work->children[cidx]);
	free(work->children);
	for (coupon = 0; coupon < COUPON_COUNT; coupon++)
		free(work->solv[coupon].nextset);
	free(work);
}

int _get_num (FILE *input)
{
	int num;
	int c;

	while (isspace(c = getchar()))
		;
	if (!isdigit(c))
		return -1;
	num = c - '0';
	while (isdigit(c = getchar()))
		num = 10 * num + c - '0';
	ungetc(c, input);
	return num;
}

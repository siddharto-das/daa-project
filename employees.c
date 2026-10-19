#define _POSIX_C_SOURCE 202405L

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include "employees.h"

int main ()
{
	void postorder_act(struct tree *, void (*)(struct tree *));
	void compute_order(struct tree *);
	void write_tree(struct tree *, int);

	struct tree *employees;
	int coupon;
	int min, min_coupon;

	setlocale(LC_ALL, "C.UTF-8");
	employees = read_tree(stdin);
	if (employees == NULL) {
		fprintf(stderr, "cannot convert input to tree\n");
		return 1;
	}
	postorder_act(employees, compute_order);

	min = -1;
	for (coupon = 0; coupon < COUPON_COUNT; coupon++) {
		if (min < 0 || employees->solv[coupon].bad < min) {
			min = employees->solv[coupon].bad;
			min_coupon = coupon;
		}
	}
	write_tree(employees, min_coupon);
	destroy_tree(employees);

	return 0;
}

void postorder_act (struct tree *work, void (*action)(struct tree *))
{
	size_t i;
	for (i = 0; i < work->multi; i++)
		postorder_act(work->children[i], action);
	(*action)(work);
}

void compute_order (struct tree *work)
{
	size_t cidx;
	struct tree *child;
	int curr, comp;
	int min, min_coupon;
	int more_bad;
	int angry;

	if (work->multi > 0) {
		for (curr = 0; curr < COUPON_COUNT; curr++) {
			work->solv[curr].bad = 0;
			work->solv[curr].nextset = malloc(
			    sizeof(int) * work->multi);
			for (cidx = 0; cidx < work->multi; cidx++) {
				child = work->children[cidx];
				min = -1;
				angry = 0;
				for (comp = 0; comp < COUPON_COUNT;
				    comp++) {
					if (curr == comp) {
						angry++;
						continue;
					}
					more_bad =
					    child->solv[comp].bad +
					    angry;
					if (min < 0 || more_bad < min) {
						min = more_bad;
						min_coupon = comp;
					}
				}
				work->solv[curr].bad += min;
				work->solv[curr].nextset[cidx] =
				    min_coupon;
			}
		}
	}
}

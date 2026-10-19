#define _POSIX_C_SOURCE 202405L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "employees.h"

void write_tree (struct tree *work, int spec)
{
	void _write_tree_r(struct tree *, int, const wchar_t *, bool);
	_write_tree_r(work, spec, NULL, true);
}

void _write_tree_r (struct tree *work, int spec, const wchar_t *prefix,
    bool fin)
{
	size_t cidx;
	wchar_t *newpre;
	printf("%ls%ls%d\n", prefix == NULL ? L"" : prefix,
	    prefix == NULL ? L"" :
		fin	   ? L"└── " :
			     L"├── ",
	    1000 * (spec + 1));
	if (work->multi) {
		if (prefix == NULL)
			newpre = L"";
		else {
			newpre = malloc(
			    sizeof(wchar_t) * (wcslen(prefix) + 5));
			wcscpy(wcpcpy(newpre, prefix),
			    fin ? L"    " : L"│   ");
		}
		for (cidx = 0; cidx < work->multi - 1; cidx++)
			_write_tree_r(work->children[cidx],
			    work->solv[spec].nextset[cidx], newpre,
			    false);
		_write_tree_r(work->children[cidx],
		    work->solv[spec].nextset[cidx], newpre, true);
		if (prefix != NULL)
			free(newpre);
	}
}

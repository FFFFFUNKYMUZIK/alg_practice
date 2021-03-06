#include "stdafx.h"

/*
For C programmers, try to solve it in-place in O(1) extra space.
*/

char * reverseWords(char * s) {
	
	char* p = s;
	while (*p != '\0') p++;

	if (p == s) return s;

	char* l = s, *r = p - 1;
	char tmp;
	while (l<r) {
		tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}

	l = s;
	char* np = s;
	char* e;

	while (l < p) {
		if (*l == ' ') {
			l++;
			continue;
		}
		e = l;
		while (e < p && *e != ' ') e++;
		r = e - 1;

		while (r >= l && r>np) {
			tmp = *np;
			*np = *r;
			*r = tmp;
			np++;
			r--;
		}
		if (r < np) {
			np += (np - l + 1);
		}
		else if (r == np) {
			np += (np - l + 2);
		}
		else np++;

		l = e + 1;
	}

	if (np == s) {
		*np = '\0';
	}
	else if (np-1 < p) {
		*(np-1) = '\0';
	}

	return s;
}

int main()
{
	char* ret;
	char in1[] = "the sky is blue";
	ret = reverseWords(in1);

	char in2[] = "  hello world!  ";
	ret = reverseWords(in2);

	char in3[] = "a good   example";
	ret = reverseWords(in3);

    return 0;
}


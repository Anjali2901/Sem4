enum { SIZE = 510, THRESHOLD = 16 };
typedef unsigned char *string;
typedef struct { string *sa; int sn, si; } stack_t;
void simplesort(string*, int, int);
static void rsorta(string *a, int n ,int b)
{
#define push(a, n, i) sp–>sa = a, sp–>sn = n, (sp++)–>si = i
#define pop(a, n, i) a = (––sp)–>sa, n = sp–>sn, i = sp–>si
#define stackempty() (sp <= stack)
#define swap(p, q, r) r = p, p = q, q = r
	stack_t stack[SIZE], *sp = stack, stmp, *oldsp, *bigsp;
	string *pile[256], *ak, *an, r, t;
	static int count[256], cmin, nc;
	int *cp, c, cmax/*, b = 0*/;
	push(a, n, b);
	while(!stackempty()) {
		pop(a, n, b);
		if(n < THRESHOLD) { /* divert */
			simplesort(a, n, b);
			continue;
		}
		an = a + n;
		if(nc == 0) { /* untallied? */
			cmin = 255; /* tally */
			for(ak = a; ak < an; ) {
				c = (*ak++)[b];
				if(++count[c] == 1 && c > 0) {
					if(c < cmin) cmin = c;
					nc++;
				}
			}
			if(sp+nc > stack+SIZE) { /* stack overflow */
				rsorta(a, n, b);
				continue;
			}
		}
		oldsp = bigsp = sp, c = 2; /* logarithmic stack */
		pile[0] = ak = a+count[cmax=0]; /* find places */
		for(cp = count+cmin; nc > 0; cp++, nc––) {
			while(*cp == 0) cp++;
			if(*cp > 1) {
				if(*cp > c) c = *cp, bigsp = sp;
				push(ak, *cp, b+1);
			}
			pile[cmax = cp–count] = ak += *cp;
		}
		swap(*oldsp, *bigsp, stmp);
		an –= count[cmax]; /* permute home */
		count[cmax] = 0;
		for(ak = a; ak < an; ak += count[c], count[c] = 0) {
			r = *ak;
			while(––pile[c = r[b]] > ak)
				swap(*pile[c], r, t);
			*ak = r;
		} /* here nc = count[...] = 0 */
	}
}
void rsort(string *a, int n) { rsorta(a, n, 0); }

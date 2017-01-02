#include <stdio.h>
#include <string.h>

int main() {
	int n, m;

	scanf("%d", &n);
	scanf("%d", &m);

	char u[n], v[m];

	scanf("%s", u);
	scanf("%s", v);

	int lcs[n+1][m+1];
	short ptrs[n+1][m+1];
	memset(lcs, 0, sizeof(lcs));
	memset(ptrs, -1, sizeof(ptrs));

	for ( int i = 1; i <= n; ++i ) {
		for ( int j = 1; j <= m; ++j ) {
			int cur = -1;
			short ptr = -1;

			if ( u[i-1] == v[j-1] ) {
				cur = lcs[i-1][j-1] + 1;
				ptr = 0;
			}

			if ( lcs[i-1][j] > cur ) {
				cur = lcs[i-1][j];
				ptr = 1;
			}

			if ( lcs[i][j-1] > cur ) {
				cur = lcs[i][j-1];
				ptr = 2;
			}

			lcs[i][j] = cur;
			ptrs[i][j] = ptr;
		}
	}

	int i = n;
	int j = m;

	char s[lcs[n][m]];
	short sptr = lcs[n][m]-1;

	for ( short cptr; cptr != -1; cptr = ptrs[i][j] ) {
		switch (cptr) {
			case 0:
				s[sptr--] = u[i-1];
				--i;
				--j;
				break;
			case 1:
				--i;
				break;
			case 2:
				--j;
				break;
			default:
				break;
		}
	}

	if ( lcs[n][m] == 0 ) {
		printf("No longest common subsequence\n");
	} else {
		printf("Longest common subsequence: %s with length %d\n", s, lcs[n][m]);
	}

	return 0;
}

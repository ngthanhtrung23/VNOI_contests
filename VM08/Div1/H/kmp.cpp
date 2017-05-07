#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5;
const long long MOD = 1e9 + 7707;
char s[2*N+1], t[N+1];
int n, next[N], f[2*N], g[2*N];

void enter() {
	scanf("%s%s", s, t);
}

void kmp(const char * s, const char * t, int * l) {
	int m = strlen(s), n = strlen(t);
	fill(next, next+n, -1);
	for(int i = 1; i < n; ++i) {
		int j = next[i-1];
		while(j >= 0 && t[i] != t[j+1]) j = next[j];
		if(t[i] == t[j+1]) ++j;
		next[i] = j;
	}
	fill(l, l+m, 0);
	for(int i = 0, j = -1; i <= m; ++i) {
		while(j >= 0 && s[i] != t[j+1]) {
			if(j >= 0) l[i-1-j] = max(l[i-1-j], j+1);
			j = next[j];
		}
		if(s[i] == t[j+1]) ++j;
		l[i-j] = max(l[i-j], j+1);
		if(j == n-1) j = next[j];
	}
}

void solve() {
	n = strlen(s);
	strncpy(s+n, s, n);
	kmp(s, t, f);
	reverse(s, s+2*n); reverse(t, t+n);
	kmp(s, t, g);
	long long res = 0;
	for(int i = 0; i < n; ++i)
		if(f[i] == n) res += n;
		else if(g[n-i] >= n - f[i] - 1) ++res;
	printf("%lld\n", res);
}

int main() {
	enter();
	solve();
	return 0;
}


// Author: happyboy99x
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N = 5e4;
char s[N+1];
int a[N], b[N], k, n;

void enter() {
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i)
		if(s[i] == '?') ++k;
	for(int i = 0; i < k; ++i)
		scanf("%d%d", &a[i], &b[i]);
}

int solve() {
	priority_queue<int, vector<int>, greater<int> > q;
	int h = 0, res = 0;
	for(int i = 0, c = 0; i < n; ++i) {
		if(s[i] == '(') ++h;
		else if(s[i] == ')') --h;
		else --h, q.push(a[c] - b[c]), res += b[c++];
		if(h < 0) {
			if(q.empty()) return -1;
			h += 2; res += q.top(); q.pop();
		}
	}
	return h == 0 ? res : -1;
}

int main() {
	enter();
	printf("%d\n", solve());
	return 0;
}


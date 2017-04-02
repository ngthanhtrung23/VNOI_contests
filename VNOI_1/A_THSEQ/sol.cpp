// Author: happyboy99x
#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 1e6, N = 2500;
int pos[(MAX << 2) + 1], f[N][N], a[N], n;

void enter() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
}

void solve() {
	memset(pos, -1, sizeof pos);
	int res = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int p = pos[a[j] - a[i] + (MAX << 1)];
			if(p != -1) f[i][j] = f[p][i] + 1;
			else f[i][j] = 2;
			res = max(res, f[i][j]);
		}
		pos[a[i] + (MAX << 1)] = i;
	}
	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	int tc; cin >> tc;
	for(int t = 0; t < tc; ++t) {
		enter();
		solve();
	}
	return 0;
}


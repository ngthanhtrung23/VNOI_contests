#include <bits/stdc++.h>
using namespace std;

int N, M;
int T[30], L[30], R[30], K[30];

char pre[1 << 25], suf[1 << 25];
int g[55][55][2];

vector<int> st[55];
vector<int> of[55][2];
int can[55][2];
char X[55];

int get(int l, int r, int typ) {
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		bool yes = !K[i]; int cnt = 0;
		for (int j = max(l, L[i]); j <= min(r, R[i]); ++j) {
			int k = (X[j] == '?' ? typ : X[j] - '0');
			if (k == T[i]) ++cnt; else cnt = 0;
			yes = yes || cnt >= K[i];
		}
		ans += (yes << i);
	}
	return ans;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) cin >> X[i];
	for (int i = 0; i < M; ++i) cin >> K[i] >> T[i] >> L[i] >> R[i];
	for (int i = 1; i <= N; ++i) for (int j = i; j <= N; ++j) for (int k = 0; k < 2; ++k) 
		// cout << i << ' ' << j << ' ' << k << ' ' << (g[i][j][k] = get(i, j, k)) << endl;
		g[i][j][k] = get(i, j, k);
	st[0].push_back(0);
	for (int i = 0; i < (1 << M); ++i) pre[i] = N + 1, suf[i] = 0;
	pre[0] = 0; suf[0] = N + 1;
	st[0].push_back(0);
	int cxnt = 0;
	for (int x = 0; x <= N; ++x) {
		while (st[x].size()) {
			int v = st[x].back(); st[x].pop_back();
			if (pre[v] != x) continue;
			for (int i = x + 1; i <= N; ++i) {
				for (int k = 0; k < 2; ++k) {
					int u = v | g[x + 1][i][k];
					if (pre[u] > i) {
						pre[u] = i; st[i].push_back(u);
					}
				}
			}
		}
	}
	st[N + 1].push_back(0);
	for (int x = N + 1; x >= 1; --x) {
		while (st[x].size()) {
			int v = st[x].back(); st[x].pop_back();
			if (suf[v] != x) continue;
			++cxnt;
			for (int i = x - 1; i >= 1; --i) {
				for (int k = 0; k < 2; ++k) {
					int u = v | g[i][x - 1][k];
					if (suf[u] < i) {
						suf[u] = i; st[i].push_back(u);
					}
				}
			}
		}
	}
	// cout << cxnt << endl;
	int mx = (1 << M) - 1;
	// for (int m = mx; m > 0; --m) {
	//     int k = __builtin_popcount(m);
	// 	if (k <= (M >> 1) - 1) {
	// 		for (int _m = m, k = _m & (-_m); _m; _m ^= k, k = _m & (-_m))
	// 			suf[m ^ k] = max(suf[m ^ k], suf[m]);
	// 	}
	// 	if (k >= (M >> 1) - 1) {
	// 		for (int _m = mx ^ m, k = _m & (-_m); _m; _m ^= k, k = _m & (-_m))
	// 			suf[m] = max(suf[m ^ k], suf[m]);
	// 	}
	// }
	// for (int i = 0; i < (1 << M); ++i) cout << i << ' ' << pre[i] << ' ' << suf[i] << endl;
	vector<int> P, S;
	for (int i = 0; i <= mx; ++i) {
		if (pre[i] <= N) P.push_back(i);
		if (suf[i] > 0) S.push_back(i);
	}
	sort(S.begin(), S.end(), [](int a, int b) { return suf[a] > suf[b]; });
	for (auto i: P) for (auto j: S) {
		if (suf[j] <= pre[i] + 1) break;
		for (int k = 0; k < 2; ++k) {
			if ((i | j | g[pre[i] + 1][suf[j] - 1][k]) == mx) {
				of[pre[i] + 1][k].push_back(1);
				of[suf[j]][k].push_back(-1);
				// cout << pre[i] + 1 << "..." << suf[j] - 1 << ' ' << k << endl;
			}
		}
	}
	// for (int m = 0; m < (1 << M); ++m) {
	// 	for (int j = N; j > pre[m]; --j) {
	// 		if (suf[((1 << M) - 1) ^ (g[pre[m] + 1][j][0] | m)] > j) {
	// 			of[pre[m] + 1][0].push_back(1); of[j + 1][0].push_back(-1);
	// 			// cout << pre[m] + 1 << "..." << j << ' ' << 0 << endl;
	// 			break;
	// 		}
	// 	}
	// 	for (int j = N; j > pre[m]; --j) {
	// 		if (suf[((1 << M) - 1) ^ (g[pre[m] + 1][j][1] | m)] > j) {
	// 			of[pre[m] + 1][1].push_back(1); of[j + 1][1].push_back(-1);
	// 			// cout << pre[m] + 1 << "..." << j << ' ' << 1 << endl;
	// 			break;
	// 		}
	// 	}
	// }
	for (int i = 1; i <= N; ++i) for (int k = 0; k < 2; ++k) {
		can[i][k] = can[i - 1][k];
		for (auto x: of[i][k]) can[i][k] += x;
		// cout << i << ' ' << can[i][k] << endl;
	}
	for (int i = 1; i <= N; ++i) {
		if (!can[i][0] && !can[i][1]) {
			return cout << "mau thuan" << endl, 0;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (X[i] != '?') printf("%c", X[i]);
		else if (can[i][0] && can[i][1]) printf("?");
		else printf((can[i][0] ? "0" : "1"));
	}
	printf("\n");
}

// Author: happyboy99x

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define TR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
const int N = 5e4;
int n, p[N], c[N];
vector<pair<int, pair<int, int> > > edge;

void initSet() {
	for(int i = 0; i < n; ++i)
		p[i] = i, c[i] = 1;
}

int getSet(int u) {
	return u == p[u] ? u : p[u] = getSet(p[u]);
}

void joint(int u, int v) {
	int x = getSet(u), y = getSet(v);
	p[x] = y; c[y] += c[x]; c[x] = 0;
}

void enter() {
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edge.push_back(make_pair(w, make_pair(u-1, v-1)));
	}
}

void solve() {
	sort(edge.begin(), edge.end());
	initSet();
	long long res = 0;
	TR(edge, it) {
		int w = it->first, u = it->second.first, v = it->second.second;
		res += w + (c[getSet(u)] * c[getSet(v)] - 1LL) * (w+1);
		joint(u, v);
	}
	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	enter();
	solve();
	return 0;
}


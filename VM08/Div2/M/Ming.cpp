#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

int N, M;
int hor[15], ver[15];
int d[22225];
vector <ii> adj[22225];

void addEdge(int u, int v, int w) {
    adj[u].pb(ii(w, v));
    adj[v].pb(ii(w, u));
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ff(i, 0, N - 1) {
        int x;
        ff(j, 1, M) {
            cin >> x;
            if (i) addEdge((i - 1) * M + j, i * M + j, x);
            else addEdge(0, i * M + j, x);
        }
        ff(j, 1, M - 1) cin >> x, addEdge(i * M + j, i * M + j + 1, x);
    }
    priority_queue <ii, vector <ii>, greater <ii> > q;
    ff(i, 1, N * M) d[i] = 500000000;
    q.push(ii(0, 0));
    int u, v, w, du;
    while (!q.empty()) {
        u = q.top().second, du = q.top().first; q.pop();
        if (du != d[u]) continue;
        if (u == N * M) return cout << d[u] << endl, 0;
        ff(i, 0, (int)adj[u].size() - 1) {
            v = adj[u][i].second, w = adj[u][i].first;
            if (d[v] > d[u] + w) d[v] = d[u] + w, q.push(ii(d[v], v));
        }
    }
    return 0;
}

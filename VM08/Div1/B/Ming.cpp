#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, Q;
int dad[100005][20];
vi adj[100005];
int B[100005], E[100005], Time;
int T[500005], cnt[500005];
int a[100005];

void upd(int node, int l, int r, int u, int v, int type) {
    if (r < u || l > v) return;
    if (u <= l && r <= v) {
        cnt[node] += type;
        if (type == 1) T[node] = r - l + 1;
        else if (!cnt[node]) T[node] = T[node*2] + T[node*2+1];
        return;
    }
    int m = l + r >> 1;
    upd(node * 2, l, m, u, v, type);
    upd(node * 2 + 1, m + 1, r, u, v, type);
    if (!cnt[node]) T[node] = T[node*2] + T[node*2+1];
}

bool get(int pos) {
    int node = 1, l = 1, r = N;
    while (l < r) {
        if (cnt[node]) return 1;
        int m = l + r >> 1;
        if (pos <= m) r = m, node *= 2;
        else l = m + 1, node = node * 2 + 1;
    }
    return cnt[node];
}

void dfs(int u) {
    B[u] = ++Time;
    ff(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        if (v == dad[u][0]) continue;
        dad[v][0] = u;
        dfs(v);
    }
    E[u] = Time;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    ff(i, 1, N) a[i] = -1;
    int u, v;
    ff(i, 1, N - 1) cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dfs(1);
    ff(j, 1, 17) ff(i, 1, N) dad[i][j] = dad[dad[i][j-1]][j-1];
    ff(i, 1, Q) {
        cin >> v >> u;
        if (v == 0) {
            a[u] *= -1;
            upd(1, 1, N, B[u], E[u], a[u]);
        }
        else {
            if (a[1] == 1) { cout << 1 << '\n'; continue; }
            if (!get(B[u])) { cout << -1 << '\n'; continue; }
            fb(i, 17, 0) if (dad[u][i] && get(B[dad[u][i]])) u = dad[u][i];
            cout << u << '\n';
        }
    }
    return 0;
}

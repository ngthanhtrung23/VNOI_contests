#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR(A,n)  { cout << #A << " = "; FOR(_,1,n) cout << A[_] << ' '; cout << endl; }
#define PR0(A,n) { cout << #A << " = "; REP(_,n) cout << A[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

double safe_sqrt(double x) {
    return sqrt(max((double)0.0,x));
}
int GI(ll& x) {
    return scanf("%lld", &x);
}

struct Edge {
    int to;
    list<Edge>::iterator rev;

    Edge(int to) :to(to) {}
};

const int MN = 100111;
list<Edge> adj[MN];
vector<int> path; // our result

void find_path(int v) {
    while(adj[v].size() > 0) {
        int vn = adj[v].front().to;
        adj[vn].erase(adj[v].front().rev);
        adj[v].pop_front();
        find_path(vn);
    }
    path.push_back(v);
}

void add_edge(int a, int b) {
    adj[a].push_front(Edge(b));
    auto ita = adj[a].begin();
    adj[b].push_front(Edge(a));
    auto itb = adj[b].begin();
    ita->rev = itb;
    itb->rev = ita;
}

int c[222][222];


#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    int n, m;
    cin >> n >> m;
    FOR(i,1,m) {
        int u, v, cost; cin >> u >> v >> cost;
        c[u][v] = c[v][u] = cost;
        add_edge(u, v);
    }
    path.clear();
    find_path(1);

    if (SZ(path) != m + 1 || path[0] != path.back()) {
        cout << -1 << endl;
        return 0;
    }

    path.pop_back();

    int nn = 1e9;
    int start = 0;
    int sum = 0;
    REP(i,SZ(path)) {
        int u = path[i], v = path[(i+1) % SZ(path)];
        sum += c[u][v];
        if (sum < nn) {
            nn = sum;
            start = i+1;
        }
    }
    REP(turn,SZ(path)+1) {
        int u = path[(start+turn) % SZ(path)];
        printf("%lld ", u);
    }
    puts("");
}


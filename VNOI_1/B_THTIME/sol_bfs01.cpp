// Author: RR
// BFS 01

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

int f[2][1011][1011];
char a[2][1011][1011];

const int di[4] = {-1,1,0,0};
const int dj[4] = {0,0,-1,1};

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    int m, n;
    while (cin >> m >> n) {
        memset(f, -1, sizeof f);
        deque<int> qt;
        deque<int> qu;
        deque<int> qv;

        memset(a, '#', sizeof a);
        REP(t, 2) FOR(i,1,m) FOR(j,1,n) {
            cin >> a[t][i][j];
            if (a[t][i][j] == 'S') {
                qt.push_back(t);
                qu.push_back(i);
                qv.push_back(j);
                f[t][i][j] = 0;
            }
        }
        while (!qt.empty()) {
            int t = qt.front(); qt.pop_front();
            int u = qu.front(); qu.pop_front();
            int v = qv.front(); qv.pop_front();
            int cur = f[t][u][v];

            if (a[t][u][v] == 'T') {
                cout << cur << endl;
                break;
            }

            if (f[1-t][u][v] < 0 && a[1-t][u][v] != '#') {
                f[1-t][u][v] = cur + 1;
                qt.push_back(1-t);
                qu.push_back(u);
                qv.push_back(v);
            }
            REP(dir,4) {
                int uu = u + di[dir], vv = v + dj[dir];
                if (a[t][uu][vv] != '#' && f[t][uu][vv] < 0) {
                    f[t][uu][vv] = cur;
                    qt.push_front(t);
                    qu.push_front(uu);
                    qv.push_front(vv);
                }
            }
        }
    }
}


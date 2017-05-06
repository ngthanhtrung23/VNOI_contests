#include <bits/stdc++.h>
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

int n, a[511][511], f[511][511], to[511];

int main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    while (scanf("%d", &n) == 1) {
        FOR(i,1,n) FOR(j,1,n) scanf("%d", &a[i][j]);
        
        FOR(i,1,n) to[i] = i % n +1;
        FOR(i,1,n) f[i][to[i]] = 1;

        FOR(dist,2,n) {
            FOR(i,1,n) {
                int j = (i + dist); if (j > n) j -= n;

                for(int k = to[i]; k != j; k = to[k]) {
                    if (f[i][k] && f[k][j] && (a[i][k] || a[j][k])) {
                        f[i][j] = 1;
                        break;
                    }
                }
            }
        }
        int cnt = 0;
        FOR(i,1,n) if (f[i][i]) ++cnt;
        cout << cnt << '\n';
        FOR(i,1,n) if (f[i][i]) cout << i << '\n';
    }
}



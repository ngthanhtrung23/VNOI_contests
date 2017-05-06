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

int m, n, a[555][555], x[555], s[555], k;

int solve() {
    int res = m*n + 1;
    FOR(up,1,m) {
        memset(x, 0, sizeof x);

        FOR(down,up,m) {
            FOR(j,1,n) {
                x[j] += a[down][j];
                s[j] = s[j-1] + x[j];
            }

            int l = 1;
            FOR(r,1,n) {
                while (l < r && s[r] - s[l] >= k) ++l;

                if (s[r] - s[l-1] >= k) {
                    res = min(res, (down - up + 1) * (r - l + 1));
                }
            }
        }
    }
    if (res > m*n) return -1;
    return res;
}

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    while (cin >> m >> n >> k) {
        FOR(i,1,m) FOR(j,1,n) {
            cin >> a[i][j];
        }
        cout << solve() << endl;
    }
}

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

const int MN = 222;
int a[MN][MN], top[MN][MN][MN], bot[MN][MN][MN], mid[MN][MN][MN];
int m, n;
char tmp[MN];

int getSum(int i, int j, int u, int v) {
    return a[u][v] - a[u][j-1] - a[i-1][v] + a[i-1][j-1];
}

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    while (cin >> m >> n) {
        memset(top, 0, sizeof top);
        memset(bot, 0, sizeof bot);
        memset(mid, 0, sizeof mid);

        FOR(i,1,m) {
            cin >> tmp;

            FOR(j,1,n) {
                a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + tmp[j-1] - '0';
            }
        }
        // top
        FOR(i,1,m) FOR(l,1,n) FOR(r,l,n) if (getSum(i, l, i, r) == r - l + 1) {
            top[i][l][r] = top[i-1][l][r] + r - l + 1;
        }

        // bot
        FORD(i,m,1) FOR(l,1,n) FOR(r,l,n) if (getSum(i, l, i, r) == r - l + 1) {
            bot[i][l][r] = bot[i+1][l][r] + r - l + 1;
        }

        // expand top & bot
        FOR(i,1,m) FORD(l,n,1) FOR(r,l+1,n) {
            top[i][l][r] = max(top[i][l][r], max(top[i][l+1][r], top[i][l][r-1]));
            bot[i][l][r] = max(bot[i][l][r], max(bot[i][l+1][r], bot[i][l][r-1]));
        }

        // mid
        int res = 0;
        FOR(i,2,m) FOR(l,1,n) FOR(r,l+2,n)
            if (getSum(i, l, i, r) == r - l + 1) {
                // extend from above
                if (mid[i-1][l][r]) mid[i][l][r] = mid[i-1][l][r] + r - l + 1;

                // top --> mid
                if (top[i-1][l+1][r-1])
                    mid[i][l][r] = max(mid[i][l][r], top[i-1][l+1][r-1] + r - l + 1);
                
                // final
                if (mid[i][l][r] && bot[i+1][l+1][r-1]) {
                    res = max(res, mid[i][l][r] + bot[i+1][l+1][r-1]);
                }
            }
        cout << res << endl;
    }
}



#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define REPD(i,n) for(int i = (n)-1; i >= 0; --i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define double long double
typedef pair<int, int> II;
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define MS(a,x) memset(a, x, sizeof(a))
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc

#define TWO(X) (1LL<<(X))
#define CONTAIN(S,X) ((S) & TWO(X))

int rand16() {
    return rand() & (TWO(16) - 1);
}
int my_rand() {
    return rand16() << 15 | rand16();
}

double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
int GI(int& x) { return scanf("%lld", &x); }

const int MN = 100111;
int good[MN], bad[MN], f[MN];
int nCell, len, gap;

int sumGood(int l, int r) {
    if (l > r) return 0;
    return good[r] - good[l-1];
}
int sumBad(int l, int r) {
    if (l > r) return 0;
    return bad[r] - bad[l-1];
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << (fixed) << setprecision(9) << boolalpha;
    while (cin >> nCell >> len >> gap) {
        int q; cin >> q;
        memset(good, 0, sizeof good);
        memset(bad, 0, sizeof bad);
        while (q--) {
            int u, typ; cin >> u >> typ;
            if (typ == 1) good[u] = 1;
            else bad[u] = 1;
        }
        FOR(i,2,nCell) {
            good[i] += good[i-1];
            bad[i] += bad[i-1];
        }
        f[0] = 0;
        FOR(i,1,nCell) f[i] = -1000111000;

        FOR(i,1,nCell) {
            // do not put anything
            if (sumGood(i, i) == 0) {
                f[i] = max(f[i], f[i-1]);
            }

            // put
            // i-len+1 -> i must not be bad.
            if (i >= len && sumBad(i-len+1, i) == 0) {
                // i-len-gap+1 -> i-len must not be good.
                if (sumGood(max(i-len-gap+1, 1LL), i-len) == 0) {
                    f[i] = max(f[i], f[max(0LL, i-len-gap)] + 1);
                }
            }
        }
        if (f[nCell] < 0) f[nCell] = -1;
        cout << f[nCell] << endl;
    }
    return 0;
}


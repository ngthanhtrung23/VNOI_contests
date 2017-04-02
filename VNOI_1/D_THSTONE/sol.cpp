// Author: RR
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

int n, a[10111];
long long l[10111];

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    int n;
    while (cin >> n && n >= 0) {
        long long sum = 0;
        FOR(i,1,n) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n) {
            cout << -1 << endl;
            continue;
        }

        FOR(i,1,n) {
            l[i] = a[i] + l[i-1] - sum / n;
        }

        int res = 0;
        FOR(i,1,n) res = max(res, llabs(l[i]));
        cout << res << endl;
    }
}

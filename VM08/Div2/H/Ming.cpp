#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

ll N; int M;
vector <ll> v;

ll f(ll n) {
    if (n == 1) return 0;
    return (f(n - 1) + M) % n;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    v.pb(N);
    while (N >= M) v.pb(N - N / M), N -= N / M;
    v.pb(N);
    ll ans = f(v.back());
    fb(i, (int)v.size() - 2, 0) ans = M * ((ans - v[i] % M + v[i+1]) % v[i+1]) / (M - 1);
    cout << ans + 1 << endl;
    return 0;
}

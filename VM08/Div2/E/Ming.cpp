#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

pair <ll, ll> euclid(ll a, ll b) {
    if (!b) return make_pair(1, 0);
    pair <ll, ll> qr = make_pair(a / b, a % b);
    pair <ll, ll> st = euclid(b, qr.second);
    return make_pair(st.second, st.first - qr.first * st.second);
}
ll flo(ll a, ll b) { if (a >= 0) return a / b; return -flo(-a, b) - 1; }

ll a, b, c, x;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> x >> b >> c; c -= x;
    if (a == 0 && b == 0) return cout << "0 0" << endl, 0;
    if (a == 0) return cout << 0 << ' ' << -c / b << endl, 0;
    if (b == 0) return cout << c / a << ' ' << 0 << endl, 0;
    ll d = __gcd(a, b); a /= d, b /= d, c /= d;
    pair <ll, ll> ans = euclid(a, -b);
    if (ans.first * a - ans.second * b == -1) c = -c;
    ans.first *= c, ans.second *= c;
    ll k = min(flo(ans.first, b), flo(ans.second, a));
    ans.first -= b * k, ans.second -= a * k;
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}

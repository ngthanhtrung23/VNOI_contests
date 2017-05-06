#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int cnt[1000006];
int ok[1000006];
vi v[50005]; int ans;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int x;
    ff(i, 1, N) cin >> x, ++cnt[x];
    ff(i, 1, 1000000) if (cnt[i]) {
        ff(j, ok[i], ok[i] + cnt[i] - 1) v[j].pb(i);
        ans = max(ans, ok[i] + cnt[i]);
        ff(j, 2, 1000000 / i) ok[i*j] = max(ok[i*j], ok[i] + cnt[i]);
        ok[i] += cnt[i];
    }
    cout << ans << endl;
    ff(i, 0, ans - 1) {
        cout << v[i].size() << ' ';
        ff(j, 0, v[i].size() - 1) cout << v[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

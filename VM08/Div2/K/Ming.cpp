#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
bool b[505][505];
bool f[505][505];
bitset <505> ans;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ff(i, 0, N - 1) ff(j, 0, N - 1) cin >> b[i][j];
    ff(i, 0, N - 1) f[i][(i + 1) % N] = 1;
    ff(d, 2, N - 1) ff(i, 0, N - 1) {
        int j = (i + d) % N;
        if (i < j) {
            ff(k, i + 1, j - 1) if (f[i][k] && f[k][j] && (b[i][k] || b[j][k])) { f[i][j] = 1; break; }
        }
        else {
            ff(k, i + 1, N - 1) if (f[i][k] && f[k][j] && (b[i][k] || b[j][k])) { f[i][j] = 1; break; }
            ff(k, 0, j - 1) if (f[i][k] && f[k][j] && (b[i][k] || b[j][k])) { f[i][j] = 1; break; }
        }
    }
    ff(i, 0, N - 1) ff(j, 0, N - 1) if (f[i][j] && f[j][i]) { if (b[i][j]) ans.set(i); else ans.set(j); }
    cout << ans.count() << endl;
    ff(i, 0, N - 1) if (ans.test(i)) cout << i + 1 << endl;
    return 0;
}

#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M, K;
int a[505][505], s[505], v[505];

int main(void) {
    cin >> N >> M >> K;
    ff(i, 1, N) ff(j, 1, M) cin >> a[i][j];
    int res = N * M + 1;
    ff(i, 1, N) {
        memset(v, 0, sizeof v);
        ff(j, i, N) {
            ff(k, 1, M) {
                v[k] += a[j][k];
                s[k] = s[k-1] + v[k];
            }
            int l = 1;
            ff(r, 1, M) {
                while (l < r && s[r] - s[l] >= K) ++l;
                if (s[r] - s[l-1] >= K) res = min(res, (j - i + 1) * (r - l + 1));
            }
        }
    }
    if (res > N * M) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}

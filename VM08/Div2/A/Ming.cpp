#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int mod = 14062008;
int N, K;
int f[100005];
bool k[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    int x;
    ff(i, 1, K) cin >> x, k[x] = 1;
    f[1] = 1;
    ff(i, 2, N) f[i] = (f[i-1] + f[i-2]) % mod * (1 - k[i]);
    cout << f[N] << endl;
    return 0;
}

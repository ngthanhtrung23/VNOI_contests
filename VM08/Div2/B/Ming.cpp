#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int a[505][505];
int s1[505][505];
int s2[505][505];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ff(i, 1, N) ff(j, 1, N) {
        cin >> a[i][j];
        s1[i][j] = s1[i][j-1] + s1[i-1][j] - s1[i-1][j-1];
        s2[i][j] = s2[i][j-1] + s2[i-1][j] - s2[i-1][j-1];
        if (i + j & 1) s1[i][j] += a[i][j]; else s2[i][j] += a[i][j];
    }
    int Q, x, y, u, v; cin >> Q;
    ff(i, 1, Q) {
        cin >> x >> y >> u >> v;
        int a1 = s1[u][v] - s1[x-1][v] - s1[u][y-1] + s1[x-1][y-1];
        int a2 = s2[u][v] - s2[x-1][v] - s2[u][y-1] + s2[x-1][y-1];
        cout << abs(a1 - a2) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int d2[10004], d5[10004];
int cnt[26];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int N = s.size();
    ff(i, 1, N) if (i % 2 == 0) d2[i] = d2[i / 2] + 1;
    ff(i, 1, N) if (i % 5 == 0) d5[i] = d5[i / 5] + 1;
    ff(i, 0, N - 1) ++cnt[s[i] - 'a'];
    int a2 = 0, a5 = 0;
    ff(i, 1, N) a2 += d2[i], a5 += d5[i];
    ff(i, 0, 25) ff(j, 1, cnt[i]) a2 -= d2[j], a5 -= d5[j];
    cout << min(a2, a5) << endl;
    return 0;
}

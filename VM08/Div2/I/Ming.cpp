#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int s[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int x;
    ff(i, 1, N) {
        cin >> x;
        s[i] = s[i-1] + x;
    }
    sort(s + 1, s + N);
    ff(i, 1, N) if (s[i] <= s[i-1]) return cout << -1 << endl, 0;
    ff(i, 1, N) cout << s[i] - s[i-1] << ' '; cout << endl;
    return 0;
}

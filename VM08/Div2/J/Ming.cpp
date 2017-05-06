#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, A, B, C;
pair <string, int> s[55]; int ca[55], cb[55];
int f[55][55][55][55];
bool trace[55][55][55][55]; //use or not

bool cmp(string s, string t) { ff(i, 0, (int)min(s.size(), t.size()) - 1) if (s[i] != t[i]) return s[i] < t[i]; return s.size() < t.size(); }
bool CMP(pair <string, int> a, pair <string, int> b) { return a.first < b.first; }
bool Cmp(vi s, vi t) { ff(i, 0, (int)min(s.size(), t.size()) - 1) if (s[i] != t[i]) return s[i] < t[i]; return s.size() < t.size(); }

vi Trace(int n, int a, int b, int c) {
    if (!f[n][a][b][c]) return vi();
    vi ss;
    while (n) {
        if (trace[n][a][b][c]) {
            ss.pb(n);
            a -= ca[n];
            b -= cb[n];
            --c;
        }
        else --n;
    }
    reverse(ss.begin(), ss.end());
    return ss;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B >> C; ++C;
    ff(i, 1, N) cin >> s[i].first >> s[i].second;
    sort(s + 1, s + N + 1, CMP);
    ff(i, 1, N) ff(j, 0, s[i].first.size() - 1) if (s[i].first[j] == 'a') ++ca[i]; else ++cb[i];
    ff(i, 1, N) {
        ff(a, 0, A) ff(b, 0, B) ff(c, 0, C) {
            f[i][a][b][c] = f[i-1][a][b][c];
            if (a < ca[i] || b < cb[i] || c < 1) continue;
            int opt = f[i][a-ca[i]][b-cb[i]][c-1] + s[i].second;
            if (f[i][a][b][c] < opt) {
                f[i][a][b][c] = opt;
                trace[i][a][b][c] = 1;
            }
            else if (f[i][a][b][c] == opt) {
                vi S = Trace(i, a - ca[i], b - cb[i], c - 1); S.pb(i);
                vi T = Trace(i - 1, a, b, c);
                if (Cmp(S, T)) {
                    f[i][a][b][c] = opt;
                    trace[i][a][b][c] = 1;
                }
            }
        }
    }
    int x = 0, y = 0, z = 0;
    ff(a, 0, A) ff(b, 0, B) ff(c, 0, C) {
        if (f[N][a][b][c] > f[N][x][y][z]) x = a, y = b, z = c;
        else if (f[N][a][b][c] == f[N][x][y][z] && Cmp(Trace(N, a, b, c), Trace(N, x, y, z))) x = a, y = b, z = c;
    }
    vi ans = Trace(N, x, y, z);
    if (ans.empty()) return cout << endl, 0;
    cout << s[ans[0]].first;
    ff(i, 1, (int)ans.size() - 1) cout << ' ' << s[ans[i]].first;
    cout << endl;
    return 0;
}

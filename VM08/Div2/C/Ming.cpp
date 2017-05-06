#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int base = 10000;
int N;
void operator *= (vi &a, int b) {
    a.pb(0);
    ff(i, 0, (int)a.size() - 2) a[i] *= b;
    ff(i, 0, (int)a.size() - 2) a[i+1] += a[i] / base, a[i] %= base;
    while (a.size() && a.back() == 0) a.pop_back();
}
void operator += (vi &a, int b) {
    a.pb(0);
    a[0] += b;
    ff(i, 0, (int)a.size() - 2) if (a[i] >= base) a[i] -= base, ++a[i+1];
    while (a.size() && a.back() == 0) a.pop_back();
}

int main(void) {
    cin >> N;
    vi v(1, 1);
    ff(i, 1, N - 2) v *= i, v += 1;
    printf("%d", v.back()); v.pop_back();
    while (v.size()) printf("%04d", v.back()), v.pop_back();
    return 0;
}

// Author: hieult
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = (int) fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
    v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}
typedef pair<int, int> II;
const ld PI = acos(-1.0);
const ld eps = 1e-9;
const int dr[] = { -1, 0, +1, 0, 1, 1, -1, -1 };
const int dc[] = { 0, +1, 0, -1, 1, -1, 1, -1 };
const int inf = (int) 1e9 + 5;
const ll linf = (ll) 1e16 + 5;
#define maxn 5005

vector<int> V[5005];
bool flag[5005];
int deg[maxn];

int a[5005];
int n, num;

bool cal(int A, int B){
    return cntbit(A ^ B) >= (n >> 1);
}

int x[5005];

bool go(int id, int num){
//  cout << id << " " << num << endl;
    if(id == (1 << n)){
        if(cntbit(num) >= n / 2) return true;
        return false;
    }

    Rep(i, 1 << n) if(!flag[i] && deg[i] < 1) return false;
//  if(so > 1) return false;
    Rep(j, 1 << n) x[j] = j;
    Rep(run, (1 << n) / 2){
        int u = rand() % (1 << n), v = rand() % (1 << n);
        swap(x[u], x[v]);
    }

    Rep(i, 1 << n){
        int u = x[i];
        if(!flag[u] && cal(num, u)){
            flag[u] = 1;
            a[id + 1] = u;
            Rep(j, (1 << n)) if(cal(u, j)){
                deg[j]--;
            }

            if(go(id + 1, u)){
                return true;
            }
            Rep(j, (1 << n)) if(cal(u, j)){
                deg[j]++;
            }
            flag[u] = 0;
        }
    }

    return false;
}

string s[5005];



int main(){
    cin >> n; ms(deg, 0);
    Rep(i, 1 << n) Rep(j, 1 << n) if(cal(i, j)) deg[i]++;

    ms(flag, 0); flag[0] = 1; a[1] = 0;
    go(1, 0);
    For(i, 1, 1 << n){
        Rep(j, n) printf("%d", getbit(a[i], j));
        puts("");
    }

}


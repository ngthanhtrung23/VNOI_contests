// Author: RR

#include <sstream>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define FORN(i,a,b) for(int i=(a),_b=(b);i<_b;i++)
#define DOWN(i,a,b) for(int i=a,_b=(b);i>=_b;i--)
#define SET(a,v) memset(a,v,sizeof(a))
#define sqr(x) ((x)*(x))
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;
using namespace std;

//Buffer reading
int INP,AM,REACHEOF;
const int BUFSIZE = (1<<12) + 17;
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp && !REACHEOF) { \
        memset(BUF,0,sizeof BUF);\
        int inpzzz = fread(BUF,1,BUFSIZE,stdin);\
        if (inpzzz != BUFSIZE) REACHEOF = true;\
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}
//End of buffer reading

const long double PI = acos((long double) -1.0);
const int MN = 250111;
const int MAXV = 50111;
const int BLOCK = 777;

int n, q, nblock;
long long res;
int a[MN], ind[MN];
int sl[411][MAXV];
int start[411], last[411], len[411];

void update(int x, int u, int k) {
    for(int v = u; v <= MAXV; v += v & -v) {
        sl[x][v] += k;
    }
}

int get(int x, int u) {
    int res = 0;
    for(int v = u; v > 0; v -= v & -v) {
        res += sl[x][v];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &a[i]);
    FORD(i,n,1) {
        update(0, a[i], 1);
        res += get(0, a[i]-1);
    }
    nblock = 1;
    int c = 0;
    FOR(i,1,n) {
        if (c == 0) start[nblock] = i;
        ind[i] = nblock; len[nblock]++;
        ++c;
        if (c == BLOCK) {
            last[nblock] = i;
            ++nblock; c = 0;
        }
    }
    last[nblock] = n;
    FOR(i,1,n) update(ind[i], a[i], 1);

    scanf("%d", &q);
    while (q--) {
        int u, val; scanf("%d%d", &u, &val);
        int p = ind[u];

        // Block truoc u
        FOR(i,1,p-1) {
            res -= len[i] - get(i, a[u]);
            res += len[i] - get(i, val);
        }

        // Block sau u
        FOR(i,p+1,nblock) {
            res -= get(i, a[u] - 1);
            res += get(i, val - 1);
        }

        // Block chua u
        FOR(i,start[p], u-1) {
            if (a[i] > a[u]) --res;
            if (a[i] > val) ++res;
        }
        FOR(i,u+1,last[p]) {
            if (a[i] < a[u]) --res;
            if (a[i] < val) ++res;
        }

        // Update block u
        update(p, a[u], -1);
        a[u] = val;
        update(p, val, +1);

        printf("%lld\n", res);
    }
    return 0;
}


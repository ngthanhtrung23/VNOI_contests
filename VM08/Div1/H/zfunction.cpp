#include<cstdio>
#include<cmath>
#include<math.h>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define ep 0.00001
#define oo 111111111
#define base 100000000
#define mod 15111992
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define rep(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
//#define g 9.81
double const PI=4*atan(1.0);

using namespace std;

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef long long int64;

void OPEN(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
}

#define maxn 100005

int n, f[maxn * 3], g[maxn * 3];
string s1, s2, t1, t2;

void z_Function(string x, int z[]){
    z[0] = 0;
    int l = 0, r = -1, k;
    for(int i = 1; i < 3 * n; i++){
        k = (i > r ? 0 : min(z[i - l], r - i + 1)) + 1;
        while(i + k - 1 < 3 * n && x[k - 1] == x[i + k - 1]) k++; z[i] = --k;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}

string reverse(string x){
    string res;
    for(int i = x.length() - 1; i >= 0; i--)
        res.PB(x[i]);
    return res;
}

int main(){
    //OPEN();
    cin >> s1 >> s2;
    n = s1.length();
    t1 = reverse(s1); t2 = reverse(s2);
    s1 = s1 + s1.substr(0, n - 1);
    t1 = t1.substr(1, n - 1) + t1;
    z_Function(s2 + char(0) + s1, f);
    z_Function(t2 + char(0) + t1, g);
    int res = 0;
    bool flag = false;
    for(int i = n + 1; i <= n + n; i ++){
        if(f[i] >= n){
            res++;
            flag = true;
        }
        if(f[i] + g[3 * n + 1 - i] == n - 1) res++;
    } 
    if(!flag)
        printf("%d", res);
    else printf("%lld\n",res * 1ll * n);
}


// Author: skykvn97

#include<cstdio>
#include<algorithm>
#define MAX     50505
using namespace std;
typedef long long ll;
struct edge {
    ll f,s;
    ll c;
    edge(){}
    edge(const ll &_f,const ll &_s,const ll &_c) {
        f=_f;s=_s;c=_c;
    }
    bool operator < (const edge &x) const {
        return (c<x.c);
    }
};
edge e[MAX];
ll up[MAX];
ll n,m;
long long res;
void loadgraph(void) {
    scanf("%lld",&n);
    ll i,u,v,c;
    res=0;
    for (i=1;i<=n;i=i+1) up[i]=-1;
    for (i=1;i<n;i=i+1) {
        scanf("%lld",&u);
        scanf("%lld",&v);
        scanf("%lld",&c);
        e[i]=edge(u,v,c);
        res=res+c;
    }
    sort(&e[1],&e[n]);
}
ll find(ll x) {
    if (up[x]<0) return (x);
    up[x]=find(up[x]);
    return (up[x]);
}
void join(ll a,ll b) {
    ll x=find(a);
    ll y=find(b);
    if (x==y) return;
    up[x]=up[x]+up[y];
    up[y]=x;
}
void process(void) {
    ll i;
    for (i=1;i<n;i=i+1) {
        res=res+(up[find(e[i].f)]*up[find(e[i].s)]-1)*(e[i].c+1);
        join(e[i].f,e[i].s);
    }
    printf("%lld",res);
}
int main(void) {
    loadgraph();
    process();
    return 0;
}

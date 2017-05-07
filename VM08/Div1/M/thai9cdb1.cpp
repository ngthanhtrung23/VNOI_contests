#include<bits/stdc++.h>
using namespace std;
const int nmax=102;

int n,m,f[nmax][2002],v[nmax],c[nmax],first[nmax],last[nmax],s[nmax],cnt;
vector<int> e[nmax];

void dfs(int x,int p){
    first[x]=++cnt;
    s[cnt]=x;
    for (int y:e[x]) if (y!=p) dfs(y,x);
    last[x]=cnt;
}

int tinh(int i,int k){
    if (i==0) return 0;
    if (f[i][k]!=-1) return f[i][k];
    int &r=f[i][k];
    if (c[i]<=k) r=max(r,tinh(s[first[i]+1],k-c[i])+v[i]);
    r=max(r,tinh(s[last[i]+1],k));
    return r;
}

main(){
    cin>>n>>m;
    for (int i=2;i<=n;++i) cin>>v[i];
    for (int i=2;i<=n;++i) cin>>c[i];
    for (int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    memset(f,255,sizeof(f));
    cout<<tinh(1,m);
}

#include <bits/stdc++.h>
#define ll long long
#define yn aslkdja
#define xn alksjd
#define xm asdljhn
#define ym alsjfdaljhf
using namespace std;
ll m,n,xm[205],ym[205],xn[205],yn[205];
ll c[505][505], w[505][505], f[505][505];
const ll source = 405;
const ll sink = 406;
const ll sink2 = 407;
vector <ll> G[505];
ll d[505], p[505];
bool inq[505];
ll ans, flow;
bool find_edmond(){
   fill(p,p+430,-1);
   fill(d,d+430,(ll) 1e18);
   queue <ll> q;
   q.push(source);
   inq[source] = 1;
   d[source] = 0;
   while(q.size()){
      ll u = q.front();
      q.pop();
      inq[u] = 0;
      for(int i=0;i<G[u].size();i++){
         ll v = G[u][i];
         if (f[u][v] == c[u][v]) continue;
         if (d[v] > d[u] + w[u][v]){
             d[v] = d[u] + w[u][v];
             p[v] = u;
             if (!inq[v])
                 inq[v] = 1,
                 q.push(v);
         }
      }
   }
   return d[sink] != (ll) 1e18;
}
void inc(){
    ll ff = (ll) 1e9;
    for(ll x=sink;x!=source;x=p[x])
        ff = min(ff, c[p[x]][x] - f[p[x]][x]);
    for(ll x=sink;x!=source;x=p[x])
        f[p[x]][x] += ff,
        f[x][p[x]] -= ff;
    ans += d[sink] * ff;
    flow += ff;
}
int main(){
   cin >> m >> n;
   for(int i=1;i<=m;i++) cin >> xm[i] >> ym[i];
   for(int i=1;i<=n;i++) cin >> xn[i] >> yn[i];
 
   for(int i=1;i<=n;i++)
      G[source].push_back(i),
      G[i].push_back(source),
      c[source][i] = 1;
 
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         G[i].push_back(j+n),
         G[j+n].push_back(i),
         c[i][j+n] = 1,
         w[i][j+n] = (xn[i] - xm[j]) * (xn[i] - xm[j]) + (yn[i] - ym[j]) * (yn[i] - ym[j]),
         w[j+n][i] = - w[i][j+n];
 
   for(int j=1;j<=m;j++)
      G[j+n].push_back(sink),
      G[sink].push_back(j+n),
      c[j+n][sink] = n/m,
 
      G[j+n].push_back(sink2),
      G[sink2].push_back(j+n),
      c[j+n][sink2] = 1;
 
   G[sink].push_back(sink2),
   G[sink2].push_back(sink);
   c[sink2][sink] = n%m;
 
   while(find_edmond())
      inc();
 
   cout << ans << endl;
   for(int i=1;i<=n;i++){
      int cnt = 0;
      for(int j=n+1;j<=n+m;j++)
         if (f[i][j]) cnt++,cout << j-n << ' ';
      assert(cnt==1);
   }
}

#include<bits/stdc++.h>
using namespace std;
const int nmax=105;
typedef long long ll;

//I use hungarian code in site kc97ble
#define N 222
#define f1(i,n) for (int i=1; i<=n; i++)
#define f2(i,a,u) for (int i=0,u; u=a[i]; i++)
int n,nNode;
int c[N][N];
int f[N], d[N], Decision[N];
int Assigned[N], Visited[N];
vector<int> Left, Right;
queue<int> qu;

bool assignable(int &a, int b){ if (a==0) a=b; else return false; return true; }
bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }
bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

int bfs_next(){
    while (qu.size()){
        int u=qu.front(); qu.pop();
        f2(i,Right,v){
            if (c[u][v]+f[u]+f[v]==0)
            if (assignable(Visited[v], u)){
                if (!Assigned[v]) return v;
                Visited[Assigned[v]]=v;
                qu.push(Assigned[v]);
            }
            if (minimize(d[v], c[u][v]+f[u]+f[v])) Decision[v]=u;
        }
    }
    return 0;
}

int bfs_first(int Start){
    while (qu.size()) qu.pop();
    f1(i,2*n) Visited[i]=0;
    f2(i,Right,u) { d[u]=c[Start][u]+f[Start]+f[u]; Decision[u]=Start; }
    Visited[Start]=-1, qu.push(Start);
    return bfs_next();
}

bool adjust(){
    int Delta=0x11112222;
    f2(i,Right,u) if (!Visited[u]) minimize(Delta, d[u]);
    if (Delta >= 0x11112222) return false;
    assert(Delta != 0);
    f2(i,Left,u) if (Visited[u]) f[u]-=Delta;
    f2(i,Right,u) if (Visited[u]) f[u]+=Delta;

    f2(i,Right,u)
    if (!Visited[u]) { d[u]-=Delta; if (d[u]==0) qu.push(Decision[u]); }
    return true;
}

void enlarge(int u){
    while (u>0){
        int y=u, x=Visited[y];
        u=Assigned[x];
        Assigned[x]=y;
        Assigned[y]=x;
    }
}

map<int, int> Map[N];

int force(int Pos, int Used){
    int Answer=0x11112222;
    if (Pos==n+1) return 0;
    if (Map[Pos].count(Used)) return Map[Pos][Used];
    for (int i=1; i<=n; i++)
    if ((1<<i-1) & ~Used)
    minimize(Answer, force(Pos+1, Used|(1<<i-1))+c[Pos][i+n]);
    return Map[Pos][Used]=Answer;
}

int hungari(){
    n=nNode;

    for (int i=1;i<=n;++i) for (int j=n+1;j<=n+n;++j) c[i][j]=c[i][j-n];

    f1(i,n) Left.push_back(i); Left.push_back(0);
    f1(i,n) Right.push_back(i+n); Right.push_back(0);

    f2(i,Left,u) {
        int x=bfs_first(u);
        while (x==0){
            if (!adjust()) break;
            else x=bfs_next();
        }
        enlarge(x);
    }
    int Answer=0;
    f1(i,n) Answer += c[i][Assigned[i]];
    return Answer;
}
//////////////////////////////////////////

const int hx[]={-1,1,0,0},hy[]={0,0,1,-1};
struct point{
    int x,y,color;
};
vector<point> bien,human;
int k,a[nmax][nmax],D[nmax][nmax];

main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) cin>>a[i][j];
    human.resize(k);
    for (int i=0;i<k;++i) cin>>human[i].x>>human[i].y>>human[i].color;
    for (int i=1;i<=n;++i){
        point tmp;
        tmp.x=1;
        tmp.y=i;
        cin>>tmp.color;
        bien.push_back(tmp);
    }
    for (int i=1;i<=n;++i){
        point tmp;
        tmp.x=i;
        tmp.y=n;
        cin>>tmp.color;
        bien.push_back(tmp);
    }
    for (int i=1;i<=n;++i){
        point tmp;
        tmp.x=n;
        tmp.y=n-i+1;
        cin>>tmp.color;
        bien.push_back(tmp);
    }
    for (int i=1;i<=n;++i){
        point tmp;
        tmp.x=n-i+1;
        tmp.y=1;
        cin>>tmp.color;
        bien.push_back(tmp);
    }
    for (int i=1;i<=k;++i){
        point x=human[i-1];
        memset(D,100,sizeof(D));
        priority_queue< pair<int,int> > heap;
        D[x.x][x.y]=a[x.x][x.y];
        heap.push({-D[x.x][x.y],x.x*1000+x.y});
        while (!heap.empty()){
            auto tmp=heap.top();
            heap.pop();
            int x=tmp.second/1000, y=tmp.second%1000;
            if (D[x][y]!=-tmp.first) continue;
            for (int i=0;i<4;++i){
                int xx=x+hx[i], yy=y+hy[i];
                if (xx>=1&&xx<=n&&yy>=1&&yy<=n&&D[xx][yy]>D[x][y]+a[xx][yy]){
                    D[xx][yy]=D[x][y]+a[xx][yy];
                    heap.push({-D[xx][yy],xx*1000+yy});
                }
            }
        }
        for (int time=1;time<=k;++time){
            int d=1e9;
            for (point tmp:bien) if (tmp.color==x.color) d=min(d,D[tmp.x][tmp.y]);
            c[i][time]=d;
            //printf("c[%d][%d]=%d\n",i,time,c[i][time]);
            int tmp=bien.back().color;
            for (int i=bien.size()-1;i>0;--i) bien[i].color=bien[i-1].color;
            bien[0].color=tmp;
        }
        for (int time=1;time<=k;++time){
            int tmp=bien[0].color;
            for (int i=0;i<bien.size()-1;++i) bien[i].color=bien[i+1].color;
            bien.back().color=tmp;
        }
    }
    nNode=k;
    cout<<hungari();
}

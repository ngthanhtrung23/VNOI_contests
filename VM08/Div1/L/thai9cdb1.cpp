#include<bits/stdc++.h>
using namespace std;
const int nmax=1011;
int n,cntthap[nmax][nmax],cnthoa[nmax][nmax],mark[nmax][nmax],lab,k,check;
int colorhoa[nmax], colorthap[nmax];

bool canh(int i,int x,int y){
    int inhoa=y>=x?cnthoa[i][y]-cnthoa[i][x-1]:cnthoa[i][n-1]-(cnthoa[i][x-1]-cnthoa[i][y]);
    int inthap=cntthap[i][max(0,n-1-k-(y>=x?y-x+1:n-x+y+1))];
    return cntthap[i][n]-inhoa-inthap;
}

void dfs(int x,int y){
    if ((y+1)%n==x){
        check=1;
        return;
    }
    if (mark[x][y]==lab) return;
    mark[x][y]=lab;
    int u=(x-1+n)%n,v=(y+1+n)%n;
    if (canh(colorhoa[u],x,y)) dfs(u,y);
    if (canh(colorhoa[v],x,y)) dfs(x,v);
}

main(){
    cin>>n;
    for (int i=n;i>=1;--i) cin>>colorthap[i];
    for (int i=0;i<n;++i) cin>>colorhoa[i];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j) cntthap[i][j]=cntthap[i][j-1]+(colorthap[j]==i);
        cnthoa[i][0]=(colorhoa[0]==i);
        for (int j=1;j<n;++j) cnthoa[i][j]=cnthoa[i][j-1]+(colorhoa[j]==i);
    }
    int d=0,c=n-1,r=n;
    while (d<=c){
        k=(d+c)/2;
        ++lab;
        check=0;
        for (int i=0;i<n;++i) if (cntthap[colorhoa[i]][n]-cntthap[colorhoa[i]][n-k-1]) dfs(i,i);
        if (check){
            r=k;
            c=k-1;
        } else d=k+1;
    }
    cout<<r;
}

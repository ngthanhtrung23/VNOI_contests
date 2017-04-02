// Author: skyvn97
#include<bits/stdc++.h>
#define MAXV   1000003
#define MAX   2525
using namespace std;
vector<int> table[2*MAXV+7];
int pnt[2*MAXV+3];
int st[MAX];
int a[MAX];
struct stacki {
	int sz;
	stacki(){}
	bool empty(void) const {
		return (sz==0);
	}
	void clear(void) {
		sz=0;
	}
	void push(const int &v) {
		sz++;
		st[sz]=v;
	}
	int top(void) const {
		return (st[sz]);
	}
	void pop(void) {
		sz--;
	}
};
stacki val;
struct hashtable {
	void clear(void) {
		int t;
		while (!val.empty()) {
			t=val.top();val.pop();
			table[t].clear();			
			pnt[t]=0;
		}
	}
	void insert(const int &v,const int &i) {
		//printf("Inserting %d %d\n",v,i);
		//printf("%d\n",v+MAXV);
		table[v+MAXV].push_back(i);
		val.push(v+MAXV);
	}
	int find(const int &v,const int &i) {
		//printf("Finding %d %d: ",v,i);
		if (v<-MAXV) return (-1);
		if (v>MAXV) return (-1);
		int t=v+MAXV;
		if (table[t].empty()) return (-1);
		if (table[t][pnt[t]]>=i) return (-1);
		while (pnt[t]<table[t].size() && table[t][pnt[t]]<i) pnt[t]++;
		pnt[t]--;
		//printf("Found\n");
		return (table[t][pnt[t]]);
	}
};
hashtable htab;
int f[MAX][MAX];
int n,r;
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
void init(void) {
	htab.clear();
	val.clear();
	//printf("123\n");
	int i,t;
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&t);
		a[i]=t;
		htab.insert(t,i);
	}
	r=0;
}
void optimize(void) {
	//printf("Optimizing\n");
	int i,j,k;
	for (j=1;j<n;j=j+1)
		for (i=j+1;i<=n;i=i+1) {
			k=htab.find(a[i]-a[j],j);
			if (k<0) f[j][i]=2;
			else f[j][i]=f[k][j]+1;
			maximize(r,f[j][i]);
		}
	printf("%d\n",r);
}
int main(void) {
	int t,c;
	scanf("%d",&t);
	for (c=1;c<=t;c=c+1) {
		//printf("Starting test %d\n",c);
		init();
		optimize();
	}
	return 0;
}

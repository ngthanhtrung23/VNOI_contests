#include <iostream>
#include <map>
using namespace std;

#define MAXN 55
typedef long long LL;

int ik[MAXN], ix[MAXN], ia[MAXN], ib[MAXN];
char a[MAXN], b[MAXN];
int n, m;
map<LL,bool> F[MAXN][MAXN][2];

bool go(int i, LL state, int len, int last) {
	if(i==n) return (state==(1LL<<m)-1) ? true : false;
	if(F[i][len][last].count(state)) return F[i][len][last][state];	
	for(int j=0;j<m;++j) if(ib[j]<i && ((state & (1LL<<j))==0)) return F[i][len][last][state] = false;
	int add[2] = {0,1};
	int nad = 2;
	if(a[i]!='?') {
		nad = 1;
		if(a[i]=='1') add[0] = 1;	
	}
	bool ret = false;
	for(int k=0;k<nad;++k) {
		int x = add[k];
		int newlen = (x==last) ? (len+1) : 1;
		LL ns = state;
		for(int j=0;j<m;++j) 
			if(ia[j]<=i-ik[j]+1 && ib[j]>=i && ix[j]==x && ik[j]<=newlen)
				ns |= (1LL<<j);
		if(go(i+1,ns,newlen,x)) {
			ret = true;
			//return F[i][len][last][state] = true;
			b[i] |= 1<<x;
		}
	}
	return F[i][len][last][state] = ret;
}

void clear() {
	for(int i=0;i<MAXN;++i) for(int j=0;j<MAXN;++j) for(int k=0;k<2;++k) F[i][j][k].clear();
}	

int main() {
	scanf("%d%d", &n, &m);
	gets(a); gets(a);
	for(int i=0;i<m;++i) {
		scanf("%d%d%d%d", ik+i, ix+i, ia+i, ib+i);
		--ia[i];
		--ib[i];
	}
	int tbegin = clock();
	//memset( F, 255, sizeof(F));
	clear();
	if(!go(0,0,0,0)) puts("mau thuan");
	else {
		/*memmove( b, a, sizeof(a));
		for(int i=0;i<n;++i) if(a[i]=='?') {
			a[i] = '0';
			//memset( F, 255, sizeof(F));
			clear();
			bool ok0 = go(0,0,0,0);
			a[i] = '1';
			//memset( F, 255, sizeof(F));
			clear();
			bool ok1 = go(0,0,0,0);
			a[i] = '?';
			if(ok0 && !ok1) b[i] = '0';
			if(ok1 && !ok0) b[i] = '1';
		}
		puts(b);*/
		for(int i=0;i<n;++i) printf("%c", b[i]==1?'0':(b[i]==2?'1':'?'));
		printf("\n");
	}
	//cout << clock() - tbegin << endl;
	//system("pause");
	return 0;
}


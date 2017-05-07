#include<cstdio>
#include<cstring>
#define MAXD   44
typedef long long ll;
const ll m[][39]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				  {0,9,99,999,9999,99999,999999,9999999,99999999,999999999,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				  {0,3,9,31,99,316,999,3162,9999,31622,99999,316227,999999,3162277,9999999,31622776,99999999,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				  {0,2,4,9,21,46,99,215,464,999,2154,4641,9999,21544,46415,99999,215443,464158,999999,2154434,4641588,9999999,21544346,46415888,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			      {0,1,3,5,9,17,31,56,99,177,316,562,999,1778,3162,5623,9999,17782,31622,56234,99999,177827,316227,562341,999999,1778279,3162277,5623413,9999999,17782794,31622776,56234132,0,0,0,0,0,0,0},
				  {0,1,2,3,6,9,15,25,39,63,99,158,251,398,630,999,1584,2511,3981,6309,9999,15848,25118,39810,63095,99999,158489,251188,398107,630957,999999,1584893,2511886,3981071,6309573,9999999,15848931,25118864,39810717}};
ll max(const ll &x,const ll &y) {
	if (x>y) return (x); else return (y);
}
struct bignum {
	ll nd;
	ll d[MAXD];
	bignum() {
		nd=0;
		memset(d,0,sizeof d);
	}
	bignum(ll x) {
		nd=0;
		if (x==0) {
			nd=1;
			d[0]=1;
			return;
		}
		while (x>0) {
			nd++;
			d[nd-1]=x%10;
			x=x/10;
		}
	}	
	bignum operator + (const bignum &x) const {
		bignum res;
		res.nd=0;
		ll i,a,b,c,s;
		c=0;
		for (i=0;i<max(nd,x.nd);i=i+1) {
			if (i>=nd) a=0; else a=d[i];
			if (i>=x.nd) b=0; else b=x.d[i];
			s=a+b+c;
			c=s/10;
			s=s%10;
			res.nd++;
			res.d[res.nd-1]=s;
		}
		if (c>0) {
			res.nd++;
			res.d[res.nd-1]=c;
		}
		while (res.d[res.nd-1]==0 && res.nd>1) res.nd--;
		return (res);
	}
	bignum operator * (const ll &x) const {
		bignum res;
		res.nd=0;
		ll s,c;
		ll i;
		c=0;
		for (i=0;i<nd;i=i+1) {
			s=d[i]*x+c;
			c=s/10;
			s=s%10;
			res.nd++;
			res.d[res.nd-1]=(ll)s;
		}
		while (c>0) {
			res.nd++;
			res.d[res.nd-1]=(ll)(c%10);
			c=c/10;
		}
		while (res.d[res.nd-1]==0 && res.nd>1) res.nd--;
		return (res);
	}
	void prll(void) const {
		printf("Nd = %d\n",nd);
		ll i;
		for (i=nd-1;i>=0;i=i-1) printf("%d",d[i]);
		printf("\n");
	}
};
ll s[6][39];
void finit(void) {
	ll i,j;
	for (i=1;i<=5;i=i+1) {
		s[i][0]=0;
		for (j=1;j<=38;j=j+1) s[i][j]=s[i][j-1]+(m[i][j]-m[i][j-1])*j;					
	}
}
bignum power(const ll &x,const ll &k) {
	bignum res=bignum(1);
	ll i;
	for (i=1;i<=k;i=i+1) res=res*x;
	return (res);
}
ll let(ll n,ll k) {
	//printf("Requests: %lld %lld\n",n,k);
	ll i;
	if (n==0) return (0);
	for (i=1;i<=38;i=i+1)
		if (s[k][i]>=n) {
			n=n-s[k][i-1];
			break;
		}
	//printf("   Nd = %lld\n",i);
	//printf("   In num = %lld\n",m[k][i-1]+(n-1)/i+1);
	//printf("   Let pos = %lld\n",(n-1)%i+1);	
	bignum tmp=power(m[k][i-1]+(n-1)/i+1,k);
	return (tmp.d[(n-1)%i]);
}
void process(const ll &n,const ll &k1,const ll &k2) {
	ll a,b,c,d,i,rem;		
	a=let(n,k1);
	b=let(n,k2);
	for (i=n-1;i>=0;i=i-1) {
		c=let(i,k1);
		d=let(i,k2);
		if (c+d<9) {
			rem=0;
			break;
		}
		if (c+d>9) {
			rem=1;
			break;
		}				
	}
	printf("%lld\n",(a+b+rem)%10);
}
ll n,k1,k2;
int main(void) {
	finit();
	while (scanf("%lld",&n)==1) {
		scanf("%lld",&k1);
		scanf("%lld",&k2);
		process(n,k1,k2);
	}
	return 0;
}


#include<cstdio>
#include<cstring>
#define BASE   29
#define NMOD   1
#define MAX   100100
typedef long long ll;
const ll mod[]={1e9+7,1e9+21,1e9+97,1e9+9,1e9+33};
char a[2*MAX];
char b[2*MAX];
ll pw[5][2*MAX];
ll sa[5][2*MAX];
ll sb[5][2*MAX];
int n;
void init(void) {
    scanf("%s",a);
    scanf("%s",b);
    n=strlen(a);
    int i,j;
    for (i=0;i<n;i=i+1) {
        a[i+n]=a[i];
        b[i+n]=b[i];
    }
    a[2*n]=0;
    b[2*n]=0;
    n=2*n;
    for (i=0;i<NMOD;i=i+1) {
        pw[i][0]=1;
        sa[i][0]=0;
        sb[i][0]=0;
        for (j=1;j<=n;j=j+1) {
            pw[i][j]=(pw[i][j-1]*BASE);
            sa[i][j]=(sa[i][j-1]+(a[j-1]-'A')*pw[i][j-1]);
            sb[i][j]=(sb[i][j-1]+(b[j-1]-'A')*pw[i][j-1]);
        }
    }
}
bool same(const int &fa,const int &fb,const int &m) {
    if (m==0) return (true);
    ll x,y;
    int i;
    for (i=0;i<NMOD;i=i+1) {
        x=(sa[i][fa+m-1]-sa[i][fa-1]);
        y=(sb[i][fb+m-1]-sb[i][fb-1]);
        if (fa<fb) x=(x*pw[i][fb-fa]);
        if (fb<fa) y=(y*pw[i][fa-fb]);
        if ((x-y)!=0) return (false);
    }
    return (true);
}
void process(void) {
    ll res=0;
    int i,l,m,r;
    for (i=1;i<=n/2;i=i+1) {
        l=0;
        r=n/2;
        while (true) {
            if (r==l) {
                m=r;
                break;
            }
            if (r-l==1) {
                if (same(i,1,r)) m=r;
                else m=l;
                break;
            }
            m=(l+r)/2;
            if (same(i,1,m)) l=m;
            else r=m-1;
        }
        if (m==n/2) res=res+n/2;
        else res=res+same(i+m+1,m+2,n/2-m-1);
    }
    printf("%lld\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}




#include<cstdio>
#include<cmath>
#include<cstring>
//#include<conio.h>
#include<algorithm>
#include<iostream>
#define oo 1111111111
#define nmax 100111
#define MAX 222
#define base 1000000000
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)


using namespace std;

struct solon
{
     int so;
     long long a[20];
     solon(){ so = 1; a[1] = 0;}
     solon(long long x){
          so = 1;
          a[1] = x;
     }

};

void print(solon A)
{
      printf("%lld",A.a[A.so]);
      for(int i = A.so-1;i>=1;i--)
          printf("%09lld",A.a[i]);
}

int sosanh(solon S1,solon S2) {
          //print(S1); printf(" %lld ",S1.a[1]); print(S2); printf(" %lld %d\n",S2.a[1],S1.a[1]<S2.a[1]);
          if(S1.so<S2.so) return -1;
          if(S1.so>S2.so) return 1;
          for(int i = S1.so;i>=1;i--){
                if(S1.a[i]<S2.a[i]) return -1;
                if(S1.a[i]>S2.a[i]) return 1;
          }
          return 0;
}

solon tong(solon A,solon B)
{
      int du = 0;
      solon C;
      if(A.so<B.so)
      {
           C = A;
           A = B;
           B = C;
      }
      for(int i = B.so+1;i<=A.so;i++) B.a[i] = 0;
      C.so = A.so;
      for(int i = 1;i<=A.so;i++)
      {
          C.a[i] = (A.a[i]+B.a[i]+du)%base;
          du = (A.a[i]+B.a[i]+du)/base;
      }
      if(du>0) {C.so++; C.a[C.so] = du;}
      return C;
}

solon tichnho(solon A,long long k,int chuso)
{
      solon C;
      long long du = 0;
      C.so = A.so+chuso;
      for(int i = 1;i<=chuso;i++)
           C.a[i] = 0;
      for(int i = chuso+1;i<=chuso+A.so;i++)
      {
           C.a[i] = (A.a[i-chuso]*k+du)%base;
           du = (A.a[i-chuso]*k+du)/base;
      }
      if(du>0) {C.so++; C.a[C.so] = du;}
      return C;
}

solon tich(solon A,solon B)
{
      solon C;
      C.so = 1; C.a[1] = 0;
      for(int i = 1;i<=B.so;i++)
      {
           C = tong(C,tichnho(A,B.a[i],i-1));
      }
      return C;
}

int GCD(int u,int v){
    int r;
    while(v!=0){
         r = u%v;
         u = v;
         v = r;
    }
    return u;
}

solon T[50],S,U,M;
long long f[10][55],u,v,r,so1,so2,so;
int n,k1,k2;

int tim(int x,int k){

      int so,vitri;
      for(int i = 1;;i++){
          //  printf("%d %d\n",x,k);
            if(x<=(f[k][i+1]-f[k][i])*i){
                  so = (x-1)/i+ f[k][i];
                  vitri = (x-1)%i + 1;
                  S = solon(so);
                  U = solon(1);
                  for(int j = 1;j<=k;j++)
                       U = tich(U,S);
                  for(int j = 1;;j++){
                        if(vitri<=9){
                               for(int k = 1;k<=vitri-1;k++)
                                    U.a[j]/=10;
                               return U.a[j]%10;
                        }
                        else vitri-=9;
                  }
            }
            x -= (f[k][i+1]-f[k][i])*i;

      }
}

int main()
{
      //freopen("NDIGIT.in","r",stdin);
      T[1] = solon(1);
      for(int i = 2;i<50;i++){
            T[i] = tichnho(T[i-1],10,0);
           // printf("%d %d\n",i,T[i].so);
      }
      memset(f,0,sizeof(f));
      for(int i = 1;i<=5;i++){
            for(int j = 1;j<=i*10;j++){
                    u = 0,v = 1000000000;
                    while(u+1<v){

                          r = (u+v)/2;
                          S = solon(r);
                          U = solon(1);
                          for(int run = 1;run<=i;run++)
                                U = tich(U,S);
                         // if(i==1) printf("%d   ",r);
                          //if(i==2){ printf("%d",U.so); printf("  "); printf("%lld",T[j].a[1]); printf("\n");}
                          if(sosanh(U,T[j])<0) u = r;
                          else v = r;
                    }
                    f[i][j] = v;
            }
      }
     // for(int i = 1;i<=9;i++) printf("%d %lld\n ",i,f[5][i]);
      while(scanf("%d %d %d",&n,&k1,&k2)>0)
      {
      so1 = 0; so2 = 0;
      for(int i = n;i>n-8 && i>0;i--){
         //  printf("%d %d\n",tim(i,k1),tim(i,k2));
           so1 = so1*10+tim(i,k1);
           so2 = so2*10+tim(i,k2);
      }
     // printf("%lld %lld\n",so1,so2);
      so = so1+so2;
      int lan = min(7,n-1);
      for(int i = 1;i<=lan;i++) so/=10;
      printf("%d\n",so%10);
      }
      //getch();
}


#include <stdio.h>

struct point {
    int X, Y;
    bool operator < (point a){ if (X==a.X) return Y<a.Y; else return X<a.X; }
};

int abs(int a){ return a>0?a:-a; }

int surface(point a, point b, point c){
    int r = a.X*b.Y-b.X*a.Y
    + b.X*c.Y-c.X*b.Y
    + c.X*a.Y-a.X*c.Y;
    return abs(r);
}

main(){
    point a, b, c;
    int n, m, r=0, key, z;
    scanf("%d%d%d", &m, &n, &key);
    for (a.X=0; a.X<=m; a.X++)
    for (a.Y=0; a.Y<=n; a.Y++)
    for (b.X=0; b.X<=m; b.X++)
    for (b.Y=0; b.Y<=n; b.Y++)
    if (a<b)
    for (c.X=0; c.X<=m; c.X++)
    {
        z=a.X*b.Y-b.X*a.Y-c.X*b.Y+c.X*a.Y;

        if (a.X==b.X){
            for (c.Y=0; c.Y<=n; c.Y++)
            if (b<c){
                if (z-2*key==(a.X-b.X)*c.Y) r++;
                if (z+2*key==(a.X-b.X)*c.Y) r++;
            }
        }
        else {
            if ((z-2*key)%(a.X-b.X)==0){
                c.Y=(z-2*key)/(a.X-b.X);
                if (c.Y>=0 && c.Y<=n && b<c) r++; }
            if ((z+2*key)%(a.X-b.X)==0){
                c.Y=(z+2*key)/(a.X-b.X);
                if (c.Y>=0 && c.Y<=n && b<c) r++; }
        }
    }
    printf("%d\n", r);
}


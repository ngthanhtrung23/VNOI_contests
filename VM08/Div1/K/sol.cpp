#include <bits/stdc++.h>
#define list ajscljalsjl
using namespace std;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	Point add(Point p) { return Point(x+p.x,y+p.y); }
	Point sub(Point p) { return Point(x-p.x,y-p.y); }
	Point mul(int k) { return Point(x*k,y*k); }
	Point div(int k) { return Point(x/k,y/k); }
};

int n, result;
Point a[1505];
vector<Point> list[222][222];

bool cmp(Point a, Point b) {
	int t = a.x * (a.y - b.y) - a.y * (a.x - b.x);
	return t < 0;
}

void process(vector<Point> &v) {
	sort( v.begin(), v.end(), cmp);
	int j = 0, k = 0;
	for(int i=0;i<v.size();++i) {
		j = max(j, i + 1);
		k = max(k, i + 1);
		while(j<v.size() && v[j].x * v[i].x + v[j].y * v[i].y > 0) ++j;
		while(k<v.size() && v[k].x * v[i].x + v[k].y * v[i].y >= 0) ++k;
		result += k - j;
	}
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;++i) scanf("%d%d", &a[i].x, &a[i].y), a[i] = a[i].mul(2);
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j) {
			Point mid = a[i].add(a[j]).div(2);
			Point v = a[i] .sub( mid );
			if(v.y<0) v = v.mul(-1);
			if(v.y==0 && v.x<0) v.x = -v.x;
			list[mid.x+110][mid.y+110].push_back(v);
		}
	for(int i=0;i<222;++i)
		for(int j=0;j<222;++j)
			process(list[i][j]);
	printf("%d\n", result);
	return 0;
}


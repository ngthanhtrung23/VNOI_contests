#include<iostream>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;

const int lim[6][42] = {
	{},
	{0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999},
	{0, 3, 9, 31, 99, 316, 999, 3162, 9999, 31622, 99999, 316227, 999999, 3162277, 9999999, 31622776, 99999999},
	{0, 2, 4, 9, 21, 46, 99, 215, 464, 999, 2154, 4641, 9999, 21544, 46415, 99999, 215443, 464158, 999999, 2154434, 4641588, 9999999, 21544346, 46415888, 99999999},
	{0, 1, 3, 5, 9, 17, 31, 56, 99, 177, 316, 562, 999, 1778, 3162, 5623, 9999, 17782, 31622, 56234, 99999, 177827, 316227, 562341, 999999, 1778279, 3162277, 5623413, 9999999, 17782794, 31622776, 56234132},
	{0, 1, 2, 3, 6, 9, 15, 25, 39, 63, 99, 158, 251, 398, 630, 999, 1584, 2511, 3981, 6309, 9999, 15848, 25118, 39810, 63095, 99999, 158489, 251188, 398107, 630957, 999999, 1584893, 2511886, 3981071, 6309573, 9999999, 15848931, 25118864, 39810717, 63095734, 99999999, 158489319}
};
const int BASE = 1e9, MAX_LEN = 5;
const int p10[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

struct BigInteger {
	long long d[MAX_LEN], n;

	BigInteger(int x = 0) {
		memset(d, 0, sizeof d); n = 0;
		for(; x != 0; x /= BASE)
			d[n++] = x % BASE;
	}

	void fix() {
		long long rem = 0;
		for(int i = 0; i < n; ++i) {
			long long temp = d[i] + rem;
			d[i] = temp % BASE;
			rem = temp / BASE;
		}
		for(; rem != 0; rem /= BASE)
			d[n++] = rem % BASE;
		while(n > 0 && d[n-1] == 0) --n;
	}

	void operator *= (const int &x) {
		for(int i = 0; i < n; ++i)
			d[i] *= x;
		fix();
	}

	int digit(int p) {
		return d[p/9] / p10[p%9] % 10;
	}
};

long long sum[6][42];
int c[6];

BigInteger pow(int a, int n) {
	BigInteger res (1);
	for(int i = 0; i < n; ++i)
		res *= a;
	return res;
}

void init() {
	for(int i = 1; i <= 5; ++i) {
		c[i] = 1;
		for(int nd = 1; nd < 42 && lim[i][nd] != 0; ++nd) {
			sum[i][nd] = sum[i][nd-1] + (0LL + lim[i][nd] - lim[i][nd-1]) * nd;
			++c[i];
		}
	}
}

int getDigit(int pos, int power) {
	int nd = upper_bound(sum[power], sum[power] + c[power], pos) - sum[power];
	pos -= sum[power][nd - 1];
	return pow(lim[power][nd - 1] + (pos / nd) + 1, power).digit(pos % nd);
}

int rem(int n, int k1, int k2) {
	if(n < 0) return 0;
	int v = getDigit(n, k1) + getDigit(n, k2);
	if(v < 9) return 0;
	return (v + rem(n-1, k1, k2)) / 10;
}

int calc(int n, int k1, int k2) {
	return (getDigit(n, k1) + getDigit(n, k2) + rem(n-1, k1, k2)) % 10;
}

int main() {
	ios::sync_with_stdio(false);
	init();
	for(int n, k1, k2; cin >> n >> k1 >> k2; )
		cout << calc(n-1, k1, k2) << "\n";
	return 0;
}


#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define debug(x) cout << #x <<" = " << x << endl
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define printvpair(v) for(int i = 0 ; (i) < (v.size()) ; ++i) cout << v[i].first  <<" " << v[i].second << endl;
#define printv(v) for(int i = 0 ; (i) < (v.size()) ; ++i) cout << v[i] << " "; cout << endl;

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = 1000000000;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};

const int N = 100001;
long long rdtsc() {
  long long x;
  asm("rdtsc" : "=A"(x)); // Выполнить ассемблерную команду rdtsc и сложить результат из регистров EDX:EAX в переменную x
  return x;
}
int main() {
	ios_base::sync_with_stdio(0);
	srand(rdtsc());
	int n = rand() % 20 + 1;
	int m = rand() % 20 + n + 1;
	
	cout << n <<" " << m << endl;
	n = rand() % 10;
	cout << n << endl;
	for(int i = 0; i < n; i++) {
		int x = rand() % 10 + 1;
		int y = rand() % 10 + 1;
		cout << x << " " << y << endl;
	}
	return 0;
}


//http://abc046.contest.atcoder.jp/tasks/abc046_b
#include<iostream>
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

const int N = 1007;
ll n,k;
int ans = 0;
int dp[N][N];
int solve(int len, int lastColor){
	if (dp[len][lastColor] != -1){
		return dp[len][lastColor];
	}
	if (len == n){
		return dp[len][lastColor] = 1;
	}
	if (len < n) {
		int x = 0;
		for(int i = 0; i < k; i++){
			if (lastColor != i){
				x += solve(len + 1,i);	
			}
		}
		return dp[len][lastColor] = x;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	
	cout << solve(0,1001) << endl;
  	return 0;
}


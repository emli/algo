//https://www.e-olymp.com/ru/problems/1521
#include<bits/stdc++.h>

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
const ll INF = 1000000000000;

const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};

const int N = 11;
ll n;
vector<pair<ll,ll> > v;
ll dp[N][N];
ll solve(ll l,ll r){
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l == r)
		return dp[l][r] = 0;
	ll ans = INF;
	for(ll mid = l; mid < r; mid++){
		ans = min(solve(l,mid) + solve(mid + 1,r) + v[l].first * v[mid].second * v[r].second, ans);
	}
	return dp[l][r] = ans;
}
string ans;
void restoreAns(ll l,ll r){
	if (l == r){
		ans += "A";
		ans += to_string(l + 1);
		return;
	}
	else if (l < r){
		ans += "(";
		ll x = INF;
		ll i2;
		for(ll mid = l; mid < r; mid++){
			ll y1 = dp[l][mid];
			ll y2 = dp[mid + 1][r] + v[l].first * v[mid].second * v[r].second;
			y1 += y2;
			if (y1 < x){
				x = y1;
				i2 = mid;
			}
		}
	//	assert(ans.size() < 100000);
		restoreAns(l,i2);
		ans += " x ";
		restoreAns(i2 + 1,r);
		ans += ")";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	while(scanf("%d",&n),n) {
		if (n == 0)break;
		v.clear();
		ans = "";
		memset(dp,-1,sizeof dp);
		forn(i,n){
			int x,y;
		//	cin >> x >> y;
			scanf("%d %d",&x,&y);
			v.push_back(make_pair(x,y));
		}
	//	cout << solve(0, n - 1) << endl;
		solve(0, n - 1);
		restoreAns(0,n - 1);
		printf("Case %d: ",t++);
		printf("%s\n",ans.c_str());
	}
  	return 0;
}

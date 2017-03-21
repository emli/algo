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
const int INF = 1000000000;
 
const int dx[4] = {0,  0, 1, -1};
const int dy[4] = {1, -1, 0,  0};
 
const int N = (int)1e6;
int dp[N + 7],a[N + 7],w1[N + 7],d[505][10001];
vector<int> v,ans;
int n,s;
int solve(int pos,int curSum){
    int &res = d[pos][curSum];
    if (res != -1)
        return res;
    if (pos == n + 1 && curSum == 0){
        return res = 0;
    }
    if (pos == n + 1 && curSum != 0){
        return res = -INF;
    }
     
    if (pos <= n){
        int ans = -INF;
        for(int i = 1; i <= curSum / w1[pos]; i++)
            if (curSum - i * w1[pos] >= 0){
                ans = max(solve(pos + 1,curSum - i * w1[pos]) + i * a[pos],ans);
            }
        ans = max(ans,solve(pos + 1,curSum));
        return res = ans;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int e,f;
    cin >> e >> f;
    s = f - e;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> w1[i];
     
    for(int w = 1; w <= s; w++){
        dp[w] = INF;
        for(int i = 1; i <= n; i++){
            if (w - w1[i] >= 0)
                dp[w] = min(dp[w],dp[w - w1[i]] + a[i]);
        }
    }
    for(int w = 1; w < s; w++){
        d[0][w] = -INF;
    }
    d[0][0] = 0;
    for(int w = 1; w <= s; w++){
        for(int pos = 1; pos <= n; pos++){
            int ans = -INF;
            for(int i = 1; i <= w / w1[pos]; i++)
                if (w - i * w1[pos] >= 0){
                    ans = max(ans,d[pos - 1][w - i * w1[pos]] + i * a[pos] );
                }
            ans = max(ans,d[pos - 1][w]);
            d[pos][w] = ans;    
        }
    }
     
    int x = d[n][s];
    if (dp[s] == INF || x < 0){
        cout << "This is impossible.\n";
        return 0;
    }
    else {
        cout << dp[s] << " " << x << endl;
    }
     
 
    return 0;
}

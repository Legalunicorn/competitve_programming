#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// NOTE:
// this feels like a dp problem? 
// k = 10 is very small 
// but this flips are on a segment as well 
//
//
// the result is a mix of segments of flips and not flips 
// if flips <= k its trivial, but we want to maximise the number of flips aredy 
// actually... is it even possible to get more than k segments ? 
// based on paper testing the segments only incrase by max each time? 
// idk 
// seems very hard to dp 
// unless i can prove that there are at most 11 segments then i can dp for (pos, flips left) 
// im just going to assume there are max k+1 segments? 
// lets try simple cases k=2, k = 3 
// k = 2 i can make any 2 segments i want 
// im just goiung to asume this is optimal 
// dp(i, is flipped, left ) -> max sum 
// then the answer is just 
// MAX(   dp(n, i, j)) for all i ,j 


ll dp[100050][2][30];
void solve(){
    // memset(dp,-1,sizeof(dp));
    ll n,k;
    cin >> n >> k;
    vector<vvl> dp(n+5, vvl(2, vl(30, -1LL)));
    vl a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    auto go = [&](auto& go, int i, int f, int left) -> ll{
        if (i == n) {
            return 0LL;
        }
        if (dp[i][f][left] != -1LL) return dp[i][f][left];
        
        ll ans = go(go, i + 1, f, left) + (ll)(f == 0 ? a[i]: b[i]);
        if (left > 0) ans = max(ans,  (ll)(f == 0 ? b[i]:a[i]) + go(go, i + 1, 1- f, left -1));
        return dp[i][f][left] = ans;
    };
    ll res = 0LL;
    res = max(res,go(go,0,0,k*2+0));
    res = max(res,go(go,0,1,k*2-1));
    // for (int i = 0; i < 2; i++){
    //     for (int j = 0; j < 29; j++) res = max(res, dp[0][i][j]);
    // }
    cout << res << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

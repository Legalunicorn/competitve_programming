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
// im actually guess this is a dp questions
// p < q
// never apply p then q 
// either we apply p only 
// or we apply q then p 
void solve(){
    // mega trivial 
    ll n,k,p,q;
    cin >> n >> k >> p >> q;
    vl a(n), x(n), y(n), z(n);
    for (auto& z:a) cin >> z;
    ll base = 0;
    for (int i = 0; i < n; i++){
        x[i] = a[i] % p;
        y[i] = (a[i] % q) % p;
        z[i] = min(x[i], y[i]);
        base += z[i];
    }
    for (int i =1; i< n; i++){
        x[i] += x[i-1];
        y[i] += y[i-1];
    }
    vl pz = z;
    for (int i = 1; i < n;i++) pz[i] += pz[i-1];
    // choose the segment for the first
    ll res = INF;
    for (int i = 0; i + k -1 < n; i++){
        ll r = x[i+k-1] - (i>0? x[i-1]:0);
        ll l = x[i+k-1] - (i>0? x[i-1]:0);
        ll xx = pz[i+k-1] - (i>0? pz[i-1]:0);
        res = min(res, base -xx+r);
        res = min(res, base-xx+l);
    }
    cout << res << endl;

    // vl pf = y;
    // for (int i = 1; i < n; i++) pf[i]+=pf[i-1];
    // dp[i][0] -> from i to n, free range
    // dp[i][1] -> from i to n, unfree
    // base case: dp[n][x] = 0;
    //
    // i have one misunderstanding 
    // p -> q does nothing BUT it helps? 
    // like we can apply "p" to a portion of some segment, for it to be "p" only
    // then we apply "q" over the full segment, then "p" again 
    // then it result in 
    // k = 5
    // x x x x y y y x x x
    // we can kind of control the length of y
    // so long these "y" segments are k distance apart if the "y" segment are shorter than ?? 
    // is it so 
    // . . . x y x y x y . . . . => not possible for k >2
    // i dont know how to formalize the problem its like a weird combination of where we can apply y 
    // depending on the length of y segment
    // y y y x y y y    -> legal if k = 3
    // y y y x y x x    -> also legal 
    // seems like you can cut short a y segment so long the missing elements are all "x"? 
    // but this would be too slow of dp as k = n 
    // k = 4 
    // maybe we can precompute like this, if we consider to start using y
    // y x x x 
    // y y x x 
    // y y y x 
    // y y y y 
    // or we can just use an [x] ? but we are missing the suffix "x" case also? 
    // x x x y
    // x x y y 
    // x y y y 
    // y y y y (dup)
    // then i+k can remake the same decision
    // 
    // we are also not considering the case where "y" segment has freedom if its length >= k
    //
    // BUG: took hint from gpt, realised that only the first operation is limiited, the rest ijust the mind
    //
    // vvl dp(n+1, vl(2, INF));
    // dp[n][0] = dp[n][1] = 0ll;
    // for (int i = n -1; i >= 0; i--){
    //     dp[i][1] = x[i] + dp[i+1][1];
    //     if (i+k<=n){
    //         ll t = pf[i+k-1] - (i>0? pf[i-1]: 0);
    //         dp[i][1] = min(dp[i][1], t + dp[i+k][0]);
    //     }
    //     dp[i][0] = min(y[i]+dp[i+1][0], x[i]+dp[i+1][1]);
    // }
    // if (n == 7){
    //     debug(x);
    //     debug(y);
    //     debug(pf);
    //     debug(dp);
    // }
    // ll res = dp[0][1];
    // cout << res << endl;
    

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}

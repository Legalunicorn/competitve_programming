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
// there must be some bounds right? the array is maxeds at N 
// so we can limit a[i] to N, or N+1 ish and it still works
// ah like the distance muyst be big ok this seems like some trivial dp no? 
// maybe i can do naive n^2 dp and then try to optimize to o(n);
// the naive dp is 
//  dp[pos][wait left]
//
// cant we simplify to dp[pos]? 
// we just assume we are free to pick from pos onwards
//
// if we pick NOW, 
//
//
// if a....b is enough distance 
// and b..c is enough distance 
// then a..c is enough 
//
// this cant be the solution its too easy
// isnt there a second dp state? like choose or not choose 
// dp[i][selected] 
//
//
// unless this is some binar search thing ? 
// no but there are just "bad" values that we cannot use 
// but the dp itself is increasing no>??. 
//
//
// induction: 
// so long what behind me has chosen properly, i do not care
// i cant just throw the ball to dp[i + req]
// that implies that i selected i AND i + req? 
//
// what if we extend the state to dp[i][used] 
// ? is there a better transition
// this mixes things up 
//
// dp[i][0] 
//
//
//
// NOTE: is this a dp trap? what if its njot even dp 



void solve(){
    ll n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl b = a;
    for (int i = 0; i < n; i++) a[i] = min(b[i], n);
    vvl dp(n*3, vl(2, 0));
    for (int i = 0; i < n; i++) dp[i][1] = b[i]; // selectted 
    // transitiosn 
    // our dp is definted as RANGE answe 
    // 1. pos i , NOT CHOSEN = 
    debug(a);
    for (int i = n-1; i >= 0; i --){
        dp[i][0] = max({dp[i+1][0], dp[i+1][1], dp[i][0]}); // if i dont choose this, just take the answer from after wards
        // if i choose now
        ll p = min(n, i + b[i] + 1);
        debug(i, p);
        dp[i][1] = max(dp[i][1], b[i] + dp[p][0]);
        dp[i][1] = max(dp[i][1], dp[i+1][0]);
        if (p <= n-1){
            if (a[p] <= a[i]){
                dp[i][1] = max(dp[i][1], b[i]+dp[p][1]);
            }
        }
    }
    // debug(dp);
    // cerr << endl;
    // res = max({res, dp[0][1], dp[0][0]});
    ll res = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++) res = max(res, dp[i][j]);
    } 
    cout << res << endl;
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

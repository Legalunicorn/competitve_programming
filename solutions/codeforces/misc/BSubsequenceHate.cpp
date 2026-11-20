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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// maybe this is dp instead? 
// what are our options? 
// 1. keep and eat a flip 
// 2. delete and eat a COUNT 

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    debug(s);
    vector<vvi> dp(n, vvi(3, vi(2, -1)));
    vi a(n);
    for (int i = 0; i < n; i++){
        if (s[i] == '1') a[i] = 1;
    }
    // dp is overkill!
    debug(a);
    auto go = [&](auto& go, int i, int v, int tight) -> int {
        debug(i, v, tight);
        if (i == n) return 0;
        if (dp[i][v][tight] != -1) return dp[i][v][tight];
        int ans = n;
        if (i == 0){
            // no matter what u do, tight = 0 still 
            int t2 = 0;
            ans = min(
                1 + go(go, i + 1, 1 - a[0], t2),
                go(go, i + 1, a[0] , t2)
            );
        } else {
            if (a[i] != v){
                if (!tight) ans = min(ans, go(go, i+1, a[i], 1));
                ans = min(ans, 1 + go(go,i+1, v, tight));
            } else{
                ans = min(ans, go(go,i+1, a[i], tight));
            }
        }

        return dp[i][v][tight] = ans;
    };
    int res = go(go, 0, a[0], 0);
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    cin >> T; 
    debug(T);
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

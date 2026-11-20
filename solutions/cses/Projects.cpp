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

void solve(){
    int n;
    cin >> n;
    vvl g(n, vl(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3 ; j++) cin >> g[i][j];
    }
    sort(all(g));
    debug(g);
    vl dp(n+1, 0);
    // dp[i] -> max cash starting [i]... unti n]
    dp[n-1]  = g[n-1][2]; // just attend, why not! 
    int INV = n * 10;
    for (int i = n - 2; i >= 0; i--){
        ll skip = dp[i+1];
        int l = i + 1, r = n - 1;
        int pos = INV;
        while(l<=r){
            int m = (l + r)/2;
            if (g[m][0] > g[i][1]){
                pos = m;
                r = m - 1;
            } else l = m +1;
        }
        ll w = (pos == INV? 0: dp[pos]);
        ll take =  g[i][2] + w;
        dp[i] = max(take,skip);
    }
    cout << dp[0] << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

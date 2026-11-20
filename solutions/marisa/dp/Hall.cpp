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

// NOTE: options 
// 1. include [L,R] then we search for the next part 
// 2. skip [L,R] then we just consider the next index directly 

void solve(){
    // she can chooose to take or not take 
    // if she takes then we want to find the max from [r+1, ...]
    int n;
    cin >> n;
    vpi a(n);
    vl v(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].F >> a[i].S;
    }
    vl dp(n+1, 0);
    sort(all(a));
    for (int i = 0; i < n; i++) v[i] = a[i].S - a[i].F + 1;
    dp[n-1] = v[n-1];
    int INV = 10*n;



    for (int i = n - 2; i >= 0; i --){
        // take or not take 
        dp[i] = max(dp[i], dp[i+1]);

        // i feel like there is a weird relation with i and i + 1 ? 
        // skip that for now 
        int l = i + 1,  r = n -1;
        int pos =  INV;
        while(l <= r){
            int m = (l  + r) /2;
            if (a[m].F > a[i].S ){
                pos = m;
                r = m - 1;
            } else l = m + 1;
        }
        ll extra = (pos == INV? 0 : dp[pos]);
        dp[i] = max(dp[i], v[i] + extra);
    }
    debug(a);
    debug(v);
    debug(dp);
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

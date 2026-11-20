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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int,int> mp;
    for (auto& x:a) mp[x]++;
    // i think this is dp 
    // we can reduce this to some kind of frequenc
    
    int m = mp.size();
    vpi g(m);
    int id = m-1;
    for(auto& [cnt,val]: mp){
        g[id--] = {val,cnt};
    }
    vvl dp(m, vl(2, -1));

    // or maybe we run with the persective of wherther the BEFORE guy was skipped or not either
    // skip == 0 , element was not skip 
    // skip == 1, previous element was skipped 
    debug(g);
    auto go = [&](auto& go, int i, int skip) -> ll {
        debug(i, skip);
        if (i==m) return 0;
        if (dp[i][skip] != -1) return dp[i][skip];
        ll evl = 0;
        ll cost = (ll)g[i].F * g[i].S;


        if (i>0) debug(g[i-1].S-1, g[i].S);
        if (skip == 1 || i == 0 || g[i - 1].S - 1 != g[i].S) {
            debug(i,cost);
          evl = cost + go(go, i + 1, 0);
          
        }
        evl = max(evl, go(go,i+1,1));
        debug(i, skip, evl);
        return dp[i][skip] = evl;
    };


    ll res = go(go, 0, 0);
    cout << res << endl;


    //
    // auto go = [&](auto& go, int i, int skip) -> ll{
    //     if (i == m) return 0;
    //     if (skip && i == m -1) return 0;
    //     if (dp[i][skip]!=-1) return dp[i][skip];
    //     // ll res = (skip == 0 ? 0 : (ll)a[i].F*a[i].S);
    //     ll res = 0; 
    //     if (skip){
    //         // can either SKIP or TAKE next
    //         // SKIP next as well 
    //
    //        if (a[i+1] == a[i]-1) 
    //     }
    // }
    // debug(g);
    //


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

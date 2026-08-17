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


// {color, value}
// only choose K 
// but the variatn must be M 
// initially we just choose one of each color 
// t >= m 
//

void solve(){
    int n,k,m;
    cin >> n >> k >> m;
    vpi a(n);
    map<int, vi> mp;
    for (int i = 0;i < n; i++) cin >> a[i].S >> a[i].F;
    debug(a);
    for (int i =0; i < n; i++){
        int v = a[i].F, c = a[i].S;
        mp[c].pb(v);
        // int v = a[i].S, c = a[i].F;
        // mp[v].pb(c);
    }
    debug(mp);
    int d = mp.size();
    vl rem;
    vl res;
    for (auto& [c, vals]: mp){
        sort(all(vals));
        for (int i = 0; i < vals.size(); i++){
            if (i == vals.size() - 1) res.pb(vals[i]);
            else rem.pb(vals[i]);
        }
    }
    sort(all(res));
    reverse(all(res));
    debug(res);
    debug(rem);

    ll ans = 0;
    for (int i = 0; i < m; i++) ans += res[i];
    for (int i = m; i < res.size(); i++) rem.pb(res[i]);
    sort(all(rem));
    reverse(all(rem));
    // if (res.size() >= k){
    //     for (int i = 0; i < k; i++) ans += res[i];
    //     cout << ans << endl;
    //     return;
    // }
    // int diff = mp.size() - k;
    debug(ans);
    int diff = k - m;
    for (int i = 0; i  < diff; i++){
        if (i >= rem.size()) break;
        ans += rem[i];
    }
    cout << ans <<endl;
            

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

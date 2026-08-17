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
    int k;
    cin >> k;
    map<ll,ll> mp;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        int v = x % k;
        if (v!=0){
            mp[k - v]++;
        }
    }
    if (mp.size()==0){
        cout << 0 << endl;
        return;
    }
    debug(mp);
    
    // number of cycles
    // each cycles cost 
    // full cycles + incomplete cycle 
    ll mx = 0;
    ll   dist = 0;
    for (auto& [v,c]:mp){
        mx = max(mx,c);
        if (c == mx) dist = max(dist, v);
    }
    debug(mx,dist);
    ll res = ((mx-1) * (k)) + (dist+1);
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

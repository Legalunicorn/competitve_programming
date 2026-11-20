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

void solve(){
    int n;
    cin >> n;
    map<ll,ll> mp;
    for (int i= 0; i < n; i++){
        ll x; cin >> x;
        mp[x]++;
    }
    debug(mp);
    ll a = 0, b = 0;
    vl g;
    for (auto& [x, f]: mp){
        if (x % 2 == 1) { // grab it!
            g.pb(f);
            if (x-1>0) mp[x-1] +=f;
            f=0;
        }
    }
    sort(rall(g));
    for (int i = 0; i < g.size(); i++){
        if (i % 2 == 0) a += g[i];
        else b += g[i];
    }
    debug(g);
    debug(mp);
    for (auto& [x, f]: mp){
        a += (x/2)*f;
        b += (x/2)*f;
    }
    cout << a << " " << b << endl;
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

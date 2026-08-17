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
    vi d;
    while(n > 0){
        d.pb(n % 10);
        n /= 10;
    }
    debug(d);
    int sz = d.size();
    ll res = 1;
    for (int i = 0; i < (1 << sz); i++){
        string u,v;
        for (int j = 0; j < sz; j ++){
            if (i >> j & 1) u += (char)(d[j]+'0');
            else v += (char)(d[j]+'0');
        
        }
        if (u.size() == 0 || v.size() == 0) continue;
        sort(u.rbegin(), u.rend());
        sort(v.rbegin(), v.rend());
        debug(u,v);
        ll x = stoll(u);
        ll y = stoll(v);
        res = max(res, x * y);
    
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

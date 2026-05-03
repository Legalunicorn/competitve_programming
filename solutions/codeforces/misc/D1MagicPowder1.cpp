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
    ll n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z; // the amount she NEEDS
    // n ingrediets 
    vl b(n);
    for (auto& z:b) cin >> z; // the amount she HAS
    // tf cant u just brute force or binayr search 
    







    auto check = [&](ll x) -> bool{
        // go through all n ingredients and check if she can make x cookies
        ll left = k;
        for (ll i = 0; i < n; i++){
            ll nd = a[i] * x;
            if (b[i] >= nd) continue;
            ll dt = nd - b[i];
            if (dt > left) return false;
            left -= dt;
        }
        return true;
    };
    ll l = 0, r = (n + k) * 2;
    ll res = l;
    while(l <= r){
        ll m = l + (r - l) / 2;
        bool evl = check(m);
        debug(m, evl);
        if (evl){
            res = m;
            l = m + 1;
        } else r = m -1;
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

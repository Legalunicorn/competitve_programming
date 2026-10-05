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


// 1 2 3 
// 2 3 1 
// 3 1 2 
//
// 1 2 3 1 2 3

void solve(){
    // omega trivial
    int n,q;
    cin >> n >> q;
    vl a(n);
    for (auto& z:a) cin >> z;
    ll u = 0ll;
    for (int i = 0; i < n; i++) u+=a[i]; // one properly length;
    vl b = a;
    for (auto& z:a) b.pb(z);
    debug(b);
    for (int i = 1; i < b.size(); i++) b[i] += b[i-1];
    debug(b);

    // (0,n-1) (n, 2n-1) (2n, 3n-1) 
    // n = 6 
    // r = 
    //  1 2 3 1 2 3 
    //  1 3 6 7 9 12
    //  1 2 3 | 2 3 1 | 3 1 2 j
    auto go = [&](ll x) -> ll {
        // 1 based
        ll evl = 0ll;
        if (x >= n){
            ll g = x/n;
            evl += g * u;
        }
        debug(x,evl);
        ll rem = x % n;
        ll d = x / n + 1;
        if (rem != 0){
            ll l = d-2; // d-1 -> 0 based -1 -> remove prefix
            ll r = d+rem-2;
            ll ex = b[r];
            if (l>=0) ex -= b[l];
            debug(x, rem, d, l, r, ex);
            evl += ex;
        }
        debug(x,evl);
        return evl;
    };

    ll l,r;
    while(q--){
        cin >> l >> r;
        ll res = go(r);
        if (l > 0) res -= go(l-1);
        cout << res << endl;
    }


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

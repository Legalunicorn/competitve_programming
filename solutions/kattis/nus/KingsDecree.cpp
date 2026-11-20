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
    vpl a(n);
    for (int i = 0; i < n; i++) cin >> a[i].F;
    for (int i = 0; i < n; i++) cin >> a[i].S;
    ll l = a[0].S;
    for (int i = 0; i < n; i++) l = min(l, a[i].S);
    ll r = 100000000000ll;
    ll res = l;

    auto check = [&](ll x) -> bool{
        ll need = 0ll, don = 0;
        for (int i = 0; i < n; i++){
            if (a[i].F > x){
                don += a[i].F - max(x, a[i].S);
            } else if (a[i].F < x){
                need += x - a[i].F;
            }
        }
        return need <= don;
    };


    debug(a);
    debug(l,r);
    while(l<=r){
        ll m = l + (r-l)/2;
        if (check(m)){
            res = m;
            l = m + 1;
        } else r = m -1;
    }
    cout << res << endl;
    // vl w(n), l(n);
    // for (auto& z:w) cin >> z;
    // for (auto& z:l) cin >> z;

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

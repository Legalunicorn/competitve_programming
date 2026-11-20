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

// NOTE:
// this is obviously binary searach 
// figure out possibility, there is jh
//
// PERF:
// - each operation add "1" at most 
// - so long all 3 are NOT equal we can always WAIT NOT 
// - its ordered
// - we just need a>b || a>c || b>c
//
//
// binary search over the "S" the min Sum 
// each is independet 
//
// a  =


// NOTE: revaluitate 


void solve(){
    ll n,k;
    cin >> n >> k;  
    vvl a(n, vl(3));
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    ll res = INF;
    for (int i=0; i < n; i++){
        ll s = a[i][0]+a[i][1]+a[i][2];
        res = min(res, s);
    }
    debug(a);
    debug("init res", res);
    ll l = res-1ll, r = INF;
    auto go = [&](ll t) -> bool{
        ll left = k;
        // ll ned = 0ll;
        for (int i = 0; i < n; i++){
            ll s = a[i][0]+a[i][1]+a[i][2];
            if (s>=t) continue;

            // my false contioniue is not true!

            bool poss = false;
            if (a[i][0] > a[i][1] || a[i][0] > a[i][2] || a[i][1] > a[i][2]) poss = true;
            // special im[possible]
            if (a[i][0] == a[i][1] && a[i][1] == a[i][2]) return false;
            if (!poss){
                ll base = 1+min(a[i][2] - a[i][1], a[i][1] - a[i][0]);
                ll ned = t - (s - base) + base; 
                if (ned > left) return false;
                left-=ned;
                // calculate differnet
                // return false;
                // if (s < t) return false;
            } else {
                // cost 1 - trivial
                if (s >= t) continue; // we are ahead;
                ll ned = t - s;
                if (ned > left) return false;
                left-=ned;
            }
        }
        return left>=0;
    };

    while(l<=r){
        ll m = (r-l)/2ll + l;
        bool evl = go(m);
        debug(m, evl);
        if (evl){
            // possible
            res = max(res, m);
            l = m+1;
        } else r = m-1;
    }
    cout << res << endl;
    // cerr << endl;

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

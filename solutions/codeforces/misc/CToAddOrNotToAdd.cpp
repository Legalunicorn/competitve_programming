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

// max number of occurances 
// min number of operations needed 
// size M sliding windows where M is the answer we want 
void solve(){
    ll n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a)); 
    vl pf  = a;
    for (int i =1 ; i <n; i++) pf[i] += pf[i-1];
    ll a2 = a[n-1]; // 
    ll l = 1, r = n, res = 1;
    debug(a);
    debug(pf);
    while(l<=r){
        int m = (l+r)/2;
        // m sized window
        int yes = 0; // possible
        ll ops = a[n-1]; // min number of operations if 
        for (int i = m-1; i < n; i++){
            ll ned = a[i]*m -(pf[i]-(i-m>=0?pf[i-m]:0));
            ll x = pf[i]-(i-m>=0? pf[i-m]:0);
            // debug(m,i,ned, a[i]*m ,x);
            if (ned <= k){
                yes = 1;
                ops = min(ops, a[i]);
                debug(a[i]*m, x);
                debug(ned, i, a[i], m);
            }
        }
        debug(m, yes, ops);
        if (yes){
            res = m;
            a2 = ops;
            l = m + 1;
        } else r = m -1;
        debug(res,a2);
        // cerr << endl;
    }
    cout << res << " " << a2 << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

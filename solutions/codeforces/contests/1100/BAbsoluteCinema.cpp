#include <bits/stdc++.h>
#include <strstream>
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
    vl a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    vl c(n), low(n);
    for (int i = 0; i < n; i++){
        c[i] = max(a[i], b[i]);
        low[i] = min(a[i],b[i]);
    }
    vl pf = c;
    vl sf = c;
    vl lpf = low;
    vl lsf = low;
    for (int i = 1; i < n; i++) {
        pf[i] += pf[i-1];
        lpf[i] = max(lpf[i], lpf[i-1]);
    }
    for (int i = n-2; i >= 0; i--) {
        sf[i] += sf[i+1];
        lsf[i] = max(lsf[i], lsf[i+1]);
    }
    ll res = -INF;
    for (int i = 0; i < n; i++){
        ll bst = 0;
        ll mx = -INF;
        if (i > 0) {
            bst += pf[i-1];
            mx = max(mx, lpf[i-1]);
        }
        if (i + 1 < n) {
            bst += sf[i+1];
            mx = max(mx, lsf[i+1]);
        }   
        // choose a[i] 
        ll e1 = max(mx, a[i]) + bst + b[i];
        ll e2 = max(mx, b[i]) + bst + a[i];
        res = max({res, e1, e2});
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
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

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

// we need to maintain the max so far
// 

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vi pos;
    vb added(n);
    ll mx = a[0];
    ll ned = 0;
    for (int i = 0; i < n; i++){
        if (a[i] < mx){
            pos.pb(i);
            added[i] = true;
            ned = max(ned, mx - a[i]);
        }
        mx = max(mx, a[i]);
    }
    debug(a);
    debug(pos);
    debug(mx,ned);
    for (auto p: pos) a[p] += ned;
    debug(a);
    bool valid = true;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1] && !added[i]) a[i] += ned;
    }
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1]) valid = false;
    }
    if (valid) cout << "YES"<< endl;
    else cout << "NO" << endl;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

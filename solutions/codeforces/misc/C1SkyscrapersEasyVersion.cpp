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

// it must have exaclty 1 peak basically, 
// this peak CAN be tied
// we can try each build to be the peak 
//

void solve(){
    int n;
    cin >> n;
    vl a(n);
    vl b(n);
    for (auto& z:a) cin >> z;
    ll res = 0;
    int idx = 0;
    for (int i = 0; i < n; i++){
        // the peak building
        ll v = a[i]; 
        ll mx = v;
        ll sum = v;
        for (int j = i-1; j >= 0; j--){
            mx = min(a[j], mx);
            sum += mx;
        }
        mx = v;
        for (int j= i+1; j < n; j++){
            mx  = min(a[j], mx);
            sum += mx;
        }
        if (sum > res){
            res = sum;
            idx = i;
        }
        // res = max(res, sum);
    }
    // construct the ansewr 
    b[idx] = a[idx];
    ll m = a[idx];
    for (int i = idx-1; i >= 0; i--){
        m = min(m, a[i]);
        b[i] = m; 
    }
    m = a[idx];
    for (int i = idx+1; i < n; i++){
        m = min(m, a[i]);
        b[i] = m;
    }
    debug(idx);
    for (auto& z: b) cout << z << " ";

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

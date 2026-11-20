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
    int n,k;
    cin >> n >> k;
    vl a(n), t(n), pf(n);
    for (auto& z:a) cin >> z;
    for (auto& z:t) cin >> z;
    ll tot = 0;
    for (int i = 0; i < n; i++){
        if (t[i] == 1) tot += a[i];
        else pf[i] = a[i];
    }
    for (int i =1; i < n; i++) pf[i] += pf[i-1];
    debug(pf);
    ll mx = 0;
    for (int i = 0; i + k - 1 < n; i++){
        // range from [i, i+k-1]
        ll gain = pf[i+k-1];
        if (i>0) gain -= pf[i-1];
        mx = max(mx, gain);
    }
    cout << tot+mx << endl;
    // calcualte his current lectrures 
    // among all the 0s we count the max segment 
    //
    // calcuate number of lecture he already gain
    // calculate max gain 
    // OR just calculate one shot

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

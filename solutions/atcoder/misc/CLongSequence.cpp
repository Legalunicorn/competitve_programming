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
    vl a(n);
    for (auto& z:a) cin >> z;
    vl b = a;
    for (int i =1 ; i < n; i++) {

        b[i] = (b[i] +  b[i-1]) % INF;
        if (b[i] < 0) b[i] += INF;
    }

    ll sum = b[n-1];

    ll x;
    cin >> x;
    ll l = 0;
    ll r = INF;
    ll res = r;
    debug(a);
    debug(b);
    while(l <= r){
        ll m = l + (r - l) /2;
        
        ll mul = m / n;
        ll mod = m % n; // 0 1 2 3 4 , n = 5 
                        // ll calc =  (sum % INF) * mul % INF;
        ll calc = (sum * mul + INF) % INF;
        if (calc < 0) calc += INF;
        if (mod > 0 ) calc  = (calc + b[mod-1]) % INF;
        calc = (calc + INF ) % INF;
        if (calc < 0) calc += INF;

        debug(m, calc);

        if (calc >= x){
            res = m;
            r = m - 1;
        } else l = m + 1;
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

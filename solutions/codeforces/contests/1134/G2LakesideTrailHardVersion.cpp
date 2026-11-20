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
    ll n,k;
    cin >> n >> k;
    vl a(n);
    for(auto& z:a) cin >> z;
    ll l = 0, r = INF, res = INF;
    debug(a);
    int mx = -12313123;
    int pp = 0;
    for (int i = 0;i < n;i++){
        if (a[i] > mx){
            mx = a[i];
            pp = i;
        }
    }
    vi t;
    for (int i = pp; i < n; i++) t.pb(a[i]);
    for (int i = 0; i < pp; i++) t.pb(a[i]);
    for (int i = 0; i < n; i++) a[i] = t[i];


    // we should clear from 
    while(l<=r){
        ll m = l+(r-l)/2;
        debug(l,r,m);
        ll left = k;
        vl c = a;
        for (int i = 0; i < n; i++){
            int j = (i+n-1)%n;
            c[i] = max(c[i], c[j] -m);
        }
        for (int i = n-1; i >= 0; i--){
            int j = (i+1)%n;
            c[i] = max(c[i], c[j] - m);
        }
        for (int i = 0; i < n; i++) left -= (c[i] - a[i]);
        if (left>=0){
            res = m;
            r = m-1ll;
        } else l = m+1ll;
    }
    // cerr << endl;
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
    while(T--) solve();
    return 0;
}

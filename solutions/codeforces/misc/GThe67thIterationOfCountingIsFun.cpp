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

// ti > tj but a[i] < a[j] is possible 
// the only restriction on a[i] is must be larger than the curent number of people sitting down 
//
// 1. check that its possible 
// then we just multiply by all possitve 
// map<time, count> 
// let x be the number of lesser values 
// then possible values are [0, x] 

 
ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vi b(n);
    for (auto& z:b) cin >> z;
    map<ll,ll> mp;
    for (int i = 0 ;i  < n ; i++){
        if (b[i] != 0){
            bool has = false;
            if (i-1 >=0 && b[i-1] < b[i]) has = true;
            if (i+1 < n && b[i+1] < b[i]) has = true;
            if (!has){
                cout << 0 << endl;
                return;
            }
        }
        mp[b[i]]++;
        
    }
    if (mp[0] == 0) {
        cout <<0 << endl;
        return;
    }
    // they cant be 0 
    // [1, cnt]
    ll res = 1;
    ll mod = 676767677;
    ll cnt = mp[0];
    debug(b);
    debug(mp);
    for (int i = 1; i < m; i++){
        debug(i, mp[i], cnt, res);
        ll evl = binpowmod(cnt-1, mp[i], mod);
        res = (res * evl) % mod;
        cnt += mp[i];
    }
    cerr << endl;
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

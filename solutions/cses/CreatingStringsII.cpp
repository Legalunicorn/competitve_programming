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

int n = 1000005;
vl f(n);
void init(){
    f[0] = 1;
    for (int i = 1 ; i < n; i++) f[i] = i * f[i-1] % MOD;
}


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

ll inv(ll x){
    return binpowmod(x, MOD-2, MOD);
}


void solve(){

    string s;
    cin >> s;
    vi freq(26);
    for (char c:s) freq[c-'a']++;
    ll res = f[s.size()];
    debug(freq);
    debug(res);
    ll div = 1l;
    for (int i = 0; i < 26;i++){
        if (freq[i] == 0) continue;
        div = div * f[freq[i]] % MOD;
        debug(div);
    }
    debug(res, div, inv(div));
    res = res * inv(div) % MOD;
    cout << res << endl;
    
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

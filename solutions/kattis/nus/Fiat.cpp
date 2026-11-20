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


vl fac;
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
ll inverse(ll x){
    return binpowmod(x, MOD-2, MOD);
}

ll bc(int n, int k){
    return fac[n] * inverse(fac[k] * fac[n-k] % MOD) % MOD;
}

void solve(){
    // catalan numbers? idk why 
    // cn = (2n n) - (2n n-1);
    int n;
    cin >> n;
    int N = 2 * n + 1;
    fac.resize(N);
    fac[0] = 1ll;
    for (int i = 1; i < N; i++) fac[i] = fac[i-1] * i % MOD;
    debug(bc(3,2));
    ll res = (bc(2*n,n)  - bc(2*n, n-1) + MOD) % MOD;
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
    while(T--) solve();
    return 0;
}

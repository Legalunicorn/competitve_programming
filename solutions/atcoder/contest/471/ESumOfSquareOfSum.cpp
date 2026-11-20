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

ll mod = 998244353ll;
int N = 200005;
vl fac(N);

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

void init(){
    fac[0] = 1ll;
    for (int i = 1 ; i < N; i++){
        fac[i] = i * fac[i-1] % mod;
    }
}
ll inverse(ll x){
    return binpowmod(x, mod-2, mod);
}

ll ncr(int n, int k){
    return fac[n] * inverse(fac[k] * fac[n-k] % mod) % mod;
}

void solve(){
    int n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    if (k == 1){
        ll ans = 0ll;
        for (int i = 0; i < n; i++){
            ll x = a[i] * a[i] % mod;
            ans = (ans+x) % mod;
        }
        cout << ans << endl;
        return;
    }
    ll res = 0;
    ll chose = ncr(n-1,k-1);
    // mis read the problem we need to square it 
    // i think we can binomial this osme how maybe ?
    // no that (a+b)^n not (a+b+c+d+e)^n 
    // there is some identidit
    // (a+b+d+...e)^2 = 
    // square of each item ONCE 
    // 2 * pairwise of ever
    debug(n,k);
    debug(chose);
    // part 1 -:>> square of each item by count
    for (int i = 0; i < n; i++){
        ll val = chose * a[i] % mod;
        val = val * a[i] % mod;
        res = (res + val)% mod;
        debug(val,res);
    }
    // part2 : count pairwise? 
    ll p2 = ncr(n-2,k-2);
    vl sf = a;
    for (int i = n-2; i >= 0; i--){
        sf[i] = (sf[i] + sf[i+1]) % mod;
    }
    ll ans = 0ll;
    for (int i = 0; i+1 < n; i++){
        ll mul = a[i] * 2 % mod; // twice
        mul = mul * p2 % mod; // appearence count 
        mul = mul * sf[i+1] % mod; // 
        ans = (ans + mul) % mod;
    }
    debug(ans,res);
    res = (res + ans) % mod;
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

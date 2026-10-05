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



// NOTE:
// dp[i][used][even left] -> from [0,i]

ll dp[26][2][500005];
vl fac(500005);
void init(){
    fac[0] = 1;
    for (int i = 1; i < 500005;i++){
        fac[i] =  i * fac[i-1] % mod;
    }
    // for (int i = 0; i <= 10; i++) debug(i, fac[i]);
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

void solve(){
    int n = 26;
    vl a(n);
    for (auto& z:a) cin >> z;
    ll sum = 0;
    for (auto z:a) sum+=z;
    for (int i = 0; i < 26;i++){
        for (int j = 0; j < 2;j++){
            for (int k = 0; k <= sum; k++) dp[i][j][k] = -1; //reset
        }
    }
    ll e = sum/2;
    auto go = [&](auto& go, int i, int u, int left) -> ll {
        if (left == 0) return 1;
        if (left < 0 || i ==n) return 0;
        if (dp[i][u][left] != -1) return dp[i][u][left];
        ll one = 0, two = 0;
        if (a[i] > 0) one = go(go, i+1, 1, left - a[i]);
        two = go(go, i+1, 0, left);
        return dp[i][u][left ] = (one+two)% mod;
    };
    // numbber of ways to choose odd is the same as coose even?
    ll evl = go(go,0,0,e);
    ll o = sum - e;
    ll base = 1ll;
    for (auto z:a) base = base * fac[z] % mod;
    ll cnt = (fac[o] * fac[e] % mod) * binpowmod(base, mod-2, mod) % mod;
    ll res = evl * cnt % mod;
    cout << res << endl;
    debug(sum,e,o,base,cnt);
    debug(res,evl);
    // cerr << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}

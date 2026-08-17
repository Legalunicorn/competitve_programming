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

// NOTE: n chosoe r in O(1) with precomputation would be useful heere 
const int MAXN = 1001000;
ll factorial[MAXN];
ll inv_factorial[MAXN];
ll spf[MAXN];

void buildspf(){
    for (int i = 0; i < MAXN;i++) spf[i]=i;
    for (int i = 2; i * i < MAXN;i++){
        for (int j = i * i; j  < MAXN; j +=i){
            if (spf[j] == j) spf[j] = i;
        }
    }
};

map<int,int> factorize(int x){
    map<int,int> mp;
    while(x>1){
        mp[spf[x]]++;
        x /= spf[x];
    }
    return mp;
};

ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
};

ll modinv(ll x){
    return binpowmod(x, MOD-2, MOD);
};

ll ncr(int n, int k){
    return factorial[n] * inv_factorial[k] % MOD * inv_factorial[n-k] % MOD;
};
void init(){
    factorial[0] = 1;
    inv_factorial[0] = modinv(1LL);
    for (int i = 1 ; i < MAXN; i++) {
        factorial[i] = i * factorial[i-1] % MOD;
        inv_factorial[i] = modinv(factorial[i]);
    }
    buildspf();
};


void solve(){
    ll x,y;
    cin >> x >> y;
    ll res = 1;
    map<int,int> f = factorize(x);
    debug(x,f);
    for (auto& [val,freq]: f){
        ll evl = ncr(y + freq - 1, freq);
        debug(y+freq-1, y, evl);
        debug(val,freq,evl);
        res = res * evl % MOD;
    }
    ll free = binpowmod(2LL, y-1, MOD);
    res = res * free % MOD;
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
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

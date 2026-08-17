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

void init(){
    int n = 1000006;
    fac.resize(n);
    fac[0] = 1;
    for (int i = 1; i < n; i++){
        fac[i] = fac[i-1] * i % INF;
    }
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

ll inverse(ll x){
    return binpowmod(x, INF-2, INF);
}

ll bic(int n, int k){
    return fac[n] * inverse(fac[k] * fac[n-k] % INF) % INF;

}

ll C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}

void solve(){
    int n,k;
    cin >> n >> k;
    int m = n - k;
    int balls = m;
    int box = k;
    debug(balls,box);
    debug(balls+box-1, balls);
    cout << C(balls+box-1, balls) << endl;
    // answer is balls in boxses 
    //
};

int main(){
    ios::sync_with_stdio(0);
    init();
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}

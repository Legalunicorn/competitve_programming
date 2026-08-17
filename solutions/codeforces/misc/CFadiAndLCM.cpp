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




vector<ll> factor(ll n){
    vector<ll> res;
    for (ll i=2; i*i <= n;i++){
        if (n % i == 0){
            ll cur = 1;
            while (n%i==0){
                cur *= i;
                n /= i;
            }
            res.pb(cur);
        }
    }
    if (n>1) res.push_back(n);
    return res;
}



void solve(){
    ll x;
    cin >> x;
    vl fac = factor(x);
    int n = fac.size();
    pl res = {INF,INF};
    for (int m = 0; m < (1 << n); m++){
        ll l = 1, r = 1;
        for (int j = 0; j < n; j++){
            if ( (m >> j)&1 ) l *= fac[j];
            else r *= fac[j];
        }
        if (max(l,r) < max(res.F,res.S)){
            res = {l,r};
        }
    }
    cout << res.F << " " << res.S << endl;


    // vl a = factor(x)
    // pl ans;
    // ll mn = INF;
    // for (int i = 0; i < a.size(); i ++){
    //     ll l = 1, r = 1;
    //     for (int j = 0; j < a.size(); j++){
    //         if (j < i) l*=a[j];
    //         else r *=a[j];
    //     }
    //     if (max(l,r) < mn){
    //         ans = {l,r};
    //         mn = max(l,r);
    //     }
    // }
    // cout << ans.F << " " << ans.F << endl;
    // map<ll,int> mp = factor(x);
    // debug(mp);
    // ll l = 1, r = 1;
    // for (auto it = mp.rbegin(); it != mp.rend(); ++it){
    //     ll fac = it->F, cnt = it->S;
    //
    //     ll mul = binpow(fac, cnt);
    //     if (l > r) swap(l,r);
    //     debug(l,r, mul);
    //     l *= mul;
    //     debug(l,r, mul);
    //     debug("     ");
    // }
    // cout << l << " " << r << endl;
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

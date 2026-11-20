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
    int n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl pf = a;
    pf[0] %=k;
    for (int i = 1; i < n; i++) {
        pf[i] += pf[i-1];
        pf[i] %= k;
    }
    map<ll,int> mp;
    debug(k,a);
    debug(pf);
    ll res = 0;
    for (int i = 0; i < n; i++){
        int b = i-k-1;
        if (b==-1){
            mp[0]++;
        } else if (b>=0){
            mp[pf[b]]++;
        }
        ll c = pf[i];
        res += mp[c];
        debug(i, c, mp[c], res);
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

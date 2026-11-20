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
    ll n ,q;
    cin >> n >> q;
    vl a(n);
    for (auto& z:a) cin >> z;

    // store the end points
    vl pos;
    ll cur = 0;
    for (int i =0 ;i  < n; i++){
        cur+=(i+1);
        pos.pb(cur);
    }
    debug(pos);
    vl pf = a;
    for (int i = 1; i < n; i++) pf[i] += pf[i-1];
    vl lay = pf;
    for (int i = 1; i < n; i++) lay[i] += lay[i-1];

    auto s = [&](ll x) -> ll { // SUM from [0, x]
        auto it = lower_bound(all(pos), x);
        int pp;
        if (*it == x){
            pp = it - pos.begin();
            return lay[pp];
        }
        else{
            it--;
            pp =  it - pos.begin();
        }
        ll sum = lay[pp];
        int id = x - pos[pp]-1;
        sum += pf[id];
        return sum;
    };

    while(q--){
        ll l,r;
        cin >> l >> r;

        if (l == 1){
            if (r == 1) cout << a[0] << endl;
            else {
                ll evl = s(r);
                cout << evl << endl;
            }

        } else{
            ll res = s(r) - s(l-1);
            cout << res << endl;
        }
    }
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

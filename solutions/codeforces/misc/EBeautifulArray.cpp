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
    ll n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    map<ll, vl> mp;
    for (int i = 0; i < n; i++){
        ll d = a[i]%k;
        debug(d,i);
        mp[d].pb(a[i]);
    }
    debug(mp);
    int odd = 0;
    for (auto& [v,l]: mp){
        if (l.size()%2==1) odd++;
    }
    // 2 9 10 11 15
    if (odd > 1){
        cout << -1 << endl;
        return;
    }
    if (odd == 1 && n % 2 == 0){
        cout << -1 << endl;
        return;
    }
    ll res = 0ll;
    // the one with odd is a special case we either skip the first or the last
    // 2 + 4 = 6 
    // 4 + 1 = 5 
    // 11 
    //
    // 1 4 10 22 28 
    //
    // with odd we can exclude certain values but they must not skip 
    //
    // 1 2 3 4 5 6 7 
    // 1 (2 3) (4 5) (6 7)
    // (1 2) 3 (4 5) (6 7)
    // (1 2) (3 4) 5 (6 7)
    // (1 2) (3 4) (5 6) 7 
    //
    // we can only skip odd numbers
    //
    for (auto& [v, b]: mp){
        sort(all(b));
        if (b.size()%2==1){
            if (b.size()==1) continue;
            vl pf(b.size());
            vl sf(b.size());
            ll cum  =0ll;
            for (int i = 1; i < b.size();i+=2){
                cum += (b[i]-b[i-1])/k;
                pf[i] = cum;
            }
            cum = 0ll;
            for (int i = b.size()-2; i >= 0; i-=2){
                cum += (b[i+1]-b[i])/k;
                sf[i] = cum;
            }
            ll best = INF;
            for (int i = 0; i < b.size(); i+=2){
                ll evl = 0ll;
                if (i-1>=0) evl+=pf[i-1];
                if (i+1<b.size()) evl+=sf[i+1];
                best = min(best, evl);
            }
            res +=best;
        } else{
            for (int i =1;i<b.size();i+=2) res+=(b[i]-b[i-1])/k;
        }
    }
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

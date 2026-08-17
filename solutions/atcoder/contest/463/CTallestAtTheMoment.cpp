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

void solve(){
    int n;
    cin >> n;
    vpl a(n);
    for (int i = 0; i < n; i++) cin >> a[i].S >> a[i].F;
    // L firrsty, H second
    sort(all(a)); 
    debug(a);
    vl suff(n);
    for (int i = 0; i < n; i++) suff[i] = a[i].S;
    debug(suff);
    for (int i = n-2; i >= 0; i--) suff[i] = max(suff[i], suff[i+1]);
    debug(suff);
    int q; 
    cin >> q;
    debug(q);
    vl res(q);
    vpl qs(q);
    for (int i = 0; i  < q ; i++){
        cin >> qs[i].F;
        qs[i].S = i;
    }
    sort(all(qs));
    debug(q);
    int idx = 0; // current index of who to remove
    for (int i = 0; i < q; i++){
        ll t = qs[i].F;
        while(idx < n && a[idx].F <= t){
            idx++;
        }
        debug(i,n,idx);
        ll evl = suff[idx];
        res[qs[i].S] = evl;
    }
    for (auto& r: res) cout << r << " ";

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

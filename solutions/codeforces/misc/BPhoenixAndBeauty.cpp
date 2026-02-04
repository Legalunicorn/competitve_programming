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
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    set<int> st(all(a));
    if (st.size()>k){
        cout << -1 << endl;
        return;
    }
    vi rep;
    for (auto& z:st) rep.pb(z);
    while(rep.size()<k) rep.pb(1);
    vi res;
    for (int i =0;i<n;i++){
        for (auto& z:rep) res.pb(z);
    }

    cout << res.size() << endl;
    for (auto& z:res) cout << z << " ";
    cout << endl;
    // debug(st);
    // vi ans;
    // for (int i = 0; i < n; i++){
    //     for (auto& x: st) ans.pb(x);
    // }
    // cout << ans.size() << endl;
    // for (auto& z:ans) cout << z << " ";
    // cout << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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

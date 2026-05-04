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
    vvl g(n, vl(3));
    map<pl,ll> st;
    for (int i = 0; i < n; i++){
        for (auto& z: g[i]) cin >> z;
        st[{g[i][0], g[i][1]}] = INF;
    }
    ll cost = 0;
    ll left = g[0][0];
    ll lcost = g[0][2];
    ll right = g[0][1];
    ll rcost = lcost;
    // number of conins 
    for (int i = 0; i < n; i++){
        ll l = g[i][0], r = g[i][1], c = g[i][2];
        st[{l,r}] = min(st[{l,r}], c);

        if (g[i][0] < left){
            left = g[i][0];
            lcost = g[i][2];
        } else if (g[i][0] == left) {
            lcost = min(lcost, g[i][2]);
        }

        if (g[i][1] > right) {
            right = g[i][1];
            rcost = g[i][2];
        } else if (g[i][1] == right) rcost = min(rcost, g[i][2]);

        ll evl = INF;

        if (st.count({left,right})) evl = st[{left,right}];
        evl = min(evl, lcost + rcost);

        cout << evl << endl;
    }
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

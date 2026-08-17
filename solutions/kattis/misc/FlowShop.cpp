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
    int n,m;
    cin >> n >> m;
    // pick with lowest id? 
    // is this just simulation> 
    // worker 1: completes in predictable order easdy isnt it just sum of all 
    // ah no its not purely sum, its based on long long has been wasted 
    // -> if we wasted so much time that okay there is some MAX involve then sum 
    vvi g(n+1, vi(m+1));
    vvi f(n+1, vi(m+1));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    }
    vi res;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            g[i][j] += max(g[i-1][j], g[i][j-1]);
            if (j == m) res.pb(g[i][j]);
        }
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

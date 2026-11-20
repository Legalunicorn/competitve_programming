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
    int k;
    cin >> k;
    vector<vvi> gg(k);
    for (int t = 0; t < k; t++){
        int n; cin >> n;
        auto& g=gg[t];
        g.resize(n);
        for (int i = 0; i + 1 < n; i++){
            int u,v;
            cin >> u >> v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    // debug(gg);
    vi st;
    vi t(k);
    int p = 0;
    for (int i = 0;i < k; i++){
        if (gg[i].size() == 1) {
            st.pb(i);
            t[i] = 0;
        } else{
            p = i;
            auto &g = gg[i];
            for (int u=0 ;u< g.size(); u++){
                if (g[u].size() == 1){
                    t[i] = g[u][0];
                }
            }
        }
    }
    for (int i =0; i < k; i++){
        if (i==p) continue;
        cout << p+1 << " " << t[p]+1 << " " << i+1 << " " << t[i]+1 << endl;
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
    while(T--) solve();
    return 0;
}

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

// mAYBE FOR EACh of the current node 
// we can simply check the list of nodes it DONT  have access to 
// then the idea is that we try to expand the list 
// we travase by those we can see, but only checkk based on those we cant see? 
//

void solve(){
    int n,m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i = 0; i < n ;i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    vi seen(n,false);
    int cnt = 0;
    vi res;
    for (int i = 0; i < n; i++){
        if (!seen[i]){
            cnt = 1;
            seen[i] = true;
            queue<int> q;
            for (int j = 0; j < n; j++){
                if (!seen[j]){
                    queue.push(j);
                    cnt++''
                }
            }
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

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
    vvi g(n);
    vi deg(n,0);
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--, y--;
        g[x].pb(y); // [i ,j] i read first then
        deg[y]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    vi ans;
    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++){
            int t = q.front(); q.pop();
            cout << t + 1 << " ";
            for (int v: g[t]){
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
        }
    }
    cout << endl;

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

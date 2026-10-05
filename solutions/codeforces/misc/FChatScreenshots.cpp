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
    vvi g(n);
    vi indeg(n);
    for (int i = 0; i < k; i++){
        vi b(n);
        for (auto& z:b) cin >> z;
        for (int i = 2; i < n;i++){
            int u = b[i-1]-1, v = b[i]-1;
            g[u].pb(v);
            indeg[v]++;
        }
    }
    bool valid = true;
    queue<int> q;
    for (int i = 0; i < n ;i++){
        if (indeg[i] == 0){
            q.push(i);
        }
    }
    vi topo;
    while(!q.empty()){
        int len = q.size();
        for (int i = 0; i < len; i++){
            int t = q.front();
            q.pop();
            topo.pb(t);
            for (auto& v: g[t]){
                indeg[v]--;
                if (indeg[v] == 0){
                    q.push(v);
                }
            }
        }
    }
    cout << (topo.size() == n ? "YES":"NO") << endl;

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

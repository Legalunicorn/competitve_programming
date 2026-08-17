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

// did this wrongly 
// i think this is a simple dp problem 
// dp[n][2] -> max vertex tree

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    auto go = [&](auto& go, int u, int p) -> int {

    }



    // int cnt = 0;
    // queue<int> q;
    // q.push(0);
    // int d = 0;
    // vb seen(n);
    // seen[0] = true;
    // while(!q.empty()){
    //     int l = q.size();
    //     while(l--){
    //         int u = q.front();
    //         q.pop();
    //         for (int v: g[u]){
    //             if (!seen[v]){
    //                 seen[v] = true;
    //                 if (d%2 == 1) cnt++;
    //                 q.push(v);
    //             }
    //         }
    //     }
    //     d++;
    // }
    // cout << max(cnt, n-1-cnt) << endl;
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

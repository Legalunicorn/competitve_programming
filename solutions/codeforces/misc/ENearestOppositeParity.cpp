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

// each position has a fixed left and right 
// might be amortized anaylsis 
// we want to know for each position 
// 1. min number of moves to ODD, min number of moves to EVEN 
// 2. if odd -> ODD = 0, if even, EVEN = 0;
// so this is sort of like a dp position, pairty 
// we need to know if its imossible though 
// because if this state is on the dfs stack we need to inore
//

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a)cin >> z;
    // graph augmentation is trivial 
    // for each ODD, find the closest to any EVEN 
    // this is simple multisource bfs 

    vvi g(n), inv(n);
    for (int i = 0; i < n; i++){
        int l = i - a[i];
        int r = i + a[i];
        if (l >= 0){
            g[i].pb(l);
            inv[l].pb(i);
        }
        if (r < n){
            g[i].pb(r);
            inv[r].pb(i);
        }
    }
    vi res(n,-1);

    // solve for odds 
    {
        queue<int> q;
        int depth;
        depth = 1;
        vi resOdd(n, -1);
        for (int i = 0; i < n; i++){
            if (a[i]%2==0){
                q.push(i);
                resOdd[i] = 0;
            }
        }
        while(!q.empty()){
            int l = q.size();
            for (int z=0;z<l;z++){
                int u = q.front(); q.pop();
                for (int v: inv[u]){
                    if (resOdd[v] == -1){
                        resOdd[v] = depth;
                        q.push(v);
                    }
                }
            }
            depth++;
        }
        for (int i = 0; i < n;i++){
            if (a[i]%2==1)res[i] = resOdd[i];
        }
    }
    {
        queue<int> q;
        int depth = 1;
        vi resEven(n, -1);
        for (int i = 0; i < n; i++){
            if (a[i]%2==1){
                q.push(i);
                resEven[i] = 0;
            }
        }
        while(!q.empty()){
            int l = q.size();
            for (int z=0;z<l;z++){
                int u = q.front(); q.pop();
                for (int v: inv[u]){
                    if (resEven[v] == -1){
                        resEven[v] = depth;
                        q.push(v);
                    }
                }
            }
            depth++;
        }
        for (int i = 0; i < n; i++){
            if (a[i] % 2 == 0) res[i] = resEven[i];
        }
        
    }
    for(auto&r: res) cout << r << " ";
}



// void solve(){
//     int n;
//     cin >> n;
//     vi a(n);
//     for(auto&z:a)cin >> z;
//     debug(a);
//     int UNSEEN = -5;
//     int INVALID = -1;
//     int STACK = -10;
//     int MAX = 10*n;
//     vvi dp(n, vi(2, UNSEEN));
//     vi res(n);
//
//     // we need to use bfs instead 
//
//
//
//     // auto go = [&](auto& go, int i, int p) -> int {
//     //
//     //     if (i < 0 || i >= n || dp[i][p] == STACK) return dp[i][p] = INVALID;
//     //     if (dp[i][p] != UNSEEN) return dp[i][p];
//     //
//     //     if (a[i]%2==p) return dp[i][p] =  0;
//     //
//     //     dp[i][p] = STACK;
//     //     int res =  MAX;
//     //
//     //     int left = go(go, i - a[i], p);
//     //     if (left != INVALID) res = min(res, 1 + left);
//     //
//     //     int right = go(go, i + a[i], p);
//     //     if (right != INVALID) res = min(res,1 + right);
//     //
//     //     if (res == MAX) res = INVALID;
//     //
//     //     return dp[i][p] = res;
//     // };
//
//     for (int i = 0; i < n; i++){
//         dp[i][a[i]%2] = 0;
//     }
//
//     for (int i = 0; i < n; i++){
//
//         queue<pi> q;
//         int depth = 0;
//
//         int tp = 1 - (a[i]%2);
//         q.push({i, tp});
//         bool found = false;
//         int res = MAX;
//         set<int> st;
//         map<int,int> mp;
//         while(!q.empty() && !found){
//             int l = q.size();
//             for (int i = 0; i < l; i++){
//                 auto [idx, tp] = q.front();
//                 q.pop();
//                 if (dp[idx][tp] == STACK){
//                     dp[idx][tp] = INVALID;
//                     continue;
//                 }
//                 if (dp[idx][tp] != UNSEEN){
//                     res = min(res, depth + dp[idx][tp]);
//                     found = true;
//                     break;
//                 }
//                 // dp[idx][tp] = UNSEEN 
//                 if (a[idx]%2 == tp){
//                     res = min(res, depth + 1);
//                     dp[idx][tp] = depth + 1;
//                     found = true;
//                     break;
//                 }
//
//                 dp[idx][tp] = STACK;
//                 st.insert(idx);
//                 mp[idx] = depth;
//                 if (idx - a[idx] >= 0 && dp[idx-a[idx]][tp] != INVALID){
//                     q.push({idx-a[idx], tp});
//                 }
//                 if (idx+a[idx] < n && dp[idx+a[idx]][tp]!=INVALID){
//                     q.push({idx+a[idx], tp});
//                 }
//             }
//             depth++;
//         }
//         if (res == MAX) {
//             res = INVALID;
//             // for (auto& x: st) dp[x][tp] = INVALID;
//             for (auto& [x,d]: mp) dp[x][tp] = INVALID;
//         } else{
//             // for (auto& x: st) dp[x][tp] = 
//             for (auto& [x,d]: mp) dp[x][tp] = res - d;
//         }
//         dp[i][tp] = res;
//         cout << res << " ";
//         debug(dp);
//     }
//
// };

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

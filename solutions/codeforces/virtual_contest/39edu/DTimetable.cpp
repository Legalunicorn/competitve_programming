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


// if we skip 1 lesson we say 1 hour 
// but if there are gaps we save all the gaps as well 
// so there is some kind of optimal set up ? 
// n days eahc with lesson details of size m 
// skip k of them 
// using x skip there is a noptimal set up 
// but using (x + 1) skip it might be better on another day 
// m * n => full lessosn 
//
// the lower bound of what we save is K 
// we want to maximise the bonus ahours saved 
//
// if X lessons in total, time >= X 
// but we still need at least X - k hours 
// time >= X
// lower bound K 
// upper bound X - K 
// 11    00000 1 00 1 000000000 1 00 10 01 01 
// maybe we want to process by gaps ? 
// but each gap has an associated COST 
// gasp of 4 -> cost of 5 deletions 
// gap of 6 -> cost of 8 deletions 
// etc. 
// this sounds exactly like a knapsack problem 
// but itsd not, becuase there is ordering 
// some cost  is based on another coist 
//
//
// how about binary search? 
// how about dp? 
// -> each day we need to spend some K and its associated with some bonus 
// -> dp[i][k] gives the best cost from day[i..n] assuniming we have k left 
// should be cubic time complexity

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (auto& z:g) cin >> z;
    int sz = max(m,k);
    vvi cost(n+5, vi(sz+5, 1000000));
    for (int i = 0; i < n; i++){
        int tot = 0;
        for (char c: g[i])
            if (c=='1') tot++;
        for (int t = tot; t <= k; t++) cost[i][t] = 0; // if skip its free
        for (int s = 0; s < m ; s++){
            if (g[i][s] == '1'){
                int less = 0;
                for (int j = s; j < m; j++){
                    if (g[i][j] == '1') {
                        less++;
                        cost[i][tot-less] = min(cost[i][tot-less], j - s + 1);
                    }
                }
            }
        }
    }

    vvi dp(n, vi(k+1, -1));
    int inf = 1000000;
    auto go = [&](auto& go, int i, int k) -> int {
        if (i == n) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int res = inf;
        for (int j = 0; j <= k; j++){
            int evl = go(go, i + 1, k - j) + cost[i][j];
            res = min(res, evl);
        }
        return dp[i][k] = res;
    };

    int ans = go(go, 0, k);
    cout << ans << endl;
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















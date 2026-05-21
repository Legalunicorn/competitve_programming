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

// NOTE :
// try either the smallest numer 
// or the larger number 
//
// small 
// 1. if a,b > d then we have to skip the first digit 

// then ans is either same length 
// 1 digit less 
// 1 digit more 
// i think cant be empty 
//
// can we just dp thos 
// pos, {more,less,same}, {opt1,opt2, zero}
//
// base case if pos == n -> return 0; 
// alternative case 
// (pos == )

void solve(){
    ll a;
    cin >> a;

    int n;
    cin >> n;
    vi d(n);
    for (auto& z: d) cin >> z;
    int l = min(d[0],d[1]);
    int r = max(d[0],d[1]);
    string s = "0" + to_string(a);
    int m = s.size() + 1;
    ll dp[20][3][2];
    memset(dp, -1, sizeof(dp));
    vl p(m);
    p[m-1] = 1;
    for (int i = m-2; i >=0; i--) p[i] = 10*p[i+1];
    vi g(m);
    for (int i = 0; i < m; i++) g[i] = s[i]-'0';
    debug(s,p);
    memset(dp,-1,sizeof(dp));
    auto go = [&](auto& go, int i, int eq, int lead) -> ll {
        if (i == m) return 0LL;
        if (dp[i][eq][lead] != -1) return dp[i][eq][lead];
        if (eq == 0) return l * p[i];
        if (eq == 2) return r * p[i];
        ll res = 100*a;

        // choose empty 
        if (lead && i != m-1){
            int e2 = eq; // 1 
            if (0 < g[i]) e2 = 1; 
            ll evl = go(go, i+1, e2, lead);
            res = min(res,evl);
        }
        // choose 1 
        int lead2 = lead;
        if (lead && d[0] != 0) lead2 = 0;
        if (d[0] < g[i]) res = min(res, go(go,i+1, 0, lead2));
        else if (d[0] == g[i]) res =min(res, go(go,i+1, 1, lead2));
        else res = min(res, go(go, i + 1, 2, lead2));

        lead2 = lead;
        if (lead && d[1] != 0) lead2 = 0;
        if (d[1] < g[i]) res = min(res, go(go, i+1, 0, lead2));
        else if (d[1] == g[i]) res = min(res, go(go,i+1,1, lead2));
        else res = min(res, go(go,i+1, 2, lead2));
        return dp[i][eq][lead] = res;
    };
    ll ans = go(go, 0, 1 ,  1);
    cout << ans << endl;


    // there is some greedy involved 
    // if we are already bigger, then we just spam the smaller digier 
    // if we are smaller, we spam the larger





    // d.pb(0);
    // string s = "0" + to_string(a);
    // ll m  = s.size();
    // ll dp[20][3][3];
    // memset(dp, -1, sizeof(dp));
    // vi g(m);
    // for (int i = 0; i < m;i++) g[i] = s[i]-'0';
    //
    // vl p(m,0);
    // p[m-1] = 1;
    // bool hasz = (d[0] == 0 || d[1] == 0);
    // for (int i = m-2 ;i >= 0; i--){
    //     p[i] = p[i+1] * 10;
    // }
    // debug(d,m);
    // debug(s);
    // debug(p);
    //
    // auto go = [&](auto& go, int i, int eq, int lead) -> ll {
    //     debug(i,eq,lead);
    //     if (i == m){
    //         if (lead && !hasz) return 100*a;
    //         else return 0LL;
    //     }
    //     if (dp[i][eq][lead]!=-1) return dp[i][eq][lead];
    //     ll res = 100*a;
    //
    //     for (int k = 0; k < d.size(); k++){
    //         int op = d[k];
    //         int lead2 = lead;
    //         int eq2 = eq;
    //         if (lead2==1 && op != 0) lead2 = 0; // no longer leader 
    //         if (eq2 == 1){
    //             if (op < g[i]) eq2 = 0;
    //             if (op > g[i]) eq2 = 2;
    //         }
    //         ll cost = 0;
    //         ll mul = 0;
    //         // if (eq2 == 0) mul = g[i] - op;
    //         // else if (eq == 2) mul = op - g[i];
    //         if (eq2 == 0){
    //             if (g[i] < op) mul = g[i] - op;
    //             else if (g[i] > op) mul = g[i] - op;
    //         } else if (eq2 == 2) {
    //             if (g[i] > op) mul = op - g[i];
    //             else if (g[i] < op) mul = op - g[i];
    //         }
    //         cost = p[i] * mul;
    //         ll evl = go(go, i+1, eq2, lead2) + cost;
    //         res = min(res,evl);
    //
    //     }
    //     return dp[i][eq][lead] = res;
    // };
    // ll ans = go(go, 0, 1, 1);
    // cout << ans << endl;
    //
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

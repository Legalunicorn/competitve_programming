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


// NOTE:
// i think i have a sort of dp-isk solution but there is a hurdle with 1 1 1 1 1 
// perhaps we can compress all seqeuentives 1s? 
// 1 1 1 1 1 1 1 
// it does make a different though you either choose the first 1, and delete the whole chain, 
// or you coos ethe last "1" so that the guy on top takes on the fall damange
//
// initiallly my thought was 
// 1 
// 2
// 3 
// 4 
//
// PERF: deletion is never optimal at (1) 
// PERF: deletion of (4) first is non optimal
//          deletion of (3-h), (2-1) (1-1)
//          deletion of (2) (3-h) (1-1) * 
//       -> we can just delete (2) (1-h-2) (4) (3-h)
// PERF: we have to delete top (2) or (3), with exception of "1" chains
//  dp[i] -> min moves to delete A[i..n]
//  deletion as (2) -> cost2 + dp[i+2]
//  deletion as (3) -> cost3 + dp[i+3]
//
//  PERF: consier (3) (2) (1) 
//   -> delete (3) 
//       -> delete (2-h)
//       -> delete (1-1)
//       total: 3 + (2-h) + (1-1) + dp[+3]
//   -> delete (2) 
//      -> delete (1-h)
//      -> delete (3)
//      total + 3 + 2 + (1-h) + dp[+3]
//
//  maybe we need to consider the value of a[+3]  if a[+3] == 1 
//      -> we can sum - 1 
// PERF: handle 1 1 1 1 1 1 x 
// 1(x) 0 0 
//
//
// define dp[i] to be the min cost to delete a[i...n]
// 
//
// 3 1 4 1 2 
// 7 4 5 1 2
//
//
// x 1 4 1 2
// 
//
// dp[i] -> cost to remove a[i..n]
// i think we need to store the cost of asusming a[i] is on the ground
//
// there are two realistic options
// either u delete a[i] now then a[i-1] 
// or u delete a[i-1] first then a[i]
// how do we represent the stateps
// remove a[i+1] first -> then its just dp[i+1] isnt it?
// -> a[i] + dp[i+1]   // delete a[i+1] first
// -> a[i] +           // delete a[i] first -> a[i+1] - height 
//
// 0 -> goes last 
// 1 -> goes ahead
// last element -> goes ahead only
// dp[i][0] cost [i..n] normal
// dp[i][1] cost [i..n] assuming a[i] has fallen down 
//
// dp[i][1] = max(0, a[i]-h) + dp[i+1][1] 
//
// dp[i][0] = dp[i+1][0/1] + a[i]
// dp[i][1] = dp[i+1][0/1]
// e = dp[i+1] + a[i]   // trivial case 
// e = max(a[i+1]-h,0) +  a[i];
//
// q: why jump first? 
// a: so a[i+1] takes fall damange -> 
//
// implicication YOU fallen BEFORE killing on top -> cost is reset
// 3
// 2 
// 1
// 0
// if u were going to call 1,2,3 , u would call it before everything toppled
// so the only case is 0 

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl dp(n+1, INF);
    dp[0] = a[0];
    // dp[1] = a[0]+a[1]-1;
    for (int i = 1; i < n; i++){
        ll o1 = INF, o2 = INF;
        // i-1 had fallen, i-2 had fallen/killed also
        if (i-2>=0) o1 = a[i-1] + max(0ll, a[i]-i) + dp[i-2];
        o2 = a[i] + dp[i-1] -1;
        dp[i] = min(o1,o2);
    }
    cout << dp[n-1] << endl;
    
    // mob can only fall ONCE
    // if mob i takes > 1 damange, i-1 did not take fall damange
    //
    // methods to clear i

    // try a diffetene approach 
    // a[0...i] what is the death cost 
    // dp[0] = a[0];
    //


    // dp[n] = 0; 
    // dp[n-1] = a[n-1];
    // vl t(n);
    // int st = -1;
    // int cnt = 0;
    // // right direciton wrong idea
    // // X h 1 1 1 1 1 S 
    // for (int i = n-1; i >= 0; i--){
    //     if (a[i] == 1){
    //         if (st==-1) st = i+1;
    //         t[i] = st;
    //     } else {
    //         // currently not 1 
    //         if (a[i]>i){
    //             st= -1;
    //             t[i] = -1; 
    //             continue;
    //         }
    //         if (a[i] <= i){
    //             if (st == -1) t[i] = i+1;
    //             else t[i] = st;
    //             st = -1;
    //         }
    //     }
    // }
    //
    // ll u,v;
    // for (int i = n-2; i >=0; i--){
    //     // optimal options
    //     // u -> delete [i+1 ... n] then delete i
    //     u = dp[i+1]+a[i];
    //     // v -> delete [i+2...n] then i, then i+1
    //     v = dp[i+2] + a[i] +  max(a[i+1]-(i+1),0ll);
    //     dp[i] = min({u,v,dp[i]});
    //
    //     // last case is very tricky, related to 1,1,1,1 type of pattern
    //     // delete i  now, without i+2 first, 
    //     // or generalize it to delete [i] now, and find the chain a[i+1] = a[i+2] = ... = 1 , until a[j] != 1 
    //     // then we delete a[j] first then the whole segment
    //     // this is possible if a[i+1] == 1
    //     if (t[i+1] != -1){
    //        dp[i] = min(dp[i],  a[i] + dp[t[i+1]]-1);
    //     }
    // }
    // debug(dp);
    // debug(a);
    // debug(t);
    // cerr << endl;
    // cout << dp[0] << endl;

    
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

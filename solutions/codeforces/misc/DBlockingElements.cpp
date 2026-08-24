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
//
// considering binary searcyh 
// however cant combine with greedy because greedy is not optimal 
//
// BS 
// -> greedy
//      -> proof it dont work? 
//      -> we dont need to max full an element 
//      MAX = 200
//      20 50, 70 100 
//      [20, 50, 70] (100)  
//      [20, 50] (70) 100 -> ans = 100 
//
//      -> it might cap at 100, but we ca
//      -> im not sure maybe it works? 
//      what is the reason it dont work> assume we cap LIM 
//      (..<lim) [S1] (<...) [S2]    -> does it guarantee if this is > LIM, then any other choice is alsmo > LIM 
//      lim = 100 
//              10 39 [51]  40 40 [50]
//              10 [39] 51 40 [40] 50 
//       
//      can we find any invariant? 
//      lets assume the optimal answer exist 
//      .. x ... x .. x x .. x ..  
//      is there some function we can make? 
//      sumseg = tot 
//      chose = 
//      
//      the chosen elements double as both as a dividor and their own sum 
//
// low bund = MAX(a), answer is at least MAX 
// upper bound = SUM(a), answer is  at lmost sum(a), ie. just do nothing, this stategy would work 
//      
//      MAX = 1e9 
//      SUM = 1e14
//
// #direction 1 
//  - binary search + unknown state 
//      - naive greedy? -> no, found counter example
//      - dp -> sum as state is impossible
//
//  #diretion 2 
//   - ans is [MAX(A), SUM(a)]
//   
//  # directio n3 
//  - 
// 1) make observations about the nature of the problem 
// - th segment is only "max" we anything less than the max we can make however messy we like
// - if we have a set limit LIM ---> the naive dp is say, for (int j = 0;.. j++) so long CURR_SUM <= LIM: try 
//      - NAIVE DP 
//      - let dp[i] represent whether its possible to fit A[i...n] under LIM 
//      - repeatedly search over the "BREAK POINTS" -> assume at i, the last breakpoint is i-1 
//      - how to solve
//      sum  =0;
//      int possible = false;
//      // consideer j as the selected divisor
//      for (int j = i; j < n; j++){
//          sum += a[j];
//          dp[j+ 1][sum - a[j]]  // BUG: we require the to change to sum left to solve !! 
//      }
//    NOTE: i read first 2 sentence of editorial. binary search and dp was right but i cant solve it still 
//
//    let dp[i] be the min sum of blocked elements in the prefix UP to i,  ASSUMING i IS BLOCKED, and on each segment without blocks, SUM <= 5 
//    mayeb its 
//
//    -> suffix a "0" then get dp[n] as the answer, if the min < m , reeturn true, whether we pick "0" or not doesnt matter
//    -> prefix a "0" as well??? 
//    then 
//
//    -> we need to find the recurrance relation 
//      -> dp[i-1] ==> if (i-1) was blocked as well, then dp[i] = min(dp[i], dp[i-1] + a[i])
//      -> we can only avoid BLOCKING for so long. from a[j] ... a[i-1], j can go left so long the sum is <=n
//      -> dp[i] = min(a[i] + dp[j]), for some index j...i-1, 
//      -> we can maintain a segment tree on dp? but we are building our dp from left to right maybe we can compute min_suffix as well 
//      dp[i] = a[i] + min(dp[j]...dp[i-1]); 
//      we are askiung from dp[j] onwards, what is 
//      i can only see segtree soluton


// cringe solution
// binary search
//  -> dp 
//      -> segment tree



void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    ll r = 0;
    for (int i = 0; i < n;i++) r+=a[i];
    ll l = MAX(a);
    ll res = r;
    while(l<=r){
        ll m = l + (r-l)/2;
        vl dp(n+1);
        ll sumdp = 0LL;
        int lo = 0;
        map<ll,int> freq;
        set<ll> st;
        st.insert(0);
        freq[0]=1;
        // st.insert(INF);
        for (int i = 0; i < n; i++) {
            while(sumdp > m){
                sumdp -= a[lo];
                ll evl = dp[lo];
                lo++;
                freq[evl]--;
                if (freq[evl]==0) st.erase(evl);

            }
            dp[i+1] = a[i] + *st.begin();
            sumdp += a[i];
            freq[dp[i+1]]++;
            st.insert(dp[i+1]);
        }
        ll blocksum = 0LL;
        int yes = 0;
        for (int i = n-1; i >= 0;i--){
            if (blocksum <= m && dp[i+1] <= m) yes = 1;
            if (blocksum>m) break;
            blocksum += a[i];
        }
        if (yes) {
            r = m - 1;
            res = m;
        } else l = m + 1;
    }
    cout << res << endl;
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

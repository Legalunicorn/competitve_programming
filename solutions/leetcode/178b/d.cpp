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

#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;
const int inv= 1e9;

// good -> stricktly monotone goes all up or all down, we can treat as two separate case solve
// SUM Of digits -> new numerb -> good 
//
//
// fancy 
// 1. good 
// 2. sum digits -> good 
//
// i think this is some extreme digit dp 
//
// there is a double counter factor as we 
// this is definitely combinatorics or dp
//
// what if a number is both good and sum digits good? ie single digit number of 
// 45 -> 9, 
// 45 and 9 are both a valid sequence 
//
// sum of digits for 15 digits is only ~150 
// the issue here is double conuting if we try to do dp 
//
// maybe its combinatrics for monotonic, but the sum is an issue as well
// we cant exit on basis that seq is NOT monotomic, because the sum might be 
//
// 0 <= SUM <= 150 
//
// 1,2,3,4,5,6,7,8,9 
// the upper bound is 9 digits 
// the sum of digits is hardly related to the sequence AT ALL 
// i think if we prune like hell its possible to brute froce 
//
// DP 
// -> TIGHT 
// -> POS 
// -> SUM SO FAR 
// -> MIN_DIGT 
// -> MAX_DIGT  
// 
// digit dp is out only hope 
//
// dp [i] [tight] [sum] [is_up] [is_d] 
// when i == end 
//  -> if up or is down YES 
//  -> if sum is UP or DOWN: YES 
//  -> else no 
//
// NOTE:
// 1. strictly increase and strictly decreases are DISJOINT aside from single digits 
// 2. 

// dp[i][tight][sum][up][down][leading]
ll dp[17][2][200][15][15][2];


// maybe we use up, down as the digit tracker, but if it becomes invalid we use 10 
//

int INVALID =  12;


ll go(int i, int tight, int sum ,int up, int down, vi& nums, int leading){
    if (dp[i][tight][sum][up][down][leading] != -1) {
        return dp[i][tight][sum][up][down][leading];
    }
    if (i >= nums.size()) {
        if (up != INVALID || down != INVALID) return 1LL;
        int mn = 10;
        int mx = -1;
        bool v1 = true, v2 = true; 
        while(sum){
            int t = sum % 10;
            if (t <= mx) v1 = false;
            if (t >= mn) v2 = false;
            mn = min(mn, t);
            mx = max(mx, t);
            sum /= 10;
        }
        // debug(sum, v1, v2);
        if (v1 || v2) return 1LL;
        else return 0LL;
    }

    int L = 9;
    if (tight == 1) L = nums[i];
    ll res = 0;

    for (int d = 0; d <= L; d++) {
        int tightTOO = tight;
        int sumTOO = sum;
        int upTOO = up;
        int downTOO = down;
        int leadingTOO = leading;
        if (leadingTOO && d != 0) leadingTOO = 0;

        if (i == 0){
            downTOO = d;
            upTOO = d;
        }

        if (upTOO != INVALID){
            if (leading ==0 && i > 0 && d <= upTOO) upTOO = INVALID;
            else upTOO = d; // d > upTOo 
        }
        if (downTOO != INVALID){
            if (leading == 0 && i > 0 && d >= downTOO) downTOO = INVALID;
            else downTOO = d;
        }
        if (tightTOO == 1 && d < L) tightTOO = 0; // no longer right 
        sumTOO += d; // new sum 

        res += go(i+1, tightTOO, sumTOO, upTOO, downTOO, nums, leadingTOO);
    }
    return dp[i][tight][sum][up][down][leading] = res;
};


ll partial(ll x){
    memset(dp,-1, sizeof(dp));
    vi nums;
    while(x){
        nums.pb(x%10);
        x/=10;
    }
    reverse(all(nums));
    debug(nums);

    return go(0, 1, 0, 0, 11, nums,1);
}



class Solution {
public:
    long long countFancy(long long l, long long r) {
        debug(r-l);
        ll x = partial(r);
        ll y = partial(l-1);
        debug(x,y);
        ll res = x - y;
        return res;


    }
};


void solve(){
    debug(partial(30));
    // debug(partial(135));
    ll l,r;
    cin >> l >> r;
    Solution sol;
    cout << sol.countFancy(l, r) << endl;
}


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif

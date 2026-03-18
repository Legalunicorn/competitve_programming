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


// 10e 5 colors 
// how do we maintain the skip status? 
// we cant just "join" the cells 
// because only adjacency matters 
//
// we need to construct our dp from the pov 
// if we pic 


class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        // this deeps like a standard dp 

        // vvl dp(n, vl(2,-1)); 
        // auto go = [&](auto& go, int i, int skip) -> ll {
        //     if (i == n ) return 0;
        //     if (dp[i][skip] != -1) return dp[i][skip];
        //     ll ans = 0;
        //     // 
        // }
        vl dp(n, -1);
        auto dfs = [&](auto& dfs, int i) -> ll{
            if (i >= n) return 0LL;
            if (dp[i] != -1) return dp[i];
            // assume we can pick this 
            // pick 
            ll o1 = nums[i];
            ll internal = 0;
            if (i + 1 < n){
                if (colors[i] == colors[i+1]) internal = dfs(dfs,i+2);
                else internal = dfs(dfs,i+1); // its fine 
            }
            o1 += internal;
            ll o2 = dfs(dfs,i+1);
            return dp[i] = max(o1,o2);

        };

        return dfs(dfs,0);
    }
};

void solve(){
    
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

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

// #define endl '\n' 
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

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res = 0;
        // construct LIS in another way 
        // the idea is that we binary search for the number 
        // if it is the greatest we add it to the list 
        // otherwise we replace the leme
        for (int b = 0; b < 31; b++ ){
            vi lis;
            for (auto& x: nums){
                if (x >> b & 1){
                    auto it  = lower_bound(all(lis), x);
                    if (it == lis.end()) lis.pb(x);
                    else *it = x;
                }
            }
            res = max(res,(int)lis.size());
        }


        return res;
    }
};


void solve(){
    Solution sol;
    int n;
    cin >> n;
    vi a(n);
    for(auto& z:a)cin >> z;
    cout << sol.longestSubsequence(a) << endl;
}




#ifdef LOCAL
int main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif

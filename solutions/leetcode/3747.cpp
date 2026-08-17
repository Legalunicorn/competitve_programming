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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){

};

using ll = long long;

ll dp[20][1] = {0};
class Solution {
public:


    long long countDistinct(long long n) {
        vector<int> nums;
        ll t = n;
        while(t>0){
            nums.push_back(t%10);
            t/=10;
        }
        reverse(nums.begin(),nums.end());
        int sz = nums.size();
        
        auto go = [&](auto& go, int pos, int tight) -> ll {
            if (pos == sz) return 0;
            if (dp[pos][tight]!=-1) return dp[pos][tight];
            ll ans = 1;
            int lim;
            if (!tight) lim = 0;
            else lim = nums[pos];

            for (int d = 1; d<=lim; d++){
                int t2 = 0;
                if (tight && d==lim) t2 = 1;
                ans += go(go,pos+1,t2);   
            }

            return dp[pos][tight] = ans;
        };

        ll res = go(go,0,1);
        return res;
    }
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

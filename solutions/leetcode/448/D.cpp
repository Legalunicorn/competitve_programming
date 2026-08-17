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


// i dont get the first eample?
// why not 3 * 5 + 2 * 4 = 15 + 8 = 23 
// oh we are limited to first k indices only 
// why cant we brute force select the best option?
// 100 * 100 * 100 ? 
// 1 00 00 00 
//

ll dp[101][101][101];

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        

        // N = n;
        // M = m;
        // ll dp[101][101][101];
        for (int i =0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                for (int l = 0; l <= k ; l++){
                    dp[i][j][l] = -1LL;
                }
            }
        }

        auto go = [&](auto& go, int i, int j, int k) -> ll{
            if (k == 0) return 0;
            else if (k < 0 || i == n || j == m) return -40000000000000000LL;
            if (dp[i][j][k]!=-1LL) return dp[i][j][k];

            ll ans = (ll)a[i] * b[j] + go(go,i+1,j+1,k-1);
            ans = max(ans, go(go,i+1,j,k));
            ans = max(ans, go(go,i,j+1,k));

            return dp[i][j][k] = ans;

        };
        ll res = go(go, 0, 0, k)   ;
        return res;
    }
};


void solve(){
    int it = 100;
    vi a(it,-1);
    vi b(it, 1);
    Solution sol;
    cout << sol.maxScore(a, b,1 ) << endl;
    
};


#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif


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

// might be some disgusting dp 
// dp[i][w1][w2]
// either we take from w1 
// or we take from w2 
// or we take from neither and both ++ 
// we need to count the number of distinct ways 
// dp[i][w1][w2] IS the number of distinct wyas 
// the hard certieratin is that 
// let w1 is NEXT POS  to use 
// so if either is 0 i
//s faled



// ll dp[102][102][102][2][2];
ll dp[102][102][102];
ll dp1[102][102][102];
ll dp2[102][102][102];



class Solution {
public:
    int interleaveCharacters(string p, string q, string t) {
       int n = p.size(), m = q.size(),  l= t.size();
       for (int i = 0; i <= l; i++){
           for (int j = 0; j <= n; j++){
               for (int k = 0; k <= m; k++){
                   dp[i][j][k] = -1;
                   dp1[i][j][k] = -1;
                   dp2[i][j][k] = -1;
               }
           }
       }
        function<ll(int,int,int)> go, go1, go2;
        go = [&]( int i, int j, int k) -> ll{
           if (i >= l) return (j && k ? 1 : 0);
           if (dp[i][j][k] != -1) return dp[i][j][k];
           ll ans = go1(i,j,k);
           ans = (ans + go2(i,j,k)) % MOD;
           return dp[i][j][k] = ans;
       };
       // search from p 
        go1 = [&]( int i, int j, int k) -> ll{
           if (j == n) return 0;
           if (dp1[i][j][k] != -1) return dp1[i][j][k];
           ll ans = go1(i, j+1, k);
           if (p[j] == t[i]) ans = (ans +  go(i+1,j+1,k) ) % MOD;
           return dp1[i][j][k] = ans;
       };
       // search from q
        go2= [&]( int i, int j, int k) -> ll{
           if (k == m) return 0;
           if (dp2[i][j][k] != -1) return dp2[i][j][k];
           ll ans = go2( i, j, k + 1);
           if (q[k] == t[i]) ans = (ans + go( i+ 1,j , k+1)) % MOD;
           return dp2[i][j][k] = ans;
       };

       ll res = go(0,0,0);
       return (int) res;
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

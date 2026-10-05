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

//#define endl '\n' 
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







class Solution {
public:
    vector<int> largestPower(vector<int>& a) {
        int n = a.size();
        // lex -> gredy 
        // we want to set pow if possible 
        // the only issue is tie breaks
        // sqrt n   x  n 
        // n log n 
        // we cvan split this by bit
        // 32 n log n 
        // 14 | 13 | 12 | 11 
        // we must ortder them byh bit set 
        // within each group we need to recursively order them
        // 15 depths in total
        sort(rall(a));

        vi res(15,0);
        for (int i = 0; i < 15; i++){
            int cnt =0;
            for (int j = 0; j < n; j++){
                int s = 14 - i;
                if (a[j] >> s & 1) cnt++;
                else break;
            }
            res[i] = cnt;
        }
        return res;
    }
};


// void solve(){
//
// };
//
//
//
//
//
// int main(){
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
//     // // freopen("file.in","r",stdin);
//     // // freopen("file.out","w",stdout);
//     // int T =1;
//     // // cin >> T; 
//     // while(T--) solve();
//     // return 0;
// }

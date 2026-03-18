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

class Solution {
public:
    long long gcdSum(vector<int>& a) {
        // construct max 
        // constuct prefix gcd 
        // sort gcd in acesing orer
        ll res = 0; 
        int n = a.size();
        vi mxx(n);
        int mx = a[0];
        for (int i = 0; i < n; i++){
            mx = max(mx, a[i]);
            mxx[i] = mx;
        }
        vi b(n);
        for (int i = 0; i < n; i++){
            b[i] = __gcd(mxx[i], a[i]);
        }
        sort(all(b));
        debug(b);
        // take the smallest unpair with larges 
        for (int i = 0; i < n/2; i++){
            if (i == n - 1 - i) break;
            int x = b[i];
            int y = b[n - 1 - i];
            res += __gcd(x,y);
        }
        return res;

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

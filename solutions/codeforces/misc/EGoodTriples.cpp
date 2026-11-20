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

ll dp[10];

void init() {
    for (int d = 1; d < 10; d++) {
        ll res = 0;
        for (int i = 0; i <= d; i++){
            for (int j = i; j <= d; j++){
                for (int k = j; k <= d; k++){
                    if (i + j + k == d){
                        // 0 same 
                        if (i == j && j == k) {
                            res++;
                        } else if (i == j || j == k){
                            // x x y 
                            res+=3;
                        } else {
                            res+=6;
                        }
                    }
                }
            }
        }
        dp[d] = res;
    }
    dp[0] = 1;
}
void solve(){
    int n;
    cin >> n;
    ll res = 1;
    while(n){
        int m = n % 10;
        res *= dp[m];
        n /= 10;
    }
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}

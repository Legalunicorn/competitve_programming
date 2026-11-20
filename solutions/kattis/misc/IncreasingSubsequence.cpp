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

void solve(int n){
    vl a(n);
    for (auto& z:a)  cin >> z;  
    // lexigraphically smallest LIS 
    vl dp(n, 1);
    vl b(n, -1);
    vl res;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[j] < a[i]){
                int evl = dp[j] + 1;
                if (evl > dp[i]){
                    dp[i] = evl;
                    b[i] = j;
                } else if (evl == dp[i]){
                    int one = a[b[i]];
                    int two = a[j];
                    if (two < one){
                        b[i] = j;
                    }
                }
            }
        }
    }
    int pos = 0;
    int mx = 1;
    for (int i = 0; i < n; i++){
        if (dp[i] > mx){
            mx = dp[i];
            pos = i;
        } else {
            if (dp[i] == mx && a[pos] > a[i]){
                pos = i;
            }
        }
    }
    int cur = b[pos];
    res.pb(a[pos]);
    while(cur != -1){
        res.pb(a[cur]);
        cur = b[cur];
    }
    reverse(all(res));
    cout << res.size() << " ";
    for (auto& r: res) cout << r << " ";
    cout << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(cin >> T && T != 0) solve(T);
    return 0;
}

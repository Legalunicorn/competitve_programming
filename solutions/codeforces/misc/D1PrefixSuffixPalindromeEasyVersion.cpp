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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vvb dp(n, vb(n));
    for (int i = 0; i < n; i++) dp[i][i] = true;
    for (int len = 1; len < n; len++){
        for (int l = 0; l < n; l++){
            int r = l + len;
            if (r < n){
                if (s[l] == s[r] && (len == 1 ||  dp[l+1][r-1]))  dp[l][r] = true;
            }
        }
    }
    string t = s;
    reverse(all(t));
    int res = 1;
    pi pos {0, n};
    debug(s,t);
    // string ans = to_string(s[0]);
    for (int l = 0; l < n; l++){
        int end = n - 1 - l;
        for (int start = l; start <= end; start++){
            if (s =="acbba") debug(l, start,end, dp[start][end]);
            if (dp[start][end]){
                ll evl = l + (n - start);
                if (evl > res){
                    res = evl;
                    pos = {l-1, start};
                }
            }
        }
        if (t[l] != s[l]) break; // there is no use
    }
    for (int r = n-1; r >= 0; r--){
        int start = n - r - 1;
        for (int end = start; end <= r; end++){
            if (dp[start][end]){
                ll evl = end + (n - r);
                if (evl > res){
                    res = evl;
                    pos = {end, r+1};
                }
            }
        }
        if (t[r] != s[r]) break;
    }
    string ans = "";
    for (int i = 0; i <= pos.F; i++) ans += s[i];
    for (int i = pos.S; i < n; i++) ans += s[i];
    cout << ans << endl;
    debug(dp);
    cerr << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

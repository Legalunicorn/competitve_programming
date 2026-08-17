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
    int q;
    cin >> s >> q;

    int n = s.size();
    // preprocess
    vvb dp(n, vb(n, false));
    for (int i = 0; i < n; i++) dp[i][i] = true; // one character is a palindrome
    // i think there are multiple ways the build this 
    // i remember we can do from center then spread outwards 
    for (int i = 0; i < n; i++){
        for (int l = i-1, r = i; r <= i + 1; r++){
            int left = l, right = r;
            while(left >= 0 && right < n && s[left] == s[right]){
                dp[left][right] = true;
                left--, right++;
            }
        }
    }

    // read query
    while(q--){
        int l,r;
        cin >> l >> r;
        l--, r--;
        if (dp[l][r]) cout << "YES" << endl;
        else cout << "NO" << endl;
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

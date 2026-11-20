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

// NOTE:
// im pretty sure we can brute force this in n log n 
// let me think about it first 


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi a(n);
    for (int i = 0; i < n; i++) a[i] = s[i]-'a';

    vvi pf(n , vi (26,0));
    for (int i = 0; i < n; i++){
        int u = a[i];
        pf[i][u]++;
    }
    for (int i = 1 ; i < n; i++){
        for (int c = 0; c < 26; c++){
            pf[i][c] += pf[i-1][c];
        }
    }
    debug(pf);


    auto get = [&](int l, int r, int c) ->  int{
        // get returns te cout 
        // but we want the MISSING COUNT 
        int ans = pf[r][c] - (l > 0 ? pf[l-1][c]: 0);;
        debug(l,r,c,ans);
        return r - l + 1 - ans;

    };
    auto dfs = [&](auto& dfs, int l, int r, int c) -> int {
        debug(l,r,c);
        if (l == r) return (a[l]==c ? 0 : 1);
        
        // given a range we try both left half and right half 
        // 1. calculate left count + recurse rigth 
        // 2. calculate right count + recourse left 
        int mid = (l + r)/2; // 0 8 -> 4 , 0 to mid 
        int left = get(l, mid, c) + dfs(dfs,mid+1,r, c+1);
        int right = get(mid+1, r, c) + dfs(dfs,l, mid, c+1);
        return min(left , right);
    };
    cerr << endl;

    int res = dfs(dfs,0, n-1, 0);
    cout << res << endl;


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

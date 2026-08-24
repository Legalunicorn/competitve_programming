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

// NOTE: 
// odd length -> all char must be equal 
// even length 
//  -> a,b,a,b,a,b 
//  -> a,a,a,a,a,a,
//
//  we can only ease characters 
//  and there are only 10 unique characters
//
//
//  note: n - max_freq is OPTIMAL for making all equal 
//  the alternative is a,b,a,b pattern 
//  we can try all a,b, patterns and exclude a==b 
//  must also check the if start with "a" then must end with "b" -> trivial we can if it ends with "a" we can just remove the last "a"! 
//  for each pattern can we build greedily? yes 
//  

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int res = n;
    int mf = 0;
    vi freq(10);
    vi a(n);
    for (int i = 0; i < n; i++) a[i] = s[i]-'0';
    for (char c:s){
        freq[c-'0']++;
        mf = max(mf, freq[c-'0']);
    }
    res = n - mf; 
    for (int x = 0; x <= 9; x++){
        for (int y = 0; y <= 9; y++){
            if (y == x) continue;
            int nxt = x;
            int del = 0;
            for (int i = 0; i < n; i++){
                if (a[i] == nxt){
                    if (nxt == x) nxt = y;
                    else nxt = x;
                } else{
                    del++;
                }
            }
            if (nxt ==y) del++;
            res = min(res, del);
        }
    }
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
    while(T--) solve();
    return 0;
}

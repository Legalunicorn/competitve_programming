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
    int n,a,b;
    cin >> n >> a >> b;
    string s; cin >> s;
    // vi g;
    // int cnt = 0;
    // for (int i = 0; i < n; i++){
    //     if (s[i] == '*'){
    //         if (cnt > 0){
    //             g.pb(cnt);
    //             cnt = 0;
    //         }
    //     } else cnt++;
    // }
    // if (cnt > 0) g.pb(cnt);
    // debug(g);
    // int l = min(a,b), r = max(a,b);
    // int res = 0;
    // for (auto& x: g){
    //     int m = x/2; 
    //     int take = min(l, m);
    //     int other = take;
    //     if (x%2==1 && r >= other+1) other++;
    //     l -= take;
    //     r -= other;
    //     res += (take + other);
    //     if (l > r) swap(l,r);
    // }
    // cout << res << endl;
    //
    //debug()s
    int res = 0;
    debug(s);
    int last = -1;// 0 -> a, 1 -> b
    for (int i = 0; i < n; i++){
        if (a == 0 && b == 0) break;
        if (s[i] == '*') last = -1;
        else{
            if (last == -1){
                if (a > b) a--, res++, last = 0;
                else if (b > a) b--, res++, last = 1;
                else if (a > 0) a--, res++, last = 0; 
                else last = -1;
            } else if (last == 0){
                if (b>0){
                    b--, res++, last = 1;
                } else last = -1;
            } else {
                if (a>0){
                    a--, res++, last = 0;
                } else last = -1;
            }
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

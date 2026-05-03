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

// a maybe can reach PEAK 
// NOTE: 
// 1. store the final answer at the end 
// 2. keep track of all player scores 
// 3. iterate all values = max and see who got ealrier


void solve(){
    int n;
    cin >> n;
    map<string, vpi> mp;
    for(int i = 0; i < n; i++){
        string s;
        int p;
        cin >> s >> p;
        mp[s].pb({p,i});
        if (mp[s].size()>1){
            auto& vv = mp[s];
            int m = vv.size();
            vv[m-1].F += vv[m-2].F;
        }
    }
    int mx = -100000000;
    for (auto& [s, v]: mp){
        mx = max(mx, v.back().F);
    }
    debug(mp);
    debug(mx);
    string res = "";
    int first = n + 10;
    for (auto& [s,v]: mp){
        if (v.back().F < mx) continue;
        for (auto& p: v){
            if (p.F >= mx && p.S <= first){
                first = p.S;
                res = s;
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

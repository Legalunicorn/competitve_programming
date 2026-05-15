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
// process array, for each element break dow ninto 
// prime factor frequency 
// push the frequency to the associated prime factor 
// <pf , vector<freqes> 
// 
//
// for each answer from 1 to MAX  
// -> break down to prime factors and check that output is satisfied

map<int,int> factor(int n){
    map<int,int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res[i]++;
            n /= i;
        }
    }
    if (n>1) res[n]++;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    map<int, vi> mp;
    int mx = 1;
    for (int i = 0; i < n;i++){
        int x; cin >> x;
        mx = max(mx,x);
        auto  m = factor(x);
        for (auto& [v,c]:m) mp[v].pb(c);
    }
    for (auto& [x,ls]: mp) sort(all(ls));
    int res = 1;
    // debug(mp);
    for (int i = 1; i <= mx; i++){
        auto m = factor(i);
        if (i>990) debug(i, m);
        if (i>990) debug(mp);
        bool valid = true;
        for (auto& [v,c]:m){
            if (!mp.count(v)) {
                valid = false;
                break;
            }
            auto& ls = mp[v];
            if (ls.size() < 2 || ls[ls.size()-2]<c){
                valid = false;
                break;
            }
        }
        if(i>990) debug(valid);

        if (valid) res = i;
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

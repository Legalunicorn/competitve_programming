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

void solve(){
    int n,k;
    cin >> n >> k; 
    map<int,int> mp;
    vi a(n);
    int best = 0;
    pi val= {1,1};
    for (auto& z:a) cin >> z;
    auto check = [&](int x) -> bool{
        if (mp.size() < k) return true;
        if (mp.count(x)) return true;
        return false;
    };
    for (int l = 0, r = 0; l < n; l++){
        while(r < n && check(a[r])){
            mp[a[r]]++;
            r++;
        }
        debug(l,r);
        if (mp.size() <= k) {
            int rng = r-l;
            if (rng>best){
                best = rng;
                val = {l+1,r};
            }
        }
        mp[a[l]]--;
        if (mp[a[l]] == 0) mp.erase(a[l]);
    }
    cout << val.F << " "<< val.S << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

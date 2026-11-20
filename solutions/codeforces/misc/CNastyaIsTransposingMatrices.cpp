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
    int n,m;
    cin >> n >> m;
    vvi a(n, vi(m));
    vvi b(n, vi(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m;j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m;j++) cin >> b[i][j];
    }
    debug(a,b);
    //start at the top 
    //the at the right 
    map<int,int> mp;
    auto go = [&](int r, int c) -> bool{
        map<int,int> mp;
        while(r < n && c >= 0){
            mp[a[r][c]]++;
            mp[b[r][c]]--;
            r++;
            c--;
        }
        for (auto& [v,c]: mp){
            if (c != 0) return false;
        }
        return true;
    };
    for (int c = 0; c < m; c++){
        bool evl = go(0,c);
        if (!evl){
            debug(".", c);
            cout << "NO" << endl;
            return;
        }
    }
    for(int r = 0; r < n; r++){
        if (!go(r, m-1)){
            debug("..",r);
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

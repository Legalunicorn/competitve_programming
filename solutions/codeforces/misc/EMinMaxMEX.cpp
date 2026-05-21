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

// split into subarrays 
// this calls for dp? 
// no this calls for binary search 

// the mex is from 0 to n - 1 
// then we cna greedy split until its possible 
// 

struct Dsu{
public:
    int n; 
    vector<int> par, size;
// public:
    Dsu(int sz){
        n = sz;
        size.assign(n,1);
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
    }

    int find(int v){
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void union_set(int a, int b){
        a = find(a);
        b = find(b);
        if (a != b){
            if (size[a] < size[b]) swap(a,b);
            par[b] = a;
            size [a] += size[b];
        }
    }
};


void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    debug(a);
    int l = 1, r = n+2;
    int res = 0;

    // need to check mex as we go thorugh 
    // n log n -> slow 
    // consiee
    int lm = n;
    auto go = [&](int t) -> bool{
        int cnt = 0, cur = 0;
        vb vis(t);
        // mex = 3, [0,1,2]
        // int cur = 0, 
        // amortized analysis? 
        for (int i = 0; i < n; i++){
            if (a[i] >= t) continue;
            if (a[i] >= cur) vis[a[i]] = true;
            // vis[a[i]] = true;
            while(cur < t && vis[cur]){
                vis[cur] = false;
                cur++;
            }
            if (cur == t) {
                cnt++;
                debug(t,i,cnt,vis);
                cur = 0;
            }
            if (cnt == k) return true;
        }
        return false;
    };

    while(l<=r){
        int m = (l+r)/2;
        bool e = go(m);
        debug(a,m,e);
        if (e){
            res = m;
            l = m + 1;
        } else r = m -1;
    }
    cout << res << endl;
    cerr << endl;
    // vi freq(n+1, 0);
    // int l = 0;
    // for (auto& z:a){
    //     if (z <= n) freq[z]++;
    //     else l++;
    // }

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

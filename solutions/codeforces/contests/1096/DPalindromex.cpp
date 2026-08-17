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


// thre is a second case of using only the center zero 

// wrong observation! 
// MEX != only the numbers must be inside 
// current approach, try building up mex 
//
// alternative:
// - focus on palindroms 
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
    int n;
    cin >> n;
    vi a;
    map<int,vector<int>> mp;
    for (int i = 0; i < 2 *n; i++){
        int x; cin >> x;
        a.pb(x);
        mp[x].pb(i);
    }

    // NOTE: zero is always in the MEX 
    // why not we just build for each 
    // 1. both zero 
    // 2. left zero.
    // 3. right zero
    debug(a);
    int res = 1;
    for (int k = 0; k < 3; k++){
        Dsu dsu(n+5);
        int left = min(mp[0][1], mp[0][0]);
        int right = max(mp[0][1], mp[0][0]);
        // ld mid = (left + right) /2;
        if (k == 1) {
            right = left;
            // mid = left;
        } else if ( k == 2){
            left = right;
            // mid = right;
        }

        int missing = 1;
        vb seen(n+5,0);
        seen[0] = true;
        int l = left, r = right;
        bool fake = false;
        if (k == 0){
            while(l <=r){
                if (a[l] != a[r]) fake = true;// invalid
                else {
                    int x = a[l];
                    if (x!=0){
                        seen[x] = true;
                        if (x+1 < n && seen[x+1]) dsu.union_set(x,x+1);
                        if (x-1 >= 0 && seen[x-1]) dsu.union_set(x,x-1);
                    }
                }
                l++, r--;
            }
        }
        if (fake) continue;
        bool stop = false;
        l = left, r = right;
        debug(k,l,r, fake);
        while(l >= 0 && r < 2*n && !stop){
            debug(a[l], a[r]);
            if (a[l] == a[r]){
                int x = a[l];
                seen[x] = true;
                if (x-1 >=0 && seen[x-1]) dsu.union_set(x,x-1);
                if (x+1 < n && seen[x+1]) dsu.union_set(x,x+1);
                int rr = dsu.size[dsu.find(0)];
                // debug(rr,k,l,r);
                res = max(res,rr);
            } else {
                stop = true;
            }
            l--, r++;
        }
    }
    cout << res << endl;
    // cerr << endl;

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

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

vb skip(1000000,false);

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    int mx = 1;
    // each list should not have duplicate
    for (int i =0; i < n; i++){
        int cnt; cin >> cnt;
        vi lis;
        for (int j = 0; j < cnt ; j++){
            int x;
            cin >> x;
            mx = max(mx, x);
            lis.pb(x);
        }
        // reverse(all(g[i]));
        reverse(all(lis));
        set<int> seen;
        for (auto& z: lis){
            if (!seen.count(z)){
                g[i].pb(z);
                seen.insert(z);
            }
        }
    }

    for (int i = 0; i <= mx; i++) skip[i] = false;

    vi Q;
    vb used(n,false);
    vvi  out;
    for (int x = 0; x < n; x++){
        int ans = -1;
        for (int i = 0; i < n; i++ ){
            if (used[i]) continue;
            if (ans == -1) ans = i;
            else {
                if (g[i] < g[ans]) ans = i;
            }
        }

        used[ans] = true;
        out.pb(g[ans]);
        for (int v: g[ans]){
            if (skip[v]) continue;
            Q.pb(v);
            skip[v] = true;

        }
        
        for (int i = 0; i < n; i++){
            if (used[i]) continue;
            vi up;
            for (int u : g[i]){
                if (!skip[u]) up.pb(u);
            }
            g[i] = up;
        }
    }
    reverse(all(out));
    for (int i = 0; i < Q.size(); i++){
        cout << Q[i] << " ";
    }
    cout << endl;


    //
    // vpi a(mx);
    // for (int i = 0; i < mx; i++){
    //     a[i] = {-1,i+1};
    // }
    // int id = 0;
    //
    // for (auto& ls: out){
    //     for (int i = ls.size() - 1; i >=0; i--){
    //         int p = ls[i]-1;
    //         a[p].F = id;
    //         id++;
    //     }
    // }
    // sort(a.rbegin(), a.rend());
    // for (int i = 0; i < mx; i++ ){
    //     if (a[i].F != -1) cout << a[i].S << " ";
    // }
    // cout << endl;
    // cerr <<  endl;

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

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

// the delta of two coeficients form a new quadratic equation 
// this equation must have no slutoin 
// means the discriminatinatn is less than 0 
//
// b^2 - 4 ac 
//
//
// for all delta B, A,C 
// we are allowed n^2 computation 
// for each i 
// we can find if j intersects 
// however its no guarantee that "j" is the best option 
// i think we can just greedily pick fuck it ? 
// no but then this is 3F 
// i think we can union all pairs that DO intersect 
// then we pick one from every non same group



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


// 1. union all pairs that intersect 
// wait but it is not transitive 
// 2. for each i, 
// lets say we union 
// how many can we extract from this gorup
// is this PIE? 
// maybe we form a graph instead ? 
// edge -> intersections 
// is this bipartite color ing 
//


void solve(){
    int n;
    cin >> n;
    vvi a(n, vi(3));
    Dsu dsu(n+1);
    vi res(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    debug("o!");
    vvi g(n);
    for (int i = 0; i < n; i++){
        for (int j = i +1; j < n; j ++){
            ll x = a[i][0] - a[j][0];
            ll y = a[i][1] - a[j][1];
            ll z = a[i][2] - a[j][2];
            ll evl = (y * y) - (4 * x * z);
            if (x == 0LL){
                if( y == 0 && z != 0) continue;
                dsu.union_set(i,j);
                g[i].pb(j);
                g[j].pb(i);

                continue;
            }
            if (evl >= 0){
                dsu.union_set(i,j);
                debug(i,j);
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }

    for (int i = 0; i < n; i++){
        // maybe we use a BFS 
        set<int> st;
        int cnt = 0;
        vb seen(n,false);
        queue<int> q;
        int d = 0;
        q.push(i);
        seen[i] = true;
        while(!q.empty()){
            int len = q.size();
            for (int j = 0; j < len; j++){
                int top = q.front(); q.pop();
                if (d%2==0){
                    if (!st.count(top)) cnt++;
                    st.insert(top);
                    for (int x: g[top]) st.insert(x);
                }
                for (int v: g[top]){
                    if (!seen[v]){
                        seen[v] = true;
                        q.push(v);
                    }
                }
            }
            d++;
        }
        res[i] = cnt;
        int p = dsu.find(i);
        mp[p] = max(mp[p], cnt);
    }
    debug(res);

    vi ans(n);
    for (int i = 0; i < n; i++){
        int tot = res[i];
        int pid = dsu.find(i);
        for (auto& [id, best]: mp){
            if (id == pid) continue;
            tot += best; 
        }
        ans[i] = tot;
    }
    for (auto& z: ans) cout << z << " ";
    cout << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("re","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

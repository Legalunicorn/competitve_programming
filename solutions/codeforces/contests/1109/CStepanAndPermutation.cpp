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
    int n,x,y;
    cin >> n >> x >> y;
    vi a(n);
    for (auto& z:a) cin >> z;
    Dsu dsu(2 * n);
    map<int,int> mp;
    // position -> value
    // for (int i = 0; i < n; i++) mp[i] = a[i];
    for (int i = 0; i < n; i++) mp[a[i]] = i;
    for (int i = 0; i < n; i++){
        if (i + x < n) dsu.union_set(i, i+x);
        if (i + y < n) dsu.union_set(i, i+y);
    }
    for (int i = 0; i < n; i++){
        int t = i+1; // target value
        if (a[i] == t) continue;
        int pos = mp[t];
        int old = a[i];
        if (dsu.find(pos) == dsu.find(i)){
            // connected
            swap(a[i], a[pos]);
            mp[t] = i;
            mp[old] = pos;
            // mp[  a[i] ] = pos;
            // mp[t] = i;
        } else{
            cout << "NO" << endl;
            return;
        }
        // we just swap as we need 
    }
    cout << "YES" << endl;

    // what the fuck am i doiung lol 
    // /


    // possible to sort the permutation? 
    // jhjj
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

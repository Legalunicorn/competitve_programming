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

//NOTE: 10^100? 
//there is some mod involved or something 
// note that i < [ai] < N 
// this means that it cannot go backwards
// so we just need to find the max of each componenet 
// we can use DSU, or something like that 
// 1. DSU, everyrhingg
// 2. for each DSU group, find the max element in it ? 
// vi ans(n);
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
    vi a(n);
    for (auto& z:a) cin >> z;
    Dsu dsu(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++){
        int j = a[i]-1;
        debug(i,j);
        dsu.union_set(i, j);
    }
    for (int i = 0; i < n; i++){
        // find the max 
        int id = dsu.find(i);
        if (!mp.count(id)) mp[id] = i+1;
        mp[id] = max(mp[id], i+1);
    }
    for (int i = 0; i <n;i++){
        int id = dsu.find(i);
        cout << mp[id] << " ";
    }
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

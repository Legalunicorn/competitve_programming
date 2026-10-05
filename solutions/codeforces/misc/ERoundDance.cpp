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

// cycles more than 2 are fixed 
// otherwise we can group all the two cycles to one or not

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

// NOTE:
// my obv is false, not only size 2 cycles are ficked 
// consider people with 2 neighbors LOCKED 
// the rest of them UNLOCKED
// 
// 1) if person is LOCKED, minially the CC is one dance 
// 2) can a group have ONLY one person unlocked? 
//      -> no its not a possible shape 
//      -> edges are bidirecitonal 
// 3) a group with ALL LOCKED, cannot be edited -> fixed number 
// 4) the rest of the groups can all join together
//
//
// IMPL 
// 1. CC using DSU, and put them into their own camps 
// 2. track the COUNT(N) -> neigbours 
// 3. check if foxed or not fixed
// 


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    Dsu dsu(n);
    vi cnt(n);
    vector<set<int>> st(n);
    for (int i = 0; i < n; i++){
        int u = dsu.find(i), v = dsu.find(a[i]-1);
        dsu.union_set(i, a[i]-1);
        st[i].insert(a[i]-1);
        st[a[i]-1].insert(i);
    }
    for (int i = 0; i < n; i++) cnt[i] = st[i].size();
    map<int, pi> mp;
    int fix = 0, fee =0 ;
    for (int i = 0; i < n; i++){
        int  p = dsu.find(i);
        mp[p].F++;
        if (cnt[i] == 2) mp[p].S++;
    }
    for (auto& [v,p]: mp){
        if (p.F==p.S) fix++;
        else fee++;
    }
    int low = fix;
    if (fee > 0) low++;
    int high = fix + fee;
    cout << low << " " << high << endl;



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

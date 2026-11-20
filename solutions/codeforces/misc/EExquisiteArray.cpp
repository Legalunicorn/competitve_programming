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


// k = 1 to n-1 
// k = 1 -> all subarrays
//
// we need to solve each k in logn or O(1) 
// i think we can flip the problem 
// start at each index, and the length we can extend depends on the K value
// k = 1 -> end 
// k = n-1 -> at most one
// there is also a reuse 
// i, i+1, i+2 
//    i+2  i+2, i+3 
// revisiting the same difference alot
// d1, d2 ,d3 ,d4, d5 ... dn-1 
// from any arbitaray starting point, we only care about the MIN diff s ofar
// k = x, it means count subarrays of d, where all elements are >= d. no empty subarrays
//
//
// 1) count by k, count independently
// - we can use array d and for each k count the number of subarrays that has all values at least k 
// - down to up or up to down? 
// - we cant count subarrays just based on max subarrays lengths, 
// - k = 1, its the full subarayy 
// - k = 1, --> all d=1 breaks the array , maybe we can store and disjion some segments? 
// intiially 
// [1,n] 
// then each round we set some split points ? -> the value is removed, the left and right are now separate 
//
// opposite direciton: [n] removed element 
// then for each k, we add some elements 
// MERGE: S1, S1 -> S_res 
// 1. rempve contribution from S1, S2 
// 2. add constriviuton of S_res = size 
//
// im thinking dsu is probably possible
//
// for ~n, k values, each time we count must be sub linear, 
// - the first pass can be linear, and  the we somehow use the previous answer
//
// 2)  count by position -> each position use some math to fill some ks


struct Dsu{
public:
    int n; 
    vector<ll> par, size, score;
// public:
    Dsu(int sz){
        n = sz;
        score.assign(n,0ll);
        size.assign(n,1);
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
    }

    int find(int v){
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    ll get_score(int v){
        int p = find(v);
        return score[p];
    }
    
    void set_score(int v, ll s){
        int p = find(v);
        score[p] = s;
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
    for (auto& z:a) cin >>z;
    vvi pos(n);
    vi b;
    for(int i = 1;i<n;i++)b.pb(abs(a[i]-a[i-1]));
    for (int i = 0; i < b.size();i++) pos[b[i]].pb(i);
    debug(a);
    debug(b);
    Dsu dsu(n);
    vl res(n); // k = 1, k  = n-1;
    ll cnt = 0ll;

    for(int k = n-1; k >= 1; k--){
        for (auto& p: pos[k]){
            // cerr << endl;
            int u = dsu.find(p);
            int l=u-1, r=u+1,v;
            if (l>=0){
                l = dsu.find(l);
                if (dsu.get_score(l)>0){
                    cnt -= (dsu.get_score(u)+dsu.get_score(l));
                    debug("tem", cnt);
                    dsu.union_set(u,l);
                    ll s = dsu.size[dsu.find(u)];
                    ll evl = s*(s+1)/2;
                    cnt += evl;
                    dsu.set_score(u, evl);
                    debug("set",u,evl);
                }
            }
            if (r <= n-1){
                r = dsu.find(r);
                if (dsu.get_score(r)>0){
                    cnt -= (dsu.get_score(u)+dsu.get_score(r));
                    debug("tem", cnt);
                    dsu.union_set(u,r);
                    ll s = dsu.size[dsu.find(u)];
                    ll evl = s*(s+1)/2;
                    cnt += evl;
                    dsu.set_score(u, evl);
                    debug("set",u,evl);
                }
            }
            if (dsu.get_score(u) == 0){
                dsu.set_score(u, 1ll);
                cnt+=1;
            }
            // debug(p, k, cnt);
            // for (int i = 0; i <= n-1; i++) cerr << dsu.get_score(i) << " ";
            // cerr << endl;
        }
        res[k] = cnt;
    }
    // cerr << endl;
    for (int i = 1; i <= n-1; i++) cout << res[i] << " ";
    cout << endl;

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

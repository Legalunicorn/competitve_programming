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



// 2 3 3 3 3 2 
// max distrance 
// visit only once 
// this is very inteeresting problem it sounds like MST
//
// isnt this straight up MST


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


// a tree is possible? or not? 
// actually it must be a straight line? 
//
// is this osme dp thing then?
//
//
// we start at a[0] 
// so obviouly 
// suppose we fix the start
// then we fix the end 
//
// start has 2 options 
// end has 2/3 options 
// total 4/6 combinations 
// actrually 
//
// once u turn back u cant go forward no more 
// hence this is d p

// dandare solved fast this must be some dp

void solve(){
    ll n;
    cin >> n;
    vl a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    debug(a,b);
    // once we use a vertical -> one side must be cleared
    vl dp(n,0);
    vl dist(n,0);
    if (a[n-1]==b[n-1]){
        dist[n-1] = 2;
    } else dist[n-1]=1;

    dp[n-1] = dist[n-1];
    for (int i = n-2; i >= 0; i--){
        ll s = 0;
        if (a[i]==b[i+1]) s+=2;
        else s+=1;
        if (a[i+1]==b[i]) s+=2;
        else s+=1;
        dist[i] = s + dist[i+1];
    }
    for (int i = n-2; i >=0; i--){
        ll evl = dist[i];
        ll x = 0;
        if (a[i]==b[i]) x+=2;
        else x+=1;
        if (a[i+1]==b[i]) x+=2;
        else x+=1;
        x += dp[i+1];
        dp[i] = max(x, evl);
    }
    cout << dp[0] << endl;


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

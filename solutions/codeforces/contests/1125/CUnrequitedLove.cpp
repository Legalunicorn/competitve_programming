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

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    // odd and even oviosuly 
    // choose two? 
    // and do not overlap 
    // split odd and event 
    // odd -> even (one direction)
    // the odd -> odd 
    // the even -> evevn 
    ll res = 0ll;
    map<ll,ll> modd,meven;
    vl odd,even;
    for (int i = 0; i < n; i++){
        if (i%2==0) even.pb(a[i]);
        else odd.pb(a[i]);
    }
    for (int i = 2; i < odd.size(); i++){
        ll s = -odd[i]+odd[i-1]+odd[i-2];
        modd[s]++;
    }
    for (int i = 2;  i < even.size();i++){
        ll s = -even[i]+even[i-1]+even[i-2];
        meven[s]++;
    }
    debug(modd);
    debug(meven);
    // even -> odd
    for (auto& [v,c]: modd){
        ll q = meven[v];
        res += c*q;
    }
    debug(a);
    debug(res);
    debug(odd);
    debug(even);
    // even -> even
    for (int i = 2; i < even.size();i++){
        ll s = -even[i]+even[i-1]+even[i-2];
        meven[s]--; // remove the current;
        vi rem;
        if (i+1<even.size()){
            ll  x = -even[i+1]+even[i]+even[i-1];
            rem.pb(x);
            meven[x]--;
        }
        if (i+2<even.size()){
            ll x = -even[i+2]+even[i+1]+even[i];
            rem.pb(x);
            meven[x]--;
        }
        debug(s,meven[s]);
        res += meven[s];
        for (auto& z:rem) meven[z]++;
    }
    debug("even done", res);
    for (int i = 2; i < odd.size();i++){
        ll s = -odd[i]+odd[i-1]+odd[i-2];
        modd[s]--;
        vi rem;
        if (i+1<odd.size()){
            ll x =-odd[i+1]+odd[i]+odd[i-1];
            rem.pb(x);
            modd[x]--;
        }
        if (i+2<odd.size()){
            ll x = -odd[i+2]+odd[i+1]+odd[i];
            rem.pb(x);
            modd[x]--;
        }
        res += modd[s];
        debug(s, modd[s]);
        for (auto& z: rem) modd[z]++;
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
    while(T--) solve();
    return 0;
}

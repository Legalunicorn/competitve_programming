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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    set<ll> st;
    for (int i = 0; i < n; i++){
        st.insert(a[i]);
    }
    ll dist = 0ll;
    ll pos = 0;
    for (int i  =0; i < n; i++){
        ll best = INF;
        ll ans = INF;
        debug(st,pos);
        auto lb = st.lower_bound(pos);
        if (lb == st.end()) lb = prev(st.end());
        // if (lb != st.end()) {
            debug(*lb);
            if (abs(pos - *lb) < best){
                best = abs(pos - *lb);
                ans = *lb;
            }
        // }
        
        debug(pos, best, ans);
        auto ub = st.upper_bound(pos);
        if (ub != st.begin()){
            auto xx = prev(ub);
            debug(*xx);
            if (abs(pos - (*xx))  <=  best){
                best = abs(pos - (*xx)) ;
                ans = *xx;
            }
        }
        debug(pos, best, ans);
        dist += best;
        pos = ans;
        st.erase(ans);
        debug(pos, best, ans, st);
        // cerr << endl;
    }
    cout << dist << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

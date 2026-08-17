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


// this is basically asking how many intervals are inside another interval 
// i dont know how to calculate this in O(n)
// 
//
// one jaring idea is using STACK - but there are some complications . 
// for example if we sort by earlier start, tie break by earlier end 
// "how many inserted are still open AFTER YOU CLOSE "
// this is tricky to resolve because how do we know how many after xx close? 
// and if we process closing separately like "im closing now, how many remain"
// it possible those remaining started later then you 
//
// they are ALL distinct 
// we can do coordinate compression as well 
// so we basically have 2 10e5 points at most 
// now we have more intereting ideas 
// we can query like 

// note: A inside B is a partial order 
// means for each we can find how many insert without carring about double count 
// how do we know how many inside ? 

// apparent this is a "classic problem"
// sort in increasing order of "b" positions..
// then we want the "posiiton" is this "a"? 


  
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
    vpi a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].F >> a[i].S;
    }
    sort(all(a), [&](const auto& p, const auto& q){
        return p.S < q.S;
    });
    debug(a);

    ordered_set<int> st;
    ll res = 0;
    for (int i = 0; i < n; i++){
        st.insert(a[i].F);
        // for all previous "A", how many are greater 
        int x  = st.size() - st.order_of_key(a[i].F) - 1;
        res += x;
    }
    cout << res << endl;
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

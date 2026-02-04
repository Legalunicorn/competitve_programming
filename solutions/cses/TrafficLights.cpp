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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    int n,x;
    cin >> x >> n;
    // every time we add a point, we find the closest left and right point 
    // this will give the segment size 
    // then we split the segment , add the two childsn int the pq 
    set<int> st;
    // multiset<int> seg;
    ordered_multiset<int> seg;
    st.insert(0);
    st.insert(x);
    seg.insert(x);
    // priorty_queue<int> pq;
    for (int i=0;i<n;i++){
        int p;
        cin >> p;
        auto right = st.lower_bound(p);
        auto left = prev(right);
        int d = *right - *left;
        debug(p);
        debug(*left, *right);
        debug(d, p - *left, *right - p);
        seg.erase(d);
        seg.insert(p - *left);
        seg.insert(*right - p);
        st.insert(p);
        debug(st);
        cout << *seg.rbegin() << endl;
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

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
    int l,q;
    cin >> l >> q;

    set<int> st;
    st.insert(0);
    st.insert(l); 
    int ii =0;

    while(q--){
        ii++;
        int id,x;
        cin >> id >> x;
        if (id==1){
            st.insert(x);
            continue;
        }
        debug(st.size());
        auto high = st.lower_bound(x);
        auto low = prev(high);
        int l = *low;
        int r = *high;
        debug(ii,x, l,r);
        cout << r - l << endl;
    }


    //
    // ordered_set<int> cuts;
    //
    // // 
    //
    // while(q--){
    //     int id,x;
    //     cin >> id >> x; 
    //     if (id==1){
    //         cuts.insert(x);
    //     } else{
    //         if (cuts.size()==0){
    //             cout << l << endl;
    //             continue;
    //         }
    //         // find the cut below it 
    //         // find the cut above it 
    //         int pos = cuts.order_of_key(x);
    //         for (auto& x: cuts) debug(x);
    //         debug(x, pos, cuts.size(), *cuts.begin(), *cuts.end());
    //         if ( x < *cuts.begin() ){
    //             // just find one bigger 
    //             int high = *cuts.find_by_order(pos);
    //             debug(x, high);
    //             cout << high << endl;
    //         } else if (x > *cuts.end()){
    //             int low = *cuts.find_by_order(pos);
    //             cout << l - low << endl; // odd by 1? 
    //         } else{
    //
    //             int low = *cuts.find_by_order(pos);
    //             int high = *next(cuts.find_by_order(pos));
    //             debug(low, high);
    //             cout << high - low + 1 << endl;
    //         }
    //     }
    // }
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

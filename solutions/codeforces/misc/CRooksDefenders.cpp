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



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


// check if EACH cell is attached by one rook 
// means either all rows are there or 
// all cols are there

void solve(){
    int n,q;
    cin >> n >> q;
    ordered_set<int> sx;
    ordered_set<int> sy;
    // set<int> sx, sy;
    map<int, int> mx, my;
    while (q--){
        int t; cin >> t;
        if (t == 1) {
            // insert rook 
            int x,y; cin >> x >> y;
            mx[x]++;
            my[y]++;
            if (mx[x] == 1) sx.insert(x);
            if (my[y] == 1) sy.insert(y);
        } else if (t == 2){
            int x,y; cin >> x >> y;
            mx[x]--;
            my[y]--;
            if (mx[x] == 0) sx.erase(x);
            if (my[y] == 0) sy.erase(y);
        } else {
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int a = sx.order_of_key(x1);
            int b = sx.order_of_key(x2);
            cerr << endl;
            debug(mx,my);
            debug(a,b);
            if (b - a == x2 - x1 && mx[x1] && mx[x2]){
                cout << "Yes" << endl;
                continue;
            }
            int c = sy.order_of_key(y1);
            int d = sy.order_of_key(y2);
            debug(c,d);
            if (d - c == y2 - y1 && my[y1] && my[y2]){
                cout << "Yes" << endl;
                continue;
            }
            cout <<"No" << endl;

            // debug(sx,sy);
            // // debug(mx,my);
            // cerr << endl;
            // int a = *sx.lower_bound(x1);
            // int b = *sx.lower_bound(x2);
            // int c = *sy.lower_bound(y1);
            // int d = *sy.lower_bound(y2);
            // if (a != b || c != d || mx[x1] != 0 || 
            //         mx[x2] != 0 || my[y1] != 0 || my[y2]!=0) cout << "Yes" << endl;
            // else cout << "No" << endl;

        }
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

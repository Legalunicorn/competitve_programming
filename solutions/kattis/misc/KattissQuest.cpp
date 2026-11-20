#include <bits/stdc++.h>
#include <queue>
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
    // priority_queue<pl, vpl, greater<pl>> pq;
    // priority_queue<pl> pq;
    // find the largest <= x > 
    // BBST can do this 
    // ordered_set<pl> st;
    set<ll> st;
    map<ll, map< ll, ll>  > mp; // energy -> <GOLD, count >  
    map<ll, set<ll>> s2;
    int cur = 0;
    while(n--){
        string cmd;
        int x,  y;
        cin >> cmd;
        if (cmd == "add"){
            cin >> x >> y; 
            st.insert(x);
            mp[x][y]++;
            cur++;
        } else{
            cin >> x;
            ll val = 0ll;
            debug(x);
            while(cur>0){
                debug(x, st);
                auto it = st.upper_bound(x);
                if (it == st.begin()) break;
                --it;
                ll e = *it;
                debug(x,e);
                auto &fg = mp[e];
                ll g = fg.rbegin()->F;
                ll freq = fg.rbegin()->S;
                if (freq == 1){
                    fg.erase(g);
                } else fg[g]--;
                cur--;
                if (fg.size() == 0) st.erase(e);
                val+=g;
                x-=e;
            }
            cout << val << endl;
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
    while(T--) solve();
    return 0;
}

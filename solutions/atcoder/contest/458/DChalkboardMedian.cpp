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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// output the median 
// huh 
// after 2 queries -> 4 numbers 
// why is it 2i + 1 
// oh there is one integer
// we can use two min heaps

// we keep the min  heap as the larger heap 
//
// the max heap store -> largest? 
// the min heap store smallest??? 


//
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <class T> using ordered_multiset = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
//

void solve(){
    ll x;
    cin >> x;
    int q;
    cin >> q;
    priority_queue<ll> bot;// mxx heap 
    priority_queue<ll, vl,greater<ll>> top; // min heap 
    top.push(x);

    // auto go = [&](ll val)-> void {
    //     if (
    // };

    int i  =0;
    while(q--){
        ll a,b;
        cin >> a >> b;
        i++;
        top.push(a);
        top.push(b);
        while(top.size() > (i+1)) {
            ll r = top.top();
            top.pop();
            bot.push(r);
        }
        // this should work right? 
        // i = 0, ignore 
        while(!bot.empty() && !top.empty() && bot.top() > top.top()){
            ll b = bot.top(), t = top.top();
            bot.pop(), top.pop();
            top.push(b);
            bot.push(t);
        }
        cout << top.top() << endl;
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

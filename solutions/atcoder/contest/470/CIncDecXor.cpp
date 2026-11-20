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

// NOTE: cheese with seg tree BUT 
// semes like a trick problem 
// xor.. 
// there is releaved value? 
// A ... 0 ... A .. 0  .. A .. 0 
// find the xor for each query ok. 
// cant we just if ai >= 1 minus ok.. 
// we have increase one 
// we have decrease universal 
// i really want to cheese this with segtree LOL 
//
// lets not be lame 
// i think this is a counting problem? 
//
// maintain the XOR SUM 
// if "1 x" we unxor the number, then xor its minus 1 
// what about operation 2? 
// maybe this is a pairt and counting problem? 
// depend on how many distinct values we have at a time? 
//
//
//
// how do we handle operation 2 even? 
// omg i misread its not A or 0 
// its ALL 0 
//
// i think this is some amortized bullshit 
// we need to store the number of opertion 2s?? 

// vl a -> store the ACTUAL values 
// map<int,int> COUNT of each values 
// map<int, int> difference between "a"  and the real value? 
//
// op1: can only increase 
// op2: can only decease 
//
//
//  i need to redo this probglem 
//  im pretty sure its n^ 2 to construct 1,22, 333,4444,55555, 6,7,8,9 ..etc 
//  actually im jusst guessint no idea maybe its not amortizsed
//  (n/2) * (n/2) is still n^ 2 thought 
//  there is no trick with xor and -1 thouigh 
//  it only poinss to handle it mannually 
//  so maybe its amoprtized i dont know 
//
// nah its definitely amortized 
// i need to solve using one map only 
// or two  
// freq + delta 
// but i need to know the pointer. 
// no. freq will grow exponentially 
// i maintain freq ONLY 
//


void solve(){
    ll n,q;
    cin >> n >> q;
    vl a(n,0ll);
    set<int> st;
    ll res = 0;
    while(q--){
        int id,x;
        cin >> id;
        debug(id);
        if (id == 1){
            cin >> x; 
            debug(x);
            int i = x-1;
            res ^= a[i];
            a[i]++;
            res ^= a[i];
            st.insert(i);
            debug(id);
        } else{
            int prev = -1;
            debug("start",st);
            debug(a);
            for (auto p: st){
                int v = a[p];
                res ^= v;
                res ^= (v-1);
                a[p]--;
                if (prev!=-1) st.erase(prev);
                if (a[p] == 0) prev = p;
                debug(p,prev);
                // if (a[p] == 0) st.erase(p);
            }
            if (prev!=-1) st.erase(prev);
        }
        debug(st);
        cout << res << endl;
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

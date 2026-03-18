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


// what the fuck is this even asking 
// oh okay 
// we finding the base of fibonnachi sequences 
// fibonnaci + multiple 
// ?? 
// M <= 1000 
//
// i think this is dp
// we can iterate all pairs sure 
//
// this is dp + pigeon hole principle or some fuck shit 
//
// i cant find a math solution 
// 
//
// s3 = A y  + B x 
// s4 = A(Ay+Bx) + By
// = A^2y + ABx + By 



void solve(){
    ll m,a,b;
    cin >> m >> a >> b;
    int res = 0;

    map<pl, int> mp;
    set<pl> st;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++) {
            ll two = i, one = j; 
            bool valid = false;
            for (int k = 0; k < 1000; k ++){
                if (st.count({one,two})) {
                    valid = false;
                    break;
                }
                ll t = a*one+ b*two;
                if (t % m == 0) {
                    st.insert({one,two});
                    valid = false;
                    break;
                }
                two = one;
                one = t;
            }
            if (valid) res++;
        }
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

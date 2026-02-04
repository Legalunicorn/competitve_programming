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

// i think this ia greedy 
// suppose we have "a" and "b" and x = 1000 
// we need to decide where to put "x",
// 1. x will definiitely be a new front we have to deal with later
// if x > a and b 
// it will definiltey count 
// we might as well cover the smaller element 
// if x > a but not b 
//

void solve(){
    vi one = {1000000};
    vi two = one;
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n ;i ++){
        int x; cin >> x;
        if (x > one.back() && x > two.back()){
            res++;
            if (one.back() < two.back()) one.pb(x);
            else two.pb(x);
        } else if (x <= one.back() && x <= two.back()){
            if (one.back() < two.back())  one.pb(x);
            else two.pb(x);
        } else if (x <= one.back()) one.pb(x);
        else two.pb(x);
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

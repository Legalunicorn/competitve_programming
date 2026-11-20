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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;



    // n = 10
    int res = n;

    bool found = false;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1]) found = true;
    }
    if (found){
        cout << 1 << endl;
    } else {
        cout << n << endl;
    }


    // vb used(n, false);
    //
    // auto dfs = [&](auto& dfs, vi ls)-> void{
    //     debug(ls);
    //     // check if it is non decrease 
    //     bool nd = true;
    //     for (int i = 1; i < ls.size(); i++){
    //         if (ls[i] < ls[i-1]) nd = false;
    //     }
    //     if (nd){
    //         res = min(res, (int)ls.size());
    //     } else{
    //         // remove one 
    //         for (int i = 0; i < ls.size(); i ++){
    //             vi g;
    //             for (int j = 0; j < ls.size(); j++){
    //                 if (j!=i) g.pb(a[j]);
    //             }
    //             dfs(dfs,g);
    //         }
    //     }
    // };
    // dfs(dfs,a);
    // cout << res << endl;
    // cerr << endl;


    // int mx = 1 << n;
    // for (int m = 0; m < mx ; m ++){
    //     vi ls;
    //     for (int i =0 ;i < n; i++){
    //         if (m >> i & 1) ls.pb(a[i]);
    //     }
    //     bool valid = true;
    //     for (int j = 1; j < ls.size();j++){
    //         if (ls[j] > ls[j-1] ){
    //             valid = false;
    //         }
    //     }
    //     if (valid){
    //         res = max(res, ls.size());
    //     }
    // }


    // can keep removing while there is an increase 
    // int res = 0;
    // stack<int> st;
    // for (int i = 0; i <n ;i++){
    //     if (!st.empty()){
    //         if (st.top() < a[i]){
    //             while(!st.empty() && st.top() < a[i]){
    //
    //             }
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
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

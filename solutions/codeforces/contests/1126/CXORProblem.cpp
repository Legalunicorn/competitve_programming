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


// NOTE:
// quite a strange problem 
// they sample test cases is quite small.. 
//
// the obv construction we can try is
//
//
// 1
// . 1 
// . . 1 
// . . . 1 
// but it could not be maxx beauty nor max n 
// unless we find a way to extend n + 1, while adding only 1 to the xor 
//
// PERF:
// 1
// 0 1 
// 0 0 1 
// - suppose f(a) = 0
// - we can double the array, each pair only add 1 to f, and add 1 to n 
// - then if we insert "0" we can extend the array also?, kk
// - then see if we can find a way to increase n without f 
//
// 1 0
// 0 1 
// 1 0 
// then we can spam 0s samfe
//
// 1 0 0 
// 0 1 0
// 0 0 1 
// 0 1 0 
// 1 0 0 
// 0 1 0
// 0 0 1
//
//
// 1 0 0 0
// 0 1 0 0 
// 0 0 1 0
// 0 0 0 1 
// 0 0 1 0
// 0 1 0 0 
// 1 0 0 0
// 0 1 

// 
// 1 
//  2 
// 1 
//   4
// 1
//  2
// 1 
//
//  

int test(vi t){
    int ans = 0;
    for (int i = 0; i < t.size(); i++){
        int x = 0;
        for (int j = i; j < t.size(); j++){
            x ^= t[j];
            if (x == 0) {
                if (t.size() < 12) debug(i,j);
                ans++;
            }
        }
    }
    return ans;
    debug(t,ans);

}
void solve(){
    ll n;
    cin >> n;
    ll mx = 1;
    int msb = 1;
    while(mx*2<= n){
        mx*=2;
        msb++;
    }
    vi ans = {0};
    int cur = 1;
    while(cur <= mx){
        vi t = ans;
        ans.clear();
        for (auto& z: t) ans.pb(z);
        ans.pb(cur);
        for (auto& z: t) ans.pb(z);
        cur *=2;
    }
    cout << ans.size() << endl;
    for (auto& z: ans) cout << z << " ";
    cout << endl;

    // vi ans = {1};
    // int pf = 1;
    // debug(n,mx);
    // for (int i = 2; i <= mx; i++){
    //     ll nxt = i ^ pf;
    //     ans.pb(nxt);
    //     pf ^= i;
    // }
    // int x = test(ans);
    // debug(msb, x, ans.size());
    // vi real = {0};
    // for (auto& z: ans){
    //     real.pb(z);
    //     real.pb(0);
    // }
    // cout << real.size() << endl;
    // for (auto& r: real) cout << r << " ";
    // cout << endl;
    // // im going to guess that 0 2 ^ msb construction is somehow possible
    // //
    // //



    // if (n == 1){
    //     cout << 3 << endl;
    //     cout << "1 1 1" << endl;
    //     return;
    // }
    // if (n <=3){
    //     cout << 7 << endl;
    //     cout << "2 2 1 0 2 0 1" << endl;
    //     return;
    // }
    // vi res;
    // debug(n,mx,msb);
    // for (int i = 1; i <= msb; i++){
    //     res.pb(1 << (i-1));
    // }
    // for (int i = msb-1; i >= 1; i--){
    //     res.pb(1 << (i-1));
    // }
    // for (int i = 2; i <= msb; i++){
    //     res.pb(1 << (i-1));
    // }
    // for (int i = msb-1; i >2; i--){
    //     res.pb(1 << (i-1));
    // }
    // vi ans;
    // ans.pb(0);
    // for (auto& z: res){
    //     ans.pb(z);
    //     ans.pb(0);
    // }
    // int  o= test(res);
    // int  p = test(ans);
    // debug(msb,res);
    // debug(o, p);
    // debug(res.size()-o, ans.size()-p);
    // cerr << endl;
    // cout << ans.size() << endl;
    // for (auto& z: ans) cout << z << " ";
    // cout << endl;

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int ff = test({4,2,1,2,4,2,1,2,4});
    // debug(ff);
    // test();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}

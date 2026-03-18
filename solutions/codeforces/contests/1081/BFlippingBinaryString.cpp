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

// its only possible if you get 
// 0000000
//
// or 
// 1111111 0
// 1 0 -> makes no sense 
// you either try 010101001 
// or 101010101
//
//




void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0;
    int zero  =0;
    int i = 1;
    vi zv, ov;
    // stack<int> sz;
    // stack<int> so;
    for (char c: s){
        if (c == '0'){
            zero++;
            zv.pb(i);
            // sz.push(i);
        } else{
            one++;
            // so.push(i);
            ov.pb(i);
        }
        i++;
    }
    if (zero == n){
        cout << 0 << endl;
        return;
    }

    if (one % 2 == 0){
        // pick all ones
        cout << ov.size() << endl;
        for (auto& z: ov ) cout << z << " ";
        cout << endl;
        return;
    }
    if (zero % 2 == 1){
        cout << zv.size() << endl;
        for (auto& z: zv) cout << z << " ";
        cout << endl;
        return;
    }
    cout << -1 << endl;


    // if (zero == n){
    //     cout << 0 << endl;
    //     return;
    // }
    //
    // // either try all ones, one try all zeros 
    // int o = one, z = zero;
    // vi temp;
    // bool flip = false;
    // for (int i = 0; i < ov.size(); i++){
    //     temp.pb(ov[i]);
    //     if (z == n){
    //         cout << temp.size() << endl;
    //         for (auto& z: temp) cout << z << " ";
    //         cout << endl;
    //         return;
    //     }
    //
    //     if (!flip){
    //         //  fix a "1"
    //         int t = o;
    //         o = 1 + z;
    //         z = t - 1;
    //     } else{
    //         int t  = z;
    //         z = 1 + o;
    //         o = t - 1;
    //     }
    //     flip = !flip;
    // }
    // if (z == n){
    //     cout << temp.size() << endl;
    //     for (auto& z: temp) cout << z << " ";
    //     cout << endl;
    //     return;
    // }
    //
    // o = one, z = zero;
    // temp.clear();
    // flip = true;
    // for (int i =0 ; i < zv.size(); i++){
    //     temp.pb(zv[i]);
    //     if (z == n){
    //         cout << temp.size() << endl;
    //         for (auto& z: temp) cout << z << " ";
    //         cout << endl;
    //         return;
    //     }
    //     if (flip){
    //         //  fix a 0
    //         int t = o;
    //         o = 1 + z;
    //         z = t - 1;
    //     } else{
    //         int t  = z;
    //         z = 1 + o;
    //         o = t - 1;
    //     }
    //     flip = !flip;
    //
    // }
    // if (z == n){
    //     cout << temp.size() << endl;
    //     for (auto& z: temp) cout << z << " ";
    //     cout << endl;
    //     return;
    // }
    // cout << -1 << endl;
    // return;
    // ones 



    // if (zero == n){
    //     cout << 0 << endl;
    //     return;
    // }
    // vi res;
    //
    // while(zero > 0 && one > 0) {
    //     debug(one,zero);
    //     if (zero % 2 == 0) {
    //         // pick 1 
    //         debug("here");
    //         if (so.empty()){
    //             cout << -1 << endl;
    //             return;
    //         }
    //         res.pb(so.top());
    //         so.pop();
    //         int t = one;
    //         one = zero + 1;
    //         zero = t - 1;
    //
    //     } else {
    //         debug("there");
    //         // odd number of zeros 
    //         if (sz.empty()){
    //             cout << -1 << endl;
    //             return;
    //         }
    //         res.pb(sz.top());
    //         sz.pop();
    //         int t = zero;
    //         zero = one + 1;
    //         one = t - 1;
    //     }
    //     swap(so,sz);
    // }
    // debug("  ");
    // if (zero == 0){
    //     cout << -1 << endl;
    //     return;
    // }
    // cout << res.size() << endl;
    // for (auto& z: res) cout << z << " ";
    // cout << endl;
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

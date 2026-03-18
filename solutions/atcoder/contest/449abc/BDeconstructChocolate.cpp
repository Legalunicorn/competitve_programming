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
 int h,w,q;
    cin >> h >> w >> q;
    while(q--){
        int id;
        int x;
        cin >> id >> x;
        if (id == 1){
            // take away the bottom x rows 
            int res = x * w;
            h -= x;
            cout << res << endl;
        } else {
            int res = x * h;
            w -= x;
            cout << res << endl;
        }
    }
    // rows = h w, cols = w 
    // vvb g(h, vb(w, true));
    // while(q--){
    //     int id;
    //     cin >> id ;
    //     if (id == 1){
    //         int r; cin >> r;
    //         // find the number in the bottom r rows and each them 
    //         int num  = 0;
    //         for (int row = h - row; row < h; row++){
    //             for (int c = 0; c < w; c++){
    //                 if (g[row][c]){
    //                     num++;
    //                     g[row][c] = false;
    //                 }
    //             }
    //         }
    //         h -= r;
    //         cout << num << endl;
    //
    //     } else {
    //         int c; cin >> c;
    //         int num  =0;
    //         for (int row = 0; row < h ; row ++){
    //             for (int col = col - c; col < w; col++){
    //                 if (g[row][c]){
    //                     num++;
    //                     g[row][c] = false;
    //                 }
    //             }
    //         }
    //         w -= c;
    //         cout << num << endl;
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

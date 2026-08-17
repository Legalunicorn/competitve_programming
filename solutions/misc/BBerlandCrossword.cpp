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


// this problem is rage bait 
// the only thing deterministic is 
// x = n 
// x = 0 
// x = 1 
// think in terms of corners 
// each side has a L,R corner 
// {b,b,b,b}
//
// for each state of corners 
// 
//
//
// this is a very good problem 
// consider the corners only 

void solve(){
    int n;
    cin >> n;
    vi a(4);
    for (auto& z: a) cin >> z;

    int f = 1 << 4;
    for (int m = 0; m < f; m++){
        vi t = a;
        if (n==2)debug(t);
        for (int i = 0; i < 4; i++){
            int b = (m >> i) & 1;
            if (b == 1){
                t[i]--;
                t[(i+1)%4]--;
                // i = 0: LU 
                // i = 1; UR 
                // i = 2; RD 
                // i = 3; DL 
            }
        }
        if (n ==2) debug(m,t);
        bool valid = true;
        for (auto& x: t){
            if (x < 0 || x > n - 2) valid = false;
        }
        if (valid){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;




    // for (int i = 0; i < n; i++){
    //     if (a[i] <= n-2) a[i] = 0;
    //     else if (a[i] == n-1) a[i] = 1;
    //     else a[i] = 2;
    // }
    //
    // vvi valid = {
    //     {1,0,0,1},
    //     {2,1,0,1},
    //     {1,1,1,1},
    //     {2,2,2,1},
    //     {2,2,2,2}
    // };
    //
    // debug(a);
    // for (auto& v: valid){
    //     debug(v);
    //     for (int s = 0; s < 4; s++){
    //
    //         bool valid = true;
    //         for (int i = 0; i < 4; i++){
    //             int p = (s + i) % 4;
    //             if (a[p] != v[i]) valid = false;
    //         }
    //
    //
    //         if (valid){
    //             cout << "YES" << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << "NO" << endl;


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

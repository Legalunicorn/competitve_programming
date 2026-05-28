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

// NOTE: 
// the max ONES is k * m 
// each column is independent from another 
// Ivan can only flip 1 -> 0
// (1) max score 
//  -> we have to maximise each column individually 
//  -> max conseq "1"s capped out with "k", and how many "1s" are before it 
// this is some two ppoint ther crak or whatever 
//
// (2) min moves


// bro its not conseuqnece its must move fromt the top 
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m ;j++) cin >> a[i][j];
    }
    // NOTE:
    // find the max range with the MOST "1"s 
    //
    pi res;
    for (int c = 0; c < m ; c++){
        vi b(n);
        for (int r = 0; r < n; r++)
            if (a[r][c]==1) b[r]=1;
        for (int i =1;i<n;i++) b[i]+=b[i-1];
        debug(b);
        int bst = 0;
        int del = 0;
        int seen = 0;
        for (int i = 0; i < n; i++){
            if (a[i][c]==1){
                int j = min(n-1, i + k - 1);
                debug(i,j);
                int cnt = b[j] - (i ? b[i-1]:0);
                if (cnt > bst){
                    bst = cnt;
                    del = seen;
                }
                seen++;
            }
        }
        debug(c, bst, del);
        res.F += bst;
        res.S += del;
    }
    cout << res.F << " " << res.S << endl;
}



// void solve(){
//     int n,m,k;
//     cin >> n >> m >> k;
//     vvi g(n, vi(m));
//     for (int i= 0; i < n;i++){
//         for (int j = 0; j < m;j++) cin >> g[i][j];
//     }
//     debug(g);
//     int res = 0;
//     int take = 0;
//     for (int i = 0; i < m; i++){
//         int cnt = 0; // how many conseq;
//         vi ls;
//         for (int j = 0; j < n; j++){
//             if (g[j][i] == 1) cnt++;
//             else{
//                 if (cnt>0) ls.pb( min(k, cnt));
//                 cnt = 0;
//             }
//         }
//         // if (cnt) ls.pb({min(k,cnt),cnt});
//         if (cnt > 0) ls.pb(min(k,cnt));
//         cnt = 0;
//         if (ls.empty()) continue;
//         // i think my deletion logic is not quite right 
//         int bst = 0;
//         int sum = 0;
//         int takesum = 0;
//         for (int j = 0; j < ls.size(); j++){
//             if (ls[j] > bst){
//                 bst = ls[j]; 
//                 takesum = sum;
//             }
//             sum += ls[j];
//         }
//         res += bst;
//         take += takesum;
//     }
//     cout << res << " " << take << endl;
//
// };

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

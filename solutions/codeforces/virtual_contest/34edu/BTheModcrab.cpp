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
    int h1, a1, c1;
    cin >> h1 >> a1 >> c1;
    int h2, a2;
    cin >> h2 >> a2;
    int hp = h1;
    vector<string> res;
    for (int i = 0; i < 10000; i++){
        debug(hp, h1, h2, a1, a2, c1);
        if (h2 <= 0 || hp <= 0) break;
        // heal or strike? 
        // if can kill monster now kill 
        if (h2 - a1 <= 0){
            res.pb("STRIKE");
            break;
        }
        if (hp - a2 <= 0){
            res.pb("HEAL");
            hp += c1;
            hp -= a2;
        } else{
            res.pb("STRIKE");
            h2 -= a1;
            hp -= a2;
        }
    }
    cout << res.size() << endl;
    for (string s: res) cout << s << endl;
};
//     for (int i = 0; i < 200; i++){
//         debug(h2, hp);
//         debug(a1,a2,c1);
//         if (h2 <= 0 || hp <= 0) break;
//         if (h2 - a1 <= 0){
//             res.pb("STRIKE");
//             break;
//         }
//         if (hp <= a2){
//             res.pb("HEAL");
//             hp = min(h1, hp + c1);
//         } else{
//             res.pb("STRIKE");
//             h2 -= a1;
//         }
//         hp -= a2;
//     }
//     cout << res.size() << endl;
//     for (auto& s: res) cout << s << endl;
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

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
// can we just divide and conquer ? 
// if a > b 
// we DONT CARE about b anymore 
//
// but its also possible to have cycles 
// merge sort and all doesnt quite work? 
// this thing can be cyclic.. how do we .. 
// even though a > b, and b cannot win 
// b might win someone else ? 
// theres only 5 marathons though 
// why not we merge sort,
//  thne the winnner we compare to eveyrone else? 
//  

void solve(){
    int n;
    cin >> n;
    vvi g(n, vi(5));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++) cin >> g[i][j];
    }
    vvi t = g;

    auto cmp = [&](const auto& p, const auto& q){
        int b = 0;
        for (int i = 0; i < 5; i++){
            if (p[i] > q[i]) b++;
            else b--;
        }
        return b < 1; // true, p won, at the front;
    };
    sort(all(g), cmp);
    debug(g);
    bool valid = true;
    for (int i = 1; i < n; i++){
        int win = 0;
        for (int j = 0; j < 5; j++){
            if (g[0][j] < g[i][j]) win++;
        }
        if (win < 3) debug(g[i], win);
        if (win < 3) valid = false;
    }
    if (!valid){
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++){
            if (g[0][0] == t[i][0]){
                cout << i+1 << endl;
                return;
            }
        }
        // find the winner which is 
    }

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

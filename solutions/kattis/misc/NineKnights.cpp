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

void solve(){
    vector<string> g(5);
    for (auto&z:g) cin >> z;
    vvi kd = {
        {-2,1}, {-2,-1},
        {2, 1}, {2, -1},
        {1, -2}, {1, 2},
        {-1 ,2}, {-1, -2}
    };
    bool valid = true;
    int cnt = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (g[i][j] == 'k'){
                cnt++;
                for (auto& d: kd){
                    int x = i + d[0], y = j + d[1];
                    if (x < 0 || x >= 5 || y < 0 || y >= 5) continue;
                    if (g[x][y] =='k') valid = false;
                }
            }
        }
    }
    if (cnt != 9) valid = false;
    cout << (valid ? "valid":"invalid");
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

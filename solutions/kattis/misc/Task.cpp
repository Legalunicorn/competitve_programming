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

// NOTE 0 -> empty space 
// behaviopr 
// 1. 4 same -> 2 cell + 2 zero 
//
//
// strategy, for each row, add non zero items 
// -> process it as so 
// if we merge -> skip an index and push new valud

void solve(){
    vvi g(4, vi(4));
    vvi f(4, vi(4));
    for (auto& z: g) for (auto& x: z) cin >> x;
    int d; cin >> d;

    // auto solve = [&]() -> void{
    //     // just do for left 
    // }
    debug(g);
    debug(d);

    if (d == 0){ // left

        for (int r =0 ;r < 4; r++){
            vi nums;
            vi ans;
            for (int c = 0; c < 4; c++){
                if (g[r][c] != 0) nums.pb(g[r][c]);
            }
            for (int i = 0; i < nums.size(); i++){
                if (i == nums.size()-1){
                    ans.pb(nums[i]); 
                    continue;
                }
                if (nums[i] == nums[i+1]) {
                    ans.pb(nums[i]*2);
                    i++;
                } else ans.pb(nums[i]);
            }
            debug(nums);
            while(ans.size() < 4) ans.pb(0);
            f[r] = ans;
        }

    } else if (d == 1){ // up rotate 
        for (int c =0; c < 4; c++){
            vi nums,ans;
            debug(c);
            for (int r= 0; r < 4; r++){
                if (g[r][c]!=0) nums.pb(g[r][c]);
            }
            for (int i = 0; i < nums.size(); i++){
                if (i == nums.size()-1){
                    ans.pb(nums[i]); 
                    continue;
                }
                if (nums[i] == nums[i+1]) {
                    ans.pb(nums[i]*2);
                    i++;
                } else ans.pb(nums[i]);
            }
            debug(nums);
            while(ans.size() < 4) ans.pb(0);
            for (int i = 0; i < 4; i++){
                debug(c,i);
                f[i][c] = ans[i];
            }
        }
    } else if (d == 2){ // rigth: FLIP sole FLIP
        for (int r =0 ;r < 4; r++){
            vi nums;
            vi ans;
            for (int c = 3; c>= 0; c--){
                if (g[r][c] != 0) nums.pb(g[r][c]);
            }
            for (int i = 0; i < nums.size(); i++){
                if (i == nums.size()-1){
                    ans.pb(nums[i]); 
                    continue;
                }
                if (nums[i] == nums[i+1]) {
                    ans.pb(nums[i]*2);
                    i++;
                } else ans.pb(nums[i]);
            }
            debug(nums);
            while(ans.size() < 4) ans.pb(0);
            reverse(all(ans));
            f[r] = ans;
        }
    } else{ // down
        for (int c =0; c < 4; c++){
            vi nums,ans;
            for (int r= 3; r >= 0; r--){
                if (g[r][c]!=0) nums.pb(g[r][c]);
            }
            for (int i = 0; i < nums.size(); i++){
                if (i == nums.size()-1){
                    ans.pb(nums[i]); 
                    continue;
                }
                if (nums[i] == nums[i+1]) {
                    ans.pb(nums[i]*2);
                    i++;
                } else ans.pb(nums[i]);
            }
            debug(nums);
            while(ans.size() < 4) ans.pb(0);
            reverse(all(ans));
            for (int i = 0; i < 4; i++){
                f[i][c] = ans[i];
            }
        }
    }
    for (auto& r:f){
        for (auto& c: r) cout << c << " ";
        cout << endl;
    }
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

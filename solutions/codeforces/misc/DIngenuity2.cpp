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


// the direcitons must be divisible? 
// what about the net, if the net is divisible is it fine ? 
//
// net x = 3 
// up up up down, : u , {u , u ,d}
//
//



void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dx = 0;
    int dy = 0;
    int x = 0, y = 0;
    for (char c: s){
        if (c == 'N') {
            y++;
            dy++;
        } else if (c=='S'){ 
            y++;
            dy--;
        } else if (c=='E') {
            x++;
            dx++;

        } else {
            x++;
            dx--;
        }
    }
    if (dx % 2 ==1 || dy % 2 ==1){
        cout << "NO" << endl;
        return;
    }

    // at least one 
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

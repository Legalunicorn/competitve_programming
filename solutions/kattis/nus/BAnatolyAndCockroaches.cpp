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
    int n;
    cin >> n;
    string s;
    cin >>s;
    // try b first
    // then try r 
    int res = n;

    // NOTE: 
    // swap solve 2: 
    // change solve 1j
    {
        // start with "B" 
        // count how many wrong "R"
        // count how many wrong "B"
        int wr =0, wb = 0;
        for (int i= 1; i < n; i+=2){
            if (s[i] =='b') wb++;
        }
        for (int i = 0; i < n; i+=2){
            if (s[i]=='r') wr++;
        }
        int swaps = min(wb,wr);
        int ans = max(wb,wr) + 
    }

    //
    // // forget that must change color also
    // {
    //     // start with "b"
    //     // then just ocunt hjow many b is in wrong position
    //     int wrong = 0;
    //     for (int i = 1; i < n; i+=2){
    //         if (s[i] == 'b') wrong++;
    //     }
    //     res = min(res,wrong);
    // }
    // {
    //     int wrong = 0;
    //     for (int i = 0; i < n; i+=2){
    //         if (s[i] =='b') wrong++;
    //     }
    //     res = min(res,wrong);
    // }
    // cout << res << endl;
    
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

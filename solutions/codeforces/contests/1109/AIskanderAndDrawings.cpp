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
    cin >> s;
    int mx = 0;
    int cur = 0;
    for (int i = 0; i < n; i++){
        if (s[i] =='#'){
            cur++;
        } else{
            if (cur>0){
                mx = max(mx, cur);
                cur = 0;
            }
        }
    }
    mx = max(cur, mx);
    debug(mx);
    if (mx == 0){
        cout << 0 << endl;
    } else{
        int t = 0;
        while(mx >0){
            if (mx <= 2){
                t++;
                break;
            } else{
                t++;
                mx-=2;
            }
        }
        cout << t << endl;
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
    while(T--) solve();
    return 0;
}

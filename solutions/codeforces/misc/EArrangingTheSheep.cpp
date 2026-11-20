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

    int n;
    cin >> n;
    string s; cin >> s;
    int cnt =0; 
    for (char c: s){
        if (c=='*') cnt++;
    }
    if (cnt == n || cnt <= 1){
        cout << 0 << endl;
        return;
    }

    int mid = (cnt+1)/2;
    int pos = -1;
    int c2 = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '*'){
            c2++;
            if (c2 == mid){
                pos = i;
                break;
            }
        }
    }
    
    ll res = 0;
    c2 = 0;
    debug(mid,pos);
    for (int i = 0; i < n; i++){
        if (s[i] == '*'){
            c2++;
            if (c2 < mid){
                int steps = mid - c2;
                int p = pos - steps;
                debug(i);
                debug(p - i);
                res += (p - i);
            } else if( c2 > mid){
                int steps = c2 - mid;
                int p = pos + steps;
                res += (i - p);
                debug(steps,p,i);
            }
        }
    }
    cout << res << endl;
    
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

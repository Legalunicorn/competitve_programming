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
    // dog shit statemeent
    int n,m;
    cin >> n >> m;
    vl a(n), b(m);
    for (auto& z: a) cin >> z;
    for (auto& z: b) cin >> z;
    a.pb(0);
    b.pb(0);
    // we can just simulate this cant we? there are at most 200 jumps 
    int one = 0, two =0;
    int oneturn = true;
    // we combine their turns so
    // both turns always go together
    // unless Bob kills Alice
    bool awin = true;
    cerr << endl;
    while(one < n && two < m){
        // exactyl one person will jump
        int done = a[one] - a[one+1] + 1;
        int dtwo = b[two] - b[two+1] + 1;
        int low = min(done,dtwo);
        a[one] -= low;
        b[two] -= low;
        debug(a,b);
        debug(one,two, done, dtwo );
        if (done < dtwo){
            one++;
        } else if (done > dtwo){
            two++;
        } else{
            one++;
            two++;
            if (two == m){
                cout << 1 << endl;
                return;
            }
        }
        if (one == n){
            cout << 2 << endl;
            return;
        }
        if (two == m){
            cout << 1 << endl;
            return;
        }
    }
    // debug(one, two);
    // if (one == n) cout << 1 << endl;
    // else cout << 2 << endl;
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

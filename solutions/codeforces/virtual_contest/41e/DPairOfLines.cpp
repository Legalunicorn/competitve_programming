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
    vpi a(n);
    for (int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
    if (n <= 4){
        cout << "YES" << endl; return;
        return;
    }
    
    // m = y
    auto check = [&](int u, int v) -> bool{
        vb seen(n);
        seen[u] = seen[v] = true;
        int top = a[u].F - a[v].F;
        int bot = a[u].S - a[v].S;
        int g = __gcd(top, bot);
        top /=g;
        bot /=g;
        int left = n-2;
        for (int i = 0; i < n; i++){
            if (i == u || i == v) continue;
            if (seen[i]) continue;
            int t = a[i].F - a[v].F;
            int b = a[i].S - a[v].S;
            g = __gcd(t,b);
            t /= g;
            b /= g;
            if (t == top && b == bot || t == -top && b == -bot){
                seen[i] = true;
                left--;
            }
        }

        if (left <= 2) return true;

        u = -1, v= -1;
        for (int i = 0; i < n; i++){
            if (!seen[i]){
                if (u == -1) u = i;
                else if (v== -1) v= i;
                else break;
            }
        }

        seen[u] = seen[v] = true;
         top = a[u].F - a[v].F;
         bot = a[u].S - a[v].S;
         g = __gcd(top, bot);
        top /=g;
        bot /=g;
        for (int i = 0; i < n; i++){
            if (i == u || i == v) continue;
            if (seen[i]) continue;
            int t = a[i].F - a[v].F;
            int b = a[i].S - a[v].S;
            g = __gcd(t,b);
            t /= g;
            b /= g;
            if (t == top && b == bot || t == -top && b == -bot && !seen[i]){
                seen[i] = true;
            }
        }
        for (int i = 0; i < n; i++) if (!seen[i]) return false;
        return true;
    };

    if (check(0,1)){
        cout << "YES" << endl;
        return;
    } else if (check(0,2)){
        cout << "YES" << endl;
        return;
    } else if (check(1,2)){
        cout << "YES" << endl;
        return;
    } else cout << "NO" << endl;
};

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

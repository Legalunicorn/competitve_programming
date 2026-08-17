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


// ive seen many gay questions this one takes the cake

int comp(int x) {
    int mx = 0;
    for (int i = 0; i < 30; i++){
        if (x >> i & 1) mx = i;
    }
    int res = 0;
    for (int i = 0; i <= mx; i++){
        if (x >> i & 1) {}
        else {
            res = res | (1 << i);
        }
    }
    debug(x, res);
    return res;
}

// EVEN 
// complement || number 
// complement can be zero? 
// no. 
//

void solve(){
    int n;
    cin >> n;
    vb seen(n+1);
    vi a;
    // 
    if (n % 2 == 1){
        int l = 1;
        for (int i = 0; i < 30; i++){
            if (n >> i & 1){
                l = (1 << i);
                break;
            }
        }
        int x = l + (l == 1 ? 2 : 1);
        a = {n, n-l, x, l};
        seen[n] = seen[n-1] = seen[x] = seen[l] = true;
        for (int i = 1; i <= n; i++){
            if (!seen[i]) a.pb(i);
        }
        reverse(all(a));
        cout << n << endl;
        for (auto& z: a) cout << z << " ";
        cout << endl;
    } else{
        int cnt = 0;
        int mx = 0;
        for (int i = 0; i < 30; i++){
            if (n >> i & 1) {
                cnt++;
                mx = i;
            }
        }

        if (cnt == 1){
            // power of 2 
            a = {n, n-1, n-2 , 3 ,1};
            seen[n] = seen[n-1] = seen[n-2] = seen[3] = seen[1] = true;
            for (int i = 2; i < n -1; i++){
                if (!seen[i]) a.pb(i);
            }
            reverse(all(a));
            int v = (1 << (mx+1)) -1;
            cout << v << endl;
            for (auto& z:a) cout << z << " ";
            cout << endl;
        } else {
            int h = (1 << mx) -1;
            //seen[h] = true;
            a = {h-1, n-1, n};
            seen[h-1] = seen[n-1] = seen[n] = true;
            for (int i = 1; i <= n;  i++){
                if (!seen[i]) a.pb(i);
            }
            reverse(all(a));
            cout << ((1 << (mx+1)) -1)<< endl;
            for (auto& z:a) cout << z << " ";
            cout << endl;
        }
    }
}


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

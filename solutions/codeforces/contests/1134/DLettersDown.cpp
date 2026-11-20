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


// NOTE:
// this is tricky if a[i] != a[n-1-i] we have two options ? 
// actually we can only go so its compulsoru for the higher one to go down

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi mp(26);
    for (int i =0; i < 26;i++) mp[i]=i;
    ll res = 0;
    vi a(n);
    for (int i =0; i < n; i++) a[i] = s[i]-'a';
    for (int i = 0; i < n; i++){
        int j = n - 1 - i;
        if (j <= i) break;
        int x = a[i], y = a[j];
        if (mp[x] != mp[y]){
            int mn = min(mp[x],mp[y]);
            // res += abs(mp[x] - mp[y]);
            mp[x] = mp[y] = mn;
        }
    }
    // i think res can be calculated after somehow
    // the strat is to check from back to front
    // does the order matter?  i think not, it would all be the same
    for (int i = 25; i >0; i--){
        if (mp[i] != i){
            mp[i-1] = min(mp[i-1], mp[i]);
            res++;
        }
    }
    cout << res << endl;


    // debug(a);
    // debug(res);
    // for (int i = 0; i < n ; i++) cerr << mp[a[i]] << " ";
    // cerr << endl << endl;
    // cout << res << endl;
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

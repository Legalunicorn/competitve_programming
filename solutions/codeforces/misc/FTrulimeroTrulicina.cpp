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

//NOTE:
// (1) we try a sequence from [1,k] 
// then when we start a new sequence we check left and up 
// -> still pssible to connect  ? 
// my idea says no, because if it connect then ont op must be differet
//



void solve(){
     int n,m,k;
     cin >> n >> m >> k;
     vvi g(n, vi(m));
     int tot = n * m;
     int grp = tot/k;
     int i = 0, j = 0;
     int cnt = 0, p = 0;
     for (int x = 0; x < grp; x++){
         vb bad(k+1);
        if (j > 0) bad[g[i][j-1]] = true;
        if (i > 0) bad[g[i-1][j]] = true;
        int st = 1;
        for (int t = 1; t <= k; t++){
            if (!bad[t]){
                st  = t;
                break;
            }
        }
        debug(x, st);
         for (int cnt = 0; cnt < k; cnt++){
             int v = st+cnt;
             if (v>k) v-=k;
             g[i][j] = v;
             j++;
             if (j == m){
                 j = 0;
                 i++;
             }
         }
     }
     for (int i = 0; i < n; i++){
         for (int j = 0 ;j < m;j++ ) cout << g[i][j] << " ";
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
    cin >> T; 
    while(T--) solve();
    return 0;
}

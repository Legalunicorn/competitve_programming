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
    int n,k,m;
    string s;
    int INV = 100000;
    cin >> n >> k >> m >> s;
    // construct the stupid next table 
    vvi next(m+5, vi(26, INV ));
    for (int c = 0; c < 26; c++){
        int cur = INV; 
        for (int i = m-1; i>=0 ;i --){
            if (s[i]-'a' == c) cur = i;
            next[i][c] = cur;
        }
    }
    debug(next);

    string ans; // try to construct a string less than length n
    int pos = 0;
    int ch = 0;
    for (int i = 0; i < n; i++){
        int far = -1;
        for(int c = 0; c < k; c++) {
            if (next[pos][c] > far){
                far = next[pos][c];
                ch = c;
            }

        }
        if (far == INV){
            ans += (char)(ch+'a');
            while(ans.size() < n ) ans += 'a';
            cout << "NO" << endl;
            cout << ans << endl;
            return;
        } else{
            pos = far + 1;
            ans += (char)(ch+'a');
        }
    }
    debug(ans);
    cout << "YES" << endl;

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

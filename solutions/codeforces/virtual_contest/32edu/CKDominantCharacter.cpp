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
    string s;
    cin >> s;
    int n = s.size();
    int res = n;
    int l = 1, r = n;

    vvi freq(n, vi(26));
    for (int i = 0; i < n; i++){
        int x = s[i] - 'a';
        freq[i][x]++;
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 26;j++) freq[i][j] += freq[i-1][j];
    }

    auto go = [&](auto& go, int k) -> bool{
        bool found = false;
        for (int c = 0; c < 26; c++){
            bool good = true;
            for (int i = 0; i + k - 1 < n; i++){
                int j = i + k - 1;
                int f = freq[j][c] - (i>0? freq[i-1][c]: 0);
                if (f == 0){
                    good = false;
                    break;
                }
            }
            if (good) return true;
        }
        return false;
    };

    debug(freq);
    while(l<=r){
        int m = (l+r)/2;
        debug(go(go,m), s);
        if (go(go, m)){
            res = m;
            r = m -1;
        } else l = m + 1;
    }
    cout << res << endl;
};

// at least length k -> monotonic 
//

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

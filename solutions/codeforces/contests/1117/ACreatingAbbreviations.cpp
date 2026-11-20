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
    int n,m;
    cin >> n >> m;
    vb freq(26);
    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        // char l = tolower(s[0]);
        char c = s[0];
        freq[c-'a'] = true;
    }
    debug(freq);
    int yes = 1;
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        debug(s);
        for (char& c: s){
            c = tolower(c);
            debug(c,freq, freq[c-'a'], c-'a');
            debug(freq[c-'a']==0);
            if (freq[c-'a']==0){
                yes = 0;
            }
        }
        char x = tolower(s[0]);
        freq[x-'a'] = true;
    }
    if (yes==1) cout << "YES" << endl;
    else cout << "NO" << endl;
    cerr << endl;
    

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

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
    // its by cases 
    // the first digit can only be up to tight 
    // ie 3 
    string s;
    cin >> s;
    if (s.size()==1){
        cout << s << endl;
        return;
    }
    int n = s.size();
    int res = (int)pow(9,(s.size()-1));
    int t  = 1;
    for (char c: s) t *= (c-'0');
    res = max(res,t);
    debug(res);
    for (int i = 0; i < n; i ++){
        if (s[i]=='0') break;
        // tight on left 
        // 999 on right 
        int evl = 1;
        for (int j = 0; j  < n ; j++){
            // if (j  <= i) evl *= (s[j]-'0'-1);
            // else evl *=9;
            if (j < i) evl *= (s[j]-'0');
            else if (j == i) evl *= (s[j]-'0'-1);
            else evl *= 9;
        }
        debug(i,evl);
        res = max(res,evl);
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

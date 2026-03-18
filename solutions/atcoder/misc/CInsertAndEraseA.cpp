#include <bits/stdc++.h>
#include <strstream>
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

//NOTE:
//only the "A" matters 
//if we see an "A" in t but its not "A" in "S"
//-> insert an "A" and move on 
//

void solve(){
    string s,t;
    cin >> s >> t;
    int i = 0, j = 0;
    int cnt = 0;
    for (char c: t){
        debug(c,i,cnt,"?");
        if (c == 'A'){
            if (i < s.size() && s[i] =='A') i++;
            else {
                cnt++; 
                // i++;
            }
            debug(c,i,cnt);
            continue;
        }
        while(i < s.size() && s[i] != c) {
            i++;
            cnt++; //deletion
        }
        if (i == s.size()){
            cout << -1 << endl;
            return;
        }
        i++;
        debug(c,i,cnt);
    }
    cout << cnt << endl;

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

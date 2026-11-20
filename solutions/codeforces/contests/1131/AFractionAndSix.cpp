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
    // cerr << endl;
    int n,m;
    cin >> n >> m;
    map<char,int> mp;
    string t,b;
    cin >> t;
    for (auto& c: t) mp[c]++;
    debug(mp);
    cin >> b;
    for (auto c: b){
        if (mp[c] == 0){
            cout << "NO" <<endl;
            return;
        }
        mp[c]--;
        if(mp[c]==0) mp.erase(c);
    }
    debug(mp);
    debug(mp.size());
    if (mp.size() == 3){
        if (mp['s']==1 && mp['i']==1 && mp['x']==1) cout << "YES" << endl;
        else cout << "NO" << endl;
        debug("ff");
        debug(mp['s']==1);
        debug(mp['i']==1);
        debug(mp['x']==1);
        return;
    } else{
        cout << "NO" << endl;
        return;
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

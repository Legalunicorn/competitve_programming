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
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    debug(n, a);
    map<int,int> mp; // val -> last;
    for (int i = 0 ; i < n; i++){
        mp[a[i]] = i;
    }
    set<pl> l;
    for (auto& z:mp){
        l.insert({z.S,z.F});
    }
    debug(l);
    vi res;
    int m = mp.size(); 
    pi cl = *l.begin();
    set<int> avail, used;
    map<int,int> pp;
    map<int, queue<int>> ps;
    for (int i = 0; i <= cl.F; i++){
        ps[a[i]].push(i);
    }
    int clear = 0;
    // actually, if u take some MIN MAX, u r clearing that space
    for (int i = 0; i < m;i ++){
        int mx;  
        if (i%2==0)mx = ps.rbegin()->F;
        else mx = ps.begin()->F;
        res.pb(mx);
        debug(mx, ps[mx].front(), cl);
        int go = ps[mx].front();

        used.insert(mx);
        ps.erase(mx); // erase for good
        debug(i, clear, go, mx);
        debug(used);
        while(clear <= go){
            int t = a[clear];
            debug(t,clear);
            if (ps[t].size()>0) ps[t].pop();
            if (ps[t].size()==0) ps.erase(t);
            clear++;
        }
        int pos = cl.F;
        if (mx == cl.S){
            l.erase(cl);
            int done = 0;
            while(!done && l.size()>0){
                cl  = *l.begin();
                if (!used.count(cl.S)) done = 1;
                else l.erase(cl);
            }
            while(pos<=cl.F){
                int t = a[pos];
                if (!used.count(t)) {
                    ps[t].push(pos);
                } 
                pos++;
            }
        }
    }
    // cerr << endl;
    cout << res.size() << endl;
    for (auto& z: res) cout << z << " ";
    cout << endl;
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

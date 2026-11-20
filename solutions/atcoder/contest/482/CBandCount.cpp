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
// coordinate compress OR binary search 
// 

void solve(){
    int n,m,p,q;
    cin >> n >> m >> p >> q;
    map<int,int> mrow, mcol;
    for (int i = 0; i < p; i++){
        int x,y;
        cin >> x >> y;
        mrow[x]++;
        mcol[y]++;
    }
    vpi row,col;
    for (auto& z: mrow) row.pb(z);
    for (auto& z: mcol) col.pb(z);
    debug(row);
    debug(col);
    for (int i = 1; i < row.size(); i++){
        row[i].S += row[i-1].S;
    }
    for (int i = 1;  i< col.size(); i++){
        col[i].S += col[i-1].S;
    }

    debug(row);
    debug(col);

    auto search = [&](vpi& x, int low, int high){
        // find the smallest index >= low
        int resl = x.size(), resr = -1;
        // find low
        {
            int l = 0, r = x.size()-1, evl = l;
            while(l<=r){
                int m = (l+r)/2;
                if (x[m].F >= low){
                    resl = m;
                    r = m -1;
                } else l = m +1;
            }
        }
        // largest index <= high
        {
            int l = 0, r = x.size()-1;
            while(l<=r){
                int m = (l+r)/2;
                if (x[m].F <= high){
                    resr = m;
                    l = m+1;
                } else r = m-1;
            }
        }

        debug(x);
        debug(low,high);
        debug(resl,resr);
        // cerr << endl;
        if (resl > resr) return 0;
        // if (x[resl].F > low) return x[resr].S - x[resl].S;

        return x[resr].S - (resl > 0 ? x[resl-1].S:0);
    };

    while(q--){
        int id, l, r;
        cin >> id >> l >> r;
        debug(id,l,r);
        if (id == 1){
            int ans = search(row, l, r);
            cout << ans << endl;
        } else {
            int ans = search(col, l, r);
            cout << ans << endl;
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

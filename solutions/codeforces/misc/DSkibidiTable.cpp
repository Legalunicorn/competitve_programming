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

// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4 
// 1 2 3 4 
// 5 6 7 8 
// 17 - 32 
// 1 - 16 
// (16-1)/4? -> 15/4 = 3 
// 1 2 3 4 
// 4 - 1 = 3 , /2 = 1 
// 1 + 1 = 2 
// 2 - 1 = 1 / 2 = 0 
//
//
//
//


// this problem is a WASTE of time

void solve(){
    int n;
    cin >> n;
    int q;
    cin >> q;


    auto go = [&](auto& go, vl& dat, ll lb, ll ub, ll x, ll y ) -> ll {
        if (dat[0] + 1 == dat[1]) {
            if (dat[0] == x) {
                if (dat[2] == y) return lb;
                else return lb + 2;
            } else {
                if (dat[2] == y) return ub;
                else return lb + 1;
            }
        } else {
            ll midx = dat[0] + (dat[1]-dat[0])/2;
            ll midy = dat[2] + (dat[3] - dat[2])/2;
            ll qt = (ub - lb)/4;

            if (x <= midx) {
                dat[1] = midx;
                if (y <= midy) {
                    dat[3] = midy;
                    ub = lb + qt;
                } else {
                    dat[2] = midy+1;
                    lb += 2*qt;
                    ub -= qt;
                }
            } else {
                dat[0] = midx+1;
                if (y <= midy) {
                    dat[3] = midy;
                    lb = ub - qt;
                } else{
                    dat[2] = midy+1;
                    lb += qt;
                    ub -= 2*qt;
                }
            }
            go(go, dat, lb, ub, x, y);
        }
    };

    auto go2 = [&](auto go2, vl& dat, ll lb, ll ub, ll d) -> pl {

    };
    while(q--){
        string id;
        cin >> id;
        if (id == "->"){
            ll x,y;
            cin >> x >> y;
        } else {
            ll d;
            cin >> d;
            // 2 ^ 2n ? 
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
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

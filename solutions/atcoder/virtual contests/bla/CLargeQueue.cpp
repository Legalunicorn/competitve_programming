#include <bits/stdc++.h>
#include <string>
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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    int q;
    cin >> q;
    deque<pl> a;
    while(q--){
        int id;
        cin >> id;
        if (id==1){
            ll c,x; cin >> c >> x;
            a.pb({c,x});
            // if (a.empty()){
            //     a.push({c,x});
            // } el
            //     int len = a.size();
            //     a.pb({c,x});
            //     // if (a.top().second == x){
            //     //     pl t = 
            //     //     a[len-1].F += c;
            //     // } else{
            //     //     a.push({c,x});
            //     // }
            // }
        } else{
            ll k;
            cin >> k;
            ll sum = 0;
            while(k > 0){
                pl top = a.front();
                a.pop_front();
                ll minus = min(k, top.F);
                sum += minus*top.S;
                k -= minus;
                if (top.F - minus > 0){
                    a.push_front({top.F - minus, top.S});
                }
            }
            cout << sum << endl;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

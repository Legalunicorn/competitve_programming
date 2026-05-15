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

// NOTE: 
// 1 | 2 
// 2 -> must start from something, [0,9] 
//

void solve(){
    int n;
    cin >> n;
    string s; cin >> s;
    vi a(n);
    for (int i = 0; i < n;i++) a[i] = s[i]-'0';
    bool found = false;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1]) found = true;
    }
    if (!found){
        vi res(n,1);
        for (auto& z:res)cout << z;
        cout << endl;
        return;
    }
    for (int p = 0; p<10;p++){
        vi col(n);
        vi one,two;
        for (int i = 0; i < n; i++){
            if (a[i] < p){
                col[i] = 1;
                one.pb(a[i]);
            } else if (a[i] > p){
                col[i] = 2;
                two.pb(a[i]);
            } else{
                if (two.empty() || two.back() == p) {
                    col[i] = 2;
                    two.pb(a[i]);
                } else{
                    col[i] = 1;
                    one.pb(a[i]);
                }
            }
        }
        debug(p, one , two);
        bool valid = true;
        for (int i = 1; i < one.size(); i++) if (one[i] < one[i-1]) valid = false;
        for (int i = 1; i < two.size(); i++) if (two[i] < two[i-1]) valid = false;
        if (valid){
            for (auto& z: col) cout << z;
            cout << endl;
            return;
        }
    }
    cerr << endl;
    cout << "-" << endl;
    // vi col(n);
    // int one = -1, two = -1;
    // vi x,y;
    // for (int i = 0; i < n;i++){
    //     if (a[i] >= one && a[i] >= two){
    //         two = a[i];
    //         col[i] = 2;
    //         y.pb(two);
    //         if (one > two) {
    //             one = a[i];
    //             col[i] = 1;
    //             x.pb(one);
    //         } else{
    //             two = a[i];
    //             col[i] = 2;
    //             y.pb(two);
    //         }
    //     } else if (a[i] >= one){
    //         one = a[i];
    //         col[i] = 1;
    //         x.pb(one);
    //     } else if (a[i] >= two){
    //         two = a[i];
    //         col[i] = 2;
    //         y.pb(two);
    //     } else{
    //         cout << "-" << endl;
    //         return;
    //     }
    // }
    // debug(x);
    // debug(y);
    // for (auto& z: col) cout << z ;
    // cout << endl;
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

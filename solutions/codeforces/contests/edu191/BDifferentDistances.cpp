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


// some shitty construction 
// the values must be pairwise distinct?
// the gaps 
// digit it into four bhh

// i found the pattner we just split it intwo groupf ogf 8
void solve(){
    int n;
    cin >> n;
    vi two = {1,2,1,2,2,1,1,2};
    if (n==2){
        for (auto& r: two) cout << r << " ";
        cout << endl;
        return;
    }

    // vi res(4*n);
    vi res;
    // even we can pair the numberz 
    // for odd -> add two at the start, last at the end
    int st = 0;
    vi pat = {0,1,1,0,1,0,0,1};
    for (int i = 1; i+1<=n ;i +=2){
        for (int j = 0; j < 8; j++){
            if (pat[j] == 0) res.pb(i);
            else res.pb(i+1);
            // st++;
        }
    }
    debug(n, res);
    if (n % 2 == 1){
        vi temp;
        temp.pb(n);
        temp.pb(n);
        for (int i = 0; i + 1 < res.size(); i++) temp.pb(res[i]);
        temp.pb(n);
        temp.pb(res.back());
        temp.pb(n);
        for (auto& r: temp) cout << r << " ";
        cout << endl;
        return;
    } else{
        // print RES
        for (auto& r: res) cout << r << " ";
        cout << endl;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

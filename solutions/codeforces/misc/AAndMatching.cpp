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

// we can pair numbers to AND = 0, by pairing with XOR max 
// { x , x & (1 << n)} 
// we want to construct "k" 
// we can probalby construct for each bit 
//
// 1101
// 1111
// 0010
//
// we want to take out "k", "c(k)" "n-1" "0"
// then {k, n-1}
// {ck, 0}

// case 3:  (hardest one)
// k = n - 1 
// "k" "0" 
// (n -1) & (n-2) = (n-2)
// then we just need 1 
// (n-3) & 1 = 1 
//
//

// just read the editorial for this 
// 0% chance i can come up with these stupid cases
void solve(){
    int n,k;
    cin >> n >> k;
    vpi res;
    if (k == 0){
        set<int> used;
        for (int i = 0 ; i < n; i++){
            int j = i ^ (n - 1);
            if (used.count(j) || used.count(i)) continue;
            used.insert(i);
            used.insert(j);
            res.pb({i,j});
        }
        for (auto& p: res) cout << p.F << " " << p.S << endl;
    } else if (k < n-1) {
        set<int> used;
        int ck = k ^ (n - 1);
        used.insert(ck);
        used.insert(0);
        used.insert(k);
        used.insert(n-1);

        for (int i = 0; i < n; i++){
            if (i == 0){
                res.pb({0, ck});
            } else if (i == k){
                res.pb({k, n-1});
            } else{
                int j = i ^ (n -1);
                if (used.count(i)) continue;
                if (used.count(j)) continue;
                used.insert(i);
                used.insert(j);
                res.pb({i, j});
            }
        }
        for (auto& p: res) cout << p.F << " " << p.S << endl;
    } else if (k == n-1){
        if (n == 4) {
            cout << -1 << endl;
            return;
        }
        // n-1, n -2 
        // n-3, 1 
        // 0, 2 
        set<int> used;
        res.pb({0,2});
        res.pb({n-1,n-2});
        res.pb({n-3,1});
        for (int i = 3; i < n-3;i++){
            if (used.count(i) || used.count(i ^ (n-1))) continue;
            used.insert(i);
            used.insert(i ^ (n-1));
            res.pb({i, i  ^ (n - 1)});
        }
        for (auto& p: res) cout << p.F << " " << p.S << endl;
    }
    // cout <<  " == " << endl;
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

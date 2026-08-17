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

// guarnteed to be possible 
// difference is tricky 
//
// consider 
//
// 3 4 5 6 7 
// 3 -> is the min so we know they all have to equalise to 3 or lower 
// our operation is added or minus the DELTA 
// 3 4 5 6 
// we want the equalise doesnt matter what the value is 
// a + (b -a ) = b 
// wtf 
// if we add the delta 
// it just makes two numerbs the same 
//
// 3 4 
// we just need to find the most common 


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int,int> mp;
    int mx = 0;
    int val = 0;
    for (auto& z:a) mp[z]++;
    for (auto& [v,c]: mp){
        if (c > mx){
            mx = c;
            val = v;
        }
    }
    // queue<pi> q;
    vb seen(n, false);

    cout << n - mx << endl;
    auto go = [&](auto& go, int i, int prev) -> void {
        if (i < 0 || i>=n) return;
        if (seen[i]) return;
        seen[i] = true;
        if (a[i] != val){
            if (a[i] < val){
                cout << "1 " << i+1 << " " << prev+1 << endl;
            } else {
                cout << "2 " << i+1 << " " << prev+ 1<< endl;
            }
            a[i] = val;
        }
        go(go, i-1, i);
        go(go, i+1,i);
    };
    for (int i=0;i<n;i++){
        if (a[i] == val) {
            go(go, i, i);
            break;
        }
    }

    // cout << n - mx << endl; // answer 
    // while (!q.empty()){
    //     int len = q.size();
    //     for (int x = 0; x < len; x++){
    //         auto [ind,prev] = 
    //         q.pop();
    //
    //
    //     }
    // }



    // int k = n - mx; 
    // cout << k << endl;
    // for (int i = 0; i < n; i++){
    //     if (a[i] == val) continue;
    //     if (a[i] > val) {
    //         cout << 2 << " " << (i+1) << " " << pos << endl;
    //     } else{
    //         cout << 1 << " " << (i+1) << " " << pos << endl;
    //     }
    //
    // }
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

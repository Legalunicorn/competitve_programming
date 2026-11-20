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


// NOTE: idk the siginificance of permutation here 
// we know that exaclty 1 element will be the start of the longest common subsequence 
// is this a two pointer then? 
// idk the idea but its messy 
// 1. store the index of array 1 in a MAP 
//
//
//
// if we try an element and its NOT the first, then its not optimal so we can skip it 
// othewise we can repeat this process? 
// that means we can skip ahead 
//
//
// completely misinterpret the problem 
//
// ! does not need to be continguous 
//
// we just need x amount to match 
// 1. we can store for each, what is the delta they match 

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for(auto& z:a) cin >> z;
    for(auto& z:b) cin >> z;
    map<int,int> mp;
    for (int i = 0; i < n; i++){
        mp[a[i]] = i;
    }
    map<int,int> ans;
    for (int i = 0; i < n; i++){
        int j = mp[b[i]];
        // we need to store the delta + n mod n 
        int d = (j - i + 2 * n) % n;
        ans[d]++;
    }
    int res = 1;
    for (auto& [v,c]: ans){
        res = max(res,c);
    }
    cout << res << endl;




    // map<int,int> mp;
    // for (int i= 0; i < n; i++) mp[a[i]] = i;
    // int res = 1; // best answre 
    // vi score(n, -1);
    //
    //
    // for (int i = 0; i < n ; i++){
    //     int j = mp[b[i]];
    //     int t = i;
    //     int ans = 0;
    //     for (int k = 0; k < n; k++){
    //         if (a[j] == b[t]) {
    //             if (score[i] != -1) {
    //                 // we have seen this index before! 
    //                 ans += score[i];
    //             }
    //             ans++;
    //             j = (j+1)%n;
    //             t = (t+1)%n;
    //         } else break;
    //     }
    //     score[i] = ans;
    //     res = max(res, ans);
    // }
    // cout << res << endl;

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

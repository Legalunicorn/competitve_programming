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


// the conditions are a little werird 
// 1. the length of the rib match Sxx 
// the b-th character on the STRING on vector
//
// look at the example 
// "r" -> 3 
// "e" -> "2"
// "t" -> 1 
//
// for each j we have to answer the queryes 
//
// how? 
//  we process each character and just pick one greedily 
//  we jst need to know if it exist a string that 
//  1. is length x 
//  2. has a[i].S character of our iteratoin
//
//  S[i] i at most length 10 
//
//  so we just need to know 
//  for each length 
//  whether a character INPUT exist as POS ??? 
//
//  Map<LENGTH, 
//
//  int[10] len 
//  int[10][26][10]

void solve(){
    // for each j: [1,M] can Sj be the spine? 

    int n;
    cin >> n;
    vpi a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].F >> a[i].S;
        a[i].S--;
    }
    int m;
    cin >> m;
    vector<string> b(m);
    for (auto& z:b) cin >> z;

    int dp[12][26][12];
    memset(dp, -1, sizeof(dp));
    for (auto& s: b){
        int l = s.size();
        for (int i = 0; i < l; i++){
            int v = s[i] - 'a';
            dp[l][v][i] = 1; // exit;
            debug(l,v,i);
        }
    }

    // what if the Spine is shorter than n???? 

    for (auto& s: b){
        // pretend its the split 
        bool valid = true;
        int l = s.size();
        if (l != n){
            cout << "No" << endl;
            continue;
        }
        for (int i = 0; i < n; i++){
            int len_need = a[i].F; //length we need
            int pos = a[i].S;  // position to equal to s[i]
            int char_need = s[i]-'a'; // 
            if (dp[len_need][char_need][pos] == -1){
                valid = false;
                break;
            }
        }
        if (valid) cout << "Yes" << endl;
        else cout << "No" << endl;
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

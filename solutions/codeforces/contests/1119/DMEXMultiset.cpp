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

//NOTE: 
//the math part, intutively we want to even out the MEX  if possible 
// because we want the MAX to be low relative to the sum 
// 1 + 1 + 3 = 5, vs 2 x 3 = 6 
// 2 2 2 = 6, 2x2 = 4
// this would then be another greedy though 
// 1. construct the balanced MEX's greedily
// 2. check the formula, if YES print the distrib
//
// how do we balance the blaues
// 1. 
// NOTE: 
// "0" is a requirement for MEX
//
// NOTE: dont jump too quick to guess
// its possible that the sol is stupid like 0,0,n. nahj 
// what about [1,0,1] sum = 2, 1x2 = 2
//            [0,0,1] NO
//            [0,0,0] NO
//      YES: 
//          [1,1,1]
//          [1,0,1]  -> if this is not possible all MEX >> is also not possible 
//          requirements
//          1. at least two ones, put the two ones in A,C 
//          2. all other numbers NOT one put in B
//
//      EDGE CASE: all Zeros OR zero is missing
// 
// A : 1
// B : 0  (dump all values 
// C : 1
//
// if grredy how do we handle large vlaues? 
// maybe we maintain a freq of values first 
// 0 -- 
// 1 -- 
// 2 -- 
// 3 -- 
//
// NOTE: eh scrap the previous idea.. 
// maintain a frequency of values 
// 0
// 1
// 2
// 3
// NOTE: the first number FREQ < 3 
// 3,3, 0
// 3,3 1 [x, x-1, x-1] sum = 3x-2,    
// 3,3 2 -> [x,x, x-1]
//
// CASE 1: zero missing -> YES, anyhow



void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    vi res(n); 
    debug(a);
    map<int, queue<int>> mp;
    for (int i = 0; i < n; i++){
        mp[a[i]].push(i);
    }
    if (mp[0].size()==1){
        cout << "NO" << endl;
        return;
    }
    debug("cc");
    // find the first numner 
    // i realsie the 3x-2 < 2x onyl for x == 1, 
    int last  = 0;
    // for (int i = 0; i < 5; i++) cerr << mp[i].size();
    for (int i = 0; i < n; i++){
        if (mp[i].size()<3){
            last = i;
            break;
        }
    }
    debug(last);
    // Make "C" the dumpster
    for (auto& [v, q]: mp){
        debug(v, q.size());
        if (q.empty()) continue;
        if (v > last){
            while(!q.empty()){
                int top = q.front(); 
                q.pop();
                res[top] = 2;
            }
        } else if (v < last){
            int one = q.front(); q.pop();
            int two = q.front(); q.pop();
            int three = q.front(); q.pop();
            res[one] = 0;
            res[two] = 1;
            res[three] = 2;
            while(!q.empty()) {
                int id = q.front(); q.pop();
                res[id] = 2;
            }
        } else if (v==last){
            if (q.size() == 1){
                int top = q.front();
                q.pop();
                res[top] = 0;
            } else if (q.size() ==2){
                int one = q.front(); q.pop();
                int two = q.front(); q.pop();
                res[one] = 0;
                res[two] = 1;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
        if (res[i] == 0) cout << "A";
        else if (res[i] == 1) cout << "B";
        else cout << "C";
    }
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

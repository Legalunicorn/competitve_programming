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

// 1 1 1 1 0 2 
// feelsl like a bfs kind of thing
// NOTE:
// 1. flipping a "0" only affects 1 cell 
// if you have a "2" or multiple "2"s which to choose? are they equal? 
// 
// contiguous non zero segmsn 
// (...) 00.00 (....) 0 (...)
//
// for each segment of 0s we can reduce it to 2 zeros 
// 00000 -> 00, the middle m-2 must be used 
// (....) 0 (.... ) 00 (..) 0 (.) 0 (....)
// each (...) block can maximally need 1 coin  is this true? 
// minially also 1 coin, its not possible for a 0 to ocnvert the blick
// hence we just need to ask how many 0s can be converted
// actually all 0s can be converted
// answer is just 
// 1. number of positive segments + middle zeros
// there are 3 cases for positive numbers 
//  0 1 0  -> this 1 is effectively a 0 
//  0 1 1 1 1 1 0 -> needs extra flip but takes care of all zeros
//  0 2 1 0 
//  convert isolated "1" to "0" 
//  then count zeros, count segments, note how many segments without "2" 
//

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int res =0;
    for (int i = 1; i + 1 < n; i++){
       if (a[i] ==1 && a[i-1]==0 && a[i+1]==0) a[i] = 0;
    }
    if (n>1){
        if (a[0]==1 && a[1]==0) a[0]  =0;
        if (a[n-1]==1 && a[n-2]==0) a[n-1] =0;
    }
    int zero = 0, dis = 0, mis2 = 0, cur = 0;
    int seg = 0;
    bool has2 = false;
    for (int i = 0; i < n; i++){
        if (a[i] > 0){
            int u = 0;
            if (i-1>=0 && a[i-1]==0) u++;
            if (i+1<n && a[i+1]==0) u++;
            dis += min(a[i], u);
            if (a[i]==2) has2= true;
            cur++;
        } else{
            cur = 0;
            zero++;
            if (i-1>=0 && a[i-1]!=0) {
                seg++;
                if (!has2) mis2++;
            }
            has2 = false;
        }
    }
    if (cur >0) seg++;
    int ans = zero + seg - dis + mis2;
    debug(a);
    debug(zero,seg,dis,mis2);
    cout << ans << endl;


    // 0 0 1 0 0 1 0 0 1 
    // 1 0 0 1 1 1 0 0 0 1
    // for positive numbers, we min(a[i], number of zero neighbors)
    // if its all "1"s we need an extra token anyways
    // but its its 0 1 1 1 1 0 2 2 2 2 
    // we can just consume one direction 
    // 

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

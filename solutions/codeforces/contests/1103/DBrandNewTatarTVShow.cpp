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
// 0 <= y- x <= k 
//
// x <= y ( y is bigger than X) 
// y <= k + x (y is at most k biggger than x)
//
//
// we want the second guy to wind 
// we pick the firsrt move 
// sort the array 
// there is some trick like 
// if a person has a frew options, which does he pick 
// and so on 
//
// person with no moves loses 
// if we have a length 2 sequence its an easy win 
//
//
//NOTE:
//a[i] <= n 
//can we dp on this? 
// dp[i][turn] -> return if some person can win
//  do this as last resorrt
//
//  NOTE:
//  -> if there is any gap > k it cut off the array already 
//  otherwise its just segments of array 
//  once we get the segments 
//  its hard to tell if Egor has a force win 
//  the size of the array dont tell 
//  if we choose to go u

// NOTE: i only have dp solution 
// let dp[i][turn] -> whether this player can force a win
// Ideas 
// if there is ambiguity it cant win? 
// wait no if there is a 1,2,3,4 sequence 
// i cant just pick the 3 and pas to my friend 
// i think we just need to find an element with on

// what we want: 
// start can have duplicates, we just want to jump to some number that has NO END 
// and freq of [1]
// for each number, if freq == 1, check if it has a number >= x - k; 

// NOTE: 
// several conditons 
// 2. freq == even, and no one to jump to 
// 3. freq == odd, and exist someone to jump to 
void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int,int> mp;
    for (auto& z:a) mp[z]++;
    sort(all(a));
    bool found = false;
    for (int i = 0; i < n; i++){
        int x = a[i];
        if (mp[x] % 2 == 1){
            // odd case 
            auto y = *lower_bound(all(a), x - k);
            if (y < x){
                found = true;
            }
        } else{
            // no one to JUMP to 
            auto big = upper_bound(all(a), x);
            if (big == a.end()){
                found = true;
                break;
            } else{
                int v = *big;
                if (v - x > k) found = true;
            }
        }
    }
    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;

    // why am i stuck 
    //
    
    // sort(all(a));
    // debug(a);
    // bool found = false;
    // for (int i = 0;i < n; i++){
    //     int x = a[i];
    //     if (mp[x] > 1) continue;
    //     auto y = lower_bound(all(a), x - k);
    //     debug(x , *y);
    //     if (*y < x){
    //         found = true;
    //         break;
    //     }
    // }
    // if (found) cout << "YES" << endl;
    // else cout << "NO" << endl;

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

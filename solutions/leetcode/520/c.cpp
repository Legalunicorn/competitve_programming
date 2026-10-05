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

//#define endl '\n' 
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



class Solution {
public:
    long long maxValue(vector<int>& a) {
        int n = a.size();
        debug(a);
        // BUG:
        // for odd length subarray the gain is not the SAME!
        // if we flip ODD 
        //  a[l] itslef does not change 
        //  how do we account for this? 
        //  split into odd/even cases ? 


        // rotate any means 
        // initially: even index: add 
        //            odd  index: minus 
        //
        //  a left rotation means that we can 
        //  some how flip the pairy of some subarray 
        //  sliding window? 
        //  max delta, initial sum 
        // fix each "R" as the end of some syubarray, what is thge best?
        // we find the min sum and flip it? 
        vi b = a;
        for (int i =1 ; i < n; i+=2) b[i] = -b[i];
        debug(b);
        ll cnt = 0ll;
        for (int i = 0; i < n; i++) cnt += b[i];
        debug(cnt);
        // if the sum is negative -> we gain 
        // if the sum is positive -> do nothing, because we lose
        ll high = -INF;
        ll pf = 0;
        ll next = -67676766777ll;
        ll res = cnt;
        ll higho = 0;
        ll highe = -INF;
        for (int i = 0; i < n; i++){
            debug(i, higho, highe);
            pf += b[i];
            ll low;
            // i -> o 
            if (i%2==1) low = pf - higho;
            else low = pf - highe;
            debug(i,low ,  pf);
            if (low < 0){
                ll evl = cnt - low - low;
                res = max(res, evl);
            }
            if (i % 2 == 1) higho = max(higho, pf);
            else highe = max(highe, pf);
            // if (low < 0) res = max(res, cnt - 2*low);
            // this high must register one late
            // if (next == -67676766777ll){
            //     highe = max(highe, 0ll);
            //     next = pf;
            //     // next = pf;
            // } else {
            //     if (i % 2 == 1) higho = max(higho, next);
            //     else highe = max(highe, next);
            //     // high = max(high, next);
            //     next = pf;
            // }
            // if (next -67676766777ll){
            //     high = max(high, next);
            //     next = pf;
            // }
            // high = max(high, pf);
            cerr << endl;
        }
        debug(res);
        return res;
    }
};


//
// int main(){
//     int n;
//     cin >> n;
//     Solution solution;
//     vi a(n);
//     for (auto& z:a) cin >> z;
//     cout << solution.maxValue(a) << endl;
// }
//


// void solve(){
//
// };
//

//
//
//
// int main(){
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);
//     // cout.tie(0);
//     // // freopen("file.in","r",stdin);
//     // // freopen("file.out","w",stdout);
//     // int T =1;
//     // // cin >> T; 
//     // while(T--) solve();
//     // return 0;
// }

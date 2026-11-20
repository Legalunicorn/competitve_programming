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


// find the n-th smallest palindrome 
// the fuck? 
// construction 
// 1,2,3,4,5,6,7,8,9 
// 11 , 22, 33, 44, 55, 66, 77, 88, 99, 
// 101, 121, 131, 141, 151, and so construction
//
// i think there is some combi + binary search 
// OR we dont some dp? 
// palindrome -> we only need half 
// we need to know the number is the nth palindrome or not 
// maybe binary search might work 
// but there is some equality bound we must cut down as much as possible to get exact 
// answer 
// N is large so its either counting or binary search 
//
// log 10e18 * digit 
// ? 
// given some number, find how many palindrome it contains 
// ! do not count leading zeros 
// 1. i think we can digit p 
//
// the idea is that we count until n/2 digits, 
// cases for odd even? ... 
// we need to mirror this shit 
// dp[digit][tight][leading]
// overcomplicated though 
// maybe its jut bs + counting 
//


// int dp[20][2][2]; //digt? 
//
// ll go(ll x){ // x is our bount 
    // ll t = x;
    // debug(t);
    // vi a; // digits;
    // while(t>0){
    //     a.pb(t%10);
    //     t /= 10;
    // }
    // debug(a);
    // for (int i =0; i < a.size(); i++){
    //     int m = min(a[i], a[a.size()-1-i]);
    //     a[i] = m;
    //     a[a.size()-1-i] = m;
    // }
    // vi b;
    // int lim = (a.size()+1)/2;
    // for (int i =0; i < lim; i++){
    //     b.pb(a[i]);
    // }
//     ll res = 0;
//     memset(dp,-1,sizeof(dp));
//     auto dfs = [&](auto& dfs, int i, int tight, int lead) -> ll{
//         if (i == lim) {
//             if (lead) return 0;
//             else return 1;
//         }
//         if (dp[i][tight][lead] != -1) return dp[i][tight][lead];
//         debug(i,tight,lead);
//         ll res = 1;
//         int mx;
//         if (tight) mx = a[i];
//         else mx = 9;
//         for (int d = 0; d <= mx ; d++){
//             int tight2 = 0; // not right 
//             int lead2 = 0; // not leading 
//             if (d == 0 && lead) lead2 = 1;
//             if (tight && d == a[i]) tight2 = 1; // set right 
//             res += dfs(dfs,i+1, tight2,lead2);
//         }
//         return dp[i][tight][lead] = res;
//     };
//     ll ans = dfs(dfs,0,1,1)+1;
//     debug(x, ans);
//     return ans;
//
// }

// ll go(ll x){
//     ll res = 0;
//     ll t = x;
//     debug(t);
//     vi a; // digits;
//     while(t>0){
//         a.pb(t%10);
//         t /= 10;
//     }
//     debug(a);
//     for (int i =0; i < a.size(); i++){
//         int m = min(a[i], a[a.size()-1-i]);
//         a[i] = m;
//         a[a.size()-1-i] = m;
//     }
//     vi b;
//     int lim = (a.size()+1)/2;
//     for (int i =0; i < lim; i++){
//         b.pb(a[i]);
//     }
//
//     // calculate 
//
//
//     return res;
//
//
// }

//
// ll calc(string s){
//
// }


// non leading>

// 1 digit -> 10 
// 2 digit -> 10 
// 3 digit ->  9 * 10 // 90 plaidimes from 100 to 999 
//
// 4 digit -> 9 * 10 
// 5 digit -> 9 * 10 * 10 
// .. then once we find the right length do something 
// 
//
//
// 46 as example 
// 10, 10 , 90 -> 110 
//
// 3 digits 0 - 999 
// then we search down> 
// find from largest digit to smalelst digit 


void solve(){
    // i thin kwe just divide by 9, then 10 10 10 10 
    ll n;
    cin >> n;
    if (n <= 10){
        cout << n-1 << endl;
        return;
    }
    string res; 
    ll curr = 9;
    ll cnt = 2;
    ll tot = 9;
    while(tot < n ){
        if (cnt % 2 == 1) curr *=10;
        tot += curr;
        if (tot >=n) break;
        debug(cnt,curr,tot);
        cnt++;
    }

    ll rem = tot - n;
    debug(rem);
    while(rem > 0){
        ll d = rem % 9;
        res.pb((char)(d+'0'));
        rem/=9;
    }
    debug(res);

    // ll curr = 9;
    // ll tot = 9;
    // ll cnt = 2;
    // // has to be the SAMEEEEEEEEE
    // // 9 10  (3)
    // // 9 10 (4)
    // //89 * 10 * 10 
    // while(tot < n ){
    //     if (cnt <=2 ) curr*=9;
    //     else curr*=10;
    //     debug(cnt,curr);
    //     cnt++;
    //     tot += curr;
    // }
    // debug(tot,curr,cnt);



    // ll tot = 9;
    // int cnt = 1;
    // // wait no 
    // // 4 digit -> 9 10 10 9 
    // // 5 digit -> 9 10 10 10 9 
    // while(tot<n){
    //     cnt++;
    //     tot*=10;
    // }
    //






    // think of it this way, 
    // for x-digits, we know how many palindromes its has 
    // 1. keep adding until we reach x? 
    // 2. 

    // maybe its direct calculation 


    // if (n <=9){
    //     cout << n-1 << endl;
    //     return;
    // }
    // ll l =1, r = INF;
    // ll ans = r;
    // while(l<=r){
    //     ll m = l + (r-l)/2;
    //     if (go(m)>=n){
    //         ans = m;
    //         r = m - 1;
    //     } else l = m +1;
    // }
    // cout << ans << endl;
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

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

// NOTE:
// this seems like construction condition
// sufficient condiution  for allices to win? 
// any also bobs move (likely some copy)
//
//  
//  mex = 0 
//  freq[0] < k 
//  mex = 1
//  freq[1] < k
//  ... 
//
//
//  the default mex = 0, and we need to construct higher and higher 
//  it makes sense for alice to construct the mex from 0 to as high as possible
//  suppose the missing mex is X 
//  alice is trying to get k X's
//  should bob try to take X's or X+1.. and so on ? 
//  suppose K = 3 , X  = 2 
//
//  2 2 2, 2 2 2 , 2 2 2 2 2 2 2 2 2  (excess twos)
//  3 3 3, 3 3 3 ,
// PERF:
//  - if alice only focus on "2", bob can take "3"s
//  - then when alice takes three 2s, bob taken three 3s, alice take one three, and bob steals the 4th three 
//  now alice cannot get mex = 3, and bob and alice can fight for 2's which is possible fo rbob to get mex =2 
// should they fight for element that is least frequent? 
// i think so ?  but we muist consider the first element that lacsk
//
//
// hence alice strategy is to LEAD
//
// actually im confused 
// if LIM[i] < 2*k we can win 
// otheriwse we need to fucons on something else j
// 
// maybe its the first element that lacks

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto&z :a) cin >> z;
    map<int,int> mp;
    for (auto& z:a) mp[z]++;
    int mx = -1;
    for (int i = 0; i < n+1; i++){
        if (mp[i] < k) break;
        mx = i;
    }
    // if (mx == -1){
    //     cout << "NO" << endl;
    //     return;
    // }

    bool alice = true;
    int x = 2*k;
    int good = x-1;
    for (int i = 0; i <= n; i++){
        if (mp[i] >= x) continue;
        if (mp[i]==good){
            cout << "YES" << endl;
            return;
        } else if (mp[i] < good){
            cout << "NO" << endl;
            return;
        }

    }


    // map<int,int> alice,bob;
    // bool isalice  = true;
    // while(!pq.empty()){
    //     pi t = pq.top(); pq.pop();
    //     if (isalice){
    //         alice[t.S]++;
    //     } else{
    //         bob[t.S]++;
    //     }
    //     if (t.F> 1) pq.push({t.F-1, t.S});
    //     isalice = !isalice;
    // }
    // int ma = 0, mb = 0;
    // for (int i = 0; i <= mx; i++){
    //     if (alice[i] >= k) ma = i;
    //     else break;
    // }
    // for (int i = 0; i <= mx;i++){
    //     if (bob[i] >= k) mb = i;
    //     else break;
    // }
    // debug(mx);
    // debug(alice);
    // debug(bob);
    // if (ma == mb) cout << "NO" << endl;
    // else cout << "YES" << endl;
    // cerr << endl;
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

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

// NOTE: Claim 1: any adjacent {Odd, Even} can be swapped 
// PERF: proof: odd + even = odd 

// NOTE: Claim 2: from (1) we can split the array into [all odd, all even] or [all even, all odd] 
// PERF: if we want [all even,all odd] parition just swap app {even,odd} pairs until they dont exist, analogous to [all odd, all even]

// NOTE: Claim 3: IF Min(a)!=Max(2) (Mod 2) (ie. min/max are separte parities) and we have partition [odd,even] we can sort all odd, sort all even
// PERF: Proof: 
// suppose we have some partition [odd, even]
// Case1: suppose Min(a), M,  is even
// 1. By claim 2, we can rearrange it to [e,e,... [all odd], M , e,e,e], basicially put min(A) beside [odd]
//    Lets focus only on [[all odd], M]
// 2. we can position M anywhere in [all odd] using claim 1, but relative positiions of odd remain unchanged
// 3. if we want to swap [o1, o2], we can position [M, o1, o2] 
// 4. then perform a reversal, and its guaranteed min is even, max is odd, hence operation allowed
// 5. then we get [o2, o1, M] 
// 6. M is free to move
// 7. hence we can swap any adjacent odd numbers
// 8. perform bubble sort -> we can sort odd 
// Case2: suppose Max(a), m, is even 
// - we can repeat the same strategy as above, and its guaranteed and operation is allowed since Max is even, min is odd
// NOTE: Lemma1 from #3: [o, o, o, o, e]   I can move e to any position I want through a seies of Claim1

// NOTE: Claim 4: Suppose there are two sorted parititions [odd,even], we can sort the array in asc order 
// PERF: Proof for #4 
// -  Suppose i have two sorted partition [Odd,Even] 
// - use claim 3b to move Even[0] downwards 
// - repeat for Even[1], where pos(Even[1]) > pos(Even[0])
// - hence there is no crossing over of Even[1] to go before Even[0] 
// - repeat for all Even 
//
// FIX: What if Min(a) == Max(a) (Mod 2)
// Suppose odd = {1 ,3 , 31, 33}
// Suppose even = {10,18,20}
// we know   33....1  -> we cannot fix 
// but what aout   31....1...33   {even = 10} 
// NOTE: -> possible 33....1  IFF we have even>33 || even<1
//       -> that is to say to sort ODD 
//       -> we an try to use min(even) OR max(even) 
//       -> for any inversion in ODD, if min(even) < both inverted pair || max(even) > both inverted pair 
//       -> analogous to sorting ODD as we ll
//   
//   -> M > m ... inversion 
//   -> iterate through odd, maintain M, and if there is inversion perform a check
//
// NOTE: Claim 5: WLOG (for odd/even)  to sort [all odd] for all inversion pairs in odd, so long Min(even) < odd_pair|| Min(odd) > odd_pair it can be sorted 
// NOTE: -> this is hence sufficent to solve the problem
//
// TEST: consider Min(A) = Max(A) (Mod 2)
// 5 .. 1 (max and min respectively)
// is it possible to put "5" after "1" ? NO
// PERF: PROVE:
// any swap that does not contain both 5,1 will not change their relative order
// any swap that contains both 5,1 cannot be 


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >>z;
    vi odd, even;
    for (int i = 0; i < n; i++){
        if (a[i]%2==1) odd.pb(a[i]);
        else even.pb(a[i]);
    }
    vi b = a;
    sort(all(b));
    if (odd.empty() || even.empty()){
        if (b==a) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    bool valid = true;
    int e_min = MIN(even);
    int e_max = MAX(even);
    int o_min = MIN(odd);
    int o_max = MAX(odd);
    int msf = -1;
    for (int i = 0; i < even.size(); i++){
        if (msf > even[i]){
            if (o_min<even[i] || o_max>msf) continue;
            valid = false;
        }
        msf = max(msf, even[i]);
    }
    msf = -1;
    for (int i = 0;i<odd.size();i++){
        if (msf > odd[i]){
            if (n==6) debug(msf, odd[i]);
            if (e_min<odd[i]||e_max>msf) continue;
            valid = false;
        }
        msf = max(msf, odd[i]);
    }
    cout << (valid ? "YES":"NO") << endl;
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

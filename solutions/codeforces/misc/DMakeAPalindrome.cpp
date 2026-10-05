#include <bits/stdc++.h>
#include <vector>
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


// NOTE: some element cants be removed
// the top k elements must stay
// if there is tie breaks then its frequency tie breaks
// the palindrome HAS to be a subsequence and exist before we do the operations
// suppose we canside the smalelst [n-k] elements 
// 
// NOTE: 
// suppose i sort the array 
// 1. i can always remove smallest to largest 
// 2. there is no reason to skip removing a number because they should come in pairs, x .. x, removing both wont affect the shape of the palindrome 
// 3. i can remove until k-1 left
// or rather 
// ASSUME i have the final shape of remaining elements, and its a palindromes.
// if i habe two mirroring small elements, i can remove both and its still a palindrome 
// if i have a center piece small element (odd palindrome), removing and its still a palindrome 
// hence i should just keep removing. 
// the tricky part is the k-th element ish> 
// k-1 remaining, n-k+1 removed 
// the k-th largest element, value i have some fredom in how i remove in making sure its a palindrome 
// using the same argument, i should either keep up to k-1 elements (maybe weird), or keep k elements 
// basiclaly if i have k-1 elements remaming, i want to know if k-1 is part of some pair or not 
// consider k-2 kept elements 
// k-1 is a must add,
// see what value is at k-1, i dont add ANY of twhose, but note how many is missing 
// miss = k-1-freq[sorted[k-1-1]];
// either add miss, or miss+1 of those element
// we maintain the position idea.
// 1 2 3 4 3 2 1 
// 1 2 3 3 2 1 
//
// check inbetween mirrors how many V are there, add the min(a,b), deduct from need, if need = 0 we stop
// depending if odd or even

void solve(){
    // cerr << endl;
    int n,k;
    cin >> n >> k;
    vi a(n);
    for (auto& z:a) cin >> z;
    if (k<=2){ // safe
        cout << "YES" << endl;
        return;
    }
    vpi b(n);
    for (int i = 0; i < n; i++) b[i] = {a[i],i};
    sort(all(b));
    map<int,int> freq;
    for (auto& z:a) freq[z]++;
    // resultant size is k-1;
    int t = b[k-2].F;
    vpi p;
    for (int i = 0; i <= k-1; i++){
        if (b[i].F == t) break;
        p.pb({b[i].S, b[i].F}); // index, value
    }
    sort(all(p));  // sort
    int m = p.size();
    debug(a,t);
    debug(p);
    // add back all the filler "t" until size == k-1
    if (p.empty()){
        debug("emoptryjh");
        debug(a);
        cout << "YES" << endl;
        return;
    }

    // p must be palindrome
    for (int i = 0; m - 1 - i > i; i++){
        if (p[i].S != p[m-1-i].S){
            debug("P fail", a);
            debug(p);
            cout << "NO" << endl;
            return;
        }
    }
    int ned = k-1 - p.size();
    debug("init: ", ned);
    int c1=0,c2=0;
    for (int i = 0; i < p[0].F; i++) if (a[i]==t) c1++;
    for (int i = p[p.size()-1].F+1; i < n; i++) if (a[i] ==t) c2++;
    debug(p, c1,c2, p[0].F);
    ned -= 2*min(c1,c2);
    debug(t,ned);
    int l = 0, r = m-1;
    while(l+1 <= r-1){
        int c1 = 0, c2 = 0;
        for (int i = p[l].F+1; i <p[l+1].F; i++) if (a[i]==t) c1++;
        for (int i = p[r-1].F+1; i <p[r].F; i++) if (a[i]==t) c2++;
        ned -= 2*min(c1,c2);
        if (ned <= 0){
            cout << "YES" << endl;
            return;
        }
        l++,r--;
    }
    if (m%2==0){ // check for missing t inserte in middle of palindrome
        int x = m/2-1;
        for (int i = p[x].F+1; i < p[x+1].F; i++) if (a[i]==t) ned--;
        if (ned<=0){
            cout << "YES" << endl;
            return;
        }
    }
    if (ned <= 0){
        cout << "YES" << endl;
        return;
    }
    debug("fail:", a, ned);
    cout << "NO" << endl;
    return;
    
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

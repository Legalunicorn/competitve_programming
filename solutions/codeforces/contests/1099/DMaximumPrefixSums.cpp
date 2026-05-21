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

// we are given C -> the max of the prefix sum
// we are given partial  A 
// C -> the max of sum so far 
// C -> monotonic 
// C -> only increases if there is a new value 
// everytime it increases -> it tells us something about A{i] }
// c[0] -> confirms a[0] 
// mayb we can split this into queries
//
//
// NOTE:
// - something tells me we can construct from Left to Right 
// - BUTT there are some constraints from the right at the same time! 
// - "C[i]/MAX" in a way is a ceiling for us 
// - we can use whatver A[i] SO LONG we dont exceed MAX  
// - at the sam time it can be dter
//
//
//
//
// NOTE:
// if c[i] > c[i-1] 
//      -> tells is directly  what the sum is from a[0] to a[i] 
//      -> each of it is a diffrent clue 
//      -> might be able to linear equatoin solv this ? 
//      
//    -> if the number of unknows increases by 1 
//    -> we can directly figure it out 
//
// BUG: 
// -> what if with multiple solution we can use arbitary numbrs 
// -> thne {5} {-1} gives a hint 
// -> if the max sum maintains, whatever we add, we can just negate! 
// -> consuder the sum from [now, next booundary] 
//      -> if it is positive -> negative it exaclty? or sth
//        -> if its negativv -> ignore 
// -> gist of the construction 
// -> we only care about [now, next break point ]
// -> if thre is no break point, we can just assign "0" all the way
// 
//
//BUG: 
//-> impossible cas 
//      -> some how A[i] we constructed exced [C]
//      -> somehow C decreases






void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vl  a(n), c(n), pf(n);
    vi nxt;
    for (auto& z:a) cin >> z;
    for (auto& z:c) cin >> z;
    if (s[0] == '1' && a[0] !=c[0]){
        cout << "No" << endl;
        return;
    }
    a[0] = c[0]; // this is a must
    pf = a;
    vl pf2 = c;
    for (int i = 1; i < n; i++) {
        pf[i] += pf[i-1]; // prefix sum of c
        pf2[i] += pf2[i-1];
    }
    nxt.pb(0);

    ll small = (ll)-1e17;
    auto sum = [&](int l, int r) -> ll {
        return pf[r] - (l > 0 ? pf[l-1]: 0);
    };
    auto sumC = [&](int l, int r) -> ll {
        return pf2[r] - (l > 0 ? pf2[l-1]: 0);
    };
    // c must be non decreasing 
    for (int i = 1; i < n; i++){
        if (c[i] < c[i-1]){
            cout << "No" << endl;
            return;
        } else if (c[i] > c[i-1]) nxt.pb(i);
    }

    int id = 1; // current nxt index
    int left = 1;
    bool took = false;
    ll tot = a[0];
    bool used = false;
    for (int i = 1; i < n; i ++){
        debug(i, id);
        if (s[i] == '1'){
            tot += a[i];
            if (id < nxt.size()){
                if (i == nxt[id]){
                    left = nxt[id]+1;
                    id++;
                    took = false;
                }
            }
            continue;
        }
        // we are at a checkpoint
        if (id == nxt.size()){
            // no more left 
            ll range = sum(left, n-1);
            debug(i, range, used, left, n-1);
            if (range <= 0) a[i] = 0;
            else{
                if (!used){
                    used = true;
                    a[i] = -range;
                } else a[i] = 0;
            }
            tot += a[i];
            continue;
        }

        if (i == nxt[id]) {
            left =  nxt[id]+1;
            ll gap = c[i] - tot;
            a[i] = gap; 
            id++;
            took = false;
        } else{
            // guranteed not the last check point 
            int right = nxt[id];
            ll range = c[right] - c[left];
            debug(i, left,right,range, took, id);
            if (!took){
                a[i] = -range;
                took = true;
            } else a[i] = 0LL; // leave it, satisfied
            tot += a[i];
        }
    }

    debug(s);
    debug(nxt);
    debug(a);
    debug(c);
    cerr << endl;
    bool pass = true;
    ll fintot = 0;
    ll msf = a[0];
    for (int i = 0; i < n; i++){
        fintot += a[i];
        msf = max(msf, fintot);
        if (msf != c[i]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for (auto& z: a) cout << z << " ";
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

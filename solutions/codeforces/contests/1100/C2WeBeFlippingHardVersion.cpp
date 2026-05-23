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


// i think this can be done with dp 
// not but ints omcplicated because a[i] > 0 
// BUG: 
// 1. we can only flip positive numbers 
// 2. in turn this makes it negative but hopfully producees a better sum 
// we need a way to construct the solitio nas we ll 
//

// NOTE: 
// we can figure out the max sum sure
// can think of it as 
// + all the position 
// - all the negatives 
//
// all the - become + 
// all the + become - 


// NOTE: 
// i think you can pick one positiv and undo all the negatives to th left of it 
// this becomes c1 slowly 


void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vi op;
    int sac = -1;
    ll best = 0; // best gain;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        if (a[i] < 0) sum += abs(a[i]);
        else{
            ll evl = -a[i] + sum;
            if (evl > best){
                sac = i;
                best = evl;
            }
        }
    }
    if (sac == -1){
        cout << 0 << endl << endl;
        // cerr << endl;
        return;
    }
    debug(sac, best);

    int st = -1, ed = -1;
    for (int i = 0; i < sac; i++){
        if (a[i] > 0){
            if (st == -1) st = i;
            ed = i;
        } else { // ngativ 
            debug(i, st, ed);
            if (st != -1){
                op.pb(ed+1);
                if (st >= 1) op.pb(st);
            }
            st = -1;
        }
    } 
    if (st!=-1){
        op.pb(ed+1);
        if (st >=1) op.pb(st);
    }
    debug("cur", op);
    op.pb(sac+1);
    // for (auto& z: op){
    //     if (a[z-1] < 0 )debug("poop");
    //     for (int i = 0; i < z; i++) a[i] *= -1;
    // }
    debug(a);
    cout << op.size() << endl;
    for (auto& z: op) cout << z << " ";
    cout << endl;
    // cerr << endl;



}

void unsolve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vi res;
    int last = -1;
    ll sum = 0;
    ll curr = 0;



    for (int i = 0; i < n; i++){
        if (a[i] < 0) {
            sum -= a[i];
        } else{
            if (last != -1){
                if (a[i] < sum){
                    res.pb(last);
                    res.pb(i+1);
                    last = i;
                    sum = abs(a[i]);
                    continue;
                } 
            }
            last = i + 1;
            sum = 0;
            // debug(a[i], pos, sum);
            // if (!pos.empty()){
            //     if (a[i] < sum){
            //         res.pb(pos.back());
            //         res.pb(i+1);
            //     }
            // } 
            // sum = 0;
            // pos.pb(i+1);
        }
    }
    vl t = a;
    
    cout << res.size() << endl;
    for (auto& r: res) cout <<r << " ";
    cout << endl;

    debug(a);


    for (auto& z: res){
        if (a[z-1] < 0) debug("POO");
        for(int i = 0; i< z; i++) a[i] *= -1;
    }
    if (n ==11){
        vi r2  = {6,3,1,5,4,7};
        for (auto& z: r2){
            for (int i = 0; i < z; i++) t[i] *=-1;
        }
        debug(t);
    }
    debug(a);

    cerr << endl;



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

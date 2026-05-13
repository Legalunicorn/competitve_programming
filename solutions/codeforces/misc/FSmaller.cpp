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
// they said the string dont go back to initial states 
// but we are allowed to change after eacho operation anyways?? 
//
// for possibility of lec smaller 
// we just need one character in the larger to be present than any character i s 
//
// s: a, aa, bb 
// t: a, aa, aaa,
//
//


void solve(){
    int q;
    cin >> q;
    vl fs(26), ft(26);
    fs[0]++;
    ft[0]++;
    while (q--) {
        int id; cin >> id;
        ll rep;
        string str;
        cin >> rep >> str;
        vl temp(26);
        for (char c: str){
            temp[c-'a'] += rep;
        }
        if (id == 1){
            for (int i = 0; i < 26; i++) fs[i] += temp[i];
        } else {
            for (int i = 0; i < 26;i ++) ft[i] += temp[i];
        }
        bool done = false;
        for (int i = 1; i < 26;i++){
            if (ft[i]){
                cout << "YES" << endl;
                done  = true;
                break;
            }
        }
        if (done) continue;
        bool others = false;
        for (int i = 1; i < 26;i++){
            if (fs[i]) others = true;
        }
        if (!others && fs[0] < ft[0]) cout << "YES" << endl;
        else cout << "NO" << endl;

        // check if "s" can be smallter than "t"
        // sufficient if any character of t is larger than smallest char of s 
        // tmax, smin 
        // using two pointer 
        // because if tmax == smin, smin = a for sure 
        // if t contains more than "a" its auto YES 
        // otherwise t is all "a" 
        // then for s to be smaller, "s" needs to be all "a" and less than t 
        //

    }
    
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

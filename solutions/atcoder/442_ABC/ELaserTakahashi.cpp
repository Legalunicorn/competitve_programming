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

constexpr ld PI = 3.14159265358979323846;
// ld PI = std::numbers::pi;

// we need to sort by polar angle, and then map it 
// 1. if A B has the same polar angle (we query for how many in said polar) angle 
//
// 2. otherwise, we start from A.. and rotated until B 
//
//
// we can do like coordinate compression or something 
// we need to find a sensible way to query using frequencies 
//
// 1. is there a precise way to store theta? 
// equivalence class of smae polar coordinate id k
// we can use atan 
//
// we can prefix sum this but we need a way to equalise the degree 
// what does clock wish imply
//  if A <= B, we can just range from A to B
//  otherwise, range from A to end 
//  then start to B 
//
//  we only have n points 


void solve(){
    int n,q;
    cin >> n >> q;
    vpi coord(n);
    for (int i=0;i < n; i++) cin >> coord[i].F >> coord[i].S;

    map<__int128,int> freq;
    map<int,__int128> mp;
    map<ld,int> cc;

    // 1. sort points 
    for (int i =0; i < n; i++){
        ld x = (ld)coord[i].F, y =(ld) coord[i].S;
        ld  score = 0.0;
        if (y>=0.0){
            if (x>0.0){
                 score = abs(atan(x/y));
            } else if (x==0.0) score = 0.000000;
            else { // fourth quaratand 
                score = 3.0*(PI/2.0) + abs(atan(y/x));
            }
        } else{
            // y is negative 
            if (x>0.0){ // 2nd quaatdrater 
                score = (PI/2.0) + abs(atan(y/x));
            } else if (x==0.000000) score = PI;
            else{
                // third quardrant 
                score = PI + abs(atan(x/y));
            }
        }

        __int128 LOL = score * (1e30);
        freq[LOL]++;
        mp[i] = LOL;

        // score *= (1e30);

        // freq[score]++;
        // mp[i] = score;
    }

    int len = freq.size();
    vl a(len);
    int pos = 0;
    for (auto& [angle,cnt]: freq){
        a[pos] = cnt;
        cc[angle] = pos;
        pos++;
    }
    pos--;

    vl b =a;
    for (int i = 1; i < b.size(); i++){
        b[i] += b[i-1];
    }


    int xd = b.size();


    // debug(mp);
    // debug(freq);
    // debug(cc);
    // debug(a);
    // debug(b);
    //

    while(q--){
        int u,v;
        cin >> u >> v;
        u--, v--;

        // debug(u,v);
        // debug(mp[u], cc[mp[u]]);
        // debug(mp[v],cc[mp[v]]);

        int  left = cc[mp[u]];
        int right = cc[mp[v]];

        debug(left,right);

        if (left == right){
            // only the count 
            cout << a[left] << endl;
        } else if (left < right){

            ll res = b[right] - (left>0? b[left-1]: 0LL);
            cout << res << endl;
        } else{

            ll p1 = b[xd-1] - (left>0 ? b[left-1]: 0LL);
            ll p2 = b[right];
            cout << (p1 + p2) << endl;
        }
    }




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

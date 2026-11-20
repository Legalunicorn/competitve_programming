#include <bits/stdc++.h>
#include <sys/types.h>
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

//NOTE:
//i think this can easily convert to dp due to limited states 
// caveat, is there back propagation of using the convertion 
// A A B -> A B C - > B C C 
//
//  
//  observations 
//  1. every opertion intriduce 1 C 
//  2. C cannot be used in an operation 
//  3. therefore there is max n operations 
//
//  operatoin 1 introduces "C" to the right 
//  operation 2 introduce "C" to the left 
//  -> it makes sense to 
//
//  -> opt1 will not allow new opt2 
//  -> opt2 will not allow new opt1 
//
//  ideas 
//  1. do one from its direction, then the other from the other direction
//  2. which do we do first? 
//  why not try both ? 


// NOTE:
// greedy idea #1 didnt work 
// there might be another greedy which is 2 pointer but i doubt.. 
// i cant prove at all 
// i know exachnge argument might work 
// there is quite a complicated dp approach 
//
// greedy #2 
// -> use a mix in one direction, then a mix backwarsd
// 
// AA -> ignore 
// BA -> opt2 CB 
// AB -> op11 BC 
// BB -> ignore 
//
//
// i cant figure out the greedy holy shit i cant prove it either 
// maybe its really dp 
//
//
// 

// NOTE: 
// I read the first paragraphs of the editorial, which is a 
// massive hint 
//
// i have an general idea now 
// that "B" eats the "A" 
// and im pretty sure if there is any consequnetive "B" we can eat all the 
// stuff. otherwise we can eat all the segmenets except 1 (with min 1 B)

// not really back to back 
// but i think its the numbre of b segments
// or otherwise just check if both ends is "A"

void solve(){
    string s, t;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int bcnt = 0;
    int len  = 0;
    vi seg;
    bool btb = false;
    for (int i = 0 ;i < n; i++){
        if (s[i] == 'A'){
            len++;
        } else{
            bcnt++;
            if (len){
                seg.pb(len);
                len = 0;
            }  else btb = true;
        }
    }
    if (len) seg.pb(len);
    sort(all(seg));
    debug(seg);
    int sum = 0;
    for (auto& z: seg) sum += z;
    if (bcnt == 0){
        cout << 0 << endl;
        return;
    }
    if (s[0] == 'A' && s[n-1] == 'A' && !btb){
        cout << sum - seg[0] << endl;
    } else cout << sum << endl;
    // if (btb || seg.size() == 1){
    //     cout << sum << endl;
    // } else{
    //     cout << sum - seg[0] << endl;
    // }

    
    // t = s;
    // int r1 = 0, r2  =0;
    // // s -> opt1 from right, the opt 2 from left 
    // for (int i = n-2; i >= 0; i--){
    //     if (s[i] == 'A' && s[i+1] == 'B') {
    //         s[i] = 'B';
    //         s[i+1] = 'C';
    //         r1++;
    //     }
    // }
    // for (int i = 0; i + 1 < n; i++){
    //     if (s[i] == 'B' && s[i+1] == 'A'){
    //         s[i] = 'C';
    //         s[i+1] = 'B';
    //         r1++;
    //     }
    // }
    //
    // // t -> 
    // for (int i = 0; i + 1  < n; i++){
    //     if (t[i] == 'B' && t[i+1] == 'A') {
    //         t[i] = 'C';
    //         t[i+1] = 'B';
    //         r2++;
    //     }
    // }
    // for (int i= n-2; i >= 0; i--){
    //     if (t[i] == 'A' && t[i+1] == 'B'){
    //         t[i] = 'B';
    //         t[i+1] = 'C';
    //         r2++;
    //     }
    // }
    // debug(r1,r2);
    // cout << max(r1,r2) << endl;
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

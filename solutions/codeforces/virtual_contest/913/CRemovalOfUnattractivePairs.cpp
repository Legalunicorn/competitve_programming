#include <bits/stdc++.h>
#include <random>
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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

// cannot remove adjaceny same 
// d a b b b 
// can we just try both left right ? 
// d a b b b = 1 
// b b b a d 
// b b
// not the right idea ? 
// if we have like a a  a x y  a a a a 
// obvious x y is the wrong deicsion 
// y o x y o x 
// the remaining string will have at most 1 unique character 
// if it had 2 -> we can just remove the area where its not the same 
// a a a b b b 
// a b a b a 
// 
// 1. always 1 unique character 
// 2. we can always force merge with the domainant frequency 
// 4. a a a a  a a a b b 
// 1. size of max freq 
// 2. n - size of that 
//
//
// almost there 
// what about odd n ? 
//  max freq of X 
//  rest are NOT x 
//  4 x 
//  5 others 
//  lets say we have 10 mx 
//  and 5 non mx 
//



void solve(){
    int n; cin >> n;
    string s; 
    cin >> s;
    vi freq(26);
    for (char c:s){
        freq[c-'a']++;
    }
    int mx = MAX(freq);
    int rem = n - mx; 
    int lim = (n%2==1)? 1:0;

    int a = mx, b = rem;
    if (a<b) swap(a,b);
    // debug(a-b);

    int ans = max(lim, mx - rem);
    cout << ans << endl;



    // stack<char> st, s2;
    //
    // for (int i=n-1; i>=0; i--){
    //     char c = s[i];
    //     if (!s2.empty() && s2.top() != c){
    //         s2.pop();
    //     } else s2.push(c);
    // }
    //
    // for (int i=0;i<n;i++){
    //     char c = s[i];
    //     if (!st.empty() && st.top() != c){
    //         st.pop();
    //     } else st.push(c);
    //     // dont push ?
    // }
    // debug(s2.size(), st.size());
    // cout << min(s2.size(),st.size()) << endl;
    
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

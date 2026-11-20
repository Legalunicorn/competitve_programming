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


// multiple of 4 ? 
// 4, 8 ,12 16 ,20 , 24 , 28, 32 , 36, 40
// 44,4 48 , 52 ,5 6, 60 
// seelct some elements, write on a string 
// beautifyil -> impossible 


// this is adhoc isnt it 
// this is so retarded 
// last two digits divisible by 4 
// or ends in 00 
// 1. generate all 2 digits divisible by 4 
// goal: no pair of digits is divisible by 4 
// number of zeros is at most "1" 
// theres only 25 numbers 
// we must not be able to form ANY of them 
//

// omg read the problem 
// its only digits 1 to 4 
// 1234 124 124


// 12, 32, 44 
// 24, u forgot 24  


// SUBSEQUENCES!!!! 
//
// BUG: 
// i did not consider that removing sum affects the rest 
// if i remove a "2"  and there are no nmore 2s behind 
//
//
// no fucking way this is dp 
// left "2"s and right "1/3"

void solve(){
    string s;
    cin >> s;
    string t ="";
    vi mp(10);
    int fours = 0;
    for(char c: s){
        if (c != '4') t += c;
        else fours++;
    }

    int n = t.size();
    if (n == 0){
        cout << fours << endl;
        return;
    }
    debug(t);
    int evl = n;
    int twos = 0; 
    vi cnt(n);
    for (int i = n-1; i >= 0;i--){
        if (t[i] == '2') twos++;
        cnt[i] = twos;
    }
    debug(cnt);
    int left = 0;
    evl = cnt[0];
    for (int i = 0; i < n; i++){
        if (t[i] == '1' || t[i] == '3') left++;
        int right = 0;
        if (i+1<n) right = cnt[i+1];
        debug(i, left, right);
        evl = min(evl, left+right);
    }
    debug(evl, fours);
    cout << evl + fours << endl;


    // bool b = false;
    // bool z = false;
    // vb seen(n, false);
    // vb seen2(n, false);
    //
    // for (int i = n-1; i >= 0; i--){
    //     if (t[i] == '2') b = true;
    //     seen[i] = b;
    // }
    // for (int i = 0; i < n; i++){
    //     if (t[i] != '2') z = true;
    //     seen2[i] = z;
    // }
    //
    // int e1 = 0, e2 = 0;
    // for (int i = 0; i < n;i ++){
    //     if (t[i] == '2'){
    //         if (seen2[i])  e1++;
    //     } else{
    //         if (seen[i]) e2++;
    //     }
    // }
    // int res = min(e1,e2);
    // cout << res + fours << endl;

    




    // map<int,int> mp;
    // vi mp(10);
    // for (char c: s){
    //     mp[c-'0']++;
    // }
    // int f = mp[4];
    //
    //
    //
    //
    // // {1,2} + f 
    // if (mp[3] == 0){
    //     cout << f + min(mp[1],mp[2]) << endl;
    //     return;
    // }
    // if (mp[2] == 0){
    //     cout << f << endl;
    //     return;
    // }
    // if (mp[1] == 0){
    //     cout << f + min(mp[2],mp[3]) << endl;
    //     return;
    // }
    //
    // // 1,2,3 are all presnet 
    // int evl = s.size();
    // evl = min(evl, mp[2]); // remove all 2s 
    // evl = min(evl, mp[1] + mp[3]);
    // cout << f + evl << endl;

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

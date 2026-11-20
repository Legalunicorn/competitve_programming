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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    string s;
    cin >> s;
    vi freq(26,0);
    int count = 0;
    int res = 0;
    for (int i=0;i<s.size();i++){
        int c = s[i]-'a';
        freq[c]++;
        count ++;
        if (freq[c] == 2){
            res += (count - 2);
            freq.assign(26,0);
            count = 0;
        }
    }
    res += count;
    cout << res << endl;
    // surely this is greedy? 
    // if freq == 1, obviously must remove 
    // we need to delet the mind count to make it eve need
    // a b g g b b  
    // idea: just keep selecting the best Odd ? 
    // traverse left to right with freq map 
    // when something Hits "2", reset count to 0 and clear all other elemenets 
    // reset the freq 
    // reset again at the end 
    // a* a* a* b^ a* b b b 
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

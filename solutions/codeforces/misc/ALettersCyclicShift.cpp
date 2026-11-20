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
    bool found = false;
    int start = -1;
    for (int i =0;i<s.size(); i++){
        char c = s[i];
        if (c!='a') {
            start = i;
            break;
        }
    }
    if (start == -1){
        cout << s.substr(0,s.size()-1) << 'z' << endl;
        return;
    }
    bool pause = false;
    int end = start;
    for (int i = start; i < s.size(); i++){
        if (s[i] != 'a') end = i;
        else break;
    }


    for (int i = 0; i < s.size(); i++){
        if (i < start || i > end) cout << s[i];
        else {
            int x = s[i]-'a';
            char r  = (char)(x - 1 +'a');
            cout << r;
        }
    }
    //
    //
    // for (int i = 0; i < s.size() ;i++){
    //     if (i < start) cout << s[i];
    //     else if (s[i]=='a'){
    //         pause = true;
    //         cout << s[i];
    //     } else if (pause) cout << s[i];
    //     else {
    //         char res = (char)((s[i]-'a')- 1+ 'a');
    //         cout << res;
    //     }
    // }

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

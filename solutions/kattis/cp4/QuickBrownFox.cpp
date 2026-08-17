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

void solve(){
    string line;
    getline(cin, line);
    vi freq(26,0);
    for (char c: line){
        if (isalpha(c)){
            c = tolower(c);
            freq[c-'a']++;
        }
    }
    string m;
    for (int i = 0; i < 26;i++){
        if (freq[i] == 0){
            m += (char)(i + 'a');
        }
    }
    if (m.size() == 0){
        cout << "pangram" << endl;
    } else{
        cout << "missing " << m << endl;
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
    cin.ignore(); // ignore the new line after "n"
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

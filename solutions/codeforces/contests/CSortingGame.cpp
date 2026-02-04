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


// Alicec move 
// Bob move 
// Alice move 
// Bob move .. 

// there is some kind of optimal strategy 
// and we need to 
// 1. determine who wins 
// 2. if alice wins print the answer 
//

// naive greedy says that we just constantly pick the LDS 
// we pick the LONGEST lds
// then we swap. 
// but what if we do that, the other place select the rest, then we instantly lose? 
// do we select suboptimally? 
//
// actually its not clear.. if we pick a lower
//
// its also not clear how to dp on this 
// my senses say its its greedy or math 
// 1. can we reverse? 
// we know the final answer, its just the sorted array 
//

// 1. every move must be at least 2 elements to change something 
//

// WAIT 
// its only BINARY STRING
//
// the obvious result is 0 0 0 0 1 1 1 1 1 
// 1. select at least 2 elements, 
// 2. cannot select all the same elements 
// 3. the selected order has to be 1 1 0 0 0 
// 1 0 0 0
// 1 1 1 0 
//
// maybe is like number of swaps? 
// note if the last character is "1" 
// we cannot select it 
// we cannot select any suffix of 1 
// or any prefix of 0 
// i feel like its the number of swaps needed to swap but i cant 


void solve(){
    int n;
    string s;
    cin >> n >> s;
    ll count = 0;

    // check if sorte
    bool found = false;
    for (int i = 1 ; i < n; i++ ){
        if (s[i]=='0' && s[i-1]=='1'){
            found = true;
            break;
        }
    }
    if (!found){
        cout << "Bob" << endl;
        return;
    }

    string t = s;
    sort(all(t));
    vi res;
    for (int i = 0; i <n ;i++){
        if (s[i] != t[i]) res.pb(i+1);
    }
    cout << "Alice" << endl;
    cout << res.size() << endl;
    for (auto& x: res) cout << x << " ";
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

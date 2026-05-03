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
// 3 1 2  
// 2 1 3  
//
// NOTE:
// 3 1 2 0 
// 0 1 3 2
// 0 1 2 3 
//
// WARNING:
// observations 
// 1. the last element is always part of LEX subsequence 
// 2. the LEX is in decreasing order 
// 3. the unselected elements need to be sorted? 
// my rough idea is to somehow assume that the shifted items shrinks and is always the same set 
// then everytime we shift we check that its greater or equal to the first pos, 
// then we shift the first pos to the next 
//
// basically we get the subsequence indexes, 
// then we sort them within those indexes 
// then we check if the array is sorted 
// if so we print the size of the subsequence 
//
// 
//
// INFO:
// what ever goes behind is FIXED 
// because lex is "greedy" it takes the largest char 
// whatever gets shifted behind get fixed, meaning it must 
// 3 20 4 4 e 15 5 5 5 


void solve(){
    int n;
    cin >> n;;
    string s;
    cin >> s;
    debug(n,s);
    // vvi next(n+1, vi (28, n + 5));
    vvi next(n+1, vi(28, n+5));
    for (int i = 0;  i  < n; i++){
        int v = s[i] - 'a';
        next[i][v] = i; // the next "i" is here!
        // next[i + 1][v] = i; 
    }
    for (int i = n-1; i >=0; i --){
        for (int j = 26; j >= 0; j -- ){
            next[i][j] = min(next[i][j],next[i+1][j]);
            // next[i][j] = min(next[i][j], next[i][j+1]);
        }
    }
    // debug(next);

    vi idx;
    string t;
    int pos = 0;
    while(pos < n) {
        debug(pos);
        bool found = false;
        for (int j = 26; j >=0; j--){
            if (next[pos][j] != n+5){
                int v = next[pos][j];
                idx.pb(v);
                t += (char)(j +'a');
                pos = v + 1;
                found = true;
                break;
            }
        }
        if (!found) break;
    }
    int cnt = 1;
    for (int i = 1; i < t.size(); i++){
        if (t[i] == t[i-1]) cnt++;
        else break;
    }
    int res = t.size() - cnt;
    // int res = t.size() - 1;
    sort(all(t));
    for (int i = 0; i  < t.size(); i ++){
        s[idx[i]] = t[i];
    }
    debug(s,t);
    cerr << endl;
    for (int i = 1; i < n; i++){
        if (s[i]-'a' < s[i-1]-'a'){
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
    
    
    // debug(next);
    // vi idx;
    // string t;
    // int curr = 0;
    // while(false){
    //     bool found = false;
    //     for (int j  = 26; j >= 0; j --){
    //         if (next[curr][j] != n + 5) {
    //             idx.pb(next[curr][j]);
    //             t += (char)(j + 'a');
    //             curr = next[curr][j];
    //             found = true;
    //             break;
    //         }
    //     }
    //     if (!found) break;
    //
    // }
    // debug(s,t,idx);

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

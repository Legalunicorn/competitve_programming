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

// lex -> greedy 
// we are given encrpted 
// we want lex smallest descryopted
// we can constructed edges, greedy, using lex rules 
// additional consttraits 
//  1. cannot make cycles of less than 26 
//  2. cannot point to self 
//
// IMPLEMENTATOIN 
//  1. for char c in string 
//      1. if we have mapped this c to another char then ignore 
//      2. else we need to find the best mapping 
//          - ensure no small loop, ensure no self loop 
//          for char x:  A - Z 
//              if x has been chosen ignore 
//              if leads to cycle < 26 ignore 
//              else refernece c -> x 
//
// how to check if edge leads to cycle? check if the two are unioned together already 
// and if so the size of union MUST be 26


struct Dsu{
public:
    int n; 
    vector<int> par, size;
// public:
    Dsu(int sz){
        n = sz;
        size.assign(n,1);
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
    }

    int find(int v){
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void union_set(int a, int b){
        a = find(a);
        b = find(b);
        if (a != b){
            if (size[a] < size[b]) swap(a,b);
            par[b] = a;
            size [a] += size[b];
        }
    }
};


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s; 
    vi a(26, -1); // idx -> point to next
    vb used(26, false);
    Dsu dsu(26); // union the alphabets

    for (int i = 0 ;i  < n; i++){
        char c = s[i];
        int parent1 = dsu.find(c-'a');
        // already maps to something
        if (a[c-'a'] != -1) continue; // already found mapping 
        for (char x = 0; x < 26; x++ ){ // A - Z 
            if (x == c-'a' || used[x]) continue;
            int parent2 = dsu.find(x);
            // debug(parent1,parent2, dsu.size[parent1]);
            if (parent1 != parent2 || (parent1 == parent2 && dsu.size[parent1] ==26)){

                a[c-'a'] = x; 
                used[x] = true;
                dsu.union_set(c-'a', x);
                break;
            }
        }
    }

    // print results 
    for (int i = 0; i  < n; i++ ) {
        cout << (char)(a[s[i]-'a'] + 'a');
    }
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

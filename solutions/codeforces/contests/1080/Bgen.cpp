#include <algorithm>
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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;


int RND(int a, int b){
    return a + rand() % (b - a + 1);
}


int main(int argc, char* argv[]){
    srand(atoi(argv[1])); // atoi(s) convert an array of chars to it 
    cout << 1 << endl;
    int n = RND(9,9);
    cout << n << endl;
    vi a(n);
    for (int i = 0; i < n; i++) a[i] = i+1;
    random_device(rd);
    mt19937 g(rd());
    shuffle(all(a), g);
    for (auto& z: a) cout << z << " ";
    cerr << n << endl;
    for (auto& z:a ) cerr << z << " ";
    cerr << endl;

};


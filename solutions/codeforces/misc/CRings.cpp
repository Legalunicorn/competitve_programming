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

// if s = t, k = 1 and we are done 
// i dont think we can prove its always possible to find another s?... 
// what about bitwise with extra "0"s 
// yeah its just multiples of 2s 
// can we proof that 
// i feel like this is some kind of proving question
// that 1. we can either always find the same substring 
//
// // 2. we can always find some zeros to cut 
//
//
// 1. find any substring size> (n/2) ending with 0 
// 2. just remove the 0 
//
// the counter case is that if they are all ones,
// then we can find the duplication esaily 
// half - 1, end -1 and half , end 
//
// actually we can find 0 on the prfix  as well it leads to the same number 
// 1. find the first 0 
// 2. if 0 < n/2 done 
// if 0 == n /2 ? 
//
// 1. find nearest 0 from the left and right 
// 1. if zero cout = 0, return any equal substring 
// 2. if n is odd and zero is only in the middle, 0 11 = 11 0 / 2 ! 


// edge case: 0/0 is not defined. 
//

int tc = 0;
void solve(){
    tc++;
    int n;
    string s;
    cin >> n >> s;
    int m = (n+1)/2;


    debug(n,m);
    for (int i = 0; i+ m < n ;i++ ){
        if (s[i] == '0'){
            int j = i +1;
            int k = j + m;
            cout << j << " " << k << " ";
            cout << j+1 << " " << k << endl;
            return;
        }
    }
    for (int i = n-1; i - m >= 0; i--){
        if (s[i]=='0'){
            int j = i + 1;
            int k = j - m;
            cout << k << " " << j<< " ";
            cout << k << " " << j-1 << endl;
            return;
        }
    }
    if (s[m-1]=='1'){
        cout << 1 << " " << n-1 << " ";
        cout << 2 << " " << n << endl;
        return;
    }
    cout << 1 << " " << m << " ";
    cout << m << " " << n << endl;

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

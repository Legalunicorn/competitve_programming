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
    int n;
    string s;
    cin >> n >> s;
    // harmonic series time complexity? 
    // iterate from 1 to sqrt(n), and check if the the modulus equals 
    // then bruteforce
    for (int k = 1; k < n; k++){
        if (n % k != 0) continue;
        // [0, k 
        int m = n / k;
        int diff = 0;
        int diff2 = 0;
        bool valid = true;
        bool valid2 = true;
        for (int i = 0; i  < m; i++){
            // if (!valid) break;
            int l = k * i;
            for (int j = 0; j < k; j ++){
                int r = l + j;
                if (s[r] != s[j]){
                    if (diff > 0){
                        valid = false;
                    } else diff++;
                }
                if (s[r] != s[j+k]){
                    if (diff2>0) valid2 = false;
                    else diff2++;
                }
            }

        }

        if (valid || valid2){
            cout << k << endl;
            return;
        }

    }
    cout << n << endl;
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

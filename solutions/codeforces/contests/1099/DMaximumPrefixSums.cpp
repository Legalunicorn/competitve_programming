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


//NOTE: 
//studying from ksun solitions 
// b[i] = sum + A[i] 
// b[j] = sum + A[i] + A[i+1] + ... + A[j] 
// let sum of A[i+1, j] be TOTAL 
// b[j] = sum + A[i] + TOTAL 
// constraints b[x] <= c[x] for all x 
// sum + A[i] + TOTAL <= c[j], for all j 
// A[i] <= c[j] - sum - TOTAL 
// "0 1 1 1 1 1 " 
void solve() {
    int n;
    cin >> n;
    string s; cin >> s;
    vl a(n), c(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:c) cin >> z;
    ll sum = 0L;
    int i  = 0;
    while(i < n){
        if (s[i] == '1'){
            sum += a[i];
            i++;
        } else{
            ll minv = c[i] - sum;
            ll acc = 0;
            for (int j = i + 1; j < n; j++){
                if (s[j] == '0') break;
                acc += a[j];
                minv = min(minv, c[j] - sum - acc);
            }
            a[i] = minv;
            s[i] = '1';
        }
    }
    bool valid = true;
    sum = 0;
    ll msf = -1e18;
    debug(a);
    for (int i = 0; i < n ; i++){
        sum += a[i];
        msf = max(msf, sum);
        if(msf != c[i]) valid = false;
    }
    if (!valid) cout << "No" << endl;
    else {
        cout << "Yes" << "\n";
        for (auto& z: a) cout << z << " ";
        cout << endl;
    }
}


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

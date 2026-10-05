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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;


vector<int> factor(int n){
    vector<int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res.push_back(i);
            n /= i;
        }
    }
    if (n>1) res.push_back(n);
    return res;
}

bool isPrime(ll x){
    for (ll i = 2 ; i * i <= x; i++){
        if (x%i==0) return false;
    }
    return true;
}


void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vi d(10,-1);
    vi ass(27,-1);
    bool found = false;
    ll res = 0;
    debug(s);
    auto go = [&](auto& go, int i) -> void{
        if (i == n){
            // debug(d);
            // construct the number, then checkw if prime
            // string x = "";
            ll x = 0;
            for (int j = 0; j < n; j++){
                x *= 10;
                x += ass[s[j]-'a'];
            }
            if (isPrime(x)){
                found = true;
                res = x;
            }
        } else{
            int c = s[i]-'a';
            if (ass[c]  == -1){
                for (int z = 0; z <= 9; z++){
                    if (i == 0 && z == 0) continue;
                    if (d[z] == -1){
                        d[z] = 0;
                        ass[c] = z;
                        go(go,i+1);
                        d[z] = -1;
                        ass[c] = -1;
                    }
                }
            }  else go(go,i+1);
        }
    };
    go(go,0);
    debug(found,res);
    if (!found) cout << -1 << endl;
    else cout << res;

    // this is just impl isnt it? 
    // 7 digits long 
    // we just try all possible digits mapping then check if prime
    // vi fac()
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}

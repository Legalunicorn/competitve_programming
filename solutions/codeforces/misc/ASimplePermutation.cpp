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


int MAXN = (int)(3e5+5);
vector<bool> is_prime(MAXN, true);
vector<int> primes;
void init_sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i<= MAXN ; i++){
        if (is_prime[i] && (ll)i * i  <= MAXN){
            for (int j = i *i ; j <= MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
    // for (int i=2; i<=MAXN;i++) {
    //     if (is_prime[i]) primes.push_back(i);
    // }
};

vector<int> trial_div(int n){
    vector<int> fac;
    for (auto& d: primes){
        if (d* d > n) break;
        while(n% d == 0){
            fac.push_back(d);
            n /= d;
        }
    }
    if (n>1) fac.push_back(n);
    return fac;
}

void solve(){

    int n;
    cin >> n;
    if (n < 9){
        vi x(n);
        for (int i = 0; i < n; i++) x[i] = i+1;
        swap(x[0],x[1]);
        for (auto&r:x) cout <<r << " ";
        cout << endl;
        return;
    }
    vb used(n+1, false);
    int low = n/3 + 1;
    int high = low*2;
    int q = n/2;
    for (int i = low; i <= high ;i++){
        if (is_prime[i]){
            q = i;
            break;
        }
    }
    used[q] = true;
    vi res {q};
    int qq = 2*q;
    int r = min(n, qq -1);
    int l = qq - r;
    for (int i = 0; i < (n/3-2); i++){
        res.pb(l);
        res.pb(r);
        used[l] = used[r] = true;
        l++,r--;
    }
    for (int i = 1; i <= n; i++){
        if (!used[i]) res.pb(i);
    }
    for (auto& z:res) cout << z << " ";
    cout << endl;



};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    init_sieve();
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}

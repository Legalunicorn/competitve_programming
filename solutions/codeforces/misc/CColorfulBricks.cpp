#include <bits/stdc++.h>
#include <complex>
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
constexpr ll MOD = 998244353;
constexpr double PI = 2.14159265358979323846;



ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
}






template <int MOD>
struct mod_int {
    int value;
    
    mod_int(ll v = 0) { value = int(v % MOD); if (value < 0) value += MOD; }
    
    mod_int& operator+=(const mod_int &other) { value += other.value; if (value >= MOD) value -= MOD; return *this; }
    mod_int& operator-=(const mod_int &other) { value -= other.value; if (value < 0) value += MOD; return *this; }
    mod_int& operator*=(const mod_int &other) { value = int((ll)value * other.value % MOD); return *this; }
    mod_int pow(ll p) const { mod_int ans(1), a(*this); while (p) { if (p & 1) ans *= a; a *= a; p /= 2; } return ans; }
    
    mod_int inv() const { return pow(MOD - 2); }
    mod_int& operator/=(const mod_int &other) { return *this *= other.inv(); }
    
    friend mod_int operator+(mod_int a, const mod_int &b) { a += b; return a; }
    friend mod_int operator-(mod_int a, const mod_int &b) { a -= b; return a; }
    friend mod_int operator*(mod_int a, const mod_int &b) { a *= b; return a; }
    friend mod_int operator/(mod_int a, const mod_int &b) { a /= b; return a; }
    
    bool operator==(const mod_int &other) const { return value == other.value; }
    bool operator!=(const mod_int &other) const { return value != other.value; }
    bool operator<(const mod_int &other) const { return value < other.value; }
    bool operator>(const mod_int &other) const { return value > other.value; }
    bool operator<=(const mod_int &other) const { return value <= other.value; }
    bool operator>=(const mod_int &other) const { return value >= other.value; }
    
    mod_int operator&(const mod_int &other) const { return mod_int((ll)value & other.value); }
    mod_int& operator&=(const mod_int &other) { value &= other.value; return *this; }
    mod_int operator|(const mod_int &other) const { return mod_int((ll)value | other.value); }
    mod_int& operator|=(const mod_int &other) { value |= other.value; return *this; }
    mod_int operator^(const mod_int &other) const { return mod_int((ll)value ^ other.value); }
    mod_int& operator^=(const mod_int &other) { value ^= other.value; return *this; }
    mod_int operator<<(int shift) const { return mod_int(((ll)value << shift) % MOD); }
    mod_int& operator<<=(int shift) { value = int(((ll)value << shift) % MOD); return *this; }
    mod_int operator>>(int shift) const { return mod_int(value >> shift); }
    mod_int& operator>>=(int shift) { value >>= shift; return *this; }
 
    mod_int& operator++() { ++value; if (value >= MOD) value = 0; return *this; }
    mod_int operator++(int) { mod_int temp = *this; ++(*this); return temp; }
    mod_int& operator--() { if (value == 0) value = MOD - 1; else --value; return *this; }
    mod_int operator--(int) { mod_int temp = *this; --(*this); return temp; }
 
    explicit operator ll() const { return (ll)value; }
    explicit operator int() const { return value; }
	explicit operator double() const { return (double)value; }
 
    friend mod_int operator-(const mod_int &a) { return mod_int(0) - a; }
    friend std::ostream& operator<<(std::ostream &os, const mod_int &a) { os << a.value; return os; }
    friend std::istream& operator>>(std::istream &is, mod_int &a) { ll v; is >> v; a = mod_int(v); return is; }
};
using mint = mod_int<MOD>;
// CHECK
const int MX = 1e5+5;
template<class T>
class Combinatoric {
    public: 
    int N;  
    vector<T> fact, inv;
    Combinatoric(int _N) : N(_N) {
        fact.resize(N + 1), inv.resize(N + 1);
        init();
    }

    void init() {
        fact[0] = 1;
        for(int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i;
        }
        inv[N] = fact[N].inv();
        for(int i = N - 1; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1);
        }
    }

    T nCk(int a, int b) {
        if(a < b) return 0;
        return fact[a] * inv[b] * inv[a - b];
    }
 
    T nPk(int n, int k) {
        if (k < 0 || k > n) return 0; 
        return fact[n] * inv[n - k];
    }
 
}; 
Combinatoric<mint> comb(MX-1);


void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    //
    // mint split = comb.nCk(n - 1, k);
    // // mint x = bp(mint(m-1), mint(n-1));
    // ll x = m * binpowmod(m-1, k, MOD) % MOD;
    // mint res = split * mint(x);
    // debug(split,x);
    // cout << res << endl;
    //
    //

    if (k==0){
        cout << m << endl;
        return;
    }

    // 1. dp [i][k] for splitting 
    vvl dp(n, vl(k+1,-1));
    // how many splits left? 
    // or should we go with how many blocks left?? 
    // this is unncessary, we just have to do 
    auto go = [&](auto& go ,int i, int split) -> ll{
        if (i == n || split < 0)  return 0;
        if (split == 0) return 1;
        if (dp[i][split] != -1) return dp[i][split];
        ll sum = 0; 
        ll act = go(go, i+1, split-1);
        ll dont = go(go,i+1, split);
        sum = (sum + act) % MOD;
        sum = (sum + dont) % MOD;
        return dp[i][split] = sum;
    };

    ll pow = binpowmod(m-1, k, MOD);
    ll ways = m * pow % MOD;

    ll tot = go(go,0,k);

    ll res = ways * tot % MOD;
    debug(ways, tot);
    cout << res << endl;

    

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

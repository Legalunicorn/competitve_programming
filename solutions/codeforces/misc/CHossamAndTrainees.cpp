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


const int LIM = 32000;
bool isprime[LIM + 1];
vi primes;

void init(){
    for (int i = 2 ; i <= LIM; i++){
        if (!isprime[i]) primes.pb(i);
        for (int p: primes) {
            if ((ll)  i* p  > LIM) break;
            isprime[i*p] = true;
            if (i % p == 0) break;
        }
    }
}

void f(int);

void fake(){

    int x[10] = {86, 70, 91, 85, 76, 18, 33, 4, 1, 26};
    f(x[2]);
    printf("%d\n", x[4]); // This line;

};

void f(int y) {

    y*=2;
}


set<ll> factorize(ll n) { 
    set<ll> res;
    for (ll d: primes){
        if (d * d > n) break;
        while(n % d == 0){
            res.insert(d);
            n/=d;
        }
    }
    if (n>1) res.insert(n);
    return res;
}


typedef struct{
int x;
char c[32];
} TTest;

TTest f(TTest);

void fake2() {
TTest t1 = {5, "hello world"};
TTest t2 = f(t1);
printf("%d%s %d %s\n", t1.x, t1.c, t2.x, t2.c);
}

TTest f(TTest t1) {
static TTest tmp;
t1.x --;
strcpy(t1.c, "penguin");
tmp = t1;
return tmp;
}

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a)  cin >> z;
    set<ll> has;
    for (int i = 0; i < n; i++){
        set<ll> evl = factorize(a[i]);
        debug(a[i], evl);
        for (auto& z: evl){
            if (has.count(z)){
                cout << "YES" << endl;
                return;
            }
            has.insert(z);
        }
    }
    cout << "NO" << endl;
        
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    fake2();
    char str[] = "HOST-";
    // f(str);
    for(int i = 0; i < 6;i++) debug(str[i]);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
